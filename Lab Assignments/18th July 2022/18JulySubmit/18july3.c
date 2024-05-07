#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int id;
    char name[50];
    float salary;
}employee;
int main()
{
    employee* e1=(employee*) malloc(sizeof(employee));
    printf("Enter the Employee ID, Name and Salary\n");
    scanf("%d",&e1->id);
    scanf("%s",&e1->name);
    scanf("%f",&e1->salary);
    
    /*Inputs Taken*/
    
    printf("\n\nOutputs:\n");
    printf("%d\n",e1->id);
    printf("%s\n",e1->name);
    printf("%f\n",e1->salary);

    /*Output*/

    return 0;
}