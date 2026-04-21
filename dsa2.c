/*NAME: TARIQ KHALIL BHATKAR
UIN: 251P032
ROLL NO: 31*/ 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void push(int value);
void pop();
void display();

int stack[SIZE];
int top=-1;

int main(){
    int value, choice;

    while(1){
        printf("\n\n****** STACK MENU ******\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. display\n");
        printf("4. exit\n");

        printf("enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            push(value);
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
            printf("\n Wrong selection!!! try again!!");
    
        }
    }
    return 0;
}
void push(int value)
{
    if (top == SIZE -1)
    {
        printf("\n stack is full ! insertion not possible!!");
    }
    else 
    {
        top++;
        stack[top] = value;
        printf("\n insertion is done!");
    }
}
void pop(){
    if(top ==-1){
    printf("\n stack is empty! deletion not possible");
}
    else{
    printf("delete element:");
    top--;
    }
}
void display(){
    int i;
    if(top==-1)
    {
        printf("\nstack is empty");

    }
    else{
        printf("\n stack elements are:");
        for(i= top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
