Read the data from the file “employee.txt” and sort on names in alphabetical order (use strcmp) using Insertion sort.

Solution: 

#include<stdio.h>
typedef struct employee
{
    char name[10];
    int age;
    long int salary;
}RECORD;
RECORD employee[100];
int readfile(RECORD *a)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("employee.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
       fscanf(fp,"%s%d%ld",a[i].name,&a[i].age,&a[i].salary);
            i++;
        }
    }
    return(i-1);
}
void writefile(RECORD *a,int n)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("sorted_employee_age.txt","w"))!=NULL)
    {
        for(i=0;i<n;i++)
           fprintf(fp,"%s\t%d\t%ld\n",a[i].name,a[i].age,a[i].salary);
   }
}
void insertionSort(RECORD *a,int n)
{
    int i,j;
    RECORD t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0 && (strcmp(a[j].name,t.name)>=0);j--)
        {
            a[j+1]=a[j];
            a[j]=t;
        }
    }
    printf("\nSorting Done!\n");
}
main()
{
    int n;
    n=readfile(employee);
    insertionSort(employee,n);
    writefile(employee,n);
}
/*Read the data from the file “employee.txt” and sort on names in alphabetical order (use strcmp) using Selection sort.

Solution: 

#include<stdio.h>
typedef struct employee
{
    char name[10];
    int age;
    long int salary;
}RECORD;
RECORD employee[100];
int readfile(RECORD *a)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("employee.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
       fscanf(fp,"%s%d%ld",a[i].name,&a[i].age,&a[i].salary);
            i++;
        }
    }
    return(i-1);
}
void writefile(RECORD *a,int n)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("sorted_employee_age.txt","w"))!=NULL)
    {
        for(i=0;i<n;i++)
           fprintf(fp,"%s\t%d\t%ld\n",a[i].name,a[i].age,a[i].salary);
   }
}
void selectionSort(RECORD *a, int n)
{
    int i, j, min_idx;
    RECORD t;
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (strcmp(a[min_idx].name,a[j].name)>=0)
            min_idx = j;
        }
         // Swap the found minimum element with the first element
        if(min_idx!=i)
        {
            t=a[i];
            a[i]=a[min_idx];
            a[min_idx]=t;
        }
    }
    printf("\nSorting Done!\n");
}
main()
{
    int n;
    n=readfile(employee);
    selectionSort(employee,n);
    writefile(employee,n);
}*/
