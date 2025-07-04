UDP Chat Application in C
===============================================================================================================
This is a minimal and modular **UDP-based Chat Application in C**, demonstrating client-server communication using **socket programming** and a **state machine**.

 Designed for learning, testing, and showcasing real-time message handling via UDP.
______________________________________________________________________________________________________________

## Project Structure

```
udp_chat_app/
├── Makefile                # Automated build instructions
├── inc/                    # Header files
│   ├── server_state.h      # Server state machine enums and prototypes
│   └── udp_common.h        # Common UDP functions and constants
├── src/                    # Source code files
│   ├── client.c            # UDP client logic
│   ├── server.c            # UDP server logic with state machine
│   ├── server_state.c      # Server state transitions
│   └── udp_common.c        # Shared networking functions
├── bin/                    # Compiled output (created by Makefile)
├── obj/                    # Compiled object files (created by Makefile)
└── README.md               # Project documentation
```

_______________________________________________________________________________________________________________

##  Features

* ✅ UDP client-server communication
* ✅ Non-blocking interactive message exchange
* ✅ State machine based server logic
* ✅ Modular C design with reusable headers
* ✅ Makefile for building and cleanup

----------------------------------------------------------------------------------------------------------------

## How to Build

```bash
make
```

This creates two binaries in `bin/`:

* `bin/client`
* `bin/server`

______________________________________________________________________________________________________________

##  How to Run

### Run the Server

```bash
./bin/server <port>
```

Example:

```bash
./bin/server 8080
```

### Run the Client

```bash
./bin/client <server_ip> <port>
```

Example:

```bash
./bin/client 127.0.0.1 8080
```

---
______________________________________________________________________________________________________________
## Example Interaction

### On Server:

```
[Server] Waiting for message on port 8080...
[Server] Received: Hello
[Server] Processing message...
[Server] Reply sent.
```

### On Client:

```
[Client] Enter message (or 'exit'): Hello
[Client] Server reply: Message received
```

---
_______________________________________________________________________________________________________________
## Concepts Demonstrated

* UDP socket programming
* Finite State Machine (FSM) in C
* Event-based design
* Layered architecture with header and source files
* Clean Makefile-based compilation

---


