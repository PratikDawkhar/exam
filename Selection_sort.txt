#include<stdio.h>
#include<stdlib.h>

void Ssort(int a[20],int n)	
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)	
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
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
	Ssort(a,n);
	printf("sorted data is:\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}
