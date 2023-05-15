#include<stdio.h>
#include<stdlib.h>

void bsort(int a[20],int n)
{
	int i,j,t;
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			if(a[i]>a[i+1])
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
	int a[20],n,i;
	printf("enter how many elements:");
	scanf("%d",&n);
	printf("enter array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	bsort(a,n);
	printf("sorted data is:\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}


