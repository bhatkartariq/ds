#include <stdio.h> // Include stdio
#include <stdlib.h> // Include stdlib
struct node { // Node struct
    int data; // Data
    struct node *next; // Next
};
struct node *front = NULL; // Front
struct node *rear = NULL; // Rear

void enqueue() { // Enqueue
    int value; // Value
    struct node *newnode; // New node
    newnode = (struct node*)malloc(sizeof(struct node)); // Allocate
    printf("\nEnter value: "); // Prompt
    scanf("%d", &value); // Read
    if (newnode == NULL) { // If failed
        printf("\nOverflow"); // Overflow
        return; // Return
    }
    newnode->data = value; // Assign
    newnode->next = NULL; // Set next null
    if (front == NULL && rear == NULL) { // If empty
        front = rear = newnode; // Set both
    } else {
        rear->next = newnode; // Link
        rear = newnode; // Update rear
    }
    printf("%d Inserted Successfully", value); // Success
}

void dequeue() { // Dequeue
    struct node *temp; // Temp
    if (front == NULL) { // If empty
        printf("\nUnderflow"); // Underflow
        return; // Return
    }
    temp = front; // Temp to front
    printf("%d Deleted Successfully", front->data); // Print deleted
    front = front->next; // Update front
    free(temp); // Free temp
    if (front == NULL) { // If empty now
        rear = NULL; // Set rear null
    }
}

void display() {
    struct node *temp;

    if (front == NULL) {
        printf("\nQueue is Empty");
        return;
    }

    temp = front;

    printf("\nQueue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() { // Main
    int choice, value; // Choice value
    while (1) { // Loop
        printf("\n\n--- Queue Menu ---"); // Menu
        printf("\n1. Enqueue"); // 1
        printf("\n2. Dequeue"); // 2
        printf("\n3. Display"); // 3
        printf("\n4. Exit"); // 4
        printf("\nEnter choice: "); // Prompt
        scanf("%d", &choice); // Read
        switch (choice) { // Switch
            case 1:
                enqueue(); // Call
                break;
            case 2:
                dequeue(); // Call
                break;
            case 3:
                display(); // Call
                break;
            case 4:
                printf("Exit Successful"); // Exit
                exit(0); // Exit
            default:
                printf("\nInvalid choice"); // Invalid
        }
    }
    return 0; // Return
}
