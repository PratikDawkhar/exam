Write a program that copies the contents of one stack into another. Use stack library to perform basic stack operations. The order of two stacks must be identical.(Hint: Use a temporary stack to preserve the order).

Solution:
#include<stdio.h>
#include"ststack.h"

void StackCopy(stack *stack1, stack *stack2)
{
    stack tempStack;
    int var,i;
    init(&tempStack);
    i=stack1->top;
    while (i>=0)
    {
        Push(&tempStack,stack1->data[i]);
        i--;   
    }
    while (!isEmpty(&tempStack))
    {
        var=Pop(&tempStack);
        Push(stack2,var);
    }
}
int main()
{
    stack s1, s2;
   
    init(&s1);
    init(&s2);
    //stack data
    Push(&s1, 1);
    Push(&s1, 2);
    Push(&s1, 3);
    Push(&s1, 4);
    Push(&s1, 5);
    StackCopy(&s1,&s2);
    printf("\nFirst Stack is\n");
    Display(&s1);
    printf("\nCopy of Stack is\n");
    Display(&s2);
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

