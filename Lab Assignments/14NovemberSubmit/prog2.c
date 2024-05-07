/*

    Compare two Binary Search Tree are Exact their mirror tree or not.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
//packages imported

typedef struct node
{
    //this is the structure

    struct node *rchild;
    int data;
    struct node *lchild;

}*NODE;
//we made the structure

NODE rinsert(NODE root,int item)
{
    //this is a insert function

    NODE new_node=(NODE)malloc(sizeof(NODE));

    new_node->data=item;
    new_node->lchild=NULL;
    new_node->rchild=NULL;

    if(root==NULL)
    {
        root=new_node;
    }

    else if(item<=root->data)
    {
        root->lchild=rinsert(root->lchild,item);
    }

    else
    {
        root->rchild=rinsert(root->rchild,item);
    }

    return root;
}
//end of recurssive method insert function

int recurrsion_check(NODE root1,NODE root2)
{
    //this is a check function

    if(root1!=NULL||root2!=NULL)
    {

        if(root1->data!=root2->data)
        {
            return 0;
        }

        else
        {
            recurrsion_check(root1->lchild,root2->rchild);
            recurrsion_check(root1->rchild,root2->lchild);
        }

    }

    return 1;
}
//end of recurssive check function

int main()
{
    //main execution function

    NODE root1=NULL;
    NODE root2=NULL;

    printf("\nFOR FIRST TREE\n");

    for(;;)
    {

        printf("\n\n :: THE MENU ::\n\n");
        printf("\n1. Insert\n");
        printf("2. EXIT\n");
        printf("\n\nEnter Your Choice\n");

        int response;
        scanf("%d",&response);

        switch(response)
        {
            case 1:

                int item;
                printf("\nEnter the Item to be inserted.\n");
                scanf("%d",&item);
                
                root1=rinsert(root1,item);

            break;

            case 2:

                goto label1;

            break;

            default:

                printf("\nWrong Choice! Try Again. \n");

            break;
        }
    }

    label1: //label 1 declared

    printf("\nFOR SECOND TREE\n");

    for(;;)
    {

        printf("\n\n :: THE MENU ::\n\n");
        printf("\n1. Insert\n");
        printf("2. EXIT\n");
        printf("\n\nEnter Your Choice\n");

        int response;
        scanf("%d",&response);

        switch(response)
        {
            case 1:

                int item;
                printf("\nEnter the Item to be inserted.\n");
                scanf("%d",&item);
                
                root2=rinsert(root2,item);

            break;

            case 2:

                goto label2;

            break;

            default:

                printf("\nWrong Choice! Try Again. \n");

            break;
        }
    }

    label2: //label 2 declared

    int response=recurrsion_check(root1,root2);

    if(response==1)
    {
        printf("\nBoth The Trees are their mirror tree.\n");
    }
    else
    {
        printf("\nBoth The Trees are not their mirror tree.\n");
    }

    return 0;
}
//end of main method
