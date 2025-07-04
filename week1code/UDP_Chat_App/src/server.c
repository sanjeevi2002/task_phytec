/*
 * UDP Server with State Machine
 * Author: Sanjeevi Ram N
 *
 * Description:
 * - Implements a basic UDP server in C
 * - Uses a finite state machine with 3 states: IDLE, PROCESSING, SENDING
 * - Listens on a specified port, receives messages, processes them, and sends responses
 */

#include "udp_common.h"      // Socket utility functions (create, send, receive)
#include "server_state.h"    // State machine enums and transition logic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entry Point: Accepts server port as a command-line argument
int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }

    // Extract port number
    int port = atoi(argv[1]);

    // 🔌 Create socket and bind to the specified port
    int sockfd = udp_create_socket();
    if (sockfd < 0 || udp_bind_socket(sockfd, port) < 0) 
    {
        perror("Server error");
        return -1;
    }

    struct sockaddr_in cliaddr;   // Client address
    char buffer[MAXLINE];         // Buffer to store received data

    // Main Server Loop: FSM-based handling
    while (1) 
    {
        switch (get_server_state()) 
        {
            // IDLE STATE: Waiting for incoming messages
            case STATE_IDLE:
                printf("[Server] Waiting for message on port %d...\n", port);
                if (udp_receive(sockfd, buffer, &cliaddr) > 0) 
                {
                    printf("[Server] Received: %s\n", buffer);
                    server_state_machine(EVENT_RECEIVED);  // Trigger processing
                }
                break;

            // PROCESSING STATE: Simulating some processing
            case STATE_PROCESSING:
                printf("[Server] Processing message...\n");
                server_state_machine(EVENT_PROCESSED);  // Move to send state
                break;

            // SENDING STATE: Sending response to client
            case STATE_SENDING:
                udp_send(sockfd, "Message received", &cliaddr);
                printf("[Server] Reply sent.\n");
                server_state_machine(EVENT_SENT);  // Return to idle
                break;
        }
    }

    return 0;
}
