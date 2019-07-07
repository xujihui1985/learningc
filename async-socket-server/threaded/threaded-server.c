#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>  // ?? unistd.h is the name of the header file that provides access to the POSIX operating system API
#include <pthread.h>

#include "utils.h"

typedef enum {
    WAIT_FOR_MSG, IN_MSG
} ProcessingState;

struct thread_config {
  int sockfd;
};

void
serve_connection(int sockfd) {
    if (send(sockfd, "*", 1, 0) < 1)  // fd, buf, length
    {
        perror("send");
        return;
    }

    ProcessingState state = WAIT_FOR_MSG;

    do {
        uint8_t buf[1024];

        int len = recv(sockfd, buf, sizeof(buf), 0); // fd, buf, length
        if (len < 0) {
            perror("recv");
            return;
        } else if (len == 0) {
            break;
        }

        for (int i = 0; i < len; i++) {
            switch (state) {
                case WAIT_FOR_MSG:
                    if (buf[i] == '^') {
                        state = IN_MSG;
                    }
                    break;
                case IN_MSG:
                    if (buf[i] == '$') {
                        state = WAIT_FOR_MSG;
                    } else {
                        buf[i] += 1;
                        if (send(sockfd, &buf[1], 1, 0) < 1) {
                            perror("send error");
                            close(sockfd);
                            return;
                        }
                    }
                    break;
                default:
                    perror("invalid message");
                    return;
            }
        }
    } while (1);

    close(sockfd);
}

void *server_thread(void *arg) {
  struct thread_config *config = (struct thread_config *)arg;
  int sockfd = config->sockfd;
  // free config after get sockfd;
  free(config);

  unsigned long id = (unsigned long)pthread_self();
  printf("thread %lu created to handle connnection with socket %d \n", id ,sockfd);
  serve_connection(sockfd);
  printf("thread %lu done\n", id);
  return 0;
}

int
main(int argc, char **argv) {
    // set buf for io，_IONBF means read or write to stream directly, no buffer
    setvbuf(stdout, NULL, _IONBF, 0);

    int port = 9090;

    if (argc >= 2) {
        port = atoi(argv[1]);
    }

    printf("Serving on port %d\n", port);

    int sockfd = listen_inet_socket(port);

    do {
        // initialize sockaddr
        struct sockaddr_in peer_addr;
        memset(&peer_addr, 0, sizeof(struct sockaddr_in));
        socklen_t peer_addr_len = sizeof(peer_addr);

        int newsockfd = accept(sockfd, (struct sockaddr *) &peer_addr, &peer_addr_len);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            return 1;
        }

        report_peer_connected(&peer_addr, peer_addr_len);

		pthread_t the_thread;

		struct thread_config *config = (struct thread_config *) malloc(sizeof(struct thread_config));
		if (!config) {
		  perror("oom");
		  return 1;
		}

		config->sockfd = newsockfd;
		pthread_create(&the_thread, NULL, server_thread, config);
		
		// Detach the thread - when it's done, its resources will be cleaned up.
		// Since the main thread lives forever, it will outlive the serving threads.
		pthread_detach(the_thread);
    } while (1);


    return 0;
}
