 There are lists where insertion should ensure the ordering of data elements. Since the elements are in ascending order the search can terminate once equal or greater element is found. Implement a singly linked list of ordered integers(ascending/descending) with insert, search and display operations.

Solution:
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* getNode(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct node *Insert(struct node *head, struct node* newNode)
{
    struct node* current;
    if (head == NULL)
        head = newNode;
    else if (head->data >= newNode->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        current=head;
        while(current->next != NULL&&current->next->data<newNode->data)
            current = current->next;
        newNode->next = current->next;       
        current->next = newNode;
    }
    return(head);
}
void search(struct node *head, int item)  
{  
    struct node *ptr;  
    int i=1,flag=0;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                flag=1;  
                break;  
            }   
            else if(ptr->data>item)
            {  
                flag=0;
                break;
            }  
            i++;  
            ptr = ptr->next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem %d is found at location %d ",item,i);   
        }
        else
            printf("\nItem %d not found\n", item);
    }           
}  
void Display(struct node* head)
{
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("\t %d",temp->data);
        temp = temp->next;
    }
}
main()
{
    int n,ch;
    struct node *head=NULL;
    struct node *new_node;
    do
    {
        printf("\n\n1.Insert into link list \n2.Dispaly \n3.Search into link list \n0.exit ");
        printf("\n \n Enter Your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :printf("\n Enter to Insert :");
                    scanf("%d",&n);
                    new_node = getNode(n);
                    head =Insert(head, new_node);     
                    break;
            case 2 :Display(head);
                    break;
            case 3 :printf("\n Enter the data to search");
                    scanf("%d",&n);
                    search(head,n);
                    break;
            case 0 :exit(0);
            default : printf("\n Invalid choice");
        }
    }while(ch!=0);
}
