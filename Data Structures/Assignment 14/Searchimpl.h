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
	display(n);
}
int linearsearch(struct numberADT *n,int key)
{
	int flag=0,i;
	for(i=0;i<n->size;i++)
	{
		if(n->a[i]==key)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		return -1;
	else
		return i;
}

void sort(struct numberADT *n)
{
	int i,j,temp;
	for(i=0;i<n->size;i++)
	{
		for(j=i+1;j<n->size;j++)
		{
			if(n->a[i]>n->a[j])
			{
				temp=n->a[i];
				n->a[i]=n->a[j];
				n->a[j]=temp;
			}
		}
	}
}

int binarysearch(struct numberADT *n,int key)
{
	sort(n);
	int lower_limit=0,upper_limit=n->size-1,middle;
		middle=(lower_limit+upper_limit)/2;
		while(lower_limit<=upper_limit)
		{
			if(key<n->a[middle])
			{
				upper_limit=middle-1;
			}
			else if(n->a[middle]<key)
			{
				lower_limit=middle+1;
			}
			else if(key==n->a[middle])
			{
				return middle;
			}	
			middle=(lower_limit+upper_limit)/2;
		}
		return -1;
}
