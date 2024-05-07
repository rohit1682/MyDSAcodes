#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int size;
}use;

//we made the structure


int main()
{
    use* e1=(use*) malloc(sizeof(use*));

    printf("\nEnter the size of the array\n");
    scanf("%d",&e1->size);

    int arr[e1->size];

    printf("\nEnter the elements of the array\n");
    for(int i=0;i<e1->size;i++)
    {
        scanf("%d",&arr[i]);
    }

    int *ptr=arr;
    //we created the pointer

    for(int i=0;i<e1->size;i++)
    {
        for(int j=i+1;j<e1->size;j++)
        {
            if(*(ptr+i)%2!=0)
            {
                int temp=*(ptr+j);
                *(ptr+j)=*(ptr+i);
                *(ptr+i)=temp;
            }
        }
    }   
    //array is sorted

    printf("\n");
    for(int i=0;i<e1->size;i++)
    {
        printf("%d\t",*(ptr+i));
    }
    //array printed

   

    return 0;
}
//end of main method
