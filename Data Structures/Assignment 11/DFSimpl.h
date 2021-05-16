struct city* init(struct city *c,int x)
{
	c->no_of_cities=x;
}

void create(struct city *c)
{
	int i,j;
	char val;
	printf("\nConnection between Cities .....(yes-Y and no -N)\n");
	printf("\nIs there any connection between following cities\n");
	for(i=0;i<c->no_of_cities;i++)
	{
		for(j=0;j<c->no_of_cities;j++)
		{
			if(i==j)
			{
				c->connection[i][j]=0;
				continue;
			}
			printf("\n%-5s and %-5s :",c->city_name[i],c->city_name[j]);
			scanf(" %c",&val);
			if(val=='Y' || val == 'y' || val == '1')
				c->connection[i][j]=1;
			else
				c->connection[i][j]=0;
		}
	}
}

void disp(struct city *c)
{
	int i,j;
	int n=c->no_of_cities;
	for(i=0;i<n;i++)
	{
		if(i==0)
			printf("\t%-7s",c->city_name[i]);
		else
			printf("\t%-7s",c->city_name[i]);	
	}	
	printf("\n\n");	
	for(i=0;i<n;i++)
	{
		printf("%-7s\t",c->city_name[i]);
		for(j=0;j<n;j++)
		{
			printf("%-6d\t",c->connection[i][j]);	
		}
		printf("\n\n");
	}	
}
int unvisited(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
			return i;
	}
	return -1;
}
int getindex(char name[],struct city *c)
{
	int i;
	for(i=0;i<c->no_of_cities;i++)
	{	
		if(strcmp(name,c->city_name[i])==0)
			return i;
	}
}
int adjvis(int i,struct city *c,int a[])
{
	int j;
	for(j=0;j<c->no_of_cities;j++)
	{
		if((c->connection[i][j]==1)&&(a[j]==0))
		{
			return j;
		}
	}	
	return -1;	

}
void DFS(struct city *c,char source[])
{
	struct stack *s;
	s=initstack();
	char x[30];
	char t[30];
	char y[30];
	int n=c->no_of_cities;
	int a[n];
	int i,j;
	for(i=0;i<n;i++)
		a[i]=0;
	int si=getindex(source,c);
	printf("\nThe Output is :\n");
	//while(unvisited(a,n)>-1)
	//{
	//	strcpy(x,c->city_name[unvisited(a,n)]);
	//	printf("%s    ",x);
		strcpy(x,c->city_name[si]);
		printf("%s    ",x);
		a[si]=1;
		push(s,x);
		while(!isEmpty(s))
		{
			strcpy(t,peek(s));
			i=getindex(t,c);
			if(adjvis(i,c,a)>-1)
			{
				j=adjvis(i,c,a);
				strcpy(y,c->city_name[j]);
				printf("%s    ",y);
				a[j]=1;
				push(s,y);
			}
			else
				pop(s);
		}
}

char *path(struct city*c,char source[],char desti[])
{
	struct stack *s;
	struct stack *f;
	f=initstack();
	s=initstack();
	char x[30];
	char t[30];
	char y[30];
	char *p=(char*)malloc(sizeof(char)*200);
	int n=c->no_of_cities;
	int a[n];
	int i,j,flag=1;
	for(i=0;i<n;i++)
		a[i]=0;
	int si=getindex(source,c);
	int e=getindex(desti,c);
	strcpy(p," ");
	strcpy(x,c->city_name[si]);
	a[si]=1;
	push(s,x);
	while(!isEmpty(s))
	{
		strcpy(t,peek(s));
		i=getindex(t,c);
		if(adjvis(i,c,a)>-1)
		{
			j=adjvis(i,c,a);
			strcpy(y,c->city_name[j]);
			a[j]=1;
			push(s,y);
			if(strcmp(y,desti)==0)
			{	
				flag=0;
				break;
			}
		}
		else
			pop(s);
	}
	while(!isEmpty(s))
	{
		push(f,pop(s));
	}
	while(!isEmpty(f))
	{
		strcat(p,pop(f));
		if(!isEmpty(f))
			strcat(p,"  ->");
	}
	if(flag==1)
	{	
		strcpy(p,"NO path");
	}
	return p;
	
}
