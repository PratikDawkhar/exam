#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct city
{
	char name [20];
	int code;
}city;
 
void isearch(int);
city a[20];
 
int fileread ()
{
 	int i=0;
 	FILE *fp;
 	fp=fopen("city.txt","r");
 	if(fp==NULL)
 	printf("error");
 	else
 	{
 		while(!feof(fp))
 		{
 			fscanf(fp,"%s %d",a[i].name,&a[i].code);
 			i++;
 		}
 		fclose(fp);
 	}
 	return i-1;
}


void main ()
{
	int i,n;
	n=fileread();
	if(n>0)
	{
		for(i=0;i<n;i++)
		printf("%s %d\n",a[i].name,a[i].code);
 		isearch(n);
 	}
}
 
void isearch(int n)
{
 	char str[20];
 	int i,flag=0;
 	printf("enter city");
 	scanf("%s",str);
 	for(i=0;i<n;i++)
	{
 		if(strcmp(str,a[i].name)==0)
	 	{
 			flag=1;
 			break;
 		}
 	}
 	if(flag==1)
		 printf("%d\n",a[i].code);
 	else
 		printf("city not found\n");
}
