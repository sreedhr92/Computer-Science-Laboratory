struct city *init(int n)
{
	struct city *c;
	c=(struct city*)malloc(sizeof(struct city));
	c->no_of_cities=n;
	//c->connection=(int **)malloc(sizeof(int)*n*n);
	//c->cityname=(char **)malloc(sizeof(char)*30*30);
	return c;
}
struct city* create(struct city *c)
{
	int i,j;
	char val;
	int n=c->no_of_cities;
	printf("\nConnection between cities:(Y-to yes,N-to no)\n ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				c->connection[i][j]==0;
				continue;
			}
			printf("\nIs there a connection bewtween %s and %-3s :",c->cityname[i],c->cityname[j]);
			scanf(" %c",&val);
			if(val=='y'||val=='Y'||val=='1')
			{
				c->connection[i][j]=1;
			}
			else
			{
				c->connection[i][j]=0;
			}	
		}
	}
	return c;
}
void disp(struct city *c)
{
	int i,j;
	int n=c->no_of_cities;
	for(i=0;i<n;i++)
	{
		if(i==0)
			printf("\t%-4s\t",c->cityname[i]);
		else
			printf("%s\t",c->cityname[i]);	
	}	
	printf("\n\n");	
	for(i=0;i<n;i++)
	{
		printf("%-4s\t",c->cityname[i]);
		for(j=0;j<n;j++)
		{
			printf("%-3d\t",c->connection[i][j]);	
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
		{
			return i;
		}	
	}
	return -1;
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
int getindex(char name[],struct city *c)
{
	int i;
	for(i=0;i<c->no_of_cities;i++)
	{	
		if(strcmp(name,c->cityname[i])==0)
			return i;
	}	
}
void BFS(struct city *c,char source[])
{
	struct queue *q;
	q=initq(q,100);
	char x[30];
	char y[30];
	char z[30];
	int i,j;
	int n=c->no_of_cities;
	int a[c->no_of_cities];
	for(i=0;i<c->no_of_cities;i++)
		a[i]=0;
	int s=getindex(source,c);
	printf("\nThe Output is :\n");
	//while(unvisited(a,n)!=-1)
	//{
		//strcpy(x,c->cityname[unvisited(a,n)]);
		//printf("%s    ",x);
		//a[unvisited(a,n)]=1;
		strcpy(x,c->cityname[s]);
		printf("%s    ",x);
		enqueue(q,x);
		a[s]=1;
		while(!isempty(q))
		{
			strcpy(z,dequeue(q));
			i=getindex(z,c);
			while(adjvis(i,c,a)!=-1)
			{
				j=adjvis(i,c,a);
				strcpy(y,c->cityname[j]);
				printf("%s    ",y);
				a[j]=1;
				enqueue(q,y);
			}
		}
}

int connect(struct city *c,char source[],char desti[])
{
	struct queue *q;
	q=initq(q,100);
	char x[30];
	char y[30];
	char z[30];
	int i,j;
	int a[c->no_of_cities];
	for(i=0;i<c->no_of_cities;i++)
		a[i]=0;
	strcpy(x,source);
	a[getindex(source,c)]=1;
	enqueue(q,x);
	while(!isempty(q))
	{
		strcpy(z,dequeue(q));
		i=getindex(z,c);
		while(adjvis(i,c,a)>-1)
		{
			j=adjvis(i,c,a);
			strcpy(y,c->cityname[j]);
			if(strcmp(y,desti))
				return 1;
			a[j]=1;
			enqueue(q,y);
		}
	}
	return 0;
}