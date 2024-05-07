#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int max,size;
}use;
//We made the structure
int main()
{
    use* e1=(use*) malloc(sizeof(use*));
    printf("Enter the size of array\n");
    scanf("%d",&e1->size);
    int arr[e1->size];
    printf("Enter the elements of the array\n");
    for(int i=0;i<e1->size;i++)
    {
        scanf("%d",&arr[i]);
    }
    //elements of the array is stored now
    int *ptr=arr;
    //pointer created
    e1->max=-1;
    //this variable finds the next greatest element
    printf("\nElement\t\tNGE \n\n");
    for(int i=0;i<e1->size;i++)
    {
        for(int j=i;j<e1->size;j++)
        {
            e1->max=-1;
            if(*(ptr+i)<*(ptr+j))
            {
                e1->max=*(ptr+j);
                break;
            }
        } 
        printf("   %d\t\t%d\n",*(ptr+i),e1->max);
        //we got all the desired next greatest elements
    }
    
    return 0;
}