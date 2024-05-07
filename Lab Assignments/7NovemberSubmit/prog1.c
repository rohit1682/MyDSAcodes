/*

    BINARY SEARCH TREE and display only in post order

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
    
    struct node *lchild;
    int data;
    struct node *rchild;

}*NODE;
//we made the structure

NODE rinsert(NODE root,int item)
{

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
//end of recurssive insert method

void nrpostorder(NODE root)
{
    //this is a display function

    printf("\n\n");

    NODE stack[100];

	NODE ptr=root;
    NODE last_visited= NULL;

	int top=-1;

	do
	{
	    while(ptr!=NULL&&ptr!=last_visited)
	    {
		    stack[++top]=ptr;
		    ptr=ptr->lchild;
	    }

	    if(top!=-1)
	    {
		    ptr=stack[top--];

		    if(ptr->rchild==NULL||ptr->rchild==last_visited)
            {
                printf("%d\t",ptr->data);
                last_visited=ptr;
            }

            else
            {
                stack[++top]=ptr;
		        ptr=ptr->rchild;
            }
	    }

        else
        {
            break;
        }
	}
    while(top!=-1|| ptr!=NULL);

    //return;
}
//end of non recurssive postorder display method

int main()
{
    //main execution function
    
    NODE root=NULL;

    for(;;)
    {
        
        printf("\n\n :: THE MENU ::\n\n");
        printf("\n1. Insert\n");
        printf("2. Display POST ORDER\n");
        printf("3. EXIT\n");
        printf("\n\nEnter Your Choice\n");
        
        int response;
        scanf("%d",&response);

        switch(response)
        {
            case 1:

                int item;
                printf("\nEnter the Item to be inserted.\n");
                scanf("%d",&item);
                
                root=rinsert(root,item);

            break;

            case 2:

                nrpostorder(root);

            break;

            case 3:

                exit(0);

            break;

            default:

                printf("\nWrong Choice! Try Again. \n");

            break;
        }
        
    }

    return 0;
}
//end of main method
