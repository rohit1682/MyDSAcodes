/*

Implementation of Circular queue

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

int main()
{
    //main execution function
    
    int size;
    printf("\nEnter the Size of the Queue\n");
    scanf("%d",&size);
    int arr[size];

    int front=-1;
    int rear=-1;

    for(;;)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter Your Chocie\n");

        int response;
        scanf("%d",&response);

        switch(response)
        {
            case 1:
            
                if((rear+1)%size==front)
                {
                    printf("\nQueue Overflow\n");
                }
                else
                {
                    int item;
                    printf("\nEnter the Item\n");
                    scanf("%d",&item);

                    if(front==-1)
                    {
                        front=0;
                        rear=0;
                    }
                    else
                    {
                        rear=(rear+1)%size;
                    }
                    arr[rear]=item;
                }

            break;

            case 2:
            
                if(front==-1)
                {
                    printf("\nQueue Underflow\n");
                }
                else
                {
                    if(front==rear)
                    {
                        front=-1;
                        rear=-1;
                    }
                    else
                    {
                        front=(front+1)%size;
                    }
                }

            break;

            case 3:

                if(front!=-1)
                {
                    printf("\nThe Queue\n\n");
                    int i=front;
                    do
                    {
                        printf("%d\t",arr[i]);
                        i=(i+1)%size;
                    }while(i!=rear);
                    printf("%d\t",arr[rear]);
                }
                else
                {
                    printf("\nQueue Empty\n");
                }

            break;

            case 4:

                exit(0);

            break;

            default:

                printf("\nWrong Choice\n");

            break;
        }
    }

    
    return 0;
}
//end of main method
