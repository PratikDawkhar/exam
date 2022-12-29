Read the data from file ‘sortedcities.txt’ containing sorted names of cities and their STD codes. Accept a name of the city from user and use binary search algorithm to check whether the name is present in the file and output the STD code, otherwise output “city not in the list”.

Solution: 

#include<stdio.h>
#include<string.h>
typedef struct city
{
    char name[30];
    int code;
}record;
record city[100];
int read_file(record *arr)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("sortedcities.txt","r"))!=NULL)
    while(!feof(fp))
    {
        fscanf(fp,"%s%d",arr[i].name,&arr[i].code);
        i++;
    }
    return (i-1);
}
void binarysearch(record *arr,int n,char key[20])
{
    int l,h,mid;
    l=0;
    h=n-1;
    while(h>=l)
    {
        mid=(l+h)/2;
        if(strcmp(key,arr[mid].name)==0)
        {
            printf("\nSTD code:%d\n ",arr[mid].code);
            break;
        }
        else if(strcmp(key,arr[mid].name)<0)
            h=mid-1;
        else
            l=mid+1;
    }
    if(h<l)
        printf("\n%s city not in list\n",key);
}
main()
{
    char key[20];
    int n,m;
    n=read_file(city);
    printf("\nEnter city name\n");
    scanf("%s",key);
    binarysearch(city,n,key);
}


