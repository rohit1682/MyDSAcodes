/*

Reverse the linked list from 'K'th node with a given value of k.

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

NODE change(int k,NODE start)
{
    //this method reverses the linked list from the given 'K'th value

    int count=count_node(start);

    if(k>count)
    {
        printf("\nInvalid Value of K\n");
        exit(0);
    }

    int i=1;
    NODE ptr=start;
    while(i<=k)
    {
        ptr=ptr->next;
        i++;
    }

    NODE new_start=ptr;
    NODE temp=ptr->next;

    while(ptr!=start)
    {
        NODE ptr2=start;
        while(ptr2->next!=ptr)
        {
            ptr2=ptr2->next;
        }
        ptr->next=ptr2;
        ptr=ptr2;
    }

    start->next=temp;

    return new_start;

}
//end of change method

void display(NODE start)
{
    //this method displays the list

    NODE ptr;
    ptr=start;

    int count=1;

    if(start==NULL)
    {
        printf("\nLIST IS EMPTY\n");

        //for empty list
    }

    else
    {
        printf("\nThe List:\n");
    
        while(ptr!=NULL)
        {
            printf("%d. %d\n",count,ptr->data);
            ptr=ptr->next;
            count++;
        }
        //list is displayed
    }

    printf("\n");
}
//end of diaplay method

int main()
{
    //main execution function
    
    NODE start=NULL;

    printf("\n\nEnter the Linked List: \n");
    start=create(start);

    printf("\nEnter the Value Of K\n");
    int k;
    scanf("%d",&k);

    start=change(k,start);

    printf("\nThe Final List:\n");
    display(start);

    return 0;
}
//end of main method
