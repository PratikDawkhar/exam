init (Q)

Create an empty queue by initializing both front and rear to -1 indicating the queue is empty.

add (Q, x)

adds an element x to the rear end of the queue Q

X=delete (Q)

Deletes an element x from front end of the queue Q.

X=peek (Q)

Without deleting, returns the front element from the queue Q

isEmpty (Q)

Checks whether the queue is empty. Queue becomes empty when rear equals to front.

isFull(Q)

Checks whether the queue is full. Queue becomes full when front reaches to MAX -1.

a) Implement a linear queue library (st_queue.h) of integers using a static implementation of the queue and implementing the above six operations. Write a program that includes queue library and calls different queue operations.

Solution:
#include <stdio.h>
#include <stdlib.h>
#include "st_queue.h"
void main()
{
    int no, ch, var;
    struct queue Q;
    init(&Q);
    do
    {
        printf("\n MENU\n1 - Add");
        printf("\n 2 - Delete");
        printf("\n 3 - Peek");
        printf("\n 4 - Display");
        printf("\n 5 - Exit");
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            add(&Q,no);
            break;
        case 2:
            no=deleteQ(&Q);
            if(no>0)
                printf("\n%d is deleted from Queue\n", no);
            break;
        case 3:
            var = peek(&Q);
            if (var != 0)
                printf("Front element : %d", var);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            display(&Q);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }while(ch!=5);
}
Library Function ( .h file )
NOTE: save file name as 'st_queue.h'.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct queue
{
    int data[MAX];
    int front, rear;
};
void init(struct queue *Q);
void add(struct queue *Q, int x);
int deleteQ(struct queue *Q);
int peek(struct queue *Q);
int isEmpty(struct queue *Q);
int isFull(struct queue *Q);
void display(struct queue *Q);

void init(struct queue *Q)
{
    Q->front = Q->rear = -1;
}
void add(struct queue *Q, int x)
{
    if(!isFull(Q))
    {
        if (Q->front == -1&&Q->rear == -1)
        {    
               Q->rear++;
            Q->data[Q->rear] = x;
            Q->front = Q->rear;
        }
           else
        {
            Q->rear++;
            Q->data[Q->rear] = x;
        }
    }
    else
        printf("\nQueue Overflow!\n");
}
int deleteQ(struct queue *Q)
{
    int x=0;
    if(!isEmpty(Q)&& Q->front<=Q->rear)
    {
        x=Q->data[Q->front];
        Q->front++;
    }
    else
        printf("\nQueue Underflow!\n");
    return x;
}
int peek(struct queue *Q)
{
    if (!isEmpty(Q)&&Q->front<=Q->rear)
        return(Q->data[Q->front]);
    else
        return 0;
}
int isEmpty(struct queue *Q)
{
     if ((Q->front == -1) && (Q->rear == -1))
        return 1;
    else
       return 0;
}
int isFull(struct queue *Q)
{
     if ((Q->rear == MAX-1))
        return 1;
    else
       return 0;
}
void display(struct queue *Q)
{
    int i;
    if ((Q->front == -1) || (Q->front >=Q->rear))
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        i=Q->front;
        while (i <= Q->rear)
           {
               printf("%d ", Q->data[i]);
            i++;
        }
    }
}
