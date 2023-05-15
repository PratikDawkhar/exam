// Eval to post
#include<stdio.h>
#include<math.h>
#include"MyStack.h" //integer stack
void eval()
{
	char post[20],x;
	int val,op1,op2,res,i;
	
	printf("\nEnter a Postfix expression");
	scanf("%s",post);
	
	for(i=0;post[i]!='\0';i++)
	{
		x=post[i];
		if(x>='A'&&x<='Z'||x>='a'&&x<='z')
		   {
		   	printf("\nEnter a value of %c",x);
		   	scanf("%d",&val);
		   	push(val);
		   }
		else if (x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
		{
			op2=pop();
			op1=pop();
			switch(x)
			{
				case '+':res=op1+op2; break;
				case '-':res=op1-op2; break;
				case '*':res=op1*op2; break;
				case '/':res=op1/op2; break;
				case '^':res=pow(op1,op2); break;

			}
			push(res);
		}
	} //end for
	res=pop();
	printf("Evaluation %d",res);
}
main()
{
	eval();
}
