#include<stdio.h>
#include "polyimpl.h"
void main()
{
	struct poly *p,*h;
	struct term s;
	p=header();
	char ch;
	int x;
	printf("Polynomial ADT\nFunctions that can be performed\n1.Addition\n2.Multiplication\nEnter the option :");
	scanf("%d",&x);
	printf("\nInput\nPolynomial 1\n");
	while(!0)
	{
		printf("\nEnter the coeff :");
		scanf("%d",&s.coeff);
		printf("Enter the expo :");
		scanf("%d",&s.expo);
		printf("\n1.Insert at front\n2.Insert at end\n3.Insert after a term");
		scanf("%d",&x);
		if(x==1)
			{insertfront(p,s);}
		else if(x==2)
			{insertend(p,s);}
		else if(x==3)
			{printf("Enter the expo :");scanf("%d",&x);insertafter(p,s,x);}
		else
			{printf("\nInvalid Option,try again by entering correct option to insert");}
		printf("\nDo you want to add a term in the Polynomial(y/n)");
		scanf("%s",&ch);
		if(ch=='n')
		{
			break;
		}
	printf("\n1.Displa-y as such\n2.Display in simplified form\nEnter option:");
	scanf("%d",&x);
	if(x==1)
	{
		display(p);
	}
	else if(x==2)
	{
		display(simply(p));
	}
	printf("\n");
}