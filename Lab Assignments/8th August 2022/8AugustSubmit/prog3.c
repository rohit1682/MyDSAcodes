#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
//all packages are imported now

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


void duplicate(NODE start)
{
    //this method searches an item entered by the user

    NODE ptr1=start;
    NODE ptr2;
    NODE ptr3;

    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        ptr3=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr2->data==ptr1->data)
            {
                ptr3->next=ptr2->next;
                ptr3=ptr2;
                ptr2=ptr2->next;

            }
            else
            {
                ptr3=ptr2;
                ptr2=ptr2->next;
            }
        }
        
        ptr1=ptr1->next;
    }
    display(start);
    
}
//end of search method


int main()
{
    //this is the main execution method which controls the flow of execution

    NODE start=NULL;
    //main execution function

    start=create(start);

    display(start);
    duplicate(start);

    return 0;
}
//end of main method
