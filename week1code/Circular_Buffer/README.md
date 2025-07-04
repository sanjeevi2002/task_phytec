
Circular Buffer in C (Array-Based Implementation)
=============================================================================================================

This project implements a Circular Buffer (or Circular Queue) using a fixed-size array in the C programming language. The buffer supports basic operations such as enqueue, dequeue, and display, and is accessible through a simple terminal-based menu.

Author: Sanjeevi Ram N
______________________________________________________________________________________________________________
Files

circular-buffer-array-c/
├── circular_buffer.c   # Full C source code with comments
└── README.md           # Project documentation
_____________________________________________________________________________________________________________
Features

Implements a circular queue using array and modulo arithmetic

Supports:

Enqueue (insert element)

Dequeue (remove element)

Display (view all buffer elements)

Detects and handles overflow (buffer full) and underflow (buffer empty)

Uses modulo-based wrap-around indexing

Interactive terminal menu for easy testing

Beginner-friendly and lightweight
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
How to Compile

Use gcc or any standard C compiler:

gcc circular_buffer.c -o circular_buffer
_____________________________________________________________________________________________________________
How to Run

./circular_buffer
____________________________________________________________________________________________________________
Sample Menu:

Circular Buffer Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice:

Example Usage

Enter your choice: 1
Enter value to enqueue: 10
Enqueued: 10



