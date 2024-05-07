#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int size,max;
}use;

//we made the structure


int main()
{
    use* e1=(use*) malloc(sizeof(use*));

    printf("\nEnter the size of the array\n");
    scanf("%d",&e1->size);
    //we got the size of array

    int arr[e1->size];
    //array created

    printf("\nEnter the elements of the array\n");
    for(int i=0;i<e1->size;i++)
    {
        scanf("%d",&arr[i]);
    }
    //got the elements of the array

    int *ptr=arr;
    //pointer created
    e1->max=arr[0];
    //we created the variables to store max 

    for(int i=0;i<e1->size;i++)
    {
        if(e1->max<=*(ptr+i))
        {
            e1->max=*(ptr+i);
        }
    }
    //fount the max elements of the array

    for(int i=0;i<e1->size;i++)
    {
        *(ptr+i)=e1->max;
    }   
    //array updated

    printf("\nFinal Array\n");
    for(int i=0;i<e1->size;i++)
    {
        printf("%d\t",*(ptr+i));
    }
    //array printed

   

    return 0;
}
//end of main method
