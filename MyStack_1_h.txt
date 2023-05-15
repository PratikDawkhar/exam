// using char in stack
char stack[10];
int top=-1;

void push(char no)
{ 
	top++;
	stack[top]=no;
}
char pop()
	{
		char x;
		x=stack[top];
		top--;
		return x;
	}
int isfull()
	{
		if(top>=9)
		return 1;
		else
		return 0;
	}
int isempty()
	{
		if(top==-1)
		return 1;
		else
		return 0;
	}
void display()
	{
	int i;
		printf("list is\n");
		for(i=top;i>=0;i--)
			printf("%c\n",stack[i]);
	}
	

