 There are lists where new elements are always appended at the end of the list. The list can be implemented as a circular list with the external pointer pointing to the last element of the list. Implement singly linked circular list of integers with append and display operations. The operation append(L, n), appends to the end of the list, n integers either accepted from user or randomly generated.

Solution:
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*tail;
struct node *append(struct node *head, int n)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if (head == NULL)
    {
        head=tail=newnode;
        head->next=head;
    }
    else
    {
        tail->next = newnode;
        newnode->next=head;
        tail=newnode;
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
        for(temp=head;temp->next!=head;temp=temp->next)
        {
            printf("\t %d ->",temp->data);
        }
        printf("\t %d ",temp->data);
    }
}
main()
{
  int ch,val;
  head=NULL;
  do
  {
    printf("\n MENU\n");
    printf("\n1.Append");
    printf("\n2.Display");
    printf("\n3.Exit");
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
        case 3: exit(0);
            break;
        default :printf("\n Invalid choice ");     
     }
   } while(ch!=3);
}
