/*
 * Server State Machine Logic
 * Author: Sanjeevi Ram N
 *
 * Description:
 *   - Implements a simple Finite State Machine (FSM) for a UDP server
 *   - Handles transitions between: IDLE → PROCESSING → SENDING → IDLE
 *   - Used in conjunction with server.c to manage non-blocking message flow
 */

#include "server_state.h"

// Global variable to store the current state
static State_t current_state = STATE_IDLE;

/*
 * server_state_machine(Event_t event)
 * ---------------------------------------
 * Handles state transitions based on incoming events.
 * Each state listens only for specific valid events to transition.
 */
void server_state_machine(Event_t event) 
{
    switch (current_state) 
    {
        case STATE_IDLE:
            if (event == EVENT_RECEIVED)
                current_state = STATE_PROCESSING;  // Move to processing
            break;

        case STATE_PROCESSING:
            if (event == EVENT_PROCESSED)
                current_state = STATE_SENDING;     // Ready to send
            break;

        case STATE_SENDING:
            if (event == EVENT_SENT)
                current_state = STATE_IDLE;        // Back to waiting
            break;
    }
}

/*
 * get_server_state()
 * ---------------------
 * Returns the current state of the server FSM.
 */
State_t get_server_state() 
{
    return current_state;
}
