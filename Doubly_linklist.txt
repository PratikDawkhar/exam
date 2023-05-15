#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next,*prev;
};
struct node*start=NULL,*q,*temp1,*temp;

void create()
{
	struct node*newnode,*temp;
	newnode=malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(start==NULL)
	start=newnode;
	else
	{
    		for(temp=start;temp->next!=NULL;temp=temp->next)
    		{ }
    	temp->next=newnode;
    	newnode->prev=temp;
	}
}

void display()
{
	if(start==NULL)
	printf("\nList is empty:");
	else
	{
		printf("list is\n");
		q=start;
		while(q!=NULL)
		{
			printf("%d\n",q->data);
			q=q->next;
		}
		printf("\n");
	}
}

void insert()
{
	struct node *temp,*q;
   int pos,cnt=2;
   temp=(struct node *)malloc(sizeof(struct node));
   printf("\nEnter data:");
   scanf("%d",&temp->data);
   temp->next=NULL;
   temp->prev=NULL;
   printf("Enter position to insert:");
   scanf("%d",&pos);
   q=start;
   if(start==NULL && pos>1)
   {
       printf("\nlist is empty Invalid position\n");
     return;
   }   
    if(pos==1)
    {
        temp->next=start;
        temp->prev=NULL;
        start=temp;
     }
     else
     {
          while(cnt<pos && q!=NULL)
          {
               q=q->next;
               cnt++;
           }
           if(q==NULL)
           {
               printf("\nInvalid position\n");
               return;
            }
             temp->next=q->next;
             q->next->prev=temp;
             temp->prev=q;
             q->next=temp;
       }
}

void delet()
{
   struct node *temp,*p;
   int pos,t;
   if(start==NULL)
   {
       printf("\n list is empty\n");
       return;
    }
    printf("\nEnter the position:");
    scanf("%d",&pos);
    t=1;
    temp=start;
    if(pos==1)
    	{
          
		  start=start->next;
		  start->prev=NULL;
          free(temp);
          printf("\n Node deleted successfully\n");
          return;
    	}
    while(t<pos-1)
    	{
           temp=temp->next;
           if(temp==NULL)
		   break;
           t++;
        }
    if(temp==NULL||temp->next==NULL)
    	printf("Invalid position\n");
    else
        {
           p=temp->next;
           temp->next=p->next;
           p->next->prev=temp;
           
           free(p);
           printf("\nNode deleted successfully\n");
        }
}

void reverse()
{ 
	for(temp=start;temp->next!=NULL;temp=temp->next)
		{ }
	for(temp1=temp;temp1!=NULL;temp1=temp1->prev)
		printf("%d\t",temp1->data);
}

void main()
{
	int choice;
	do
	{
		printf("\n1.create \n2.display \n3.insert \n4.delete \n5.reverse \n6.exit\n");
		printf("enter choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
			break;
			
			case 2:display();
			break;
			
			case 3:insert();
			break;
			
			case 4:delet();
			break;
			
			case 5:reverse();
			break;
			
			case 6:exit(0);
			default:printf("\n Invalid Position:");
		}
	}
	while(choice!=6);	
}
