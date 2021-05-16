#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"priorityqueueADTintf.h"
#include"priorityqueueADTimpl.h"
struct Employee input()
{
	struct Employee x;
	printf("Enter the name :");
	scanf("%s",x.name);
	return x;
}
void main()
{
	struct Pqueue *q;
	struct Employee x;
	int choice,n,i;
	printf("Enter Capacity :");
	scanf("%d",&n);
	q=init(n);
	do
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice :");	
		scanf("%d\n",&choice);
		if(choice==1)
		{
			insert(q,input());
		}
		else if(choice==2)
		{
			x=deletemin(q);
			display_emp(x,0);
		}
		else if(choice==3)
		{	

			display(q,1,0);
		}
		else if(choice==4)
		{
			printf("\nExiting Thank you...\n");
		}
		else
		{
			printf("Invalid Choice");
		}
	}while(choice!=4);
}		
