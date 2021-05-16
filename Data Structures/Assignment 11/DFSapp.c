#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackADTintf.h"
#include"StackADTimpl.h"
#include"DFSintf.h"
#include"DFSimpl.h"
void main()
{
	struct city *c;
	c=(struct city*)malloc(sizeof(struct city));
	int i,n;
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
		printf("\n1.Create\n2.disp\n3.DFS output \n4.Path between two cities\n5.Exit\n\tEnter choice:");
		scanf("%d",&n);	
		if(n==1)
			create(c);
		else if(n==2)
			disp(c);
		else if(n==3)
		{
			char source[10];
			printf("\nEnter the source:");
			scanf("%s",source);
			DFS(c,source);
		}
		else if(n==4)
		{
			printf("\nEnter the Source :");
			scanf("%s",source);
			printf("\nEnter the Desti :");
			scanf("%s",desti);
			if(strcmp(path(c,source,desti),"No path")==0)
				printf("\nNO path\n");
			else
				printf("\nThe city are connected by the path :%s ",path(c,source,desti));
		}
		else if(n==5)
			break;
	}
}
/*PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 11> gcc DFSapp.c -o a                                                                          PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 11> ./a          
Enter the no. of cities :6

Enter City 1's name :a

Enter City 2's name :c

Enter City 3's name :d

Enter City 4's name :e

Enter City 5's name :f

Enter City 6's name :g

1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:1

Connection between Cities .....(yes-Y and no -N)

Is there any connection between following cities

a     and c     :n

a     and d     :n

a     and e     :n

a     and f     :y

a     and g     :y

c     and a     :y

c     and d     :y

c     and e     :n

c     and f     :n

c     and g     :n

d     and a     :n

d     and c     :y

d     and e     :n

d     and f     :y

d     and g     :n

e     and a     :n

e     and c     :y

e     and d     :y

e     and f     :n

e     and g     :y

f     and a     :n

f     and c     :n

f     and d     :n

f     and e     :y

f     and g     :n

g     and a     :n

g     and c     :n

g     and d     :n

g     and e     :n

g     and f     :n

1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:2
        a       c       d       e       f       g

a       0       0       0       0       1       1

c       1       0       1       0       0       0

d       0       1       0       0       1       0

e       0       1       1       0       0       1

f       0       0       0       1       0       0

g       0       0       0       0       0       0


1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:3

The Output is :
a    f    e    c    d    g
1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:4

Enter the Source :a

Enter the Desti :e

The city are connected by the path : a  ->f  ->e
1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:4

Enter the Source :e

Enter the Desti :d

The city are connected by the path : e  ->c  ->d
1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:4

Enter the Source :d

Enter the Desti :a

The city are connected by the path : d  ->c  ->a
1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:4

Enter the Source :a

Enter the Desti :c

The city are connected by the path : a  ->f  ->e  ->c
1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:4

Enter the Source :g

Enter the Desti :a

The city are connected by the path :NO path
1.Create
2.disp
3.DFS output
4.Path between two cities
5.Exit
        Enter choice:5*/ 
