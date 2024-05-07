#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int size,max,c;
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
    e1->c=0;
    //here the frequency will be stored

    for(int i=0;i<e1->size;i++)
    {
        if(e1->max<=*(ptr+i))
        {
            e1->max=*(ptr+i);
        }
    }
    //found the max element of the array

    for(int i=0;i<e1->size;i++)
    {
        if(e1->max==*(ptr+i))
        {
            e1->c++;
        }
    }
    //found thecount of the max element of the array

    printf("\nMax Element\tFrequency\n");
    printf("   %d\t\t  %d\n",e1->max,e1->c);
   

    return 0;
}
//end of main method
