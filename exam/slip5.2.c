 Implement a priority queue library (PriorityQ.h) of integers using a static implementation of the queue and implementing the below two operations. Write a driver program that includes queue library and calls different queue operations.

1) Add an element with its priority into the queue.

2) Delete an element from queue according to its priority.

Solution:
#include<stdio.h>
#include"PriorityQ.h"
int main()
{
	int ch,n,i,data,p;
	do{
		
		printf("\n\tMENU\n\n1 Insert the Data in Queue\n2 Display the Data in Queue \n3 Delete the data from the Queue\n4 Exit\n");
		printf("Enter Your Choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1:
		      printf("\nEnter your data and Priority of data");
			scanf("%d%d",&data,&p);
			enqueue(data,p);
			break;
         	    case 2:
		        display();
			break;
		    case 3:
			n=dequeue();
			if(n>0)
		         printf("\nDeleted Element = %d\n",n);
			break;
		    case 4:
			break;
		    default:
			printf("\nIncorrect Choice");
		}
	}while(ch!=4);
    return 0;
}
Library Function ( .h file )
NOTE: save file name as 'PriorityQ.h'.

#include<stdio.h>
#define MAX 20
int Q[MAX],Pr[MAX];
int r = -1,f = -1;
void enqueue(int data,int p)
{
	int i;
	if((f==0)&&(r==MAX-1)) 
		printf("Queue is full");
	else
	{
		if(f==-1)
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == MAX-1)
		{
			for(i=f;i<=r;i++) 
			{ 
				Q[i-f] = Q[i]; 
				Pr[i-f] = Pr[i]; 
				r = r-f; 
				f = 0; 
				for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
					 Q[i+1] = Q[i];
					 Pr[i+1] = Pr[i];
					}
					else
					 break;
				}
				Q[i+1] = data;
				Pr[i+1] = p;
				r++;
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
				 Q[i+1] = Q[i];
			         Pr[i+1] = Pr[i];	
				}
				else
				 break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}
}
void display() 
{
	int i;
	if(f==-1)
		printf("Queue is Empty\n");
	else
	{
		for(i=f;i<=r;i++)
		{
	   printf("\nElement= %d\tPriority = %d",Q[i],Pr[i]);
		}
	}
}
int dequeue()
{
	int x;
	if(f == -1)
	{
		printf("Queue is Empty");
		return 0;
	}	
	else
	{
		x=Q[f];
		if(f==r)
			f = r = -1;
		else
			f++;
		return x;
	}
	
}
