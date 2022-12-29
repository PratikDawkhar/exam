 Implement a list library (singlylist.h) for a singly linked list. Create a linked list, reverse it and display reversed linked list.
Solution:

#include<stdio.h>
#include<stdlib.h>
#include"singlyList.h"
main()
{
  int ch,n;
  struct node *head=NULL;
  do
  {
    printf("\nMENU\n");
    printf("\n1.Create");
    printf("\n2.Display");
    printf("\n3.Reverse");
    printf("\n4.Exit\n");
    printf("\nEnter Ur Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter The Number of Node You Want\n");
            scanf("%d",&n);
            head=create(head,n);
            break;
        case 2:
               printf("\nLinked list is :\n");
            display(head);
            break;
        case 3:
            head=reverseList(head);
            break;
        case 4:
               exit(0);
            break;
        default :printf("\nInvalid choice ");     
     }
   } while(ch!=4);
}

Library Function ( .h file )
NOTE: save file name as ' singlyList.h'.

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node* create(struct node *head, int n)
{
    struct node *new_node, *temp;
    int i;
    for(i=1;i<=n;i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter node %d: ",i);
        scanf("%d",&new_node->data);
        new_node->next = NULL;
        // If it is the first node
        if (head == NULL)
        {
            // Initialize the start
            head = (struct node*)malloc(sizeof(struct node));
            head->next = new_node;
        }
        else
        {
            temp=head->next;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new_node;
        }
    }
    return head;
}
void display(struct node* head)
{
    struct node *temp;
    if(head==NULL)
        printf("\nCreate List First!");
    else
    {   
        for(temp=head->next;temp!=NULL;temp=temp->next)
        {
            printf("\t %d ->",temp->data);
        }
        printf("NULL");
    }
}
struct node *reverseList(struct node *head)
{
    struct node *prevNode, *curNode, *nextNode;
    if(head != NULL)
    {
        prevNode = NULL;
        curNode = head->next;
        nextNode = NULL;
        while(curNode != NULL)
        {
            nextNode = curNode->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = nextNode;
        }
        head->next= prevNode; // Make last node as head
        printf("SUCCESSFULLY REVERSED LIST \n");
    }
    return(head);
}

