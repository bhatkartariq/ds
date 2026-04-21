#include<stdio.h>
#include<stdlib.h>//for malloc

/*coder : tariq bhatkar 
uin : 251P032
roll no :31
*/

//define struct 
struct node
{
    int data;//store values 
    struct node *next; //store address
       
};
struct node *top=NULL;
void push()
{
    struct node*newnode;
    int value ;

    newnode=(struct node*)malloc(sizeof(struct node));
    
    if (newnode==NULL)
    {
        printf("\nStack overflow");
        return;
    }

    printf("\nenter value to push ");
    scanf("%d",&value);

    newnode->data=value;
    newnode->next=top;
    top=newnode;

    printf("\nelement inserted !!");

}

void pop()
{
    struct node*temp;
    if (top==NULL)
    {
        printf("\nstack underflow ");
        return;

    }
    temp=top;  
    top=top->next;
    printf("\npopped element:%d",temp->data);
    
    
    
    free(temp);

}
void display()
{
    struct node* temp = top;

    if (temp == NULL)
    {
        printf("\nstack underflow ");
        return;
    }

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    printf("coder: Tariq bhatkar");
    int choice;

    while(1)
    {
        printf("\n--- Stack using Linked List Menu ---\n");
        printf("1 push\n");
        printf("2 pop\n");
        printf("3 Display\n");
        printf("4 Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default: 
            printf("Invalid choice\n");
        }
    }

    return 0;
}