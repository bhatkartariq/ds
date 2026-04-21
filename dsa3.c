/*NAME: TARIQ KHALIL BHATKAR
UIN: 251P032
ROLL NO: 31*/ 
#include<stdio.h>
#include<string.h>
#include<ctype.h>//for isalnum()

char stack[100];
int top=-1;

void push(char x){
     stack[++top]=x;
}


char pop(){
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char x){
    if (x =='(')
        return 0;
    if (x =='+'||x =='-')
        return 1;
    if (x== '*'||x=='/')
        return 2;
    if (x=='^')
        return 3;
    return 0;
}

int main(){
    char exp[100];
    char *e, x;

    printf("Enter the infix expression: ");
    scanf("%s",exp);

    e = exp;

    printf("Postfix expression: ");
    while (*e !='\0')
    {
        if (isalnum(*e))//if character is an operand (letter or digits)
        {
            printf("%c",*e);
        }
        else if(*e =='('){
            push(*e);
        }
        else if(*e ==')'){
            while ((x =pop()) != '(')//pop and print until '(' is found
            {
                printf("%c",x);
            }
           
        }
        else{
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top!=-1){
        printf("%c", pop());
    }
    return 0;
}
