/*Name: Zain mohamed saeed kazi
roll no :  40
uin: 251P037*/ // Author information comment
#include<stdio.h> // Include standard input output library
#include<math.h> // Include math library for pow function
#include<ctype.h> // Include ctype library for isdigit
int stack[50]; // Declare integer stack array
int top=-1; // Declare and initialize top to -1

void push(int x) // Push function
{
     top++; // Increment top
     stack[top]=x; // Assign x to stack
}
int pop(){ // Pop function
    int y; // Declare y
    y=stack[top]; // Assign top to y
    top--; // Decrement top
    return y; // Return y
}


int main(){ // Main function
    char exp[50]; // Declare expression array
    int i = 0, op1,op2,result; // Declare variables
    printf("Enter the postfix expression:"); // Prompt for postfix
    scanf("%s",exp); // Read expression
    while (exp[i]!='\0') // Loop through expression
    {
        if(isdigit(exp[i])) // If digit
        {
            push(exp[i]-'0'); // Push digit value
        }
        else // Else operator
        {
            op1=pop(); // Pop op1
            op2=pop(); // Pop op2
            switch (exp[i]) // Switch on operator
            {
            case '+': // Addition
                push(op2+op1); // Push sum
                break;
            case'-': // Subtraction
                push(op2-op1); // Push difference
                break;
            case'*': // Multiplication
                push(op2*op1); // Push product
                break;
            case'/': // Division
                push(op2/op1); // Push quotient
                break;
            case'^': // Power
                push(pow(op2,op1)); // Push power
                break;
            }
        }
        i++; // Increment i
    }
    result= pop(); // Pop result
    printf("\nThe answer of postfix exppression %s= %d\n",exp,result); // Print result
    printf("\ncoder: Zain mohamed saeed kazi"); // Print coder
    return 0; // Return 0
}
