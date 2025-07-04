/*
 * UDP Client in C
 * Author: Sanjeevi Ram N
 * Description:
 *   - Connects to a UDP server
 *   - Sends user messages
 *   - Receives replies from the server
 *   - Demonstrates use of sockets and command-line arguments
 */

#include "udp_common.h"       // Contains socket utility functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>        // For sockaddr_in and inet_addr
#include <unistd.h>           // For close()

int main(int argc, char *argv[]) 
{
    // Step 1: Validate command-line arguments
    if (argc != 3) 
    {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return -1;
    }

    // Extract server details from arguments
    const char *server_ip = argv[1];
    int port = atoi(argv[2]);

    // Step 2: Create UDP socket
    int sockfd = udp_create_socket();  // Defined in udp_common.h
    if (sockfd < 0) return -1;

    // Step 3: Define server address structure
    struct sockaddr_in servaddr;
    char buffer[MAXLINE], message[MAXLINE];

    // Clear memory and set up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);                    // Convert port to network byte order
    servaddr.sin_addr.s_addr = inet_addr(server_ip);    // Convert IP string to binary

    // Step 4: Communication loop
    while (1) 
    {
        // Take user input
        printf("[Client] Enter message (or 'exit'): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';  // Remove trailing newline

        // Exit condition
        if (strcmp(message, "exit") == 0) break;

        // Step 5: Send message to server
        udp_send(sockfd, message, &servaddr);  // Defined in udp_common.h

        // Step 6: Wait for server reply
        if (udp_receive(sockfd, buffer, &servaddr) > 0)
            printf("[Client] Server reply: %s\n", buffer);
    }

    // Step 7: Cleanup
    close(sockfd);
    return 0;
}

