#include "udp_common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return -1;
    }

    const char *server_ip = argv[1];
    int port = atoi(argv[2]);
    int sockfd = udp_create_socket();
    if (sockfd < 0) return -1;

    struct sockaddr_in servaddr;
    char buffer[MAXLINE], message[MAXLINE];

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(server_ip);

    while (1) 
    {
        printf("[Client] Enter message (or 'exit'): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';

        if (strcmp(message, "exit") == 0) break;

        udp_send(sockfd, message, &servaddr);
        if (udp_receive(sockfd, buffer, &servaddr) > 0)
            printf("[Client] Server reply: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
