#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct rec
{
	char name[30];
	int age;
	int sal;
}rec;

rec a[100];

int read()
{
	int i=0;
	FILE *fp;
	if((fp=fopen("emp.txt","r"))!=NULL)
	{
		while(!feof(fp))
		{
			fscanf(fp,"%s %d %d",a[i].name,&a[i].age,&a[i].sal);
			i++;
		}
	}
	return i-1;
}

void write(int n)
{
	int i=0;
	FILE *fp;
	if((fp=fopen("semp.txt","w"))!=NULL)
	{
		for(i=0;i<n;i++)
		fprintf(fp,"%s\t%d\t%d\n",a[i].name,a[i].age,a[i].sal);
	}
}


void sort(int n)
{
	int i,j;
	rec t;
	for(j=0;j<n-1;j++)
	{
	  for(i=0;i<n-j-1;i++)
	  {  
	    if(strcmp(a[i].name,a[i+1].name)>0)
		{
		  t=a[i];
		  a[i]=a[i+1];
		  a[i+1]=t;
		}
	  }
	}
}
	
	
	
int main()
{
	int n;
	n=read();
	printf("%d",n);
	sort(n);
	write(n);
}

