Write a program that merges two ordered linked lists into third new list. When two lists are merged the data in the resulting list are also ordered. The two original lists should be left unchanged. That is merged list should be new one. Use linked implementation.
 
Solution:
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *append(struct node *head, int x)
{
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
} void display(struct node* head)
{
    struct node *temp;
    if(head==NULL)
        printf("\nCreate List First!");
    else
    {   
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            printf("\t %d ->",temp->data);
        }
        printf("NULL");
    }
}

struct node* mergeLL(struct node* head1,struct node* head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *head3=NULL, *temp3;
    if(head1==NULL)
    {
        head3=head2;
    }
    else if (head2==NULL)
    {
        head3=head1;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
              head3 = append(head3, temp1->data);
              temp1 = temp1->next;
        }
        else if(temp1->data > temp2->data)
        {
              head3 = append(head3, temp2->data);
              temp2 = temp2->next;
        }
        else
        {
              head3 = append(head3, temp2->data);
              temp2 = temp2->next;
              temp1 = temp1->next;
        }
    }
    temp3=head3;
    while(temp3->next!=NULL)
        temp3=temp3->next;
    if (temp1 == NULL)
    {
        temp3->next=temp2;
    }
    if (temp2 == NULL)
    {
        temp3->next=temp1;
    }
    return head3;
}
int main()
{
    struct node *h1, *h2, *h3;
    int data, n1, n2, i;
    h1=h2=NULL;
    printf("\nEnter The Number of Nodes of First List::\n");
    scanf("%d", &n1);
    printf("\nEnter The Number of Nodes of Second List::\n");
    scanf("%d", &n2);
    printf("\nEnter The Data of First List in Sorted Order\n");
    for(i=1; i<=n1;i++)
    {
        scanf("%d",&data);
        h1=append(h1, data);
    }
    printf("\nEnter The Data of Second List in Sorted Order\n");
    for(i=1; i<=n2;i++)
    {
        scanf("%d",&data);
        h2=append(h2, data);
    }
    h3=mergeLL(h1,h2);
    printf("\nGiven First List is::\n");
    display(h1);
    printf("\nGiven Second List is::\n");
    display(h2);
    printf("\nMerge of Two List is:\n");
    display(h3);
    return 0;
} 
