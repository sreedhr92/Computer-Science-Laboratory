struct numberADT* init(int ne)
{
	struct numberADT *n;
	n=(struct numberADT*)malloc(sizeof(struct numberADT));
	n->size=ne;
	n->a=(int *)malloc(sizeof(int)*ne);
	return n;
}
void display(struct numberADT *n)
{
	int i;
	printf("\nThe Elements are:\n");
	for(i=0;i<n->size;i++)
	{
		printf("%d  ",n->a[i]);
	}
}
void insertElements(struct numberADT *n,int x[])
{
	int i;
	for(i=0;i<n->size;i++)
	{
		n->a[i]=x[i];
	}
	//display(n);
}

void selsort(struct numberADT *n)
{
	int i,j,min,temp,pos;
	for(i=0;i<n->size;i++)
	{
		min=n->a[i];
		pos=i;
		for(j=i+1;j<n->size;j++)
		{
			if(min>n->a[j])
			{
				min=n->a[j];
				pos=j;
			}
		}
		n->a[pos]=n->a[i];
		n->a[i]=min;
		display(n);
	}
}

void shellsort(struct numberADT *n)
{
	int depth=n->size/2,i,temp;
	while(depth>1)
	{
		int visited[n->size];
		for(i=0;i+depth<n->size;i++)
		{
			if(n->a[i]>n->a[i+depth])
			{
				temp=n->a[i+depth];
				n->a[i+depth]=n->a[i];
				n->a[i]=temp;
			}
		}
		depth--;
	}
	printf("\nOutput after shellsort\n");
	display(n);
	printf("\nOutput for selsort\n");
	selsort(n);
}