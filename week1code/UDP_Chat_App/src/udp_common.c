/*
 * udp_common.c
 * ------------------------------
 * UDP Socket Utility Functions
 * Author: Sanjeevi Ram N
 *
 * Description:
 *   This file provides reusable wrapper functions to simplify
 *   UDP socket communication for client-server applications.
 *
 * Functions:
 *   - udp_create_socket() : Create UDP socket
 *   - udp_bind_socket()   : Bind socket to port
 *   - udp_receive()       : Receive data from client
 *   - udp_send()          : Send data to client
 */

#include "udp_common.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

/**
 * udp_create_socket()
 * -----------------------
 * Creates a new UDP socket using IPv4 and datagram protocol.
 * 
 * Returns:
 *   int sockfd: Socket file descriptor or -1 on error.
 */
int udp_create_socket() 
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
        perror(" Socket creation failed");
    return sockfd;
}

/**
 * udp_bind_socket()
 * ---------------------
 * Binds a socket to a specified port and listens on any local IP.
 * 
 * Parameters:
 *   sockfd - socket file descriptor
 *   port   - port number to bind
 * 
 * Returns:
 *   0 on success, -1 on error.
 */
int udp_bind_socket(int sockfd, int port) 
{
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;  // Bind to all local interfaces

    return bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
}

/**
 * udp_receive()
 * -----------------
 * Receives a UDP message from a client.
 * 
 * Parameters:
 *   sockfd  - socket descriptor
 *   buffer  - character buffer to store received message
 *   addr    - pointer to sockaddr_in to store sender's address
 * 
 * Returns:
 *   Number of bytes received, or -1 on error.
 */
int udp_receive(int sockfd, char *buffer, struct sockaddr_in *addr) 
{
    socklen_t len = sizeof(*addr);
    int n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)addr, &len);
    if (n >= 0) buffer[n] = '\0';  // Null-terminate the message
    return n;
}

/**
 * udp_send()
 * ---------------
 * Sends a UDP message to the client.
 * 
 * Parameters:
 *   sockfd   - socket descriptor
 *   message  - string to send
 *   addr     - destination address
 * 
 * Returns:
 *   Number of bytes sent, or -1 on error.
 */
int udp_send(int sockfd, const char *message, struct sockaddr_in *addr) 
{
    return sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)addr, sizeof(*addr));
}

