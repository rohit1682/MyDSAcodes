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

NODE create(NODE start)
{
    //this method creates a new node

    NODE new_node;
    int data;
    printf("\nEnter the data. If entered -1, list is complete \n");
    scanf("%d",&data);
    while(data!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node*));
        new_node->data=data;

        if(start==NULL)
        {
            //this is for empty list

            start=new_node;
            new_node->next=NULL;
        }
        else //making it the first node
        {
            //here the nodes are inserted from the first

            new_node->next=start;
            start=new_node;
        }
        printf("\nEnter the data. If entered -1, list is complete \n");
        scanf("%d",&data);
    }
    return start;
}
//end of creating node method

void display(NODE start)
{
    //this method displays the list

    NODE ptr;
    ptr=start;

    int count=1;

    printf("\nThe List:\n");
    
    while(ptr!=NULL)
    {
        printf("%d. %d\n",count,ptr->data);
        ptr=ptr->next;
        count++;
    }
    //list is displayed
    printf("\n");
}
//end of diaplay method

int count_node(NODE start)
{
    //here the number of nodes are counted

    NODE ptr=start;
    int count=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    return count;
}
//end of count_node method

NODE insert(NODE start,int data)
{
    //this method inserts an item entered by the user

    NODE new_node;
    new_node=(struct node*)malloc(sizeof(struct node*));
    new_node->data=data;

    if(new_node==NULL)
    {
        printf("\nMemory Overflow\n");
        exit(0);
    }
    //overflow condition checked

    label:
    //label created

    int pos;
    printf("\nEnter the Position\n");
    scanf("%d",&pos);

    if(pos==1||start==NULL)
    {
        new_node->next=start;
        start=new_node;
        //this condition is for first position or empty list
    }
    
    else 
    {
        int count = count_node(start);

        if(pos==count+1)
        {
            //this is for last position 

            NODE ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }

        else if(pos>count+1||pos<1)
        {
            //this is for invalid position

            printf("\nInvalid Position!! Try again\n");
            goto label;
        }

        else
        {
            //this is for a valid position between the first and last position
           
            NODE ptr=start;
            int i=0;
            while(i!=pos-1)
            {
                ptr=ptr->next;
                i++;
            }
            new_node->next=ptr->next;
            ptr->next=new_node;
        }
    }
    
    display(start);

    return start;
}
//end of insert method

NODE deleteByData(NODE start,int data)
{
    //this method deletes an item entered by the user

    if(start==NULL)
    {
        printf("\nUnderflow of List\n");
        exit(0);
    }
    //underflow condition is checked

    NODE ptr=start;
    NODE ptr2=NULL;
    int flag=0;
    while(ptr->next!=NULL)
    {
        if(ptr->data==data)
        {
            //first node
            if(ptr==start)
            {
                start=ptr->next;
            }

            //logic for interim delete
            else 
            {
                ptr2->next=ptr->next;
            }

            flag=1;
            break;

        }

        else
        {
            ptr2=ptr;
            ptr=ptr->next;
        }

        // logic for last node deletion
        if(ptr->data==data)
        {
            ptr2->next=NULL;
            flag=1;
        }
       
    }

    if(flag==1)
    {
        display(start);
    }
    else
    {
        printf("Item Not Found!! Try Again!!");
    }

  return start;  
    
}
//end of delete method

void search(NODE start,int data)
{
    //this method searches an item entered by the user

    NODE ptr=start;
    int flag=0;//flag variable to check the variable found or not

    while(ptr!=NULL)
    {

        if(ptr->data==data)
        {
            flag=1;
            break;
            //flag is updated to 1 for getting the item in the list
        }
        
        else
        {
            ptr=ptr->next;
        }
    }

    if(flag==0)
    {
        printf("\nItem Not Found\n");
    }
    else 
    {
        printf("\nItem Found\n");
    }
    //appropriate message is shown
}
//end of search method


int main()
{
    //this is the main execution method which controls the flow of execution

    NODE start=NULL;
    //main execution function

    for(;;)//this is an infinite for loop
    {
        label:

        int data;

        printf("\n1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("\nEnter Your Choice\n\n");
        //here the menu is displayed
    
        int response;
        scanf("%d",&response);

        switch (response)
        {
            case 1:
                start=create(start);
                break;
            case 2:
                printf("\nEnter the Data\n");
                scanf("%d",&data);
                start=insert(start,data);
                break;    
            case 3:
                printf("\nEnter the Data to be deleted\n");
                scanf("%d",&data);
                start=deleteByData(start,data);
                break;
            case 4:
                printf("\nEnter the Data to be searched\n");
                scanf("%d",&data);
                search(start,data);
                break;
            case 5:
                display(start);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nWRONG INPUT!! TRY AGAIN\n");
                goto label;
                break;
        }
        //this is the switch case
    }

    return 0;
}
//end of main method
