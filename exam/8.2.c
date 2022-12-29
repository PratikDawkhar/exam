Write a program to check whether the contents of two stacks are identical. Use stack library to perform basic stack operations. Neither stack should be changed.

Solution:
#include<stdio.h>
#include"ststack.h"
int isSameStack(stack *stack1,  stack *stack2)
{
    int flag = 1;
    int i;
    if (stack1->top != stack2->top)
    {
        flag = 0;
        return flag;
    }
    i=stack1->top;
    while (i>=0)
    {
        if (stack1->data[i] != stack2->data[i])
        {
            flag = 0;
            break;
        }
        i--;    
    }
    return flag;
}
int main()
{
    stack s1, s2;
    init(&s1);
    init(&s2);
    //first stack data
    Push(&s1, 1);
    Push(&s1, 2);
    Push(&s1, 3);
    Push(&s1, 4);
    Push(&s1, 5);
    //second stack data
    Push(&s2, 1);
    Push(&s2, 2);
    Push(&s2, 3);
    Push(&s2, 4);
    Push(&s2, 5);
    printf("\nFirst Stack is\n");
    Display(&s1);
    printf("\nSecond Stack is\n");
    Display(&s2);
    if (isSameStack(&s1, &s2))
        printf("\nStacks are Same");
    else
        printf("\nStacks are Not Same");
 
    return 0;
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
    if(!isEmpty(s))
    for(i=s->top;i>=0;i--)
        printf("%d  ",s->data[i]);
    else
        printf("Stack is Empty");
}
