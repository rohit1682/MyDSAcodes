/*

Implementation Of Double Ended Queue Using Arrays

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

void impres()
{
    int size;
    printf("\nEnter the Size of The Array\n");
    scanf("%d",&size);

    int arr[size];
    int front=-1;
    int rear=-1;

    for(;;)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. EXIT \n");
        printf("\nEnter Your Choice\n");

        int response1;
        scanf("%d",&response1);

        switch(response1)
        {
            case 1:
       
                if(rear==size-1)
                {
                    printf("\nQueue Overflow\n");
                }         

                else
                {
                    printf("\nEnter the Item To be Inserted\n");
                    int item;
                    scanf("%d",&item);

                    if(front==-1)
                    {
                        front=0;
                        rear=0;                        
                    }   

                    else
                    {
                        rear++;
                    }

                    arr[rear]=item;
                } 

            break;

            case 2:

                if(front==-1)
                {
                    printf("\nQueue Underflow\n");
                }

                else if(front==rear)
                {
                    front=-1;
                    rear=-1;
                }

                else
                {
                    printf("\n1. Delete From the First\n");
                    printf("2. Delete From the Last\n");
                    printf("\nEnter Your Choice\n");

                    int response2;
                    scanf("%d",&response2);

                    switch(response2)
                    {
                        case 1:

                            int i=front;
                            do
                            {
                                arr[i]=arr[i+1];
                                i++;
                            }while(i!=rear);
                            rear--;
                            
                        break;

                        case 2:

                            rear--;

                        break;

                        default:

                            printf("\nWrong Choice\n");

                        break;
                    }
                }

            break;

            case 3:

                if(front==-1)
                {
                    printf("\nThe Queue is Empty\n");
                }

                else
                {
                    printf("\nThe Queue:\n");
                    for(int i=front;i<=rear;i++)
                    {
                        printf("%d\t",arr[i]);
                    }
                    printf("\n");
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
    
}

void outres()
{
    int size;
    printf("\nEnter the Size of The Array\n");
    scanf("%d",&size);

    int arr[size];
    int front=-1;
    int rear=-1;

    for(;;)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. EXIT \n");
        printf("\nEnter Your Choice\n");

        int response1;
        scanf("%d",&response1);

        switch(response1)
        {
            case 1:

                if(rear==size-1)
                {
                    printf("\nQueue Overflow\n");
                }         

                else
                {
                    printf("\nEnter the Item To be Inserted\n");
                    int item;
                    scanf("%d",&item);

                   
                        printf("\n1. Insert from the First\n");
                        printf("2. Insert from the Last\n");
                        printf("\nEnter Your Choice\n");

                        int response2;
                        scanf("%d",&response2);

                        switch(response2)
                        {
                            case 1:

                                if(front==-1)
                                {
                                    front=0;
                                    rear=0; 
                                    arr[front]=item;                       
                                }

                                else
                                {
                                    if(rear+1<size)
                                    {
                                        
                                        int c=rear;
                                        while(c>=front)
                                        {
                                            arr[c+1]=arr[c];
                                            c--;
                                        }

                                        arr[front]=item;
                                        rear++;
                                    }

                                    else
                                    {
                                        printf("\nQueue Overflow\n");
                                    }
                                    
                                }

                            break;

                            case 2:
        
                                if(front==-1)
                                {
                                    front=0;
                                    rear=0;                        
                                }   
        
                                else
                                {
                                    rear++;
                                }
            
                                arr[rear]=item;

                            break;

                            default:

                                printf("\nWrong Choice\n");

                            break;

                        }
                    
                } 

            break;

            case 2:

                if(front==-1)
                {
                    printf("\nQueue Underflow\n");
                }

                else if(front==rear)
                {
                    front=-1;
                    rear=-1;
                }

                else
                {
                    front++;
                }

            break;

            case 3:

                if(front==-1)
                {
                    printf("\nThe Queue is Empty\n");
                }

                else
                {
                    printf("\nThe Queue:\n");
                    for(int i=front;i<=rear;i++)
                    {
                        printf("%d\t",arr[i]);
                    }
                    printf("\n");
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
}
        
int main()
{
    //main execution function
    
    printf("\n1. Input Restricted Double Ended Queue.\n");
    printf("2. Output Restricted Double Ended Queue.\n");
    printf("3. EXIT Program\n");
    printf("\nEnter Your Choice\n");
    
    int response1;
    scanf("%d",&response1);

    switch(response1)
    {
        case 1:

            impres();

        break;

        case 2:

            outres();

        break;

        case 3:

            exit(0);

        break;

        default:

            printf("\nWrong Input\n");

        break;
    }
    
    return 0;
}
//end of main method
