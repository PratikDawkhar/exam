 Create a random array of n integers. Accept a value x from user and use linear search algorithm to check whether the number is present in the array or not and output the position if the number is present.

Solution:

#include<stdio.h>
int linear_search(int *a,int n,int ele)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==ele)
            return i;
    }
    return -1;
}
void generate(int *a, int n)
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
    int a[20],i,j,n,x,ans;
    printf("\n Enter how many elemants:");
    scanf("%d",&n);
    generate(a,n);
    printf("\n Elements are:\n");
    display(a,n);
    printf("\n Enter searching element : ");
    scanf("%d",&x);
    ans=linear_search(a,n,x);
    if(ans==-1)
        printf("\n %d is NOT found.",x);
    else
        printf("\n %d is found at %d position\n",x,ans+1);         
}
