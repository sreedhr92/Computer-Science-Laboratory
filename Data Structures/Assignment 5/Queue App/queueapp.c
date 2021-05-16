#include<stdio.h>
#include<stdlib.h>
#include"cqueueintf.h"
#include"cqueueimpl.h"
//input for the job...........
struct job input()
{
	struct job x;
	printf("Enter job name       :");
	scanf(" %c",&x.name);
	printf("Enter cpu burst time :");
	scanf("%d",&x.cputime);
	return x;
}

void main()
{
	struct queue *q1,*q2;
	struct job j;
	int n,x,y;
	printf("\n***********Job Scheduling**********\nEnter the Capacity of both queues :");
	scanf("%d",&n);
	//initializing both queues.........
	q1=init(q1,n);
	q2=init(q2,n);
	do
	{
		printf("\n\n1.Enqueue a job\n2.Dequeue a job\n3.Display\n4.Exit\n\nEnter option :");
		scanf("%d",&x);
		if(x==1)
		{
			//equeueing based on the conditions......
			j=input();
			if(isempty(q1))
				enqueue(q1,j);
			else if(isempty(q2))
				enqueue(q2,j);
			//if working of queue 1 is greater then job is added to queue 2........
			else if(worktime(q1)<worktime(q2))
				enqueue(q1,j);
			else if(worktime(q1)>worktime(q2))
				enqueue(q2,j);
		}
		else if(x==2)
		{
			//dequeueing a job...........
			printf("\n1.Dequeue from queue 1\n2.Dequeue from queue 2\nEnter option :");
			scanf("%d",&x);
			if(x==1)
				{j=dequeue(q1);printf("\n[ %c | %d ]",j.name,j.cputime);}
			else
				{j=dequeue(q2);printf("\n[ %c | %d ]",j.name,j.cputime);}
		}
		else if(x==3)
		{
			//displaying the queue.........
			printf("\n1.Display queue 1\n2.Display queue 2\n3.Display both queues \nEnter option :");
			scanf("%d",&x);
			if(x==1)
				{printf("\nQueue 1 :\n");display(q1);}
			else if(x==2)
				{printf("\nQueue 2 :\n");display(q2);}
			else if(x==3)
				{
					printf("\nQueue 1 :\n");
					display(q1);
					printf("\n\nQueue 2 :\n");
					display(q2);
				}
		}	
	}while(x!=4);
}
/*Output:
version 1
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 5\Queue App> gcc
queueapp.c -o a
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 5\Queue App> ./a

***********Job Scheduling**********
Enter the Capacity of both queues :6


1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :A
Enter cpu burst time :2

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :B
Enter cpu burst time :4

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :C
Enter cpu burst time :8

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :D
Enter cpu burst time :5

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :E
Enter cpu burst time :2

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :F
Enter cpu burst time :7

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :G
Enter cpu burst time :4

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :H
Enter cpu burst time :3

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :I
Enter cpu burst time :6

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :J
Enter cpu burst time :6

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :3

1.Display queue 1
2.Display queue 2
3.Display both queues
Enter option :3

Queue 1 :

The Jobs are :
[ A | 2 ]
[ C | 8 ]
[ F | 7 ]
[ I | 6 ]

Queue 2 :

The Jobs are :
[ B | 4 ]
[ D | 5 ]
[ E | 2 ]
[ G | 4 ]
[ H | 3 ]
[ J | 6 ]

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :4
----------------------------------------------------------------


version 2
Output:
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 5\Queue App> gcc
queueapp.c -o a
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 5\Queue App> ./a

***********Job Scheduling**********
Enter the Capacity of both queues :1


1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :A
Enter cpu burst time :3

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :B
Enter cpu burst time :6

Enqueued !

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :1
Enter job name       :C
Enter cpu burst time :8

Queue is full

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :2

1.Dequeue from queue 1
2.Dequeue from queue 2
Enter option :1
The dequeued element is
[ A | 3 ]

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :2

1.Dequeue from queue 1
2.Dequeue from queue 2
Enter option :2
The dequeued element is
[ B | 6 ]

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

Enter option :3

1.Display queue 1
2.Display queue 2
3.Display both queues
Enter option :3

Queue 1 :

Queue is empty

Queue 2 :

Queue is empty

1.Enqueue a job
2.Dequeue a job
3.Display
4.Exit

*/