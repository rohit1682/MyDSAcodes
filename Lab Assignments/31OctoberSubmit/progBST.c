/*

    BINARY SEARCH TREE [Recurssive Method]

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

/*
NODE nrinsert(NODE root)
{
    //this is the insert function

    NODE new_node=(NODE)malloc(sizeof(NODE)); // new node created
    new_node->lchild=NULL;
    new_node->rchild=NULL;

    if(new_node==NULL)
    {
        printf("\nTree Overflow\n");
        exit(0);
    }

    int item;

    printf("\nEnter the Item to be Inserted\n");
    scanf("%d",&item);

    new_node->data=item;

    if(root==NULL)
    {
        root=new_node;
    }

    else
    {
        NODE ptr=root;

        while(ptr!=NULL)
        {
            if(item<=ptr->data)
            {
                if(ptr->lchild!=NULL)
                {
                    ptr=ptr->lchild;
                }
                else
                {
                    ptr->lchild=new_node;
                    break;
                }
            }

            else
            {
                if(ptr->rchild!=NULL)
                {
                    ptr=ptr->rchild;
                }
                else
                {
                    ptr->rchild=new_node;
                    break;
                }
            }
        }
    }

    return root;
}
//end of non recurssive insert function
*/

void rpreorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        rpreorder(root->lchild);
        rpreorder(root->rchild);
    }
    return;
}
//end of recurssive prefix display function

void rinorder(NODE root)
{
    if(root!=NULL)
    {
        rinorder(root->lchild);
        printf("%d\t",root->data);
        rinorder(root->rchild);
    }
    return;
}
//end of recurssive infix display function

void rpostorder(NODE root)
{
    if(root!=NULL)
    {
        rpostorder(root->lchild);
        rpostorder(root->rchild);
        printf("%d\t",root->data);
    }
    return;
}
//end of recurssive postfix display function

void recurrsiveDisplay(NODE root)
{
    //this is a display function for recurssive format

    printf("\n1. Prefix Notation\n");
    printf("2. Infix Notation\n");
    printf("3. Postfix Notation \n");
    printf("\n\nEnter Your Choice\n");

    int response;
    scanf("%d",&response);

    switch(response)
    {
        case 1:

            printf("\n");
            rpreorder(root);
            printf("\n");

        break;

        case 2:

            printf("\n");
            rinorder(root);
            printf("\n");

        break;

        case 3:

            printf("\n");
            rpostorder(root);
            printf("\n");

        break;

        default:

            printf("\nWrong Choice! Try Again\n");

        break;


    }
}
//end of recurssive display menu method

void nrpreorder(NODE root)
{	
    NODE stack[100];

	NODE ptr=root;
	
	int top=-1;

	do
    {
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			stack[++top]=ptr;
			ptr=ptr->lchild;
		}

		if(top!=-1)
		{
			ptr=stack[top--];
			ptr=ptr->rchild;
		}

	}
    while(top!=-1||ptr!=NULL);

    return;
     
}
//end of non recurssive preorder display method

void nrinorder(NODE root)
{
    NODE stack[100];

	NODE ptr=root;

	int top=-1;

	do
	{
	    while(ptr!=NULL)
	    {
		    stack[++top]=ptr;
		    ptr=ptr->lchild;
	    }

	    if(top!=-1)
	    {
		    ptr=stack[top--];
		    printf("%d\t",ptr->data);
		    ptr=ptr->rchild;
	    }
	}
    while(top!=-1|| ptr!=NULL);

    return;
}
//end of non recurssive inorder display method


void nrpostorder(NODE root)
{
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
	}
    while(top!=-1|| ptr!=NULL);

    return;
}
//end of non recurssive postorder display method


void nonRecurrsiveDisplay(NODE root)
{
    //this is a display function for non recurssive format

    printf("\n1. Prefix Notation\n");
    printf("2. Infix Notation\n");
    printf("3. Postfix Notation \n");
    printf("\n\nEnter Your Choice\n");

    int response;
    scanf("%d",&response);

    switch(response)
    {
        case 1:

            printf("\n");
            nrpreorder(root);
            printf("\n");

        break;

        case 2:

            printf("\n");
            nrinorder(root);
            printf("\n");

        break;

        case 3:
         
            printf("\n");
            nrpostorder(root);
            printf("\n");

        break;

        default:

            printf("\nWrong Choice! Try Again\n");

        break;

    }
}
//end of non recurssive display method

void display(NODE root)
{

    printf("\n1. Recurssive\n");
    printf("2. Non Recurssive\n");
    printf("3. Main Menu\n");
    printf("\n\nEnter Your Choice\n");

    int response;
    scanf("%d",&response);

    switch(response)
    {
        case 1:

            printf("\n");
            nonRecurrsiveDisplay(root);
            printf("\n");

        break;

        case 2:

            printf("\n");
            recurrsiveDisplay(root);
            printf("\n");

        break;

        case 3:

            //going to the main menu

        break;

        default:

            printf("\nWrong Choice! Try Again\n");

        break;

    }

}

int main()
{
    //main execution function
    
    NODE root=NULL;

    for(;;)
    {
        
        printf("\n1. Insert\n");
        printf("2. Display\n");
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

                display(root);

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
