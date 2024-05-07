#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int size;
}use;
//We made the structure

int main()
{
    use* e1=(use*) malloc(sizeof(use*));

    printf("Enter the size of array\n");
    scanf("%d",&e1->size);
    int arr1[e1->size],arr2[e1->size];
    //arrays created

    int c=0;

    printf("Enter the elements of the array\n");
    for(int i=0;i<e1->size;i++)
    {
        scanf("%d",&arr1[i]);
    }
    //we got the elements of the array

    int *ptr1=arr1;
    //first pointer created for array1

    for(int i=e1->size-1;i>=0;i--)
    {
        arr2[c]=*(ptr1+i);
        c++;
    }

    int *ptr2=arr2;
    //second pointer created for array 2

    printf("\nFirst Array:\n");
    for(int i=0;i<e1->size;i++)
    {
        printf("%d\t",*(ptr1+i));
    }
    
    printf("\nSecond Array:\n");
    for(int i=0;i<e1->size;i++)
    {
        printf("%d\t",*(ptr2+i));
    }
    //now the two arrays are printed


    return 0;
}