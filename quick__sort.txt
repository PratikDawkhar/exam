//quicksort in function
#include<stdio.h>
#include<stdlib.h>
void generate(int a[10],int n)
{
	int i;
	printf("\nArray elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}
int partition(int a[10],int l,int h)
{
	int pivot , i,j, temp;
	pivot=a[l];
	i=l+1;
	j=h;
	while(i<=j)
	{
		while(a[i]<pivot)
		i++;
		while(a[j]>pivot)
		j--;
		if(i<=j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[l]=a[j];
	a[j]=pivot;
	return j;
}
void quicksort (int a[10],int l,int h)
{
	int m;
	if(l<h)
	{
		m=partition(a,l,h);
		quicksort(a,l,m-1);
		quicksort(a,m+1,h);
	}
}
void display(int a[10],int n)
{
	int i;
	printf("\nSorted data");
	for(i=0;i<n;i++)
	printf("\n%d",a[i]);
 } 
int main()
{
 	int a[10],n;
 	printf("\n Enter the size of array:");
 	scanf("%d",&n);
 	generate(a,n);
 	partition(a,0,n-1);
 	quicksort(a,0,n-1);
 	display(a,n);
}
