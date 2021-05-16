struct poly *header()
{
	struct poly *temp;
	temp=(struct poly*)malloc(sizeof(struct poly));
	temp->next=NULL;
	return temp;
}
void insertfront(struct poly *p,struct term x)
{
	struct poly *temp;
	temp=(struct poly*)malloc(sizeof(struct poly));
	temp->r=x;
	temp->next=p->next;
	p->next=temp;
}
void insertend(struct poly *p,struct term x)
{
	struct poly *temp,*temp1;
	temp1=(struct poly*)malloc(sizeof(struct poly));
	temp=p;  
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp1->r=x;
	temp1->next=temp->next;
	temp->next=temp1;
}
void insertafter(struct poly *p,struct term x,int exp)
{
	struct poly *temp,*temp1;
	temp1=(struct poly*)malloc(sizeof(struct poly));
	temp=p;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if((temp->r.expo)==exp)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	temp1->r=x;
	temp1->next=temp->next;
	temp->next=temp1;
}
void display(struct poly *p)
{
	struct poly *temp;
	temp=p;
	printf("\n");
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("%dX^%d ",temp->r.coeff,temp->r.expo);
		if(temp->next!=NULL)
		{
			printf("+ ");
		}
	}
}
int maxepo(struct poly *p)
{
	struct poly *temp;
	temp=p;
	int m=0;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->r.expo>m)
		{
			m=temp->r.expo;
		}
	}
	return m;
} 
int evaluate(struct poly *p,int x)
{
	struct poly *temp;
	temp=p;
	float result=0,a;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		a=pow(x,temp->r.expo);
		a=a*(temp->r.coeff);
		result+=a;
	}
	return result;
}

void simplify(struct poly *p)
{
	int m=maxepo(p);
	struct poly *temp,*result;
	result=header();
	temp=p;
	int sum=0,i;
	struct term x;
	for(i=m;i>=0;i--)
	{
		sum=0;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(temp->r.expo==i)
			{
				sum+=temp->r.coeff;
			}
		}
		if(sum!=0)
		{
			x.coeff=sum;
			x.expo=i;
			insertend(result,x);
		}temp=p;
	}
	display(result);
}
void add(struct poly *p1,struct poly *p2)
{
	struct poly *t1,*t2,*t3;
	struct term temp;
	t3=header();
	t1=p1;
	t2=p2;
	while(t1->next!=NULL && t2->next!=NULL)
	{
		t1=t1->next;
		t2=t2->next;
		if(t1->r.expo>t2->r.expo)
		{
			temp=t1->r;
			t1=t1->next;
		}
		else if(t1->r.expo<t2->r.expo)
		{
			temp=t2->r;
			t2=t2->next;
		}
		else
		{
			temp.expo=t1->r.expo;
			temp.coeff=(t1->r.coeff)+(t2->r.coeff);
		}
		insertend(t3,temp);
	}
	printf("\nPoly 1\n");
	display(p1);
	printf("\nPoly 2\n");
	display(p2);
	printf("\nAddition Result\n");
	display(t3);
}
void multiply(struct poly *p1,struct poly *p2)
{

	struct poly *t1,*t2,*t3;
	struct term x;
	t3=header();
	t1=p1;
	while(t1->next!=NULL)
	{
		t1=t1->next;
		t2=p2;
		while(t2->next!=NULL)
		{
			t2=t2->next;
			x.expo=t1->r.expo+t2->r.expo;
			x.coeff=t1->r.coeff*t2->r.coeff;
			insertend(t3,x);
		}
	}
	printf("\nPoly 1\n");
	display(p1);
	printf("\nPoly 2\n");
	display(p2);
	printf("\nMultiplication Result\n");
	simplify(t3);
}
