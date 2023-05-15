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
	if((fp=fopen("sin.txt","w"))!=NULL)
	{
		for(i=0;i<n;i++)
		fprintf(fp,"%s\t%d\t%d\n",a[i].name,a[i].age,a[i].sal);
	}
}


void isort(int n)
{
	int i,j;
	rec t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=0&&strcmp(a[j].name,t.name)>0)
		{
			a[j+1]=a[j];
			j--;
		}
	a[j+1]=t;
	}
}
	

int main()
{
	int n;
	n=read();
	isort(n);
	write(n);
}
