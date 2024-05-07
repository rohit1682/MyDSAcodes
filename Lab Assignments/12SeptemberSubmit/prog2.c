/*

Find the Merging Point of Two Linked List

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
        printf("\nEnter the data. If entered -1, list is complete \n");
        scanf("%d",&data);
    }

    return start;

}
//end of create function

void display(NODE start)
{
    //this is the display method

    NODE ptr=start;
    
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }

}
//end of display method

void change(NODE start1,NODE start2,NODE start3)
{
    //this method will link the two linked list

    NODE ptr1=start1;
    NODE ptr2=start2;

    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
    }

    while(ptr2->next!=NULL)
    {
        ptr2=ptr2->next;
    }

    ptr1->next=start3;
    ptr2->next=start3;

}
//end of change method

int count_node(NODE start)
{
    //this method wil find the number of nodes in the list

    int count=1;
    NODE ptr=start;

    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }

    return count;

}
//end of count_node method

void find(NODE start1,NODE start2)
{
    //this will find the merging point

    int count1=count_node(start1);
    int count2=count_node(start2);
    int difference;

    NODE ptr1=start1;
    NODE ptr2=start2;

    if(count1>count2)
    {
        difference=count1-count2;

        int i=1;
        while(i<=difference)
        {
            ptr1=ptr1->next;
            i++;
        }
    }
    else if(count2>count1)
    {
        difference=count2-count1;
        
        int i=1;
        while(i<=difference)
        {
            ptr2=ptr2->next;
            i++;
        }
    }
    else
    {
        difference=0;
    }

    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->data==ptr2->data)
        {
            printf("\n\n\nThe Merging Point of the Two Linked Lists is: %d\n",ptr1->data);
            break;
        }
        else
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    
}
//end of find method

int main()
{
    //main execution function
    
    NODE start1=NULL;
    NODE start2=NULL;
    NODE start3=NULL;

    printf("\n\nEnter The First Linked List: \n");
    start1=create(start1);

    printf("\n\nEnter The Second Linked List: \n");
    start2=create(start2);

    printf("\n\nEnter The Common Part of the two Linked List: \n");
    start3=create(start3);

    change(start1,start2,start3);

    printf("\n\nThe First List: \n");
    display(start1);

    printf("\n\nThe Second List: \n");
    display(start2);

    find(start1,start2);

    return 0;
}
//end of main method
