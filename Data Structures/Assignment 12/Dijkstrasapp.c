#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"StackADTintf.h"
//#include"StackADTimpl.h"
#include"Dijkstrasintf.h"
#include"Dijkstrasimpl.h"
void main()
{
	struct city *c;
	c=(struct city*)malloc(sizeof(struct city));
	int i,n;
	int index;
	char source[30];
	char desti[30];
	printf("\nEnter the no. of cities :");
	scanf("%d",&n);
	c=init(c,n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter City %d's name :",i+1);
		scanf("%s",c->city_name[i]);
	}
	while(1)
	{
		printf("\n1.Create\n2.disp\n3.Dijkstras output \n4.Path between two cities\n5.Exit\n\tEnter choice:");
		scanf("%d",&n);	
		if(n==1)
			create(c);
		else if(n==2)
			disp(c);
		else if(n==3)
		{
			printf("Enter the source to start :");
			scanf("%s",source);
			index=getindex(source,c);
			Dijkstras(c,index);
		}
		/*else if(n==4)
		{
			printf("\nEnter the Source :");
			scanf("%s",source);
			printf("\nEnter the Desti :");
			scanf("%s",desti);
			if(strcmp(path(c,source,desti),"No path")==0)
				printf("\nNO path\n");
			else
				printf("\nThe city are connected by the path :%s ",path(c,source,desti));
		}*/
		else if(n==5)
			break;
	}
}
