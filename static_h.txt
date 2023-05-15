\\stack.h

#define SIZE 3
int top,s[SIZE];
void init()
{
	top=-1;
}
void push()
{
	int h,n;
	if(top==SIZE-1)
		printf("\n stack is full\n");
	else
		{
		printf("\nenter the number");
		scanf("%d",&n);
		top++;
		s[top]=n;
		}
}
void pop()
{
	if(top==1)
		printf("\nstack is empty");
	else
	{
		printf("\n poped value:%d\n",s[top]);
		top--;
	}
}
void isempty()
{
	if(top==-1)
		printf("\n stack is empty \n");
	else
		printf("\n stack is not empty");
}
void isfull()
{
	if(top==SIZE-1)
	printf("\nstack is not full\n");
}
void peek()
{
	if(top==-1)
		printf("\n stack is empty");
	else
		{
		printf("\n peek value:%d\n",s[top]);
		}
}
