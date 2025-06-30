#include "server_state.h"

static State_t current_state = STATE_IDLE;

void server_state_machine(Event_t event) 
{
    switch (current_state) 
    {
        case STATE_IDLE:
            if (event == EVENT_RECEIVED)
                current_state = STATE_PROCESSING;
            break;
        case STATE_PROCESSING:
            if (event == EVENT_PROCESSED)
                current_state = STATE_SENDING;
            break;
        case STATE_SENDING:
            if (event == EVENT_SENT)
                current_state = STATE_IDLE;
            break;
    }
}

State_t get_server_state() 
{
    return current_state;
}
