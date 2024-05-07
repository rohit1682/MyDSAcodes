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

        NODE new_node;
        new_node=(struct node*)malloc(sizeof(struct node*));
        //node created for main list

        new_node->data=data;

        if(start==NULL)
        {
            start=new_node;
            new_node->next=NULL;
        }

        else
        {
            NODE ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }   
            ptr->next=new_node;
            new_node->next=NULL;
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

    NODE last=NULL;

    printf("\nThe List in reverse order:\n");
        
    while(last!=start)
    {
        NODE ptr=start;
        while(ptr->next!=last)
        {
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
        last=ptr;
    }

    //list is displayed

    printf("\n");
}
//end of diaplay method

int main()
{
    //this is the main execution method which controls the flow of execution

    NODE start=NULL;
    //main execution function

    start=create(start);
    display(start);
    
    return 0;
}
//end of main method
