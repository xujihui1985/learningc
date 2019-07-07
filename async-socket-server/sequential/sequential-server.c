#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>  // ?? unistd.h is the name of the header file that provides access to the POSIX operating system API

#include "utils.h"

typedef enum {
    WAIT_FOR_MSG, IN_MSG
} ProcessingState;

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

int
main(int argc, char **argv) {
    // set buf for io，_IONBF means read or write to stream directly, no buffer
    setvbuf(stdout, NULL, _IONBF, 0);

    func_not_null(NULL);

    char *a = "aaaaaa";
    char *b = a;
    printf(a, "aaa");

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
        serve_connection(newsockfd);
        printf("peer done\n");
    } while (1);


    return 0;
}