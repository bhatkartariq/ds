#include<stdio.h> // Include stdio
#include<stdlib.h> // Include stdlib

//structue of node // Node structure comment
struct node
{
    int data; // Data field
    struct node *next; // Next pointer
}; // Close struct definition
struct node *head=NULL;//hea pointer is saved to first address // Head pointer
//insert at beginning // Insert begin function
void insert_begin(){
    struct node *newnode; // New node
    int item; // Item
    newnode=(struct node*) malloc(sizeof(struct node)); // Allocate memory
    if(newnode== NULL) // If allocation failed
    {
        printf("\nmemory overflow"); // Print overflow
        return; // Return
    }
    printf("\nenter value: "); // Prompt value
    scanf("%d",&item); // Read item
    newnode->data=item; // Assign data
    newnode->next=head; // Set next to head
    head=newnode; // Update head
    printf("\nnode inssreted at beginning!!\n"); // Success
}

void insert_end(){ // Insert end
    struct node *newnode , *temp; // New node and temp
    //temp = traversal pointer // Temp for traversal
    int item; // Item
    newnode=(struct node*)malloc(sizeof(struct node)); // Allocate
    if(newnode==NULL){ // If failed
        printf("\nmemory overflow\n"); // Overflow
        return ; // Return
    }
    printf("enter value : "); // Prompt
    scanf("%d",&item); // Read
    newnode->data=item; // Assign
    newnode->next=NULL; // Set next null
    if (head==NULL){ // If empty
        head=newnode; // Set head
    }
    else 
    {
        temp=head; // Temp to head
        while (temp->next !=NULL) // Traverse to end
        {
            temp=temp->next; // Move temp
        }
        temp->next=newnode; // Link newnode
        printf("\ninserted at ennd\n"); // Success
    }
}
void insert_position(){ // Insert at position
    struct node *newnode,*temp; // New and temp
    int item,pos,i; // Item, pos, i
    newnode=(struct node*)malloc(sizeof(struct node)); // Allocate
    if(newnode==NULL){ // If failed
        printf("\nmemory overflow\n"); // Overflow
        return ; // Return
    }
    printf("\nenter position"); // Prompt pos
    scanf("%d", &pos); // Read pos
    printf("\nenter valeue \n"); // Prompt value
    scanf("%d",&item); // Read item
    newnode->data=item; // Assign data
    temp=head; // Temp to head
    for (i=1;i<pos-1;i++){ // Loop to pos-1
        temp=temp->next; // Move temp
        if(temp==NULL) // If invalid
        {
            printf("\ninvalid position\n"); // Invalid
            return; // Return
        }
    }
    newnode->next= temp->next; // Link newnode
    temp->next=newnode; // Update temp next
    printf("\nnode inserted at position\n"); // Success
}

void delete_begin(){ // Delete begin
    struct node *temp; // Temp
    if(head==NULL){ // If empty
        printf("\nlist i empty\n"); // Empty
        return ; // Return
    }
    temp=head; // Temp to head
    head =head->next; // Update head
    free(temp); // Free temp
    printf("\nnode deleted from beginning\n"); // Success
}


void delete_end(){ // Delete end
    struct node *temp,*prev; // Temp and prev
    if(head==NULL){ // If empty
        printf("\nlist i empty\n"); // Empty
        return ; // Return
    }
    if (head->next==NULL){ // If single
        free(head); // Free head
        head=NULL; // Set null
        return; // Return
    }
    temp=head; // Temp to head
    while (temp->next !=NULL) // Traverse
    {
        prev=temp; // Update prev
        temp=temp->next; // Move temp
    }
    prev->next=NULL; // Unlink
    free(temp); // Free temp
    printf("node deleted at end"); // Success
}
void delete_pos(){ // Delete pos
    struct node *temp,*prev; // Temp prev
    int pos,i; // Pos i
    printf("\nenter position to delete\n"); // Prompt pos
    scanf("%d",&pos); // Read pos
    temp=head; // Temp to head
    if (pos==1){ // If first
        head = temp->next; // Update head
        free(temp); // Free
        printf("\nnode deleted\n"); // Success
        return; // Return
    }
}
void display(){ // Display
    struct node *temp; // Temp
    if(head ==NULL){ // If empty
        printf("list is empty"); // Empty
        return; // Return
    }
    else{
        temp=head; // Temp to head
        while (temp!=NULL) // Traverse
        {
            printf("%d->",temp->data); // Print data
            temp=temp->next; // Move temp
        }
        printf("NULL\n"); // NULL
    }
}
int main() // Main function
{
    
    int choice; // Declare choice variable

    while(1) // Infinite loop
    {
        printf("\n--- Singly Linked List Menu ---\n"); // Menu
        printf("1 Insert at Beginning\n"); // 1
        printf("2 Insert at End\n"); // 2
        printf("3 Insert at Position\n"); // 3
        printf("4 Delete from Beginning\n"); // 4
        printf("5 Delete from End\n"); // 5
        printf("6 Delete from Position\n"); // 6
        printf("7 Display\n"); // 7
        printf("8 Exit\n"); // 8
        printf("Enter choice: "); // Prompt
        scanf("%d",&choice); // Read choice

        switch(choice) // Switch statement
        {
            case 1: // Option 1
            insert_begin(); // Call insert at beginning
            break;
            case 2: // Option 2
            insert_end(); // Call insert at end
            break;
            case 3: // Option 3
            insert_position(); // Call insert at position
            break;
            case 4: // Option 4
            delete_begin(); // Call delete from beginning
            break;
            case 5: // Option 5
            delete_end(); // Call delete from end
            break;
            case 6: // Option 6
            delete_pos(); // Call delete from position
            break;
            case 7: // Option 7
            display(); // Call display
            break;
            case 8: // Option 8
            exit(0); // Exit program
            default: // Invalid option
            printf("Invalid choice\n"); // Print invalid message
        }
    }
    return 0; // Return 0
}
