#include<stdio.h> // Include stdio
#include<stdlib.h>//for malloc // Include stdlib
/*coder : tariq bhatkar 
uin : 251P032
roll no :31
*/ // Author
//define struct // Struct
struct node
{
    int data;//store values // Data
    struct node *next; //store address // Next
}; // Close struct definition
struct node *top=NULL; // Top pointer
void push() // Push
{
    struct node*newnode; // New node
    int value ; // Value
    newnode=(struct node*)malloc(sizeof(struct node)); // Allocate
    if (newnode==NULL) // If failed
    {
        printf("\nStack overflow"); // Overflow
        return; // Return
    }
    printf("\nenter value to push "); // Prompt
    scanf("%d",&value); // Read
    newnode->data=value; // Assign
    newnode->next=top; // Link
    top=newnode; // Update top
    printf("\nelement inserted !!"); // Success
}

void pop() // Pop
{
    struct node*temp; // Temp
    if (top==NULL) // If empty
    {
        printf("\nstack underflow "); // Underflow
        return; // Return
    }
    temp=top; // Temp to top
    top=top->next; // Update top
    printf("\npopped element:%d",temp->data); // Print popped
    free(temp); // Free temp
}
void display() // Display
{
    struct node* temp = top; // Temp to top
    if (temp == NULL) // If empty
    {
        printf("\nstack underflow "); // Underflow
        return; // Return
    }
    while (temp != NULL) // Traverse
    {
        printf("%d->", temp->data); // Print
        temp = temp->next; // Move
    }
    printf("NULL"); // NULL
}
int main() // Main
{
    printf("coder: Tariq bhatkar"); // Coder
    int choice; // Choice
    while(1) // Loop
    {
        printf("\n--- Stack using Linked List Menu ---\n"); // Menu
        printf("1 push\n"); // 1
        printf("2 pop\n"); // 2
        printf("3 Display\n"); // 3
        printf("4 Exit\n"); // 4
        printf("Enter choice: "); // Prompt
        scanf("%d",&choice); // Read
        switch(choice) // Switch
        {
            case 1: 
            push(); // Call
            break;
            case 2:
            pop(); // Call
            break;
            case 3:
            display(); // Call
            break;
            case 4:
            exit(0); // Exit
            default: 
            printf("Invalid choice\n"); // Invalid
        }
    }
    return 0; // Return
}
