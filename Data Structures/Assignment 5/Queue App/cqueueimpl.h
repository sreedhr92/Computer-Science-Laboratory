struct queue* init(struct queue *q,int x)
{
	q=(struct queue *)malloc(sizeof(struct queue));
	q->capacity=x;
	q->rear=-1;
	q->front=-1;
	q->size=0;
	q->a=(struct job*)malloc(sizeof(struct job)*x);
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


void enqueue(struct queue *q,struct job x)
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
		printf("\nEnqueued !");
	}
}
struct job dequeue(struct queue *q)
{
	if(isempty(q))
	{
		printf("\nQueue is empty");
		struct job a={'\0',0};
		return a;

	}
	else
	{
		printf("The dequeued element is");
		q->front=(q->front+1)%q->capacity;
		q->size--;
		return q->a[q->front];
	}
}
int worktime(struct queue *q)
{
	int i,j,time=0;
	j=(q->front+1)%q->capacity;
	for(i=0;i<q->size;i++)	
	{
		time+=q->a[i].cputime;
		j=(j+1)%q->capacity;
	}
	return time;
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
		printf("\nThe Jobs are :");
		for(i=0;i<q->size;i++)	
		{
			printf("\n[ %c | %d ]",q->a[j].name,q->a[i].cputime);
			j=(j+1)%q->capacity;
		}
	}
}

	

