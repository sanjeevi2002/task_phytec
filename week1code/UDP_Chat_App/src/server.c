#include "udp_common.h"
#include "server_state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }

    int port = atoi(argv[1]);
    int sockfd = udp_create_socket();
    if (sockfd < 0 || udp_bind_socket(sockfd, port) < 0) 
    {
        perror("Server error");
        return -1;
    }

    struct sockaddr_in cliaddr;
    char buffer[MAXLINE];

    while (1) {
        switch (get_server_state()) 
        {
            case STATE_IDLE:
                printf("[Server] Waiting for message on port %d...\n", port);
                if (udp_receive(sockfd, buffer, &cliaddr) > 0) 
                {
                    printf("[Server] Received: %s\n", buffer);
                    server_state_machine(EVENT_RECEIVED);
                }
                break;

            case STATE_PROCESSING:
                printf("[Server] Processing message...\n");
                server_state_machine(EVENT_PROCESSED);
                break;

            case STATE_SENDING:
                udp_send(sockfd, "Message received", &cliaddr);
                printf("[Server] Reply sent.\n");
                server_state_machine(EVENT_SENT);
                break;
        }
    }

    return 0;
}
