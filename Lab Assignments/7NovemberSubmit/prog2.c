/*

Bubble Sort of an Array

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
//packages imported

void array()
{
    //this is the array method

    int size;
    printf("\nEnter the Size of the Array\n");
    scanf("%d",&size);

    int arr[size];

    printf("\nEnter the Elements of the Array\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    //now lets sort it using bubble sort

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    

    //now printing the array

    printf("\nThe Sorted Array\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }

}
//end of array method

int main()
{
    //main execution function

    array();

    return 0;
}
//end of main method
