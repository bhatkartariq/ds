#include <stdio.h> // Include standard input output library
#define SIZE 10 // Define SIZE as 10
int queue[SIZE]; // Declare queue array
int front = -1; // Initialize front to -1
int rear = -1; // Initialize rear to -1
void enqueue(); // Prototype enqueue
void dequeue(); // Prototype dequeue
void display(); // Prototype display
int isFull(); // Prototype isFull
int isEmpty(); // Prototype isEmpty

int main() // Main function
{
    int choice; // Declare choice
    while(1) // Infinite loop
    {
        printf("\n------ MENU ------\n"); // Print menu
        printf("1. Enqueue\n"); // Option 1
        printf("2. Dequeue\n"); // Option 2
        printf("3. Display\n"); // Option 3
        printf("4. Exit\n"); // Option 4
        printf("Enter your choice: "); // Prompt choice
        scanf("%d", &choice); // Read choice

        switch(choice) // Switch
        {
            case 1:
                enqueue(); // Call enqueue
                break;
            case 2:
                dequeue(); // Call dequeue
                break;
            case 3:
                display(); // Call display
                break;
            case 4:
                printf("Program ended.\n"); // Print end
                return 0; // Return 0
            default:
                printf("Invalid choice! Please try again.\n"); // Invalid
        }
    }
    return 0;
}

void enqueue() // Enqueue function
{
    int element; // Declare element
    if(isFull()) // If full
    {
        printf("Queue is full! Cannot enqueue.\n"); // Print full
    }
    else
    {
        printf("Enter element to enqueue: "); // Prompt element
        scanf("%d", &element); // Read element
        if(front == -1) // If first element
        {
            front = 0; // Set front to 0
        }
        rear++; // Increment rear
        queue[rear] = element; // Assign element
        printf("Element %d enqueued successfully.\n", element); // Success
    }
}

void dequeue() // Dequeue function
{
    if(isEmpty()) // If empty
    {
        printf("Queue is empty! Cannot dequeue.\n"); // Print empty
    }
    else
    {
        int element = queue[front]; // Get front element
        if(front == rear) // If only one element
        {
            front = -1; // Reset front
            rear = -1; // Reset rear
        }
        else
        {
            front++; // Increment front
        }
        printf("Element %d dequeued successfully.\n", element); // Success
    }
}

void display() // Display function
{
    if(isEmpty()) // If empty
    {
        printf("Queue is empty.\n"); // Print empty
    }
    else
    {
        printf("Queue elements: "); // Print label
        for(int i = front; i <= rear; i++) // Loop from front to rear
        {
            printf("%d ", queue[i]); // Print element
        }
        printf("\n"); // Newline
    }
}
int isFull() // isFull function
{
    return rear == SIZE - 1; // Return if rear at max
}
int isEmpty() // isEmpty function
{
    return front == -1; // Return if front -1
}
