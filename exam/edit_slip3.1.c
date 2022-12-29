/*Sort a random array of n integers (create a random array of n integers) in ascending order by using insertion sort algorithm. 

Solution:*/
#include<stddef.h>
#include<stdio.h>
void insertion_sort(int *a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j= i-1; j>=0 && temp<a[j]; j--)
            a[j+1]=a[j];
        a[j+1]=temp;
    }
}
void generate(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]= rand()%100;
}
void display(int *a,int n)
{              
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void main()
{
    int a[20],i,j,n;
    printf("\n Enter how many elements:");
    scanf("%d",&n);
    generate(a,n);
    printf("\n Elements are:\n");
    display(a,n);
    insertion_sort(a,n);
    printf("\n After sorting elements are :\n");
    display(a,n);
}
