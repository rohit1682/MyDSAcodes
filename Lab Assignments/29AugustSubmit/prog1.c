#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct poly
{
    int coef;
    int exp;
    struct poly *link;
}*POLY;
//we made the structure

POLY create_poly(POLY start)
{
    int choice;
    POLY new_node;
    POLY last;

    do
    {
        int coef,exp;

        new_node=(POLY)malloc(sizeof(POLY));
        printf("\nEnter the Coefficient and Exponent. Exponent must be in Decending order.\n");
        scanf("%d%d",&coef,&exp);
        new_node->link=NULL;

        if(start==NULL)
        {
            new_node->coef=coef;
            new_node->exp=exp;

            start=new_node;
            last=new_node;
        }

        else
        {
            if(exp<last->exp)
            {
                new_node->coef=coef;
                new_node->exp=exp;

                last->link=new_node;
                last=new_node;
            }

            else
            {
                printf("\nInvalid Exponent Input\n");
            }
            
        }

        printf("\nEnter 0 to Stop\n");
        scanf("%d",&choice);

    }while(choice!=0);

    return start;
}
//end of create method

POLY insert(POLY ptr,int exp,int coef)
{
    //this method creates a new polynomial with two added polynomial

    POLY new_node=(POLY)malloc(sizeof(POLY));

    if(new_node==NULL)
    {
        printf("\nOut Of Memory\n");
        exit(0);
    }

    else
    {
        new_node->exp=exp;
        new_node->coef=coef;
        new_node->link=NULL;

        if(ptr==NULL)
        {
            ptr=new_node;
        }

        else
        {
            ptr->link=new_node;
            ptr=new_node;
        }

    }
    return ptr;
}
//end of insert function

POLY poly_add(POLY start1,POLY start2)
{
    //this method adds two polynomials

    POLY ptr1=start1;
    POLY ptr2=start2;
    POLY ptr3=NULL;

    while(ptr1!=NULL||ptr2!=NULL)
    {
        
        if(ptr1->exp>ptr2->exp)
        {
            ptr3=insert(ptr3,ptr1->exp,ptr1->coef);
            ptr1=ptr1->link;
        }

        else if(ptr1->exp<ptr2->exp)
        {
            ptr3=insert(ptr3,ptr2->exp,ptr2->coef);
            ptr2=ptr2->link;
        }

        else if(ptr1->exp+ptr2->exp!=0)
        {
            ptr3=insert(ptr3,ptr1->exp,ptr1->coef+ptr2->coef);
            ptr1=ptr1->link;
            ptr2=ptr2->link;

        }
    }

    while(ptr1!=NULL)
    {
        ptr3=insert(ptr3,ptr1->exp,ptr1->coef);
        ptr1=ptr1->link;
        
    }

    while(ptr2!=NULL)
    {
        ptr3=insert(ptr3,ptr2->exp,ptr2->coef);
        ptr2=ptr2->link;
        
    }
    
    return ptr3;
}
//end of addition method

void display(POLY start)
{
    //this method displays the list passed in it

    if(start==NULL)
    {
        printf("\nPolynomial Does Not Exist\n");
    }

    else
    {
        POLY ptr=start;

        while(ptr!=NULL)
        {
            if(ptr->coef>0)
            {
                printf("+");
            }
            printf(" %d(x^%d) ",ptr->coef,ptr->exp);
            ptr=ptr->link;
        }
    }
}
//end of display method

int main()
{
    //main execution function
    
    POLY start1=NULL;
    POLY start2=NULL;

    printf("\nEnter First Polynomial\n");
    start1=create_poly(start1);

    printf("\nEnter Second Polynomial\n");
    start2=create_poly(start2);

    printf("\nFirst Polynomial:\n");
    display(start1);

    printf("\n");

    printf("\nSecond Polynomial:\n");
    display(start2);

    printf("\n");

    /*
    POLY start3=poly_add(start1,start2);
    
    printf("\nFinal Polynomial:\n");
    display(start3);
    */

    return 0;
}
//end of main method
