/*

Implementation Of Stack Using both Linked List and Arrays

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
    struct node *next;
}*NODE;
//we made the structure

void displayarr(int arr[],int top)
{
    if(top==-1)
    {
        printf("\nStack Is Empty\n");
    }

    else
    {
        printf("\nThe Stack\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",arr[i]);
        }
    }
}

void array()
{
    int size=500;
    int arr[size];
    int top=-1;

    int response;

    do
    {
        printf("\n\n\tStack Using Array\n");
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. Display\n");
        printf("\nEnter 0 to Stop\n");
        printf("\n\nEnter Your Choice\n");

        scanf("%d",&response);

        if(response==1)
        {
            int item;
            printf("\nEnter The Item To be Inserted\n");
            scanf("%d",&item);

            if(top==size-1)
            {
                printf("\nStack Is Full\n");
            }

            else
            {
                if(top==-1)
                {
                    top=0;
                }

                else
                {
                    top=top+1;
                }
                arr[top]=item;
            }
        }

        else if(response==2)
        {

            if(top!=-1)
            {
                int temp=arr[top];
                if(top==0)
                {
                    top=-1;
                }
                else
                {
                    top=top-1;
                }

                printf("\n%d is Deleted\n",temp);
            }
            
            else
            {
                printf("\nStack is Empty\n");
            }
            
        }

        else if(response==3)
        {
            displayarr(arr,top);
        }

    }while(response!=0);

}

void displayll(NODE start)
{

    if(start==NULL)
    {
        printf("\nStack Empty\n");
    }

    else
    {
        NODE ptr=start;
        
        printf("\n\n\tThe List\n\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }

}

NODE pushll(NODE start)
{
    printf("\nEnter the Item to be Inserted\n");
    int item;
    scanf("%d",&item);
    printf("\nhello\n");
    

    NODE new_node;
    new_node=(NODE)malloc(sizeof(NODE));

    if(new_node==NULL)
    {
        printf("\nStack Overflow\n");
        exit(0);
    }

    new_node->data=item;
    new_node->next=NULL;
    
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
        new_node->next=start;
        start=new_node;
    }

    displayll(start);

    return start;
}

NODE popll(NODE start)
{
    if(start==NULL)
    {
        printf("\nStack Underflow\n");
    }

    else
    {
        if(start->next==NULL)
        {
            start=NULL;
        }

        else
        {
            NODE ptr=start;
            start=start->next;
            free(ptr);
        }
    }

    displayll(start);

    return start;
}

void linkList()
{
    NODE start=NULL;
    int response;

    for(;;)
    {
        printf("\n\n\tStack Using Linked List\n");
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. Display\n");
        printf("\nEnter 0 to Stop\n");
        printf("\n\nEnter Your Choice\n");

        scanf("%d",&response);

        switch (response)
        {
            case 0:
                exit(0);
                break;

            case 1:
                start=pushll(start);
                break;

            case 2:
                start=popll(start);
                break;

            case 3:
                displayll(start);
                break;

            default:
                printf("\nWrong Choice\n");
                break;
        }   
    }
    
}

int main()
{
    //main execution function

    printf("\n\n\tThe Menu\n");
    printf("\n1. Implementation of Stack Using Linked List\n");
    printf("\n2. Implementation of Stack Using Array\n");
    printf("\n\nEnter Your Choice\n");

    int response;
    scanf("%d",&response);

    switch (response)
    {
        case 1:
            linkList();
            break;

        case 2:
            array();
            break;

        default:
            printf("\nWrong Choice\n");
            break;
    }

    return 0;
}
//end of main method
