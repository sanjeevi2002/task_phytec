/*
 * Queue Using Linked List in C
 * Author: Sanjeevi Ram N
 * Description:
 *   This program implements a queue using a dynamic linked list structure.
 *   It supports the following operations:
 *   - Enqueue: Add an element to the rear
 *   - Dequeue: Remove an element from the front
 *   - Display: Show all queue elements
 *   - Menu-driven user interaction
 */

#include <stdio.h>   // For input/output functions
#include <stdlib.h>  // For malloc() and free()

// Define the structure for a node in the linked list
struct Node 
{
    int data;               // Data field
    struct Node* next;      // Pointer to the next node
};

// Define front and rear pointers to keep track of the queue ends
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue: Add a new element to the rear of the queue
void enqueue(int value) 
{
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check for memory allocation failure
    if (!newNode) 
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // Initialize the new node
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, make both front and rear point to the new node
    if (rear == NULL) 
    {
        front = rear = newNode;
    } 
    else 
    {
        // Link the new node at the end of the queue and update rear
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}

// Dequeue: Remove an element from the front of the queue
void dequeue() 
{
    // Check if the queue is empty
    if (front == NULL) 
    {
        printf("Queue is empty!\n");
        return;
    }

    // Store the current front node in a temp variable
    struct Node* temp = front;

    // Print the value being dequeued
    printf("Dequeued: %d\n", front->data);

    // Move the front pointer to the next node
    front = front->next;

    // If the queue becomes empty, reset the rear pointer
    if (front == NULL)
        rear = NULL;

    // Free the memory of the dequeued node
    free(temp);
}

// Display: Print all elements from front to rear
void display() 
{
    // Check if the queue is empty
    if (front == NULL) 
    {
        printf("Queue is empty!\n");
        return;
    }

    // Traverse the queue and print each node's data
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function: runs an interactive menu
int main() 
{
    int choice, value;

    // Infinite loop for menu interaction
    while (1) 
    {
        // Display available options to the user
        printf("\nQueue Menu (Linked List):\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform corresponding operation based on user input
        switch (choice) 
        {
            case 1:
                // Input value and enqueue
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                // Dequeue from front
                dequeue();
                break;

            case 3:
                // Display queue
                display();
                break;

            case 4:
                // Exit the program
                printf("Exiting program.\n");
                return 0;

            default:
                // Handle invalid menu choice
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
