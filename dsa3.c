/*NAME: TARIQ KHALIL BHATKAR
UIN: 251P032
ROLL NO: 31*/ // Author information comment
#include<stdio.h> // Include standard input output library
#include<string.h> // Include string library for strlen (though not used)
#include<ctype.h>//for isalnum() // Include ctype for isalnum function
char stack[100]; // Declare character array for stack
int top=-1; // Declare and initialize top to -1

void push(char x){ // Push function for char
     stack[++top]=x; // Increment top and assign x to stack
}
char pop(){ // Pop function for char
    if (top == -1) // Check if stack is empty
        return -1; // Return -1 if empty
    else
        return stack[top--]; // Return top element and decrement top
}
int priority(char x){ // Priority function for operators
    if (x =='(') // If left parenthesis
        return 0; // Return 0
    if (x =='+'||x =='-') // If + or -
        return 1; // Return 1
    if (x== '*'||x=='/') // If * or /
        return 2; // Return 2
    if (x=='^') // If ^
        return 3; // Return 3
    return 0; // Default return 0
}

int main(){ // Main function
    char exp[100]; // Declare array for expression
    char *e, x; // Declare pointer e and char x
    printf("Enter the infix expression: "); // Prompt for infix expression
    scanf("%s",exp); // Read expression
    e = exp; // Set e to point to exp
    printf("Postfix expression: "); // Print postfix label
    while (*e !='\0') // Loop until end of string
    {
        if (isalnum(*e))//if character is an operand (letter or digits) // Check if operand
        {
            printf("%c",*e); // Print operand
        }
        else if(*e =='('){ // If left parenthesis
            push(*e); // Push to stack
        }
        else if(*e ==')'){ // If right parenthesis
            while ((x =pop()) != '(')//pop and print until '(' is found // Pop until left parenthesis
            {
                printf("%c",x); // Print popped
            }
        }
        else{ // Else operator
            while (priority(stack[top]) >= priority(*e)) // While stack top has higher or equal priority
            {
                printf("%c", pop()); // Pop and print
            }
            push(*e); // Push current operator
        }
        e++; // Increment e
    }
    while (top!=-1){ // While stack not empty
        printf("%c", pop()); // Pop and print
    }
    return 0; // Return 0
}
