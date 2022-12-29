A doubly ended queue allows additions and deletions from both the ends that is front and rear. Initially additions from the front will not be possible. To avoid this situation, the array can be treated as if it were circular. Implement a queue library (dstqueue.h) of integers using a static implementation of the circular queue and implementing the nine operations :

1)init(Q), 2)isempty(Q) 3)isFull(Q) 4)getFront(Q), 5)getRear(Q), 6)addFront(Q,x), 7)deleteFront(Q), 8) addRear(Q,x), 9)deleteRear(Q) .

Solution:
#include <stdio.h> 
#include"dstqueue.h"
int main()
{
	int ch,n,i,data,p;
	init();
	do
	{
		printf("\n\tMENU\n\n1 AddFront\n2 AddRear\n3 RemoveFront\n4 DeleteRear\n5 getFront\n6 getRear\n7 Display\n8 Exit\n");
		printf("Enter Your Choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter your data");
				scanf("%d",&data);
				AddFront(data);
				break;
			case 2:
				printf("\nEnter your data");
				scanf("%d",&data);
				AddRear(data);
				break;
			case 3:
				RemoveFront();
				break;
			case 4:
				DeleteRear();
				break;
			case 5:
				n=getFront();
				if(n>0)
				printf("\nFront Element = %d\n",n);
				break;
			case 6:
				n=getRear();
				if(n>0)
					printf("\nRear Element = %d\n",n);
				break;
			case 7:
				Display();
				break;
			case 8:
				break;
			default:
				printf("\nIncorrect Choice");
		}
	}while(ch!=8);
    return 0;
}

Library Function ( .h file )
NOTE: save file name as 'dstqueue.h'.

#include <stdio.h>  
#define size 5
int deque[size];
int f, r;
void init()
{
	f=r=-1;
}
int isEmpty()
{
	if((f==-1) && (r==-1))  
    {  
        return 1;
    }  
    else 
    	return 0;
}
int isFull()
{
	if((f==0 && r==size-1) || (f==r+1))  
    {  
        return 1;
    }
    else 
    	return 0;
}
void AddFront(int x)  
{  
    if(isFull())  
    {  
        printf("\nDequeue is full\n");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        f=r=0;  
        deque[f]=x;  
    }  
    else if(f==0)  
    {  
        f=size-1;  
        deque[f]=x;  
    }  
    else  
    {  
        f=f-1;  
        deque[f]=x;  
    }  
}  
void AddRear(int x)  
{  
    if(isFull())  
    {  
        printf("\nDeque is full\n");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else if(r==size-1)  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else  
    {  
        r++;  
        deque[r]=x;  
    }  
}  
void Display()  
{  
    int i=f;  
    printf("\n Elements in a deque : ");  
    while(i!=r) 
    {  
        printf("%d ",deque[i]);  
        i=(i+1)%size;  
    }  
    printf("%d",deque[r]);  
}  
int getFront()  
{  
    if(isEmpty())  
    {  
        printf("\nDequeue is empty");
		return 0; 
    }  
    else  
    {  
        return(deque[f]);  
    }       
}  
int getRear()  
{  
    if(isEmpty())  
    {  
        printf("\nDequeue is empty"); 
        return 0;
    }  
    else  
    {  
        return(deque[r]);  
    }        
}
void RemoveFront()  
{  
    if(isEmpty())  
    {  
        printf("Dequeue is empty");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[f]);  
        f=-1;  
        r=-1;            
    }  
    else if(f==(size-1))  
    {  
         printf("\nThe deleted element is %d", deque[f]);  
         f=0;  
    }  
    else  
    {  
        printf("\nThe deleted element is %d", deque[f]);  
        f=f+1;  
    }  
}  
void DeleteRear()  
{  
    if(isEmpty())  
    {  
        printf("\nDequeue is empty\n");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[r]);  
        f=-1;  
        r=-1;         
    }  
    else if(r==0)  
    {  
        printf("\nThe deleted element is %d", deque[r]);  
        r=size-1;  
    }  
    else  
    {  
        printf("\nThe deleted element is %d", deque[r]);  
        r=r-1;  
    }  
}  
