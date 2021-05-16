struct queue* init(struct queue *q,int x)
{
	q=(struct queue *)malloc(sizeof(struct queue));
	q->capacity=x;
	q->rear=-1;
	q->front=-1;
	q->size=0;
	q->a=(int *)malloc(sizeof(int)*x);
	return q;
}

int isfull(struct queue *q)
{
	if(q->size==q->capacity)
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
	if(q->size==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void enqueue(struct queue *q,int x)
{
	if(isfull(q))
	{
		printf("\nQueue is full");
	}
	else
	{
		q->rear=(q->rear+1)%q->capacity;
		q->a[q->rear]=x;
		q->size++;
		//printf("\nEnqueued !");
	}
}
int dequeue(struct queue *q)
{
	if(isempty(q))
	{
		printf("\nQueue is empty Elements =");
		return 0;
	}
	else
	{
		//printf("The dequeued element is");
		q->front=(q->front+1)%q->capacity;
		q->size--;
		return q->a[q->front];
	}
}

void display(struct queue *q)
{
	int i,j;
	if(isempty(q))
	{
		printf("\nQueue is empty");
	}
	else
	{	j=(q->front+1)%q->capacity;
		printf("\nThe elements are :");
		for(i=0;i<q->size;i++)	
		{
			printf("\n%d",q->a[j]);
			j=(j+1)%q->capacity;
		}
	}
}

	

