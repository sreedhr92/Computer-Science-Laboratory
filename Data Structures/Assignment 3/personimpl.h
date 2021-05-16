struct personlist* header()
{
	struct personlist *temp;
	temp=(struct personlist*)malloc(sizeof(struct personlist));
	temp->lptr=NULL;
	temp->rptr=NULL;
	return temp;
}
void insertafterpin(struct personlist *p,struct person x,int a)
{
	struct personlist *temp1,*temp2,*temp3;
	temp1=(struct personlist*)malloc(sizeof(struct personlist));
	temp1->t=x;
	temp2=p;
	while(temp2->rptr!=NULL)
	{
		temp2=temp2->rptr;
		if(temp2->t.pin==a)
		{
			break;
		}
	}
	if(temp2->rptr!=NULL)
	{
		temp3=temp2->rptr;
		temp1->lptr=temp2;
		temp1->rptr=temp3;
		temp2->rptr=temp1;
		temp3->lptr=temp1;
	}
	else
	{
		temp2->rptr=temp1;
		temp1->rptr=NULL;
		temp1->lptr=temp2;
	}
}
void insertend(struct personlist *p,struct person x)
{
	struct personlist *temp1,*temp2;
	temp1=(struct personlist*)malloc(sizeof(struct personlist));
	temp1->t=x;
	temp2=p;
	while(temp2->rptr!=NULL)
	{
		temp2=temp2->rptr;
	}
	temp2->rptr=temp1;
	temp1->rptr=NULL;
	temp1->lptr=temp2;
}
void insertfront(struct personlist *p,struct person x)
{
	struct personlist *temp1,*temp2;
	temp1=(struct personlist*)malloc(sizeof(struct personlist));
	temp2=p->rptr;

	temp1->t=x;

	p->rptr=temp1;
	temp1->rptr=temp2;
	temp1->lptr=p;
	

	if(temp2!=NULL)
	{
		temp2->lptr=temp1;
	}
}
void sort(struct personlist *p)
{
	struct personlist *temp1,*temp2;
	temp1=p->rptr;
	temp2=p->rptr;
	struct person dumb;
	while(temp1->rptr->rptr!=NULL)
	{
		temp2=p->rptr;
		while(temp2->rptr->rptr!=NULL)
		{
			if(temp2->t.age>temp2->rptr->t.age)
			{
				dumb=temp2->t;
				temp2->t=temp2->rptr->t;
				temp2->rptr->t=dumb;
			}
			temp2=temp2->rptr;
		}
		temp1=temp1->rptr;
	}

}
struct ratio count(struct personlist *p)
{
	struct personlist *temp;
	struct ratio k;
	int m=0,f=0;
	temp=p->rptr;
	while(temp!=NULL)
	{
		if(strcmp(temp->t.sex,"male"))
		{
			m++;
		}
		else
		{
			f++;
		}
		temp=temp->rptr;
	}
	int i=0,min;
	if(m<f)
		min=m;
	else
		min=f;
	for(i=2;i<=min;i++)
	{
		if(m%i==0&&f%i==0)
		{
			m/=i;
			f/=i;
		}
	}
	k.male=m;
	k.female=f;
	return k;
}
struct personlist* seniorperson(struct personlist *p)
{
	struct personlist *temp;
	struct personlist *senior;
	senior=header();
	temp=p;
	while(temp->rptr!=NULL)
	{
		temp=temp->rptr;
		if(temp->t.age>60)
		{
			insertend(senior,temp->t);
		}
	}
	return senior;
}
struct personlist *locateperson(struct personlist *p,char s[])
{
	struct personlist *temp,*locate;
	locate=header();
	temp=p;
	while(temp->rptr!=NULL)
	{
		temp=temp->rptr;
		if(strcmp(temp->t.city,s)==0)
		{
			insertend(locate,temp->t);
		}
	}
	return locate;
}
void display(struct personlist *p)
{
	struct personlist *temp,*last;
	temp=p->rptr;
	int k=0;
	while(temp!=NULL)
	{
		printf("\nPerson %d :",k+1);
		printf("\nName    :%s\nPIN     :%d\nAGE     :%d\nSEX     :%s\nSTREET  :%s\nCITY    :%s\n",temp->t.name,temp->t.pin,temp->t.age,temp->t.sex,temp->t.street,temp->t.city);
		last=temp;
		temp=temp->rptr;	
		printf("\n");
		k++;
	}
}	
void display_1(struct personlist *p)
{
	struct personlist *temp,*last;
	temp=p->rptr;
	int k=0;
	while(temp!=NULL)
	{
		printf("\nPerson %d :",k+1);
		printf("\nName    :%s\nPIN     :%d\nAGE     :%d\nSEX     :%s\nSTREET  :%s\nCITY    :%s\n",temp->t.name,temp->t.pin,temp->t.age,temp->t.sex,temp->t.street,temp->t.city);
		last=temp;
		temp=temp->rptr;	
		printf("\n");
		k++;
	}
	char x;
	printf("Do you want to print in the reverse order(y/n) ? :");
	scanf("%s",&x);
	if(x=='y')
	{
		while(last->lptr!=NULL)
		{
			printf("\nPerson %d :",k+1);
			printf("\nName    :%s\nPIN     :%d\nAGE     :%d\nSEX     :%s\nSTREET   :%s\nCITY    :%s\n",last->t.name,last->t.pin,last->t.age,last->t.sex,last->t.street,last->t.city);
			last=last->lptr;
			printf("\n");
			k++;
		}
	}
}	
