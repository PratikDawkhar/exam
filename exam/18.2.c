 Write a program that multiply two single variable polynomials. Each polynomial should be represented as a list with linked list implementation.

Solution:
#include<stdio.h> 
#include<stdlib.h>
struct Polynode
{
    int coeff, power;
    struct Polynode* next;
};
struct Polynode * append(struct Polynode* poly, int coeff, int power)
{
    struct Polynode* ptr;
    struct Polynode* newnode = (struct Polynode*)malloc(sizeof(struct Polynode));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    if (poly == NULL)
        return newnode;
    ptr = poly;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
    return poly;
}

void Display(struct Polynode* poly)
{
    struct Polynode *ptr=poly;
    while (ptr->next!= NULL)
    {
        printf(" %dx^%d ",ptr->coeff,ptr->power);
        if( ptr->next!=NULL && ptr->next->coeff >=0)
          printf("+");
        ptr = ptr->next;
    }
    printf("%d \n",ptr->coeff);
}
void removeDuplicates(struct Polynode* poly)
{
    struct Polynode *ptr1, *ptr2, *dup;
    ptr1 = poly;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->power == ptr2->next->power)
            {
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                 free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
struct Polynode* multiply(struct Polynode* poly1, struct Polynode* poly2,struct Polynode* poly3)
{
    struct Polynode *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            int coeff, power;
            coeff = ptr1->coeff * ptr2->coeff;
            power = ptr1->power + ptr2->power;
            poly3 = append(poly3, coeff, power);
            ptr2 = ptr2->next;
        }
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
    removeDuplicates(poly3);
    return poly3;
}
int main()
{
    char ch;
    int coef, pow;
    struct Polynode *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    printf("\nEnter 1st Polynomial :");
    do
    {
        printf("\nEnter coeff:");
        scanf("%d",&coef);
        printf("\nEnter power:");
        scanf("%d",&pow);
        poly1=append(poly1,coef,pow);
        printf("\n To Continue(y/n):");
        ch=getch();
    }while(ch=='y' || ch=='Y');
    printf("\nEnter 2nd Polynomial :");
    do
    {
        printf("\nEnter coeff:");
        scanf("%d",&coef);
        printf("\nEnter power:");
        scanf("%d",&pow);
        poly2=append(poly2,coef,pow);
        printf("\nTo Continue(y/n):");
        ch=getch();
    }while(ch=='y' || ch=='Y');
       
    printf("1st Polynomial:- ");
    Display(poly1);
 
    printf("2nd Polynomial:- ");
    Display(poly2);
 
    poly3 = multiply(poly1, poly2, poly3);
 
    printf("Resultant Polynomial:- ");
    Display(poly3);
 
    return 0;
}
