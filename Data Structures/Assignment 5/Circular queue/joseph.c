#include<stdio.h>
#include<stdlib.h>
#include"circularqueueintf.h"
#include"circularqueueimpl.h"

void main()
{
	int n,m,i,a;
	printf("Enter the value of n :");
	scanf("%d",&n);
	struct queue *q;
	q=init(q,n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the element :");
		scanf("%d",&a);
		enqueue(q,a);
	}
	display(q);
	do
	{
		printf("\nEnter the value of m :");
		scanf("%d",&m);
		enqueue(q,dequeue(q));
		while(q->size>1)
		{
			for(i=1;i<m;i++)
			{
				enqueue(q,dequeue(q));
			}
			printf("\n%d is out",dequeue(q));
		}
		printf("\nThe winner is %d",dequeue(q));
		printf("\npress 1 to continue.. or 0 to stop :");
		scanf("%d",&a);
	}while(a!=0);
}
