Init(S)

Create an empty stack and initializes value of top to -1 indicating the stack is empty

Push(S,x)

Insert element x into stack S

Pop(S)

Deletes and returns topmost element from stack S

Peek(S)

Returns topmost element from the stack S without deleting element.

isEmpty(S)

Checks and returns if the stack S is empty or not. Stack isempty when top==-1

isFull(S)

Checks and returns if the stack S is full or not. Stack isfull when top==MAX-1

a) Implement a stack library (ststack.h) of integers using a static implementation of the stack and implementing the above six operations. Write a driver program that includes stack library and calls different stack operations.

Solution:
#include<stdio.h>
#include"sstack.h"
void main()
{
    stack s;
    int x,op;
    init(&s);
    do
    {
        printf("\n\n1)Push\n2)Pop\n3)Display\n4)Peek\n5)Quit");
        printf("\nEnter Your choice: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("\n enter a number :");
            scanf("%d",&x);
            if(!isFull(&s))
                Push(&s,x);
            else
                printf("\nStack is full......!(Stack Overflow)");
            break;
            case 2:
            if(!isEmpty(&s))
            {
                x=Pop(&s);
                printf("\npopped value= %d",x);
            }
            else
                printf("\nStack is empty.....!(Stack Underflow)");
            break;
            case 3:
                Display(&s);
                break;
            case 4:
            if(!isEmpty(&s))
            {
                x=Peek(&s);
                printf("\nPeek value= %d",x);
            }
            else
                printf("\nStack is empty.....!!(Stack Underflow)");
                break;
        }
    }while(op!=5);
}
Library Function ( .h file )
NOTE: save file name as 'sstack.h'.

#include<stdio.h>
#define MAX 5
typedef struct stack
{
    int data[MAX];
    int top;
}stack;
void init(stack *);
int isEmpty(stack *);
int isFull(stack *);
int Pop(stack *);
void Push(stack *,int);
int Peek(stack *);
void Display(stack *);
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
    s->top=s->top+1;
    s->data[s->top]=x;
}
int Pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}
int Peek(stack *s)
{
    return(s->data[s->top]);
}
void Display(stack *s)
{
    int i;
    printf("\n");
    for(i=s->top;i>=0;i--)
        printf("%d  ",s->data[i]);
}
