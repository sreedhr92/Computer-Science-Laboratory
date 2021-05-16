struct hashtable* init(int n)
{
	struct hashtable *h;
	h=(struct hashtable*)malloc(sizeof(struct hashtable));	
	h->s=n;
	int i;
	for(i=0;i<n;i++)
	{
		h->list[i]=(struct node*)malloc(sizeof(struct node));
		h->list[i]->next=NULL;
	}
	return h;
}
		
void insert(struct  hashtable *h,int x)
{
	int val;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	val=x%h->s;
	temp->data=x;
	temp->next=h->list[val]->next;
	h->list[val]->next=temp;
	printf("\nInserted\n");
}

int search(struct hashtable *h,int x)
{
	int val;
	struct node *temp;
	val=x%h->s;
	temp=h->list[val]->next;
	while(temp!=NULL)
	{
		if(temp->data==x)
			return 1;
		temp=temp->next;
	}
	return 0;
}
void display(struct node *p)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=p->next;
	while(temp!=NULL)
	{
		printf("%d   ",temp->data);
		temp=temp->next;
	}
}
void disp(struct hashtable *h)
{
	int i;
	int n=h->s;
	printf("\nHash table :\n");
	for(i=0;i<n;i++)
	{
		printf("\nIndex :%d  ->",i);
		display(h->list[i]);		
	}
	printf("\n");
	
}				

