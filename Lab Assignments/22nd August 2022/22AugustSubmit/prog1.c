/*

Circular Double linked List Operations

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
}*NODE;

NODE create(NODE start)
{
    NODE new_node;
    if(new_node==NULL)
    {
        printf("\nOverflow\n");
        exit(0);
    }
    else
    {
        int x;
        printf("\nEnter The Data. Enter -999 to Exit\n");
        scanf("%d",&x);
        while(x!=-999)
        {
            new_node=(NODE)malloc(sizeof(NODE));
            new_node->data=x;
            if(start==NULL)
            {
                start= new_node;
                new_node->lptr=start;
                new_node->rptr=start;
            }
            else
            {
                new_node->rptr=start;
                new_node->lptr=start->lptr;
                start->lptr->rptr=new_node;
                start->lptr=new_node;
                start=new_node;
            }
            printf("\nEnter The Data. Enter -999 to Exit\n");
            scanf("%d",&x);
        }
    }
    return start;
}

int count_node(NODE start)
{
    int count=1;
    NODE ptr=start;
    
    if(ptr==NULL)
    {
        return 0;
    }
    
    do
    {
        ptr=ptr->rptr;
        count++;
        
    }while(ptr->rptr!=start);
    
    return count;
}

void display(NODE start)
{
    NODE ptr1=start;
    
    if(start==NULL)
    {
        printf("\nList Underflow\n");
        exit(0);
    }
    
    printf("\nThe list In Forward Direction\n");
    
    do
    {
        printf("%d\t",ptr1->data);
        ptr1=ptr1->rptr;
        
    }while(ptr1!=start);
    
    printf("\n");
    
}

NODE insert(NODE start)
{
    
    NODE new_node;
    new_node=(NODE)malloc(sizeof(NODE));
    
    if(new_node==NULL)
    {
        printf("\nList Overflow\n");
        exit(0);
    }
    
    int count= count_node(start);
    
    int x;
    printf("\nEnter the Data to be Inserted\n");
    scanf("%d",&x);
    
    int pos;
    printf("\nEnter the Position\n");
    scanf("%d",&pos);
    
    new_node->data=x;
    
    if(pos==1)
    {
        if(start==NULL)
        {
            start=new_node;
            new_node->rptr=new_node;
            new_node->lptr=new_node;
            
            display(start);
            
            return start;
        }
        
        new_node->lptr=start->lptr;
        new_node->rptr=start;
        start->lptr->rptr=new_node;
        start->lptr=new_node;
        start=new_node;
    }
    
    else if(pos>count+1)
    {
        printf("\nPosition Not Valid.\n");
        return start;
    }
    
    else
    {
        NODE ptr=start;
        
        int i=0;
        
        do
        {
            ptr=ptr->rptr;
            i++;
            
        }while(i<=pos-3);
        
        new_node->rptr=ptr->rptr;
        new_node->lptr=ptr;
        ptr->rptr->lptr=new_node;
        ptr->rptr=new_node;
        
    }
    
    display(start);
    
    return start;
}

NODE deletePosition(NODE start)
{
    
    if(start==NULL)
    {
        printf("\nUnderflow Of List\n");
        return start;
    }
    
    int pos;
    printf("\nEnter the Position\n");
    scanf("%d",&pos);
    
    int count=count_node(start);
    
    if(pos==1)
    {
        
        NODE ptr=start;
        start->lptr->rptr=start->rptr;
        start->rptr->lptr=start->lptr;
        start= start->rptr;
        free(ptr);
        
        if(start->rptr==start)
        {
            start=NULL;
        }
        
    }
    
    else if(pos==count)
    {
        NODE ptr=start->lptr;
        start->lptr->lptr->rptr=start;
        start->lptr=start->lptr->lptr;
        free(ptr);
        
    }
    
    else if(pos>=2&&pos<=count-1)
    {
        NODE ptr=start;
        int i=1;
        
        if(pos>count)
        {
            printf("\nInvalid Position\n");
            return start;
        }
        
        while(i<=pos-1)
        {
            ptr=ptr->rptr;
            i++;
        }
        
        ptr->lptr->rptr=ptr->rptr;
        free(ptr);
    }
    
    else
    {
        printf("\nData Not Found.\n");
    }

    return start;
}

NODE deleteData(NODE start)
{
    
    NODE ptr=start;
    
    int flag=0;
    
    if(ptr==NULL)
    {
        printf("\nUnderflow Of List\n");
        return start;
    }
    
    int item;
    printf("\nEnter the Data To be Deleted\n");
    scanf("%d",&item);
    
    do
    {
        if(ptr->data==item)
        {
            ptr->lptr->rptr=ptr->rptr;
            ptr->rptr->lptr=ptr->lptr;
            
            if(ptr==start)
            {
                start=ptr->rptr;
            }
            
            free(ptr);
            
            flag=1;
            break;
        }
        
        else
        {
            ptr=ptr->rptr;
        }
        
    }while(ptr!=start);
    
    if(flag==1)
    {
        return start;
    }
    
    else
    {
        printf("\nData Not Found\n\n");
        return start;
    }
}

NODE delete(NODE start)
{
    
    printf("\nThe Menu:\n");
    printf("1. Delete By Position\n");
    printf("2. Delete By Data\n");
    printf("\nEnter Your Choice:\n\n");

    int response;
    scanf("%d",&response);

    switch (response)
    {
        case 1:
            start=deletePosition(start);
            printf("\n");
            break;
            
        case 2:
            start=deleteData(start);
            printf("\n");
            break;
                
        default:
            printf("\nWrong Choice!! Try Again!!\n");
            break;
    }
    
    display(start);
    
    return start;
}

void traverse(NODE start)
{
    NODE ptr1=start;
    NODE ptr2=start->lptr;
    
    if(start==NULL)
    {
        printf("\nList Underflow\n");
        exit(0);
    }
    
    printf("\nThe list In Forward Direction\n");
    
    do
    {
        printf("%d\t",ptr1->data);
        ptr1=ptr1->rptr;
        
    }while(ptr1!=start);
    
    printf("\n\nThe list In Backward Direction\n");
    
    do
    {
        printf("%d\t",ptr2->data);
        ptr2=ptr2->lptr;
        
    }while(ptr2!=start->lptr);
    
    printf("\n");
}

void search(NODE start)
{
    NODE ptr=start;

    int flag=0;
    int item;
    printf("\nEnter the Data To be Searched\n");
    scanf("%d",&item);

    while(ptr->lptr!=start)
    {
        if(ptr->data=item)
        {
            flag=1;
            break;
        }
        else
        {
            ptr=ptr->rptr;
        }
    } 
    
    if(flag==1)
    {
        printf("\nItem Found\n");
    }
    else
    {
        printf("\nItem Not Found\n");
    }
}

int main()
{
    NODE start=NULL;
    
    for(;;)
    {
        
        printf("\nThe Menu:\n");
        printf("1. Create Data\n");
        printf("2. Insert New Data\n");
        printf("3. Traverse\n");
        printf("4. Delete Data\n");
        printf("5. Search For A Data\n");
        printf("6. Exit Program\n");
        printf("\nEnter Your Choice:\n\n");

        int response;
        scanf("%d",&response);

        switch (response)
        {
            case 1:
                start=create(start);
                break;
                
            case 2:
                start=insert(start);
                break;
                
            case 3:
                traverse(start);
                break;
                
            case 4:
                start=delete(start);
                break;
                
            case 5:
                search(start);
                break;
                
            case 6:
                exit(0);
                
            default:
                printf("\nWrong Choice!! Try Again!!\n");
                break;
                
        }
    }
    return 0;
}





