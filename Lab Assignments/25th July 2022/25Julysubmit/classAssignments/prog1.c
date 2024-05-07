#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int min,max,size;
}use;
//We made the structure

int main()
{
    use* e1=(use*) malloc(sizeof(use*));

    printf("Enter the size of array\n");
    scanf("%d",&e1->size);
    int arr[e1->size];
    //array created

    printf("Enter the elements of the array\n");
    for(int i=0;i<e1->size;i++)
    {
        scanf("%d",&arr[i]);
    }
    //stored the elements of the array

    int *ptr=arr;
    //we created the pointer

    e1->max=arr[0];
    e1->min=arr[0];
    //we created the variables to store max and min

    for(int i=0;i<e1->size;i++)
    {
        if(e1->max<=*(ptr+i))
        {
            e1->max=*(ptr+i);
        }
        if(e1->min>=*(ptr+i))
        {
            e1->min=*(ptr+i);
        }
    }
    //fount the max and min elements of the array
    
    printf("Max: %d\n",e1->max);
    printf("Min: %d\n",e1->min);

    return 0;
}