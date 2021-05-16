#include<stdio.h>
#include<stdlib.h>
#include"cqueueintf.h"
#include"cqueueimpl.h"

void main()
{
	int n,m,i,a;
	printf("Enter the value of n :");
	scanf("%d",&n);
	struct queue *q;
	q=init(q,n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element :");
		scanf("%d",&a);
		enqueue(q,a);
	}
	display(q);
	do
	{
		printf("Enter the value of m :");
		scanf("%d",&m);
		while(q->size>1)
		{
			for(i=0;i<m;i++)
			{
				enqueue(q,dequeue(q));
				printf("%d is out",dequeue(q));
			}
		}
		printf("\nThe winner is %d",dequeue(q));
	}
}