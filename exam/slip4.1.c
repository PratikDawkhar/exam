 Sort a random array of n integers (accept the value of n from user) in ascending order by using bubble sort algorithm.

Solution: 

#include<stdio.h>
void bubble_sort(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void generate(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
       a[i]=rand()%100;
}
void display(int *a,int n)
{              
    int i;
    for(i=0;i<n;i++)
   {
        printf("%d\t",a[i]);
   }
}
main()
{
    int a[20],i,j,n;
    printf("\n Enter how many elements:");
    scanf("%d",&n);
    generate(a,n);
    printf("\n Elements are:\n");
    display(a,n);
    bubble_sort(a,n);
    printf("\n After sorting elements are :\n");
    display(a,n);
}
