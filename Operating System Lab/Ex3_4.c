#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct process
{
	char id[20];
	int arr_time;
	int burst_time;
	int wait_time;
	int resp_time;
	int turn_time;
	int priority;
	int flag;
};
struct job
{
	int start,end;
	char id[20];
};
struct queue
{
	int a[50];
	int capacity,front,rear,size;

};
struct queue* init()
{
	struct queue *q;
	q->capacity=50;
	q->front=0;
	q->rear=0;
	q->size=0;
	return q;
}

void enqueue(struct queue *q,int x)
{
		q->a[q->rear]=x;
		q->rear=q->rear+1 % q->capacity;
		q->size++;
}
int dequeue(struct queue *q)
{
	int x=q->front;
	q->front=q->front+1% q->capacity;
	q->size--;
	return q->a[x];
}
struct process input()
{ 
	struct process x;
	printf("\nProcess ID   :");
	scanf("%s",x.id);
	printf("Arrival time :");
	scanf("%d",&x.arr_time);
	printf("Burst time   :");
	scanf("%d",&x.burst_time);
	printf("Priority     :");
	scanf("%d",&x.priority);
	printf("\n");
	x.flag=0;
	return x;
}
struct process* sort_based_on_arrival_time(struct process a[],int n)
{
	struct process temp;
	int min=100,pos=0,i,j,k;
	for(i=0;i<n;i++)
	{
		min=a[i].arr_time;
		for(j=i+1;j<n;j++)
		{
			if(min>a[j].arr_time)
				min=a[j].arr_time;
		}
		for(k=0;k<n;k++)
		{
			if(min==a[k].arr_time)
			{
				pos=k;
				break;
			}
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
	return a;
}
int terminate(struct process a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i].flag==0)
			return 0;
	}
	return 1;
}
int get_high_priority_job(struct process a[],int n,int max)
{
	int i,j,k=0;
	int job[n];
	int high_pr;
	int high_pr_index;
	for(i=1;i<n;i++)
	{
		if(a[i].arr_time<=max&&a[i].flag==0)
		{	
			job[k]=a[i].priority;
			k++;
		}
	}
	if(k==0)
		return 0;
	high_pr=job[0];
	for(i=1;i<k;i++)
	{
		if(high_pr>job[i])
			high_pr=job[i];
	}
	for(i=1;i<n;i++)
	{
		if(high_pr==a[i].priority&&a[i].flag==0)
		{	
			high_pr_index=i;
			break;
		}	
	}
	return high_pr_index;
}
int get_high_priority_job_preemptive(struct process temp[],struct process a[],int n,int max)
{
	int i,j,k=0;
	int job[n];
	int high_pr;
	int high_pr_index;
	for(i=0;i<n;i++)
	{
		if(a[i].arr_time<=max && a[i].flag==0 && temp[i].flag==0)
		{	
			job[k]=a[i].priority;
			k++;
		}
	}
	if(k==0)
		return -1;
	high_pr=job[0];
	for(i=0;i<k;i++)
	{
		if(high_pr > job[i])
			high_pr = job[i];
	}
	for(i=0;i<n;i++)
	{
		if(high_pr==a[i].priority && a[i].flag==0 && temp[i].flag==0)
		{	
			high_pr_index=i;
			break;
		}	
	}
	return high_pr_index;
}
int count(int a)
{
	if(a/10==0)
		return 1;
	else
		return 2;
}
void display_gantt(struct process a[],int n)
{
	int gantt[n+1],exe_time=0,i;
	printf("\n");
	for(i=0;i<n+1;i++)
	{
		if(i<n)
		{
			if(exe_time < a[i].arr_time)
			{
				printf("\nThe Cpu is idle for time %-2d to %-2d ",exe_time,a[i].arr_time);
				gantt[i]=a[i].arr_time;
				exe_time=a[i].arr_time;
				exe_time=exe_time+a[i].burst_time;
			}
			else
			{
				gantt[i]=exe_time;
				exe_time=exe_time+a[i].burst_time;
			}
		}
		else
			gantt[i]=exe_time;
	}
	printf("\n\n\t\t\t\t\t\tGANTT CHART\n\n\n\t\t");
	int length = (14*n)+n;
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n\t\t");
	int place,k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0)
		{
			place=0;
			printf("|");
		}
		else
		{
			place++;
			if(place==6 && k<n)
			{
				printf("%s ",a[k].id);
				k++;
			}
			else if(place>7 ||place<6)
				printf(" ");
		}	
	}
	printf("\n\t\t");
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n\t\t");
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0 && k<n+1 )
		{	
			if(count(gantt[k])==1)
			{
				printf("%d ",gantt[k]);
				k++;
			}
			else
			{
				printf("%d",gantt[k]);
				k++;
			}
		}
		else
		{
			printf(" ");
		}	
	}
}
void display_gantt_p(struct job a[],int n)
{
	int gantt[n+1],exe_time=0,i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		gantt[i]=a[i].start;
	}
	gantt[i]=a[i-1].end;
	printf("\n\n\t\t\t\t\t\tGANTT CHART\n\n\n\t\t");
	int length = (14*n)+n;
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n\t\t");
	int place,k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0)
		{
			place=0;
			printf("|");
		}
		else
		{
			place++;
			if(place==6 && k<n)
			{
				printf("%s ",a[k].id);
				k++;
			}
			else if(place>7 ||place<6)
				printf(" ");
		}	
	}
	printf("\n\t\t");
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n\t\t");
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0 && k<n+1 )
		{	
			if(count(gantt[k])==1)
			{
				printf("%d ",gantt[k]);
				k++;
			}
			else
			{
				printf("%d",gantt[k]);
				k++;
			}
		}
		else
		{
			printf(" ");
		}	
	}
}
void display_table(struct process a[],int n)
{
	int i;
	float avg_wait=0,avg_turn=0,avg_resp=0;
	for(i=0;i<n;i++)
	{
		/*printf("\nProcess ---%d",i+1);
		printf("\nProcess ID 	:%s\n",a[i].id);
		printf("Arrival time 	:%d\n",a[i].arr_time);
		printf("Burst time 	:%d\n\n",a[i].burst_time);
		printf("Waiting time 	:%d\n",a[i].wait_time);
		printf("Turn around 	:%d\n",a[i].turn_time);
		printf("Response time 	:%d\n",a[i].resp_time);*/
		avg_wait=avg_wait+a[i].wait_time;
		avg_turn=avg_turn+a[i].turn_time;
		avg_resp=avg_resp+a[i].resp_time;
	}
	avg_wait=avg_wait/n;
	avg_turn=avg_turn/n;
	avg_resp=avg_resp/n;
	/*printf("\nThe Average Waiting time of all process is       :%.1f",avg_wait);
	printf("\nThe Average Response time of all process is      :%.1f",avg_turn);
	printf("\nThe Average Turn around time of all process is   :%.1f",avg_resp);*/
	printf("\n\n------------------------------------------------------------------------------------------------");
	printf("\n|Process_id|\t|Arrival time|\t|Burst time|\t|Waiting time|\t|Turn around|\t|Response time |");
	printf("\n------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("|    %-6s|\t|     %-7d|\t|    %-6d|\t|     %-7d|\t|     %-6d|\t|     %-9d|\n",a[i].id,a[i].arr_time,a[i].burst_time,a[i].wait_time,a[i].turn_time,a[i].resp_time);
	}
	printf("------------------------------------------------------------------------------------------------\n");
	printf("\t\t  Average time  \t\t|   %-9.2f|\t|   %-8.2f|\t|    %-10.2f|",avg_wait,avg_turn,avg_resp);
	printf("\n------------------------------------------------------------------------------------------------\n");
}
void PNP(struct process a[],int n)
{
	a=sort_based_on_arrival_time(a,n);
	struct process b[n];
	int i,k,wait=0;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			a[i].wait_time=0;
			a[i].resp_time=0;
			a[i].turn_time=a[i].burst_time;
			if(wait<=a[i].arr_time)
				wait=a[i].burst_time+a[i].arr_time;
			else
				wait=a[i].burst_time;
			a[i].flag=1;
			b[i]=a[i];

		}
		else
		{
			k=get_high_priority_job(a,n,wait);
			if(k==0)
				k=i;
			if(wait<a[k].arr_time)
				wait=a[k].arr_time;
			a[k].wait_time=wait-a[k].arr_time;
			a[k].turn_time=a[k].wait_time+a[k].burst_time;
			a[k].resp_time=a[k].wait_time;
			wait=wait+a[k].burst_time;
			a[k].flag=1;
			b[i]=a[k];
		}
	}
	display_table(b,n);
	display_gantt(b,n);
}
void PP(struct process a[],int n)
{
	a=sort_based_on_arrival_time(a,n);
	struct process temp[n];
	int fl[n];
	struct job b[30];
	struct process job[3*n];
	int i=0,k=0,wait=0,t=0,f=0,j,p,count=0;
	for(i=0;i<n;i++)
	{
		temp[i]=a[i];
		a[i].wait_time=0;
		fl[i]=0;
	}
	i=0;
	//printf("\n%d  %d\n",wait,k);
	while(1)
	{
		if(i<n){	
		//if(f==1)
		//	i=k;
		label:
		if(terminate(a,n)==1)
			break;
		f=0;
		if(wait<=a[i].arr_time)
			wait=a[i].arr_time;
		if(fl[i]!=1)
		{
			a[i].resp_time=wait-a[i].arr_time;
			temp[i].resp_time=wait-a[i].arr_time;
			fl[i]=1;
		}
		strcpy(b[t].id,temp[i].id);
		b[t].start=wait;
		for(j=1;j<=temp[i].burst_time;j++)
		{
			wait=wait+1;
			temp[i].burst_time--;
			j--;
			if(temp[i].burst_time==0)
			{
				b[t].end=wait;
				a[i].flag=1;
				temp[i].flag=1;
				//comp=i;
			}
			//l:
			//printf("\n%s",temp[i].id);
			k=get_high_priority_job_preemptive(a,temp,n,wait);
			//if(comp==k)
			//	goto l;
		//	printf("\n%d  %d\n",wait,k);
			if(k!=-1 && k!=i)
			{
				b[t].end=wait;
				t++;
				f=1;
				i=k;
				goto label;
			}
		}
		//if(f!=1)
		//	i++;
	}
	}
	b[t].end=wait;
	t++;
	//for(i=0;i<t;i++)
	//{
	//	printf("\n%s    start= %d   end= %d",b[i].id,b[i].start,b[i].end);
	//}
	for(i=0;i<n;i++)
	{
		for(j=0;j<t;j++)
		{
			if(strcmp(a[i].id,b[j].id)==0)
			{
				a[i].wait_time=a[i].wait_time+(b[j].start-temp[i].arr_time);
				temp[i].arr_time=b[j].end;
			}
		}
		a[i].turn_time=a[i].burst_time+a[i].wait_time;
	}
	display_table(a,n);
	display_gantt_p(b,t);
	
}
struct queue*update(struct queue *q,struct process a[],int n,int max)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i].arr_time <= max && a[i].flag==0)
			enqueue(q,i);
	}
	return q;
}
void RR(struct process a[],int n,int slice)
{
	a=sort_based_on_arrival_time(a,n);
	struct process temp[n];
	int fl[n];
	struct job b[30];
	struct process job[3*n];
	struct queue *q;
	q=init();
	int i=0,k=0,wait=0,t=0,f=0,j,p,count=0;
	for(i=0;i<n;i++)
	{
		temp[i]=a[i];
		a[i].wait_time=0;
		fl[i]=0;
	}
	i=0;
	q=update(q,a,n,a[i].arr_time);
	while(1)
	{
		if(i<n){	
		//if(f==1)
		//	i=k;
		label:
		if(terminate(a,n)==1)
			break;
		f=0;
		//if(wait<=a[i].arr_time)
		//	wait=a[i].arr_time;
		if(fl[i]!=1)
		{
			a[i].resp_time=wait-a[i].arr_time;
			temp[i].resp_time=wait-a[i].arr_time;
			fl[i]=1;
		}
		strcpy(b[t].id,temp[i].id);
		b[t].start=wait;
		for(j=1;j<=slice;j++)
		{
			wait=wait+1;
			temp[i].burst_time--;
			j--;
			if(temp[i].burst_time==0)
			{
				b[t].end=wait;
				a[i].flag=1;
				temp[i].flag=1;
				k=dequeue(q);
				q=update(q,a,n,wait);
				goto label;
				//comp=i;
			}
		}
		q=update(q,a,n,wait);
			//l:
			//printf("\n%s",temp[i].id);
			k=dequeue(q);
			printf("\n%d",k);
			//if(comp==k)
			//	goto l;
		//	printf("\n%d  %d\n",wait,k);
			if(k!=-1 && k!=i)
			{
				b[t].end=wait;
				t++;
				f=1;
				i=k;
				goto label;
			}
		//if(f!=1)
		//	i++;
	}
	}
	b[t].end=wait;
	t++;
	for(i=0;i<t;i++)
	{
		printf("\n%s    %d     %d",b[i].id,b[i].start,b[i].end);
	}
}
int main()
{
	int choice,choice1;
	struct process *p;
	int n,i,slice;
	printf("\n--------------------CPU SCHEDULING ALGORITHMS----------------\n");
	for(;;)
	{
		printf("\n1.Round Robin\n2.Priority\n3.EXIT\nEnter your option :");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nRound Robin CPU SCHEDULER\n\n");
			printf("Number of process:");
			scanf("%d",&n);
			p=(struct process*)malloc(sizeof(struct process)*n);	
			for(i=0;i<n;i++)
			{
				p[i]=input();
			}
			printf("\nEnter the slice value:");
			scanf("%d",&slice);
			RR(p,n,slice);
		}
		else if(choice==2)
		{
			printf("\n1.Non-Preemptive\n2.Preemptive\nEnter your choice:");
			scanf("%d",&choice1);
			if(choice1==1)
			{
				printf("\nPriority NON-PREEMPTIVE CPU SCHEDULER\n\n");
				printf("Number of process:");
				scanf("%d",&n);
				p=(struct process*)malloc(sizeof(struct process)*n);	
				for(i=0;i<n;i++)
				{
					p[i]=input();
				}
				PNP(p,n);
			}
			else if(choice1==2)
			{
				printf("\nPriority PREEMPTIVE CPU SCHEDULER\n\n");
				printf("Number of process:");
				scanf("%d",&n);
				p=(struct process*)malloc(sizeof(struct process)*n);	
				for(i=0;i<n;i++)
				{
					p[i]=input();
				}
			}
			PP(p,n);
		}
		else if(choice==3)
		{
			break;
		}
		else 
		{
			printf("\nYou typed a random choice\n");
		}
	}
	return 0;
}
/*Output:
PS F:\Study\SSN\4thSem\OS\Assignment> gcc cpus2.c -o a                                                                                                        PS F:\Study\SSN\4thSem\OS\Assignment> ./a                                                                                                                     
--------------------CPU SCHEDULING ALGORITHMS----------------

1.Round Robin
2.Priority
3.EXIT
Enter your option :2

1.Non-Preemptive
2.Preemptive
Enter your choice:1

Priority NON-PREEMPTIVE CPU SCHEDULER

Number of process:
7

Process ID   :p1
Arrival time :2
Burst time   :3
Priority     :4


Process ID   :p2
Arrival time :4
Burst time   :2
Priority     :4


Process ID   :p3
Arrival time :5
Burst time   :1
Priority     :1


Process ID   :p4
Arrival time :7
Burst time   :4
Priority     :2


Process ID   :p5
Arrival time :9
Burst time   :2
Priority     :7


Process ID   :p6
Arrival time :15
Burst time   :6
Priority     :6


Process ID   :p7
Arrival time :16
Burst time   :8
Priority     :3



------------------------------------------------------------------------------------------------
|Process_id|    |Arrival time|  |Burst time|    |Waiting time|  |Turn around|   |Response time |
------------------------------------------------------------------------------------------------
|    p1    |    |     2      |  |    3     |    |     0      |  |     3     |   |     0        |
|    p3    |    |     5      |  |    1     |    |     0      |  |     1     |   |     0        |
|    p2    |    |     4      |  |    2     |    |     2      |  |     4     |   |     2        |
|    p4    |    |     7      |  |    4     |    |     1      |  |     5     |   |     1        |
|    p5    |    |     9      |  |    2     |    |     3      |  |     5     |   |     3        |
|    p6    |    |     15     |  |    6     |    |     0      |  |     6     |   |     0        |
|    p7    |    |     16     |  |    8     |    |     5      |  |     13    |   |     5        |
------------------------------------------------------------------------------------------------
                  Average time                  |   1.57     |  |   5.29    |   |    1.57      |
------------------------------------------------------------------------------------------------


The Cpu is idle for time 0  to 2
The Cpu is idle for time 14 to 15

                                                GANTT CHART


                ----------------------------------------------------------------------------------------------------------
                |     p1       |     p3       |     p2       |     p4       |     p5       |     p6       |     p7       |
                ----------------------------------------------------------------------------------------------------------
                2              5              6              8              12             15             21             29

PS F:\Study\SSN\4thSem\OS\Assignment> gcc cpus2.c -o a                                                                                                        PS F:\Study\SSN\4thSem\OS\Assignment> ./a                                                                                                                     
--------------------CPU SCHEDULING ALGORITHMS----------------

1.Round Robin
2.Priority
3.EXIT
Enter your option :2

1.Non-Preemptive
2.Preemptive
Enter your choice:2

Priority PREEMPTIVE CPU SCHEDULER

Number of process:5

Process ID   :p1
Arrival time :0
Burst time   :6
Priority     :2


Process ID   :p2
Arrival time :1
Burst time   :2
Priority     :2


Process ID   :p3
Arrival time :1
Burst time   :3
Priority     :4


Process ID   :p4
Arrival time :2
Burst time   :1
Priority     :1


Process ID   :p5
Arrival time :2
Burst time   :2
Priority     :3



------------------------------------------------------------------------------------------------
|Process_id|    |Arrival time|  |Burst time|    |Waiting time|  |Turn around|   |Response time |
------------------------------------------------------------------------------------------------
|    p1    |    |     0      |  |    6     |    |     1      |  |     7     |   |     0        |
|    p3    |    |     1      |  |    3     |    |     10     |  |     13    |   |     10       |
|    p2    |    |     1      |  |    2     |    |     6      |  |     8     |   |     6        |
|    p5    |    |     2      |  |    2     |    |     7      |  |     9     |   |     7        |
|    p4    |    |     2      |  |    1     |    |     0      |  |     1     |   |     0        |
------------------------------------------------------------------------------------------------
                  Average time                  |   4.80     |  |   7.60    |   |    4.60      |
------------------------------------------------------------------------------------------------



                                                GANTT CHART


                -------------------------------------------------------------------------------------------
                |     p1       |     p4       |     p1       |     p2       |     p5       |     p3       |
                -------------------------------------------------------------------------------------------
                0              2              3              7              9              11             14
 */