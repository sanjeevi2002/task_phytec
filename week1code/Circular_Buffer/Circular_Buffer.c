/*
 * Circular Buffer Implementation in C
 * Author: Sanjeevi Ram N
 * Description:
 *   - Uses a fixed-size array to implement a circular queue
 *   - Supports enqueue, dequeue, and display operations
 *   - Handles wrap-around with modulo arithmetic
 */

#include <stdio.h>      // Standard I/O library for printf and scanf

#define SIZE 5          // Define the size of the circular buffer

// Global variables
int buffer[SIZE];       // Array to represent the circular buffer
int front = -1;         // Index of the front element in the buffer
int rear = -1;          // Index of the rear element in the buffer

// Check if buffer is full (next rear overlaps front)
int isFull() 
{
    // If next rear equals front, buffer is full
    return ((rear + 1) % SIZE) == front;
}

// Check if buffer is empty (no elements inserted)
int isEmpty() 
{
    return front == -1;
}

// Enqueue operation: Insert an element into the buffer
void enqueue(int data) 
{
    if (isFull()) 
    {
        // No space left in the buffer
        printf("Buffer is full! Cannot enqueue %d\n", data);
        return;
    }

    if (isEmpty()) 
    {
        // First element being inserted
        front = rear = 0;
    } 
    else 
    {
        // Move rear circularly using modulo
        rear = (rear + 1) % SIZE;
    }

    buffer[rear] = data;    // Store the new value
    printf("Enqueued: %d\n", data);
}

// Dequeue operation: Remove the front element from the buffer
void dequeue() 
{
    if (isEmpty()) 
    {
        // No elements to dequeue
        printf("Buffer is empty! Cannot dequeue\n");
        return;
    }

    // Display the value being removed
    printf("Dequeued: %d\n", buffer[front]);

    if (front == rear) 
    {
        // Last element removed — reset the buffer
        front = rear = -1;
    } 
    else 
    {
        // Move front circularly
        front = (front + 1) % SIZE;
    }
}

// Display operation: Print the elements in the buffer
void display() 
{
    if (isEmpty()) 
    {
        // Nothing to show
        printf("Buffer is empty!\n");
        return;
    }

    printf("Buffer contents: ");
    int i = front;
    
    // Print elements from front to rear in circular order
    while (1) 
    {
        printf("%d ", buffer[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function: Menu-driven interface to test buffer operations
int main() 
{
    int choice, value;

    while (1) 
    {
        // Display menu options
        printf("\n Circular Buffer Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);     // Get user choice

        switch (choice) 
        {
            case 1:
                // Add data to buffer
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                // Remove data from buffer
                dequeue();
                break;

            case 3:
                // Show current buffer state
                display();
                break;

            case 4:
                // Exit the program
                printf("Exiting.\n");
                return 0;

            default:
                // Handle invalid input
                printf("Invalid choice!\n");
        }
    }
}

