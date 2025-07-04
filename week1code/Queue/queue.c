/*
 * Queue Implementation using Array in C
 * Author: Sanjeevi Ram N
 * Description: This program demonstrates a simple queue using a static array.
 * Features:
 * - Enqueue operation
 * - Dequeue operation
 * - Display queue contents
 * - Menu-driven user interaction
 */

#include <stdio.h>

// Define maximum queue size
#define SIZE 5

// Queue array and tracking indices
int queue[SIZE];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int data) 
{
    // Check if queue is full
    if (rear == SIZE - 1) 
    {
        printf("Queue is full!\n");
        return;
    }

    // First insertion: set front to 0
    if (front == -1) 
    {
        front = 0;
    }

    // Insert data at next rear position
    rear++;
    queue[rear] = data;
    printf("Enqueued: %d\n", data);
}

// Function to remove an element from the queue
void dequeue() 
{
    // Check if queue is empty
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty!\n");
        return;
    }

    // Remove element from front
    printf("Dequeued: %d\n", queue[front]);
    front++;

    // If queue becomes empty after dequeue, reset indices
    if (front > rear) 
    {
        front = rear = -1;
    }
}

// Function to display all elements of the queue
void display() 
{
    // Check if queue is empty
    if (front == -1) 
    {
        printf("Queue is empty!\n");
        return;
    }

    // Print elements from front to rear
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function: provides interactive menu to the user
int main() 
{
    int choice, data;

    // Infinite loop for menu until user exits
    while (1) 
    {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) 
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

