/*NAME: TARIQ KHALIL BHATKAR
UIN: 251P032
ROLL NO: 31*/ // Author information comment
#include<stdio.h> // Include standard input output library
#include<stdlib.h> // Include standard library for exit function
#define SIZE 10 // Define constant SIZE as 10 for stack size
void push(int value); // Function prototype for push
void pop(); // Function prototype for pop
void display(); // Function prototype for display
int stack[SIZE]; // Declare integer array for stack
int top=-1; // Declare and initialize top to -1

int main(){ // Main function
    int value, choice; // Declare variables for value and choice
    while(1){ // Infinite loop for menu
        printf("\n\n****** STACK MENU ******\n"); // Print menu header
        printf("1. push\n"); // Print push option
        printf("2. pop\n"); // Print pop option
        printf("3. display\n"); // Print display option
        printf("4. exit\n"); // Print exit option
        printf("enter your choice:"); // Prompt for choice
        scanf("%d",&choice); // Read choice

        switch (choice) // Switch on choice
        {
            case 1:
            printf("Enter the value to be inserted: "); // Prompt for value
            scanf("%d",&value); // Read value
            push(value); // Call push
            break; // Break
            case 2:
            pop(); // Call pop
            break; // Break
            case 3:
            display(); // Call display
            break; // Break
            case 4:
            exit(0); // Exit program
            default:
            printf("\n Wrong selection!!! try again!!"); // Print invalid
    
        }
    }
    return 0;
}
void push(int value) // Push function
{
    if (top == SIZE -1) // Check if stack is full
    {
        printf("\n stack is full ! insertion not possible!!"); // Print full message
    }
    else 
    {
        top++; // Increment top
        stack[top] = value; // Assign value to stack
        printf("\n insertion is done!"); // Print success
    }
}
void pop(){ // Pop function
    if(top ==-1){ // Check if stack is empty
    printf("\n stack is empty! deletion not possible"); // Print empty message
}
    else{
    printf("delete element:"); // Print delete message
    top--; // Decrement top
    }
}
void display(){ // Display function
    int i; // Declare i
    if(top==-1) // Check if empty
    {
        printf("\nstack is empty"); // Print empty
    }
    else{
        printf("\n stack elements are:"); // Print elements label
        for(i= top;i>=0;i--) // Loop from top to 0
        {
            printf("%d\n",stack[i]); // Print element
        }
    }
}
