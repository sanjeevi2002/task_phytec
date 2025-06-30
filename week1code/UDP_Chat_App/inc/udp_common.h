#ifndef UDP_COMMON_H
#define UDP_COMMON_H

#include <netinet/in.h>

#define MAXLINE 1024

int udp_create_socket();
int udp_bind_socket(int sockfd, int port);
int udp_receive(int sockfd, char *buffer, struct sockaddr_in *addr);
int udp_send(int sockfd, const char *message, struct sockaddr_in *addr);

#endif
