 Write a program that checks whether a string of characters is palindrome or not. The function should use a stack library (cststack.h) of stack of characters using a static implementation of the stack..

Solution:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cststack.h"
void main()
{
    int i, flag=1;
    char str[MAX], b;
    stack s;
    init(&s);
    printf("Enter the String\n");
    scanf("%s", str);
    for (i = 0;i<strlen(str);i++)
    {
        Push(&s,str[i]);
    }
    printf("\nGiven Stack is\n");
    Display(&s);
    for (i = 0;i < (strlen(str) / 2);i++)
    {    
        b=Pop(&s);
        if (str[i] != b)
        {
           flag=0;
           break;
        }
    }
    if (flag==1)
        printf("\n%s is palindrome\n",  str);
    else
        printf("\n%s is not a palindrome\n", str);
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
void Push(stack *,char);
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
void Push(stack *s,char x)
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
void Display(stack *s)
{
    int i;
    printf("\n");
    if(!isEmpty(s))
    for(i=s->top;i>=0;i--)
        printf("%c  ",s->data[i]);
    else
        printf("Stack is Empty");
}
