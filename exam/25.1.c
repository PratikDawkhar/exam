Write a program to convert an infix expression of the form (a*(b+c)*((d-a)/b)) into its equivalent postfix notation. Consider usual precedence’s of operators. Use stack library of stack of characters using static implementation.

Solution:
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"cststack.h"
stack s;

int is_operator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
    {
        return 1;
    }
    else
    {
    return 0;
    }
}
int precedence(char symbol)
{
    if(symbol == '^')
    {
        return(3);
    }
    else if(symbol == '*' || symbol == '/')
    {
        return(2);
    }
    else if(symbol == '+' || symbol == '-')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;
    i=0;
    j=0;
    item=infix_exp[i];
    while(item != '\0')
    {
        if(item == '(')
        {
            Push(&s,item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            x=Pop(&s);
            while(is_operator(x) == 1 && precedence(x)>= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = Pop(&s);
            }
            Push(&s,x);
            Push(&s,item);
        }
        else if(item == ')')
        {
            x = Pop(&s);
            while(x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = Pop(&s);
            }
        }
        i++;
        item = infix_exp[i];
    }
    postfix_exp[j] = '\0';
}

int main()
{
    char infix[30], postfix[30];
    init(&s);
    printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
    printf("\nEnter Infix expression : ");
    gets(infix);
    InfixToPostfix(infix,postfix);
    printf("Postfix Expression: ");
    puts(postfix);
    return 0;
}

Library Function ( .h file )
NOTE: save file name as 'cststack.h'.

#include<stdio.h>
#define MAX 30
typedef struct stack
{
    char data[MAX];
    int top;
}stack;
void init(stack *);
int isEmpty(stack *);
int isFull(stack *);
char Pop(stack *);
void Push(stack *,int);
void init(stack *s)
{
    s->top=-1;
}
int isEmpty(stack *s)
{
    if(s->top==-1)
        return(1);
    return(0);
}
int isFull(stack *s)
{
    if(s->top==MAX-1)
        return(1);
    return(0);
}
void Push(stack *s,int x)
{
    if(!isFull(s))
    {
        s->top=s->top+1;
        s->data[s->top]=x;
    }
    else
        printf("\nStack OverFlow!");
}
char Pop(stack *s)
{
    char x;
    if(!isEmpty(s))
    {
        x=s->data[s->top];
        s->top=s->top-1;
    }
    else
        printf("\nStack Underflow");
    return(x);
}
