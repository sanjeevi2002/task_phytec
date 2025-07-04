Week1Code – OSI Model, Data Structures & UDP Chat App (C)

This project covers core C concepts for system-level programming. You’ll find simple, modular code implementing:

- OSI Model Summar
- Basic Data Structures: Queue (Array, Linked List), Circular Buffer
  Event-Driven State Machine
- UDP-Based Chat App (Client & Server)

________________________________________________________________________________________________________________

 Folder Structure
           week1code/
           ├── inc/ # Header files
           │ ├── udp_common.h
           │ └── server_state.h
           ├── src/ # Source files
           │ ├── client.c # UDP client
           │ ├── server.c # UDP server + state machine
           │ ├── udp_common.c # UDP helper functions
           │ └── server_state.c # FSM logic
           ├── queue_array.c # Basic queue using array
           ├── queue_linkedlist.c # Queue using linked list
           ├── circular_buffer.c # Circular buffer (fixed size)
           ├── state_machine.c # Simple FSM example
           ├── Makefile # Build system
