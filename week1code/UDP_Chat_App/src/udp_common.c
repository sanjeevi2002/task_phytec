
#include "udp_common.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int udp_create_socket() 
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) perror("Socket creation failed");
    return sockfd;
}

int udp_bind_socket(int sockfd, int port) 
{
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    return bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
}

int udp_receive(int sockfd, char *buffer, struct sockaddr_in *addr) 
{
    socklen_t len = sizeof(*addr);
    int n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)addr, &len);
    if (n >= 0) buffer[n] = '\0';
    return n;
}

int udp_send(int sockfd, const char *message, struct sockaddr_in *addr) 
{
    return sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)addr, sizeof(*addr));
}
