struct city* init(struct city *c,int x)
{
	c->no_of_cities=x;
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
void create(struct city *c)
{
	int i,j,k,n=c->no_of_cities;
	int ne;
	char x[50][50];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c->connection[i][j]=0;
			c->distance[i][j]=0;

		}
	}
	printf("\n Check connection : ");
	for(i=0;i<c->no_of_cities;i++)
	{
		printf("\n Edge count of %s : ",c->city_name[i]);
		scanf(" %d",&ne);
		if(ne>0)
			printf(" Edges of %s    :\n",c->city_name[i]);
		for(j=0;j<ne;j++)
		{
			printf(" Edge %d    : ",j+1);
			scanf(" %[^\n]",x[j]);
			c->connection[getindex(c->city_name[i],c)][getindex(x[j],c)]=1;
			printf(" Distance :");
			scanf(" %d",&c->distance[getindex(c->city_name[i],c)][getindex(x[j],c)]);
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
void displaytable(struct city *c,int k[],int d[],char path[10][30])
{
	int i;
	int n=c->no_of_cities;
	printf("[v]\t[k]\t[d]\t[p]\n");
	for(i=0;i<n;i++)
	{
		if(d[i]==100)
			printf("%-4s\t%d\t∞\t%s\n",c->city_name[i],k[i],d[i],path[i]);
		else
			printf("%-4s\t%d\t%d\t%s\n",c->city_name[i],k[i],d[i],path[i]);
	}
	printf("\n");
}
int leastvisited(int k[],int d[],int n)
{
	int i,m=1000,pos;
	for(i=0;i<n;i++)
	{
		if(d[i]<m && k[i]!=1)
		{
			m=d[i];
			pos=i;
		}
	}
	return pos;
}
int adjacent(struct city *c,int v,int tempvis[])
{
	int i;
	for(i=0;i<c->no_of_cities;i++)
	{
		if(c->connection[v][i]==1 && tempvis[i]==0)
		{
			tempvis[i]=1;
			return i;
		}
	}
	return -1;
}
void Dijkstras(struct city *c,int start)
{
	int i,n,vi,w;
	char v[30];
	n=c->no_of_cities;
	int k[n];
	int d[n];
	char path[n][30];
	int tempvis[n];
	for(i=0;i<n;i++)
	{
		k[i]=0;
		d[i]=100;
		strcpy(path[i],"0");
	}
	printf("\nThe Initialisation table \n");
	displaytable(c,k,d,path);
	k[start]=1;
	d[start]=0;
	strcpy(v,c->city_name[start]);
	printf("\nAfter %s is known\n",v);
	displaytable(c,k,d,path);
	while(unvisited(k,n)>-1)
	{
		strcpy(v,c->city_name[leastvisited(k,d,n)]);
		vi=getindex(v,c);
		k[vi]=1;
		printf("\nAfter %s is known\n",v);
		for(i=0;i<n;i++)
			tempvis[i]=0;
		while(w=adjacent(c,vi,tempvis)>-1)
		{
			if(k[w]==0)
			{
				if(d[vi]+c->distance[vi][w]<d[w])
				{
					d[w]=d[vi]+c->distance[vi][w];
					strcpy(path[w],c->city_name[vi]);
				}
			}
		}
		displaytable(c,k,d,path);
	}
	printf("\nThe final table:\n");
	displaytable(c,k,d,path);
}
