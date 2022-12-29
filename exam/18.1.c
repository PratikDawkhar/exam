Sort a random array of n integers (accept the value of n from user) in ascending order by using recursive Counting sort algorithm. 

Solution:

#include<stdio.h>
void counting_sort(int *array, int size)
{
    int output[10], max, i;
    int count[100];
    // Find the largest element of the array
    max = array[0];
    for (i = 0; i <size; ++i)
    {
        printf("%d\t",array[i]);
    }
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        max = array[i];
    }

    // Initialize count array with all zeros.
    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    // Store the count of each element
    for (i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    // Store the cummulative count of each array
    for (i = 1; i <= max; i++)
    {
        count[i] += count[i-1];
    }
    // Find the index of each element of the original array in count array, and place the elements in output array
    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    // Copy the sorted elements into original array
    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
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
    counting_sort(a,n);
    printf("\n After sorting elements are :\n");
    display(a,n);
}
