Implement a list library (doublylist.h) for a doubly linked list with the above operations. Write a menu driven driver program to call the operations append, insert, delete specific node, delete at position, search, display.

Solution:
#include<stdio.h>
#include<stdlib.h>
#include "doublylist.h"
main()
{
  int ch,val,i,m,a,pos,sr,d;
  struct node *head=NULL;
  do
  {
    printf("\n MENU\n");
    printf("\n1.Append");
    printf("\n2.Display");
    printf("\n3.Search");
    printf("\n4.Insert");
    printf("\n5.Delete By Value");
    printf("\n6.Delete By Position");
    printf("\n7.Exit\n");
    printf("\nEnter Ur Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter The Value To Append\n");
            scanf("%d",&val);
            head=append(head,val);
            break;
        case 2:
            printf("\n Linked list is :\n");
            display(head);
            break;
        case 3:
            printf("\n Enter data to be search : ");
            scanf("%d",&val);
            search(head,val);
            break;
        case 4:
            printf("\n Enter the value and position to be data added :");
            scanf("%d%d",&val,&pos);
            head=insert(head,val,pos);
            break;
        case 5:
            printf("\n Enter the data to be deleted :");
            scanf("%d",&val);
            head=delete_val(head,val);
            break;
        case 6:
            printf("\n Enter position to be data deleted :");
            scanf("%d",&pos);
            head=delete_pos(head,pos);
            break;
        case 7: exit(0);
            break;
        default :printf("\n Invalid choice ");     
     }
   } while(ch!=7);
}
Library Function ( .h file )
NOTE: save file name as ' doublylist.h'.

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
int cnt=0;
struct node *append(struct node *head, int x)
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        // Initialize the start
        head = (struct node*)malloc(sizeof(struct node));
        head->next = newnode;
        newnode->prev=head;
        cnt++;
    }
    else
    {
        // Insert the node in the end
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev=temp;
        cnt++;
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
struct node *insert(struct node *head,int x,int pos)
{
    struct node *temp,*newnode;
    int i;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(pos>=cnt)
    {
        for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=newnode;
            newnode->prev=temp;
        cnt++;
    }
    else
    {              
        if(pos==1)
        {
            newnode->next=head->next;
            head->next->prev=newnode;
            head->next=newnode;
            newnode->prev=head;
            cnt++;
        }
        else
        {
            for(i=1,temp=head->next;i<pos-1;i++)
                temp=temp->next;
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
            cnt++;
        }
    }
    return head;
}
void search(struct node*head, int x)
{
    struct node *temp;
    int flag=0;      
       for(temp=head;temp!=NULL;temp=temp->next)
    {
        if(x==temp->data)
        {
            flag=1;
            break;
        }
    }    
    if(flag==1)
        printf("\nELEMENT IS FOUND ");
    else
        printf("\nELEMENT IS NOT PRESENT ");
}
struct node* delete_pos(struct node *head,int pos)
{
    struct node *temp,*temp1;
    int i;
    if(pos>cnt)
    {
        printf("\n Invalid position ");
    }
    else
    {
        if(pos==1)
        {
            temp=head->next;
            head->next=temp->next;
            temp->next->prev=head;
            temp->next=NULL;
            temp->prev=NULL;
            free(temp);
            cnt--;
        }
        else if(pos==cnt)
        {   
            for(i=1,temp=head->next;i<cnt-1;i++)
                temp=temp->next;
            temp1=temp->next;
            temp->next=NULL;
            temp1->prev=NULL;
            free(temp1);
            cnt--;
        }
        else
        {
            for(i=1,temp=head->next;i<pos-1;i++)
                temp=temp->next;
            temp1=temp->next;
            temp->next=temp1->next;
            temp1->next->prev=temp;
            temp1->next=NULL;
            temp1->prev=NULL;
            free(temp1);
            cnt--;
        }
    }
    return head;
}
struct node* delete_val(struct node *head, int x)
{
    struct node *temp,*temp1;
    int i, flag=0;
    i=1;
    temp=head;
    while(temp!=NULL)
    {
        if(x==temp->next->data)
        {
            flag=1;
            temp1=temp->next;
            temp->next=temp1->next;
            if(temp1->next!=NULL)
                temp1->next->prev=temp;
            temp1->next=NULL;
            temp1->prev=NULL;
            free(temp1);
            cnt--;
            break;
        }
        temp=temp->next;
    }
    if(flag==1)
        printf("\nELEMENT IS FOUND AND DELETED ");
    else
        printf("\nELEMENT IS NOT PRESENT ");
    return head;
}

