#include<stdio.h> 
#include<stdlib.h>
#include"static.h"
void main()
{
	int ch;
	while(1)
	{
		printf("\n _______");
		printf("\n 1.init");
		printf("\n 2.push");
        printf("\n 3.pop");
		printf("\n 4.isempty");
		printf("\n 5.isfull");
		printf("\n 6.peek");
		printf("\n 7.exit");
		printf("\n enter your choice");
		scanf("%d", & ch);
	switch(ch)
		{
			case 1: init();
				break;
			case 2: push();
				break;
			case 3: pop();
				break;
			case 4: isempty();
				break;
			case 5: isfull();
				break;
			case 6: peek();
				break;
			case 7: exit(0);
			default:printf("\n invalid choice");
		}
	}
}

