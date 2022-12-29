Sort a random array of n integers (accept the value of n from user) in ascending order by using selection sort algorithm.

Solution: 

#include<stdio.h>
void selection_sort(int *a, int n )
{
    int i=0, j=0, temp=0, minindex;
    for(i=0; i<n; i++ )
    {
        minindex = i;
        for( j=i+1; j<n; j++ )
        {
            if(a[j]<a[minindex] )
                    minindex=j;
        }
        temp = a[i];
        a[i]= a[minindex];
        a[minindex] = temp;
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
    printf("\n Enter how many elemants:");
    scanf("%d",&n);
    generate(a,n);
    printf("\n Elements are:\n");
    display(a,n);
    selection_sort(a,n);
    printf("\n After sorting elements are :\n");
    display(a,n);
}
