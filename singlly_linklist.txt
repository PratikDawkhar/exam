#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
}*start=NULL,*q,*t;


void create()
{
	t=(struct node *)malloc(sizeof(struct node));
	printf("\nenter no:");
	scanf("%d",&t->data);
	t->next=NULL;
	if(start==NULL)
		start=t;
	else{
		q=start;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=t;
	}
	
}

void display()
{
	if(start==NULL)
		printf("list is empty\n");
	else
	{
		printf("list is \n");
		for(q=start;q!=NULL;q=q->next)
			printf("%d\n",q->data);
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("1.creat\n2.display\n3.exit\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
				break;
			case 2:display();
				break;
			case 3:exit(0);
		}
	}
}

