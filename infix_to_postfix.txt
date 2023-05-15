// inf to pos
#include<stdio.h>
#include<string.h>
#include"MyStack_1.h"
int priority(char op)
	{
		switch (op)
		{
			case'+':return 10;
			case'-':return 10;
			case'*':return 20;
			case'/':return 20;
			case'^':return 30;
			default:return 0;
		}
	}
	
void inf_to_pos()
{
	char x,inf[20],pos[20];
	int i,j=0;
	
	printf("\nEnter a infix expression\n");
	scanf("%s",inf);	
	
	for(i=0;inf[i]!='\0';i++)
	{
		x=inf[i];
		
		if(x>='A'&&x<='Z'||x>='a'&&x<='z')
		pos[j++]=x;
		
		else if (x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
		{
			while(priority(x)<=priority(stack[top]))
		     	pos[j++]=pop();
			
			push(x);
		}
		else if (x=='(')
		push (x);
		else if (x==')')
		{
			while(stack[top]!='(')
		  	     pos[j++]=pop();
			
			pop();//remove ( from stack
		}
	}
	while(!isempty())
	 	pos[j++]=pop();
	
	pos[j]='\0';
	printf("postfix expression is %s",pos);
}

void inf_to_pre()
{
	char x,inf[20],pos[20];
	int i,j=0;
	
	printf("\nEnter a infix expression\n");
	scanf("%s",inf);	
	
	for(i=strlen(inf)-1;i>=0;i--)
	{
		x=inf[i];
		
		if(x>='A'&&x<='Z'||x>='a'&&x<='z')
		pos[j++]=x;
		
		else if (x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
		{
			while(priority(x)<priority(stack[top]))
		     	pos[j++]=pop();
			
			push(x);
		}
		else if (x==')')
		push (x);
		else if (x=='(')
		{
			while(stack[top]!=')')
		  	     pos[j++]=pop();
			
			pop();//remove ( from stack
		}
	}
	while(!isempty())
	 	pos[j++]=pop();
	
	pos[j]='\0';
	printf("prefix expression is %s",strrev(pos));
}

void main()
{
	inf_to_pos();
	inf_to_pre();	
}
