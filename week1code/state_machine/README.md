Finite State Machine (FSM) Message Handler in C
================================================================================================================

This project demonstrates a simple finite state machine (FSM) implemented in C for handling message input, processing, and sending replies.

Author: Sanjeevi Ram N
________________________________________________________________________________________________________________
Files Structure

fsm-message-handler/
├── fsm.c         # Main source code implementing the FSM
└── README.md     # Project documentation
________________________________________________________________________________________________________________
Features

State Machine with 3 clear states:

IDLE — waiting for input

PROCESSING — simulates processing the message

SENDING — simulates sending a reply

Transitions driven by defined events (RECEIVE, DONE, SENT)

Clean and modular C code

Uses enum for both states and events

Well-commented and beginner-friendly
----------------------------------------------------------------------------------------------------------------
How to Compile

Use GCC or any C compiler:

gcc state_machine.c -o state_machine
________________________________________________________________________________________________________________
How to Run

./state_machine
_______________________________________________________________________________________________________________

You’ll be prompted to enter messages. Type exit to quit.

Enter a message to receive (type 'exit' to quit): Hello World
Processing message: "Hello World"
Sending reply for: "Hello World"
Enter a message to receive (type 'exit' to quit): exit
Exiting...
_______________________________________________________________________________________________________________
Concepts Covered

Finite State Machine (FSM) implementation in C

Use of enum to manage states and events

Structured control flow using switch-case

Input handling using fgets()

Clean separation of logic per state
______________________________________________________________________________________________________________
State Machine Flow

           +-------------+         +-----------------+
           |             |         |                 |
           |   IDLE      +-------->+   PROCESSING    |
           |             |         |                 |
           +------+------+
                  ^                        |
                  |                        v
           +------+-------------+  +--------------+
           |                    |  |              |
           |     SENDING <------+  |   (DONE)     |
           |                    |  +--------------+
           +--------------------+



