#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int a,b,size,count;
}use;
//We made the structure
int main()
{
    use* e1=(use*) malloc(sizeof(use*));
    printf("\nEnter the size of array\n");
    scanf("%d",&e1->size);
    int arr[e1->size];
    //array created
    printf("\nEnter the elements of the array\n");
    for(int i=0;i<e1->size;i++)
    {
        scanf("%d",&arr[i]);
    }
    //got the elements of the array
    int *ptr=arr;
    printf("\nEnter the two elements\n");
    scanf("%d",&e1->a);
    scanf("%d",&e1->b);
    //got the two boundaries
    
    e1->count=0;
    //we will get the count by this

    printf("\nThe elements are: \n");
    for(int i=0;i<e1->size;i++)
    {
        if(*(ptr+i)==e1->a)
        {
            for(int j=i;j<=e1->size;j++)
            {
                printf("%d\t",*(ptr+j));
                e1->count++;
                //printed the required elements and count is updated
                if(*(ptr+j)==e1->b)
                {
                    break;
                }
            }
        }
    }
    //operation done

    int flag=0;
    for(int i=0;i<e1->size;i++)
    {
        if(*(ptr+i)==e1->b)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        e1->count=0;
    }
    printf("\nThe Count: %d\n",e1->count);
    
    return 0;
}