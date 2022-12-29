 Write a program that reverses a string of characters. The function should use a stack library (cststack.h) of stack of characters using a static implementation of the stack.

Solution:
#include <stdio.h>
#include <string.h>
#include"cststack.h"
int main()
{
    char str[30];
    stack s;
    int i;
    printf("Input a string ");
    scanf("%[^\n]s",str); /*read string with spaces*/
    /*gets(str);-can be used to read string with spaces*/
    init(&s);
    for(i=0;i<strlen(str);i++)
        Push(&s,str[i]);
        
    i=0;
    while(!isEmpty(&s))
    {
        str[i]=Pop(&s);
        i++;
    }
    printf("Reversed String is: %s\n",str);
    
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
