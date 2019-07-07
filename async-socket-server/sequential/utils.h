#ifndef __UTILS_H__
#define __UTILS_H__

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int listen_inet_socket(int portnum);

void report_peer_connected(const struct sockaddr_in *sa, socklen_t salen);

void
func_not_null(int a[static 1]);

#endif // __UTILS_H__
