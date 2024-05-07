/*

Find the middle node of a linked list by traversing it only once

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

NODE create(NODE start)
{
    //this method creates a new node

    printf("\n");

    NODE new_node;
    int data;
    printf("\nEnter the data. If entered -999, list is complete \n");
    scanf("%d",&data);
    while(data!=-999)
    {
        new_node=(NODE)malloc(sizeof(NODE));
        new_node->data=data;

        if(start==NULL)
        {
            //this is for empty list

            start=new_node;
            new_node->next=NULL;
        }
        else //making it the first node
        {
            //here the nodes are inserted from the last

            NODE ptr=start;

            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }

            new_node->next=NULL;
            ptr->next=new_node;

        }
        printf("\nEnter the data. If entered -999, list is complete \n");
        scanf("%d",&data);
    }

    return start;

}
//end of create function

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

void find(NODE start)
{
    //this method finds the middle node of the list

    int count=count_node(start);

    if(count%2==0)
    {
        NODE ssptr=start;
        NODE sptr=start;
        NODE fptr=start;

        while(fptr!=NULL)
        {
            ssptr=sptr;
            sptr=sptr->next;
            fptr=fptr->next->next;
        }

        printf("\nthe Middle Node of the List: %d\n",ssptr->data);

    }

    else
    {
        NODE sptr=start;
        NODE fptr=start;

        while(fptr->next!=NULL)
        {
            sptr=sptr->next;
            fptr=fptr->next->next;
        }

        printf("\nthe Middle Node of the List: %d\n",sptr->data);
    } 

}
//end of find method

int main()
{
    //main execution function
    
    NODE start=NULL;

    printf("\n\nEnter the Linked List: \n");
    start=create(start);

    find(start);

    return 0;
}
//end of main method
