#include <stdio.h>
#define SIZE 5

int buffer[SIZE];
int front = -1, rear = -1;

// Check if buffer is full
int isFull() 
{
    return ((rear + 1) % SIZE) == front;
}

// Check if buffer is empty
int isEmpty() 
{
    return front == -1;
}

// Enqueue (Add to buffer)
void enqueue(int data) 
{
    if (isFull()) 
    {
        printf("Buffer is full! Cannot enqueue %d\n", data);
        return;
    }

    if (isEmpty()) 
    {
        front = rear = 0;
    } else 
    {
        rear = (rear + 1) % SIZE;
    }

    buffer[rear] = data;
    printf("Enqueued: %d\n", data);
}

// Dequeue (Remove from buffer)
void dequeue() 
{
    if (isEmpty()) 
    {
        printf("Buffer is empty! Cannot dequeue\n");
        return;
    }

    printf("Dequeued: %d\n", buffer[front]);

    if (front == rear) 
    {
        // Buffer is now empty
        front = rear = -1;
    } else 
    {
        front = (front + 1) % SIZE;
    }
}

// Display buffer contents
void display() 
{
    if (isEmpty()) 
    {
        printf("Buffer is empty!\n");
        return;
    }

    printf("Buffer contents: ");
    int i = front;
    while (1) 
    {
        printf("%d ", buffer[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Menu to test the circular buffer
int main() 
{
    int choice, value;

    while (1) 
    {
        printf("\nCircular Buffer Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
