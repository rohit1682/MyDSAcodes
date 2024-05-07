#include<stdio.h>

struct node
{
    int coef,exp;
    struct node *link;
};

void main()

{

    struct node *p,*q,*r,*temp1,*temp2,*temp3,*ptr2;

    int ch,c;
    printf("\nEnter the first polynomial ");

    p=(struct node *)malloc(sizeof(struct node));

    temp1=p;

    printf("\n\nEnter the coeffeicient : ");
    scanf("%d",&temp1->coef);

    printf("\nEnter the exponent : ");
    scanf("%d",&temp1->exp);

    temp1->link=NULL;

	    printf("\n\nDo you want to enter more elements in the polynomial ? 1-Yes 0-No ");
    scanf("%d",&ch);

    while(ch)
    {

      temp1->link=(struct node *)malloc(sizeof(struct node));

      temp1=temp1->link;

      printf("\n\nEnter the coeffeicient : ");
      scanf("%d",&temp1->coef);

      printf("\nEnter the exponent : ");
      scanf("%d",&temp1->exp);

      temp1->link=NULL;

      printf("\n\nDo you want to enter more elements in the polynomial ? 1-Yes 0-No ");
      scanf("%d",&ch);

    }



    printf("\nEnter the second polynomial ");

    q=(struct node *)malloc(sizeof(struct node));

    temp2=q;

    printf("\n\nEnter the coeffeicient : ");
    scanf("%d",&temp2->coef);

    printf("\nEnter the exponent : ");
    scanf("%d",&temp2->exp);

    temp2->link=NULL;

    printf("\n\nDo you want to enter more elements in the polynomial ? 1-Yes 0-No ");
    scanf("%d",&c);

    while(c)
    {

      temp2->link=(struct node *)malloc(sizeof(struct node));

      temp2=temp2->link;

      printf("\n\nEnter the coeffeicient : ");
      scanf("%d",&temp2->coef);

      printf("\nEnter the exponent : ");
      scanf("%d",&temp2->exp);

      temp2->link=NULL;

      printf("\n\nDo you want to enter more elements in the polynomial ? 1-Yes 0-No ");
      scanf("%d",&c);

    }

     temp1=p;
     temp2=q;

     r=(struct node *)malloc(sizeof(struct node));
     temp3=r;

     while(temp1!=NULL && temp2!=NULL)
     {

       if(temp1->exp==temp2->exp)
        {

	  temp3->link=(struct node *)malloc(sizeof(struct node));

	  temp3=temp3->link;

	  temp3->exp=temp1->exp;

	  temp3->coef=temp1->coef+temp2->coef;

	  temp1=temp1->link;

	  temp2=temp2->link;

	  temp3->link=NULL;

        }

       else

         if(temp1->exp>temp2->exp)
	  {

	    temp3->link=(struct node *)malloc(sizeof(struct node));

	    temp3=temp3->link;

	    temp3->coef=temp1->coef;

	    temp3->exp=temp1->exp;

	    temp1=temp1->link;

	    temp3->link=NULL;

	  }

        else

	  if(temp2->exp>temp1->exp)
	   {

	      temp3->link=(struct node *)malloc(sizeof(struct node));

	      temp3=temp3->link;

	      temp3->coef=temp2->coef;

	      temp3->exp=temp2->exp;

	      temp2=temp2->link;

	      temp3->link=NULL;

	   }


      }//end of while


      while(temp1!=NULL)
      {

         temp3->link=(struct node *)malloc(sizeof(struct node));

         temp3=temp3->link;

         temp3->coef=temp1->coef;

         temp3->exp=temp1->exp;

         temp1=temp1->link;

         temp3->link=NULL;

      }



      while(temp2!=NULL)
      {

         temp3->link=(struct node *)malloc(sizeof(struct node));

         temp3=temp3->link;

         temp3->coef=temp2->coef;

         temp3->exp=temp2->exp;

         temp2=temp2->link;

         temp3->link=NULL;

      }

     temp1=p;
     temp2=q;

     printf("\n\nFirst polynomial : \n");

      while(temp1!=NULL)
       {

         printf("%dx^%d ",temp1->coef,temp1->exp);

         temp1=temp1->link;
         if(temp1!=NULL)
	      {
	        printf("+ ");
	      }

  }


     printf("\n\nSecond polynomial : \n");

      while(temp2!=NULL)
       {

         printf("%dx^%d ",temp2->coef,temp2->exp);

         temp2=temp2->link;

         if(temp2!=NULL)
	  {
	   printf("+ ");
	  }

       }




    temp3=r;
    temp3=temp3->link;

    printf("\n\n\nAfter addition of the polynomials : \n ");

    while(temp3!=NULL)
     {

       printf("%dx^%d ",temp3->coef,temp3->exp);

       temp3=temp3->link;
       if(temp3!=NULL)
	{
	 printf("+ ");
	}

     }

}