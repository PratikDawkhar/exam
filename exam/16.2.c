 A postfix expression of the form ab+cd-*ab/ is to be evaluated after accepting the values of a, b, c and d. The value should be accepted only once and the same value is to be used for repeated occurrence of same symbol in the expression. Formulate the problem and write a C program to solve the problem by using stack.

Solution:
#include<stdio.h>
#include<string.h>
int stack[20];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}
void evalPostFix(char exp[])
{
    char *e;
    int n1,n2,n3,num;
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
        }
        push(n3);
    }
    e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
}
int main()
{
    char exp[20],temp[20];
    char *e,*t;
    int n1,n2,n3,num,i,j;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(isalpha(exp[i]))
        {
            printf("\nEnter The Value of %c", exp[i]);
            scanf("%d", &num);
            num=num+48;
            for(j = i + 1; j<strlen(exp); j++)
              {
                  if(exp[j] == exp[i])  
                {
                    exp[j]=num;
                }
            }
            exp[i]=num;
        }
    }
    printf("\nNow Given Expression is\n");
    puts(exp);
    printf("\nEvaluation of given expression\n");
    evalPostFix(exp);
    return 0;
}
