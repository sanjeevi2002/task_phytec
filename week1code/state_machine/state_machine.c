#include <stdio.h>
#include <string.h>

typedef enum 
{
    STATE_IDLE,
    STATE_PROCESSING,
    STATE_SENDING
} State_t;

typedef enum 
{
    EVENT_NONE,
    EVENT_RECEIVE,
    EVENT_DONE,
    EVENT_SENT
} Event_t;


State_t currentState = STATE_IDLE;
char message[100] = {0};

// receiving a message
Event_t receiveMessage() 
{
    printf("Enter a message to receive (type 'exit' to quit): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline

    if (strcmp(message, "exit") == 0)
        return EVENT_NONE;
    return EVENT_RECEIVE;
}

//  processing
Event_t processMessage()
{
    printf("Processing message: \"%s\"\n", message);
    return EVENT_DONE;
}

// sending a reply
Event_t sendReply()
 {
    printf("Sending reply for: \"%s\"\n", message);
    return EVENT_SENT;
}

// State machine logic
void stateMachine(Event_t event) 
{
    switch (currentState) {
        case STATE_IDLE:
            if (event == EVENT_RECEIVE) 
            {
                currentState = STATE_PROCESSING;
            }
            break;

        case STATE_PROCESSING:
            if (event == EVENT_DONE)
            {
                currentState = STATE_SENDING;
            }
            break;

        case STATE_SENDING:
            if (event == EVENT_SENT) 
            {
                currentState = STATE_IDLE;
            }
            break;

        default:
            currentState = STATE_IDLE;
            break;
    }
}


int main() 
{
    Event_t event = EVENT_NONE;

    while (1) 
    {
        switch (currentState) 
        {
            case STATE_IDLE:
                event = receiveMessage();
                if (event == EVENT_NONE) 
                {
                    printf("Exiting...\n");
                    return 0;
                }
                break;

            case STATE_PROCESSING:
                event = processMessage();
                break;

            case STATE_SENDING:
                event = sendReply();
                break;
        }

        stateMachine(event);
    }

    return 0;
}
