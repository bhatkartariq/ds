#include <stdio.h> // Include stdio
#include <stdlib.h> // Include stdlib

struct node // Node struct
{
    int data;//stores values // Data
    struct node *next;//stores address // Next
};
struct node *last = NULL;//making last to null // Last pointer

// Insert at Beginning // Insert begin
void insert_begin(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); // Allocate
    if(newnode == NULL) // If failed
    {
        printf("Overflow\n"); // Overflow
        return; // Return
    }
    newnode->data = value; // Assign data
    if(last == NULL) // If empty
    {
        last = newnode; // Set last
        last->next = last; // Circular
    }
    else
    {
        newnode->next = last->next; // Link
        last->next = newnode; // Update last next
    }
}

// Insert at End // Insert end
void insert_end(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); // Allocate
    if(newnode == NULL) // If failed
    {
        printf("Overflow\n"); // Overflow
        return; // Return
    }
    newnode->data = value; // Assign
    if(last == NULL) // If empty
    {
        last = newnode; // Set last
        last->next = last; // Circular
    }
    else
    {
        newnode->next = last->next; // Link
        last->next = newnode; // Update
        last = newnode; // Update last
    }
}

// Delete from Beginning // Delete begin
void delete_begin()
{
    if(last == NULL) // If empty
    {
        printf("List is empty\n"); // Empty
        return; // Return
    }
    struct node *temp = last->next; // Temp to first
    if(last->next == last) // If single
    {
        last = NULL; // Set null
    }
    else
    {
        last->next = temp->next; // Update last next
    }
    printf("Deleted: %d\n", temp->data); // Print deleted
    free(temp); // Free
}

// Delete from End // Delete end
void delete_end()
{
    if(last == NULL) // If empty
    {
        printf("List is empty\n"); // Empty
        return; // Return
    }
    struct node *temp = last->next; // Temp to first
    if(temp == last) // If single
    {
        printf("Deleted: %d\n", last->data); // Print
        free(last);//deleting the last node // Free
        last = NULL; // Set null
        return; // Return
    }
    while(temp->next != last) // Traverse to prev of last
    {
        temp = temp->next; // Move
    }
    printf("Deleted: %d\n", last->data); // Print
    temp->next = last->next; // Update
    free(last); // Free last
    last = temp; // Update last
}

// Display // Display
void display()
{
    if(last == NULL) // If empty
    {
        printf("List is empty\n"); // Empty
        return; // Return
    }
    struct node *temp = last->next; // Temp to first
    printf("Circular List: "); // Label
    do
    {
        printf("%d -> ", temp->data); // Print
        temp = temp->next; // Move
    } while(temp != last->next); // Until back
    printf("%d(head)\n",last->next->data);//for getting the output with last input // Head
}

// Main Function // Main
int main()
{
    int choice, value; // Choice value
    while(1) // Loop
    {
        printf("\n--- Circular Linked List (ADT) ---\n"); // Menu
        printf("1. Insert Beginning\n"); // 1
        printf("2. Insert End\n"); // 2
        printf("3. Delete Beginning\n"); // 3
        printf("4. Delete End\n"); // 4
        printf("5. Display\n"); // 5
        printf("6. Exit\n"); // 6
        printf("Enter choice: "); // Prompt
        scanf("%d", &choice); // Read
        switch(choice) // Switch
        {
            case 1:
                printf("Enter value: "); // Prompt
                scanf("%d", &value); // Read
                insert_begin(value); // Call
                break;
            case 2:
                printf("Enter value: "); // Prompt
                scanf("%d", &value); // Read
                insert_end(value); // Call
                break;
            case 3:
                delete_begin(); // Call
                break;
            case 4:
                delete_end(); // Call
                break;
            case 5:
                display(); // Call
                break;
            case 6:
                exit(0); // Exit
            default:
                printf("Invalid choice\n"); // Invalid
        }
    }
}
