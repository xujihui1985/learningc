#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define N_BACKLOG 64



int
listen_inet_socket(int portnum)
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0)
  {
	perror("ERROR opening socket");
  }

  int opt = 1;
  // SOL_SOCKET set options at the socket level
  // SO_REUSEADDR supplied to bind() should allow reuse of local addresses
  // opt 1 is the value of SO_REUSEADDR options
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
  {
	perror("setsockopt");
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(struct sockaddr_in));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // 0.0.0.0 any address for binding
  serv_addr.sin_port = htons(portnum);

  // bind server address with sockfd
  if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
	perror("ERROR on binding");
  }

  if (listen(sockfd, N_BACKLOG) < 0)
  {
	perror("ERROR on listen");
  }

  return sockfd;
}

void
report_peer_connected(const struct sockaddr_in *sa, socklen_t salen)
{
  char hostbuf[NI_MAXHOST];
  char portbuf[NI_MAXSERV];

  if (getnameinfo((struct sockaddr *)sa, salen, hostbuf, NI_MAXHOST, portbuf, NI_MAXSERV, 0) == 0)
  {
	printf("peer (%s, %s) connected\n", hostbuf, portbuf);
  } 
  else
  {
	printf("peer (%s) connected\n", "unknown");
  }

}

void
func_not_null(int a[static 1])  // means a at least has one element, so null is not able to pass to this function
{

}
