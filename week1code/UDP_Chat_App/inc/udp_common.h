/*
 * udp_common.h
 * ---------------------------------------
 * Common UDP Communication Interface
 * Author: Sanjeevi Ram N
 *
 * Description:
 *   This header provides helper functions for UDP socket creation,
 *   binding, sending, and receiving messages.
 *
 * Purpose:
 *   To abstract and simplify the use of UDP networking in both
 *   client and server applications using a consistent API.
 */
#ifndef UDP_COMMON_H
#define UDP_COMMON_H
#include <netinet/in.h>  // For sockaddr_in
// 📦 Maximum buffer size for UDP message transfer
#define MAXLINE 1024
/**
 * udp_create_socket()
 * ---------------------
 * Creates a UDP socket using IPv4.
 *
 * Returns:
 *   - Socket file descriptor on success
 *   - -1 on failure
 */
int udp_create_socket();
/**
 * udp_bind_socket()
 * -------------------
 * Binds a socket to a specific port on the local machine.
 *
 * Parameters:
 *   - sockfd : Socket file descriptor
 *   - port   : Port number to bind to
 *
 * Returns:
 *   - 0 on success
 *   - -1 on failure
 */
int udp_bind_socket(int sockfd, int port);
/**
 * udp_receive()
 * -----------------
 * Receives a UDP message from any sender.
 *
 * Parameters:
 *   - sockfd : Socket file descriptor
 *   - buffer : Character array to store received message
 *   - addr   : Pointer to sockaddr_in struct (will be filled with sender info)
 *
 * Returns:
 *   - Number of bytes received
 *   - -1 on failure
 */
int udp_receive(int sockfd, char *buffer, struct sockaddr_in *addr);

/**
 * udp_send()
 * -------------
 * Sends a UDP message to the specified address.
 *
 * Parameters:
 *   - sockfd  : Socket file descriptor
 *   - message : Message to send
 *   - addr    : Destination address (IP and port)
 *
 * Returns:
 *   - Number of bytes sent
 *   - -1 on failure
 */
int udp_send(int sockfd, const char *message, struct sockaddr_in *addr);

#endif // UDP_COMMON_H

