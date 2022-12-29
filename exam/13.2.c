Write a program that sorts the elements of linked list using any of sorting technique.

Solution:
#include<stdio.h> 
#include<stdlib.h>
struct node
{  
    int data;  
    struct node *next;  
};
struct node *head, *tail = NULL;  
void append(int data)
{  
  struct node *newstruct Polynode=(struct node*) malloc (sizeof(struct node));  
    newstruct Polynode->data = data;  
    newstruct Polynode->next = NULL;  
    if(head == NULL) 
    {  
        head = newstruct Polynode;  
        tail = newstruct Polynode;  
    }  
    else
    { 
        tail->next = newstruct Polynode;  
        tail = newstruct Polynode;  
    }  
}  
void sortList()
{  
    struct node *current = head, *index = NULL;  
    int temp;  
    if(head == NULL)
    { 
        return;  
    }  
    else
    { 
        while(current != NULL)
        { 
            index = current->next;  
            while(index != NULL)
            { 
                if(current->data > index->data)
                { 
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }  
}  
void display()
{  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL)
    { 
        printf("%d->\t", current->data);  
        current = current->next;  
    }  
    printf("NULL\n");  
}     
int main()  
{  
    int n, i, data;
    printf("\nHow Many nodes You Want?\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter The Data :\t");
        scanf("%d", &data);
        append(data); 
    }
    printf("Original list: \n");  
    display();  
    //Sorting list  
    sortList();   
    printf("Sorted list: \n");  
    display();
    return 0;  
}
