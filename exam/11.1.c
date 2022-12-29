 Read the data from file 'cities.txt' containing names of cities and their STD codes. Accept a name of the city from user and use sentinel linear search algorithm to check whether the name is present in the file and output the STD code, otherwise output “city not in the list”.

Solution: 

#include<stdio.h>
#include<string.h>
typedef struct city
{
    char name[20];
    int code;
}record;
record city[100];
int read_file(record *a)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("cities.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s%d",a[i].name,&a[i].code);
            i++;
        }
    }
    return (i-1);
}
void sentinelSearch(record *arr, int n, char x[20])
{
    char last[20];
    int i,flag=0;
    strcpy(last, arr[n-1].name);
    strcpy(arr[n-1].name, x);
    for(i=0;i<n;i++)
    {
        if(strcmp(arr[i].name,x)==0)
        {
            flag=1;
            break;
        }
    }
    strcpy(arr[n-1].name, last);  
    if (flag==1&&i!=n-1)
        printf("\n%s=%d\n",arr[i].name,arr[i].code);
    else
        printf("\n%s City not in the list\n",x);
}
main()
{
    char x[20];
    int n;
    n=read_file(city);
    printf("\nEnter city name\n");
    gets(x);
    sentinelSearch(city,n,x);
}

File:

cities.txt
