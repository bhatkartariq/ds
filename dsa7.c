#include<stdio.h>
#include<stdlib.h>
/*coder : tariq bhatkar 
uin : 251P032
roll no :31
*/



//structue of node
struct node
{
    int data;
    struct node *next; 
       
};
struct node *head=NULL;//hea pointer is saved to first address

//insert at beginning
void insert_begin(){
    struct node *newnode;
    int item;

    newnode=(struct node*) malloc(sizeof(struct node));

    if(newnode== NULL)
    {
        printf("\nmemory overflow");
        return;
    }

    printf("\nenter value: ");
    scanf("%d",&item);
    

    newnode->data=item;
    newnode->next=head;
    head=newnode;
    
    printf("\nnode inssreted at beginning!!\n");

}

void insert_end(){
    struct node *newnode , *temp;
    //temp = traversal pointer
    int item;

    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("\nmemory overflow\n");
        return ;
    }
    printf("enter value : ");
    scanf("%d",&item);

    newnode->data=item;
    newnode->next=NULL;

    if (head==NULL){
        head=newnode;

    }
    else 
    {
        temp=head;
        while (temp->next !=NULL)
        {
            temp=temp->next; 
        }
        temp->next=newnode;
        printf("\ninserted at ennd\n");
        

    }

    
}
void insert_position(){
    struct node *newnode,*temp;
    int item,pos,i;


    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("\nmemory overflow\n");
        return ;
    }
    printf("\nenter position");
    scanf("%d", &pos);


    printf("\nenter valeue \n");
    scanf("%d",&item);

    newnode->data=item;

    temp=head;
    for (i=1;i<pos-1;i++){
        temp=temp->next;
        if(temp==NULL)
        {
            printf("\ninvalid position\n");
            return;
        }
    }
    newnode->next= temp->next;

    temp->next=newnode;

    printf("\nnode inserted at position\n");

    
}

void delete_begin(){
    struct node *temp;
    if(head==NULL){
        printf("\nlist i empty\n");
        return ;
    }
    temp=head;
    head =head->next;

    free(temp);

    printf("\nnode deleted from beginning\n");
}


void delete_end(){
    struct node *temp,*prev;


    if(head==NULL){
        printf("\nlist i empty\n");
        return ;
    }

    if (head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    while (temp->next !=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    
    printf("node deleted at end");    
}
void delete_pos(){
    struct node *temp,*prev;
    int pos,i;
    printf("\nenter position to delete\n");
    scanf("%d",&pos);
    
    temp=head;

    if (pos==1){
        head = temp->next;
        free(temp);
        printf("\nnode deleted\n");
        return;

    }

}
void display(){
    struct node *temp;
    if(head ==NULL){
        printf("list is empty");
        return;
    }
    else{
        temp=head;
        while (temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}int main()
{
    printf("coder: Tariq bhatkar");
    int choice;

    while(1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1 Insert at Beginning\n");
        printf("2 Insert at End\n");
        printf("3 Insert at Position\n");
        printf("4 Delete from Beginning\n");
        printf("5 Delete from End\n");
        printf("6 Delete from Position\n");
        printf("7 Display\n");
        printf("8 Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
            insert_begin();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            insert_position();
            break;
            case 4:
            delete_begin();
            break;
            case 5:
            delete_end();
            break;
            case 6:
            delete_pos();
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);

            default: 
            printf("Invalid choice\n");
        }
    }

    return 0;
}