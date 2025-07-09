Week1Code – OSI Model, Data Structures & UDP Chat App (C)

This project covers core C concepts for system-level programming. You’ll find simple, modular code implementing:

- OSI Model Summar
- Basic Data Structures: Queue (Array, Linked List), Circular Buffer
  Event-Driven State Machine
- UDP-Based Chat App (Client & Server)

________________________________________________________________________________________________________________
## Folder Structure

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

Week2Code – Nordic nRF52840 DK Setup, UART & BLE Porting (Contiki-NG)

This project focuses on embedded development using the **Nordic nRF52840 Development Kit**. It includes LED control, UART communication, and ongoing BLE porting to Contiki-NG. This work is part of the Week 2 internship task.

You’ll find:

- Basic LED control examples using Nordic SDK
- UART peripheral demo (minicom log included)
- BLE Porting Documentation for Contiki-NG on nRF52840
- Hardware features and installation notes

---

## Folder Structure
       week_2/Nordic_nrf52840-dk/
       ├── Documents/ # Reference docs, datasheets, guides
       ├── Installation/ # Toolchain, nRF SDK, and setup instructions
       ├── Led_code/ # LED blink code using Nordic SDK
       ├── nRF52840 DK Peripheral UART demo/ # UART send/receive example
       ├── Port_feature.png # Board pinout and peripheral diagram
       ├── nrf_servo_minicom.txt # UART output from minicom
       ├── porting_ble_Document 1 # BLE Porting steps for Contiki-NG
       ├── README.md # Project overview (this file)
