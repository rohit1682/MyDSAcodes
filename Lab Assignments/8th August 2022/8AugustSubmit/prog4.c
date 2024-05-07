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
        //for next data
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
    return count; //returning the no. of nodes
}
//end of count_node method

void palindrome(NODE start)
{
    //this method checks for palindromic list

    int count=count_node(start);
    int count2=1;

    int flag=0;

    NODE ptr=start;
    while(count2<=(count/2))
    {
         
        NODE ptr2=start;
        for(int i=0;i<=count-(count2+1);i++)
        {
            ptr2=ptr2->next;
        }
        if(ptr->data!=ptr2->data)
        {
            flag=1;
            break;
        }
        count2++;
        ptr=ptr->next;
    }//this is the logic

    if(flag==1)
    {
        printf("\nNOT PALINDROME\n");
    }
    else
    {
        printf("\nPALINDROME\n");
    }
    //this was the final check for palindromic list
}
//end of search method

int main()
{
    //this is the main execution method which controls the flow of execution

    NODE start=NULL;

    start=create(start);  //this is the node creation method

    palindrome(start);  //this is the palindrome check method

    return 0;
}
//end of main method

