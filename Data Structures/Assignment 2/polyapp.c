#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "polyintf.h"
#include "polyimpl.h"
struct poly* input(struct poly *p,struct term s)
{
	static int i=0;
	int k=0,x;
	char ch;
	printf("\nInput\nPolynomial %d\n",++i);
	while(!0)
	{
		if(k==0)
		{
			printf("\nEnter the coeff :");
			scanf("%d",&s.coeff);
			printf("Enter the expo :");
			scanf("%d",&s.expo);
			insertfront(p,s);
			printf("\nInserted!\n");
			k++;	
			printf("\nDo you want to add a term in the Polynomial(y/n) :");
			scanf("%s",&ch);
		}
		printf("\nEnter the coeff :");
		scanf("%d",&s.coeff);
		printf("Enter the expo :");
		scanf("%d",&s.expo);
		printf("\n1.Insert at front\n2.Insert at end\n3.Insert after a term\n\nEnter the option:");
		scanf("%d",&x);
		if(x==1)
			{insertfront(p,s);printf("\nInserted\n");}
		else if(x==2)
			{insertend(p,s);printf("\nInserted\n");}
		else if(x==3)
			{printf("Enter the expo :");scanf("%d",&x);insertafter(p,s,x);printf("\nInserted\n");}
		else
			{printf("\nInvalid Option,try again by entering correct option to insert");}
		printf("\nDo you want to add a term in the Polynomial(y/n) :");
		scanf("%s",&ch);
		if(ch=='n')
		{
			break;
		}
	}	
	return p;
}
void main()
{
	struct poly *p1,*p2,*h,*p;
	struct term s;
	int x;
	do
	{
	printf("\n\nPolynomial ADT\nFunctions that can be performed\n1.Addition\n2.Multiplication\n3.Simplfy a polynomial\n4.Degree of the polynomial\n5.Evaluate a polynomial\n6.Exit\nEnter the option :");
	scanf("%d",&x);
	if(x==1)
	{
		p1=header();
		p2=header();
		p1=input(p1,s);
		p2=input(p2,s);
		add(p1,p2);
	}	
	else if(x==2)
	{
		p1=header();
		p2=header();
		p1=input(p1,s);
		p2=input(p2,s);
		multiply(p1,p2);
	}
	else if(x==3)
	{
		p=header();
		p=input(p,s);
		printf("\nOriginal form\n");
		display(p);
		printf("\nSimplified form\n");
		simplify(p);
	}
	else if(x==4)
	{
		p=header();
		p=input(p,s);
		printf("\nPolynomial\n");
		display(p);
		printf("\nDegree of the polynomial is %d",maxepo(p));
	}
	else if(x==5)
	{
		p=header();
		p=input(p,s);
		printf("\nPolynomial\n");
		display(p);
		int x;
		printf("\nEnter the value of x :");
		scanf("%d",&x);
		printf("\nResult =%d",evaluate(p,x));
	}
	else
	{
		printf("\nEnter the correct option\n");
	}
	}while(x!=6);
}