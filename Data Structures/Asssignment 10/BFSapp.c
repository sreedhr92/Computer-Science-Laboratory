#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linearqueueintf.h"
#include"linearqueueimpl.h"
#include"BFSintf.h"
#include"BFSimpl.h"
void main()
{
	struct city *c;
	int n;
	char val;
	printf("\nEnter the no. of cities:");
	scanf("%d",&n);
	c=init(n);
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n%d Enter city name : ",i+1);
		scanf("%s",c->cityname[i]);
	}
	c=create(c);
	while(1)
	{
		printf("\n1.Display\n2.Output of visiting tht cities in the breadth first search\n3.Check the connection between the two cities\n4.Exit\n\tEnter choice :");
		scanf("%d",&n);
		if(n==3)
		{
			char source[30],desti[30];
			printf("\nEnter the source :");
			scanf("%s",source);
			printf("\nEnter the destinatio :");
			scanf("%s",desti);
			if(connect(c,source,desti)==1)
			{
				printf("\nYes you have a route between these two cities..\n");
			}
			else
			{
				printf("\nNo you don't have a connection between two cities...\n");
			}
		}
		else if(n==1)
			disp(c);
		else if(n==2)
		{
			char source[10];
			printf("\nEnter the source:");
			scanf("%s",source);
			BFS(c,source);
		}
		else if(n==4)
		{
			break;
		}
		else
		{
			printf("\nInvalid Choice..\n");
		}
	}	
		
}
/*Output:
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Asssignment 10> gcc BFSapp.c -o a                                                                         PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Asssignment 10> ./a         
Enter the no. of cities:6

1 Enter city name : a

2 Enter city name : b

3 Enter city name : c

4 Enter city name : d

5 Enter city name : e

6 Enter city name : f

Connection between cities:(Y-to yes,N-to no)

Is there a connection bewtween a and b   :y

Is there a connection bewtween a and c   :y

Is there a connection bewtween a and d   :n

Is there a connection bewtween a and e   :n

Is there a connection bewtween a and f   :n

Is there a connection bewtween b and a   :n

Is there a connection bewtween b and c   :n

Is there a connection bewtween b and d   :y

Is there a connection bewtween b and e   :y

Is there a connection bewtween b and f   :n

Is there a connection bewtween c and a   :n

Is there a connection bewtween c and b   :n

Is there a connection bewtween c and d   :n

Is there a connection bewtween c and e   :n

Is there a connection bewtween c and f   :y

Is there a connection bewtween d and a   :n

Is there a connection bewtween d and b   :n

Is there a connection bewtween d and c   :n

Is there a connection bewtween d and e   :n

Is there a connection bewtween d and f   :n

Is there a connection bewtween e and a   :n

Is there a connection bewtween e and b   :n

Is there a connection bewtween e and c   :n

Is there a connection bewtween e and d   :n

Is there a connection bewtween e and f   :n

Is there a connection bewtween f and a   :n

Is there a connection bewtween f and b   :n

Is there a connection bewtween f and c   :n

Is there a connection bewtween f and d   :n

Is there a connection bewtween f and e   :n

1.Display
2.Output of visiting tht cities in the breadth first search
3.Check the connection between the two cities
4.Exit
        Enter choice :1
        a       b       c       d       e       f

a       0       1       1       0       0       0

b       0       0       0       1       1       0

c       0       0       0       0       0       1

d       0       0       0       0       0       0

e       0       0       0       0       0       0

f       0       0       0       0       0       0


1.Display
2.Output of visiting tht cities in the breadth first search
3.Check the connection between the two cities
4.Exit
        Enter choice :2

The Output is :
	a  b  c  d  e  f 
1.Display
2.Output of visiting tht cities in the breadth first search
3.Check the connection between the two cities
4.Exit
        Enter choice :3

Enter the source :b

Enter the destinatio :e

Yes you have a route between these two cities..

1.Display
2.Output of visiting tht cities in the breadth first search
3.Check the connection between the two cities
4.Exit
        Enter choice :4
*/        