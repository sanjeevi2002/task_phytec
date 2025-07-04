/*
 * server_state.h
 * ------------------------------
 * Server-Side State Machine Header
 * Author: Sanjeevi Ram N
 *
 * Description:
 *   This header defines a simple finite state machine (FSM) for managing
 *   server behavior in a UDP-based communication system.
 * 
 * States:
 *   - STATE_IDLE        : Server is waiting for a message
 *   - STATE_PROCESSING  : Server is processing the received data
 *   - STATE_SENDING     : Server is sending a response back
 * 
 * Events:
 *   - EVENT_RECEIVED    : Triggered when a message is received
 *   - EVENT_PROCESSED   : Triggered after processing is complete
 *   - EVENT_SENT        : Triggered after sending the reply
 */

#ifndef SERVER_STATE_H
#define SERVER_STATE_H

// State_t defines the various states the server can be in
typedef enum 
{
    STATE_IDLE,         // Waiting for client message
    STATE_PROCESSING,   // Processing received message
    STATE_SENDING       // Sending response to client
} State_t;

// Event_t defines events that trigger state transitions
typedef enum 
{
    EVENT_RECEIVED,     // Message received from client
    EVENT_PROCESSED,    // Processing completed
    EVENT_SENT          // Message sent to client
} Event_t;

/**
 * server_state_machine()
 * ------------------------
 * Transitions server state based on input event.
 *
 * Parameters:
 *   - event : Event_t representing the latest event
 */
void server_state_machine(Event_t event);

/**
 * get_server_state()
 * --------------------
 * Returns the current state of the server.
 *
 * Returns:
 *   - State_t : current server state
 */
State_t get_server_state();

#endif // SERVER_STATE_H

