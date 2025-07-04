/*
 * Simple Finite State Machine (FSM) in C
 * Author: Sanjeevi Ram N
 * 
 * Description:
 * This program implements a simple message handler using a state machine with 3 states:
 *  - STATE_IDLE: Waiting for user to input a message
 *  - STATE_PROCESSING: Simulates processing of the received message
 *  - STATE_SENDING: Simulates sending a reply
 * 
 * State transitions are triggered by events, and the program loops until the user types "exit".
 */

#include <stdio.h>
#include <string.h>

// Define the different states in the FSM
typedef enum 
{
    STATE_IDLE,        // Waiting for message input
    STATE_PROCESSING,  // Message is being processed
    STATE_SENDING      // Message is being sent
} State_t;

// Define the events that trigger transitions between states
typedef enum 
{
    EVENT_NONE,        // No event (used for exit)
    EVENT_RECEIVE,     // Message received
    EVENT_DONE,        // Processing completed
    EVENT_SENT         // Reply sent
} Event_t;

State_t currentState = STATE_IDLE;   // Keeps track of the current FSM state
char message[100] = {0};             // Buffer to store the input message

// Function: Receive message from user
Event_t receiveMessage() 
{
    printf("Enter a message to receive (type 'exit' to quit): ");
    fgets(message, sizeof(message), stdin);  // Read message input
    message[strcspn(message, "\n")] = '\0';  // Remove trailing newline

    if (strcmp(message, "exit") == 0)
        return EVENT_NONE;   // User wants to exit

    return EVENT_RECEIVE;    // Message was received
}

// Function: Simulate processing the message
Event_t processMessage()
{
    printf("Processing message: \"%s\"\n", message);  // Simulate processing
    return EVENT_DONE;       // Indicate processing is done
}

// Function: Simulate sending a reply to the message
Event_t sendReply()
{
    printf("Sending reply for: \"%s\"\n", message);  // Simulate sending
    return EVENT_SENT;       // Indicate reply has been sent
}

// FSM Core Logic: Handles transitions between states based on events
void stateMachine(Event_t event) 
{
    switch (currentState) 
    {
        case STATE_IDLE:
            if (event == EVENT_RECEIVE) 
            {
                currentState = STATE_PROCESSING;  // Move to processing state
            }
            break;

        case STATE_PROCESSING:
            if (event == EVENT_DONE)
            {
                currentState = STATE_SENDING;     // Move to sending state
            }
            break;

        case STATE_SENDING:
            if (event == EVENT_SENT) 
            {
                currentState = STATE_IDLE;        // Return to idle state
            }
            break;

        default:
            currentState = STATE_IDLE;            // Reset to idle on unexpected condition
            break;
    }
}

// Main: Executes the FSM in a loop until user exits
int main() 
{
    Event_t event = EVENT_NONE;

    while (1) 
    {
        // Execute function depending on current state
        switch (currentState) 
        {
            case STATE_IDLE:
                event = receiveMessage();     // Wait for user input
                if (event == EVENT_NONE) 
                {
                    printf("Exiting...\n");   // Exit condition
                    return 0;
                }
                break;

            case STATE_PROCESSING:
                event = processMessage();     // Simulate processing
                break;

            case STATE_SENDING:
                event = sendReply();          // Simulate sending reply
                break;
        }

        stateMachine(event);  // Update the state based on the event
    }

    return 0;
}

