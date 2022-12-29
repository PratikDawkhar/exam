init (Q)

Create an empty queue as a circular linked list by initializing S to NULL indicating that the queue is empty

AddQueue(Q, x)

This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position.

Steps:

1. Check whether queue is Full – Check ((rear == SIZE-1 && front == 0) || (rear == front-1)).

2. If it is full then display Queue is full. If queue is not full then, check if (rear == SIZE – 1 && front! = 0) if it is true then set rear=0 and insert element.

X=DeleteQueue(Q)

This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from front position.

Steps:

1. Check whether queue is Empty means check (front==-1).

2. If it is empty then display Queue is empty. If queue is not empty then step 3

3. Check if (front==rear) if it is true then set front=rear= -1 else check if (front==size-1), if it is true then set front=0 and return the element.

X=peek (Q)

returns the data element in the front (Q->next) node of the Queue Q

isEmpty (Q)

Check if the Queue is empty which is equivalent to checking if Q==NULL

b) Implement a circular queue library (cir_queue.h) of integers using a dynamic (circular linked list) implementation of the queue and implementing the above five operations. Write a menu driven program that includes queue library and calls different queue operations..

Solution:
#include <stdio.h>
#include <stdlib.h>
#include "cir_queue.h"
int main()
{
    int num,choice;
    init();
    while(1)
    {
        printf("\n\nQUEUE OPERATIONS\n\n1.AddQUEUE\n2.DeleteQUEUE\n3.Peek\n4.DISPLAY\n\n");
        printf("\nEnter Your Choice ::\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter item : ");
                scanf("%d",&num);
                AddQueue(num);
                break;
            case 2:
                if(!(isEmpty()))
                    printf("\nDeleted element : %d",DeleteQueue());
                else
                    printf("\nEMPTY QUEUE\n");
                break;
            case 3:
                if(!(isEmpty()))
                    printf("\nPeek element : %d",peek());
                else
                    printf("\nEMPTY QUEUE\n");
                break;
            case 4:
                display();
                break;
            default: exit(0);
        }
    }
    return 0;
}
Library Function ( .h file )
NOTE: save file name as 'cir_queue.h'.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *rear,*front;

void init()
{
    front = rear = NULL;
}
void AddQueue(int data)
{
    struct node *newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(front == NULL)
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
    rear -> next = front;
}

int DeleteQueue()
{
    int x;
    struct node *temp;
    if (front == NULL)
    {
        return -1;
    }
    else if (front == rear)
    {
        x = front->data;
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        x = temp -> data;
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
    return x;
}
int peek()
{
    int x;
    struct node *temp;
    if (front == NULL)
    {
        return -1;
    }
    else
    {
        x = front->data;
    }
    return x;
}
int isEmpty()
{
    if(front == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void display()
{
    struct node *temp = front;
    if(isEmpty())
    {
        printf("\nCIRCULAR QUEUE is EMPTY ");
    }
    else
    {
    printf("\nCIRCULAR QUEUE : ");
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while (temp != front);
    }
}
