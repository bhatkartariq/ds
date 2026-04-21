/*Name : Bhatkar Tariq 
Roll No : 31
UIN: 251P032*/ // Author information
#include <stdio.h> // Include stdio
#include <stdlib.h> // Include stdlib
#define size 10 // Define size
void enQueue(); // Prototype enQueue
void deQueue(); // Prototype deQueue
void display(); // Prototype display
int cQueue[size] , front = -1, rear = -1; // Declare circular queue and pointers
void main() // Main function // Main function
{
    int value , choice;; // Declare value and choice
    printf("\n\nCoded by:Bhatkar Tariq\n"); // Print coder
    while(1) // Infinite loop
    {
        printf("\n----MENU----\n\n"); // Print menu
        printf("1.Enter new element\n"); // Option 1
        printf("2.Delete element\n"); // Option 2
        printf("3.Display\n"); // Option 3
        printf("4.Exit\n"); // Option 4
        printf("Enter your choice: "); // Prompt choice
        scanf("%d", &choice); // Read choice

        switch(choice) // Switch
        {
            case 1:
            printf("Enter the value to be inserted:"); // Prompt value
            scanf("%d",&value); // Read value
            enQueue(value); // Call enQueue
            break;
            case 2:
            deQueue(); // Call deQueue
            break;
            case 3:
            display(); // Call display
            break;
            case 4:
            printf("The program has been ended. Thank You for using!!\n"); // Print end
            exit(0); // Exit
            default:
            printf("Invalid option selected!!\nPlease Choose again\n"); // Invalid
        }
    }
}

void enQueue(int n) // enQueue function
{
    if ((rear == size -1&&front==0)||(front == rear + 1))//condition for checking // Check full
    {
        printf("The Queue is already full!!\n"); // Print full
    }
    else
    {
        if (rear == size -1 && front != 0) // If rear at end and front not 0
        {
            rear = -1; // Reset rear
        }
        rear++; // Increment rear
        cQueue[rear] = n; // Assign value
        if(front == -1) // If first
        {
            front = 0; // Set front
        }
        printf("Insertion was successful!!\n"); // Success
    }
}

void deQueue() // deQueue function
{
    if (front == -1) // If empty
    {
        printf("The Queue is already empty!!\n"); // Print empty
    }
    else
    {
        printf("The deleted value is: %d\n", cQueue[front]); // Print deleted
        if (front == rear) // If only one
        {
            front = rear = -1; // Reset
        }
        else
        {
            front = (front + 1) % size; // Circular increment
        }
    }
}

void display() // Display function
{
    if ((front == -1)) // If empty
    {
        printf("The Queue is empty!!\n"); // Print empty
    }
    else
    {
        if(front >rear) // If wrapped
        {
            for (int i = front; i<=size -1; i++) // Loop from front to end
            {
                printf("%d ", cQueue[i]); // Print
            }
            for (int i = 0; i<=rear; i++) // Loop from 0 to rear
            {
                printf("%d ", cQueue[i]); // Print
            }
        }
        else // Not wrapped
        {
            for (int i = front; i<=rear; i++) // Loop front to rear
            {
                printf("%d ", cQueue[i]); // Print
            }
        }
    }
    return 0; // Return 0 (though void)
}
