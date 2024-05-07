#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int realnum1;
    int imgnum1;
    int realnum2;
    int imgnum2;
    int realsum,imgsum;
    int realdifference,imgdifference;
}numbers;
int main()
{
    numbers* n=(numbers*) malloc(sizeof(numbers));
    printf("Enter the real and imaginary part of Number1\n");
    scanf("%d",&n->realnum1);
    scanf("%d",&n->imgnum1);
    printf("Enter the real and imaginary part of Number2\n");
    scanf("%d",&n->realnum2);
    scanf("%d",&n->imgnum2);

    /*Inputs Taken*/
    
    n->realsum=n->realnum1+n->realnum2;
    n->imgsum=n->imgnum1+n->imgnum2;
    if(n->realnum1>=n->realnum2)
    {
        n->realdifference=n->realnum1-n->realnum2;
        n->imgdifference=n->imgnum1-n->imgnum2;
    }
    else
    {
        n->realdifference=n->realnum2-n->realnum1;
        n->imgdifference=n->imgnum2-n->imgnum1;
    }

    /*Operations Done*/

    printf("\n\nOutputs:\n");
    printf("Sum: %d+%di\n",n->realsum,n->imgsum);
    printf("Difference: %d+%di\n",n->realdifference,n->imgdifference);

    /*Outputs shown*/

    return 0;
}