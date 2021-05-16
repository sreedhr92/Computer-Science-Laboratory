struct queue* initq(struct queue *q,int x)
{
	q=(struct queue *)malloc(sizeof(struct queue));
	q->capacity=x;
	q->rear=-1;
	q->front=-1;
//	q->a=(int *)malloc(sizeof(int)*x);
	return q;
}

int isfull(struct queue *q)
{
	if(q->rear==q->capacity-1)
	{
		return 1;
	}
	else
	{
		return 0;

	}
}

int isempty(struct queue *q)
{
	if(q->rear==q->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void enqueue(struct queue *q,char x[])
{
	if(isfull(q))
	{
		printf("\nQueue is full");
	}
	else
	{
		q->rear++;
		strcpy(q->a[q->rear],x);
		//printf("\nEnqueued !\n");
	}
}
char* dequeue(struct queue *q)
{
	if(isempty(q))
	{
		printf("\nQueue is empty Elements =");
		return 0;
	}
	else
	{
	//	printf("The dequeued element is");
		q->front++;
		return q->a[q->front];
	}
}

/*void display(struct queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("\nQueue is empty");
	}
	else
	{
		printf("\nThe elements are :");
		for(i=q->front+1;i<=q->rear;i++)	
		{
			printf("\n%d",q->a[i]);
		}
	}
}*/

	

