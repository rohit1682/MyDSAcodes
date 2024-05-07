/*

Given An Array of character formed with 'A' and 'B' only. 
The string is marked with a special character 'X' which represents the middle of the list.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node
{

    char data;
    struct node *next;

}*NODE;
//we made the structure


NODE push(NODE start,char item)
{
    NODE new_node=(NODE)malloc(sizeof(NODE));

    new_node->data=item;
    new_node->next=NULL;

    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
        NODE ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

        ptr->next=new_node;
        
    }

    return start;

}

char pop(NODE start)
{
    NODE ptr1=start;
    NODE ptr2=start;

    while(ptr1->next!=NULL)
    {
        ptr2=ptr1;
        ptr1=ptr1->next;
    }

    char item=ptr1->data;
    ptr2->next=NULL;
    free(ptr1);

    return item;

}

bool palindrome()
{

    char str[500];
    int c=0;

    printf("\nEnter the String\n");
    scanf("%s",&str);

    NODE start=NULL;
    int flag=0;
    int i;

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='X')
        {
            c=1;
            break;
        }
        else
        {
            start=push(start,str[i]);
        }
    }

    for(int j=i+1;j<strlen(str);j++)
    {
        char item=pop(start);
        if(item!=str[j])
        {
            flag=1;
            break;
        }
    }

    if(c==0)
    {
        return false;
    }

    else
    {
        if(flag==1)
        {
            return false;
        }

        else
        {
            return true;
        }
    }
    

}

int main()
{
    //main execution function

    bool response=palindrome();

    if(response==true)
    {
        printf("\nThe String is Palindrome\n");
    }

    else
    {
        printf("\nThe String is Not Palindrome\n");
    }

    return 0;
}
//end of main method
