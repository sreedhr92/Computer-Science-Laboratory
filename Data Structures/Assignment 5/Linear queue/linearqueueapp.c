#include<stdio.h>
#include<stdlib.h>
#include"lqueueintf.h"
#include"lqueueimpl.h"

void main()
{
	struct queue *q;
	int x,a,n;
	printf("Enter the capacity of the queue to be created :");
	scanf("%d",&n);
	q=init(q,n);
	printf("\n*********Linear queue**********\n");
	do
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\nEnter the choice:");
		scanf("%d",&x);	
		if(x==1)
		{
			printf("Enter the element :");
			scanf("%d",&a);
			enqueue(q,a);
		}
		else if(x==2)
		{
			printf(" %d",dequeue(q));
		}
		else if(x==3)
		{
			display(q);
		}
	}while(x!=4);
}
	
