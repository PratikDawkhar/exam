#include<stdio.h>
#include<stdlib.h>

void isort(int a[20],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=0&&a[j]>t)	
		{
			a[j+1]=a[j];
			j--;
		}
	a[j+1]=t;
	}
}


int main()
{
	int a[20],n,i;
	printf("enter how many elements:");
	scanf("%d",&n);
	printf("enter array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	isort(a,n);
	printf("sorted data is:\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}
