#ifndef SERVER_STATE_H
#define SERVER_STATE_H

typedef enum 
{
    STATE_IDLE,
    STATE_PROCESSING,
    STATE_SENDING
} State_t;

typedef enum 
{
    EVENT_RECEIVED,
    EVENT_PROCESSED,
    EVENT_SENT
} Event_t;

void server_state_machine(Event_t event);
State_t get_server_state();

#endif
