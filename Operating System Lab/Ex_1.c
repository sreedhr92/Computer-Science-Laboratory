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
	int flag;
};
struct job
{
	int start,end;
	char id[20];
};
struct process input()
{
	struct process x;
	printf("\nProcess ID   :");
	scanf("%s",x.id);
	printf("Arrival time :");
	scanf("%d",&x.arr_time);
	printf("Burst time   :");
	scanf("%d",&x.burst_time);
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
int get_short_job(struct process a[],int n,int max)
{
	int i,j,k=0;
	int job[n];
	int min_burst_time;
	int min_burst_index;
	for(i=1;i<n;i++)
	{
		if(a[i].arr_time<=max&&a[i].flag==0)
		{	
			job[k]=a[i].burst_time;
			k++;
		}
	}
	if(k==0)
		return 0;
	min_burst_time=job[0];
	for(i=1;i<k;i++)
	{
		if(min_burst_time>job[i])
			min_burst_time=job[i];
	}
	for(i=1;i<n;i++)
	{
		if(min_burst_time==a[i].burst_time&&a[i].flag==0)
		{	
			min_burst_index=i;
			break;
		}	
	}
	return min_burst_index;
}
int get_short_job_preemptive(struct process temp[],struct process a[],int n,int max)
{
	int i,j,k=0;
	int job[n];
	int min_burst_time;
	int min_burst_index;
	for(i=0;i<n;i++)
	{
		if(a[i].arr_time<=max && a[i].flag==0 && temp[i].flag==0)
		{	
			job[k]=a[i].burst_time;
			k++;
		}
	}
	if(k==0)
		return -1;
	min_burst_time=job[0];
	for(i=0;i<k;i++)
	{
		if(min_burst_time > job[i])
			min_burst_time = job[i];
	}
	for(i=0;i<n;i++)
	{
		if(min_burst_time==a[i].burst_time && a[i].flag==0 && temp[i].flag==0)
		{	
			min_burst_index=i;
			break;
		}	
	}
	return min_burst_index;
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
void FCFS(struct process a[],int n)
{
	int i;
	a=sort_based_on_arrival_time(a,n);	
	printf("\nThe process will be executed on this order[ FCFS ]\n");
	for(i=0;i<n;i++)
	{
		printf("\n %s",a[i].id);
	}
	int wait=0;
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
		}
		else
		{
			if(wait<a[i].arr_time)
				wait=a[i].arr_time;
			a[i].wait_time=wait-a[i].arr_time;
			a[i].turn_time=a[i].wait_time+a[i].burst_time;
			a[i].resp_time=a[i].wait_time;
			wait=wait+a[i].burst_time;
		}
	}
	display_table(a,n);
	display_gantt(a,n);
	
}
void SJFNP(struct process a[],int n)
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
			k=get_short_job(a,n,wait);
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
void SJFP(struct process a[],int n)
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
			k=get_short_job_preemptive(a,temp,n,wait);
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
int main()
{
	int choice,choice1;
	struct process *p;
	int n,i;
	printf("\n--------------------CPU SCHEDULING ALGORITHMS----------------\n");
	for(;;)
	{
		printf("\n1.FCFS\n2.SJF\n3.EXIT\nEnter your option :");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nFCFS CPU SCHEDULER\n\n");
			printf("Number of process:");
			scanf("%d",&n);
			p=(struct process*)malloc(sizeof(struct process)*n);	
			for(i=0;i<n;i++)
			{
				p[i]=input();
			}
			FCFS(p,n);
		}
		else if(choice==2)
		{
			printf("\n1.Non-Preemptive\n2.Preemptive\nEnter your choice:");
			scanf("%d",&choice1);
			if(choice1==1)
			{
				printf("\nSJF NON-PREEMPTIVE CPU SCHEDULER\n\n");
				printf("Number of process:");
				scanf("%d",&n);
				p=(struct process*)malloc(sizeof(struct process)*n);	
				for(i=0;i<n;i++)
				{
					p[i]=input();
				}
				SJFNP(p,n);
			}
			else if(choice1==2)
			{
				printf("\nSJF PREEMPTIVE CPU SCHEDULER\n\n");
				printf("Number of process:");
				scanf("%d",&n);
				p=(struct process*)malloc(sizeof(struct process)*n);	
				for(i=0;i<n;i++)
				{
					p[i]=input();
				}
			}
			SJFP(p,n);
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
/*OUTPUT:

1.FCFS
2.SJF
3.EXIT
Enter your option :1

FCFS CPU SCHEDULER

Number of process:7

Process ID   :p1
Arrival time :2
Burst time   :3


Process ID   :p2
Arrival time :4
Burst time   :2


Process ID   :p3
Arrival time :5
Burst time   :1


Process ID   :p4
Arrival time :7
Burst time   :4


Process ID   :p5
Arrival time :9
Burst time   :2


Process ID   :p6
Arrival time :15
Burst time   :6


Process ID   :p7
Arrival time :16
Burst time   :8


The process will be executed on this order[ FCFS ]

 p1
 p2
 p3
 p4
 p5
 p6
 p7

------------------------------------------------------------------------------------------------
|Process_id|    |Arrival time|  |Burst time|    |Waiting time|  |Turn around|   |Response time |
------------------------------------------------------------------------------------------------
|    p1    |    |     2      |  |    3     |    |     0      |  |     3     |   |     0        |
|    p2    |    |     4      |  |    2     |    |     1      |  |     3     |   |     1        |
|    p3    |    |     5      |  |    1     |    |     2      |  |     3     |   |     2        |
|    p4    |    |     7      |  |    4     |    |     1      |  |     5     |   |     1        |
|    p5    |    |     9      |  |    2     |    |     3      |  |     5     |   |     3        |
|    p6    |    |     15     |  |    6     |    |     0      |  |     6     |   |     0        |
|    p7    |    |     16     |  |    8     |    |     5      |  |     13    |   |     5        |
------------------------------------------------------------------------------------------------
                  Average time                  |   1.71     |  |   5.43    |   |    1.71      |
------------------------------------------------------------------------------------------------


The Cpu is idle for time 0  to 2
The Cpu is idle for time 14 to 15

                                                GANTT CHART


                ----------------------------------------------------------------------------------------------------------
                |     p1       |     p2       |     p3       |     p4       |     p5       |     p6       |     p7       |
                ----------------------------------------------------------------------------------------------------------
                2              5              7              8              12             15             21             29
1.FCFS
2.SJF
3.EXIT
Enter your option :2

1.Non-Preemptive
2.Preemptive
Enter your choice:1

SJF NON-PREEMPTIVE CPU SCHEDULER

Number of process:7

Process ID   :p1
Arrival time :2
Burst time   :3


Process ID   :p2
Arrival time :4
Burst time   :2


Process ID   :p3
Arrival time :5
Burst time   :1


Process ID   :p4
Arrival time :7
Burst time   :4


Process ID   :p5
Arrival time :9
Burst time   :2


Process ID   :p6
Arrival time :15
Burst time   :6


Process ID   :p7
Arrival time :16
Burst time   :8



----------------------------------------------------------------------------------------------------------------------------------------
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


1.FCFS
2.SJF
3.EXIT
Enter your option :2

1.Non-Preemptive
2.Preemptive
Enter your choice:2

SJF PREEMPTIVE CPU SCHEDULER

Number of process:5

Process ID   :p1
Arrival time :0
Burst time   :8


Process ID   :p2
Arrival time :1
Burst time   :6


Process ID   :p3
Arrival time :2
Burst time   :1


Process ID   :p4
Arrival time :3
Burst time   :9


Process ID   :p5
Arrival time :4
Burst time   :3



------------------------------------------------------------------------------------------------
|Process_id|    |Arrival time|  |Burst time|    |Waiting time|  |Turn around|   |Response time |
------------------------------------------------------------------------------------------------
|    p1    |    |     0      |  |    8     |    |     10     |  |     18    |   |     0        |
|    p2    |    |     1      |  |    6     |    |     4      |  |     10    |   |     0        |
|    p3    |    |     2      |  |    1     |    |     0      |  |     1     |   |     0        |
|    p4    |    |     3      |  |    9     |    |     15     |  |     24    |   |     15       |
|    p5    |    |     4      |  |    3     |    |     0      |  |     3     |   |     0        |
------------------------------------------------------------------------------------------------
                  Average time                  |   5.80     |  |   11.20   |   |    3.00      |
------------------------------------------------------------------------------------------------



                                                GANTT CHART


                -------------------------------------------------------------------------------------------------------------------------
                |     p1       |     p2       |     p3       |     p2       |     p5       |     p2       |     p1       |     p4       |
                -------------------------------------------------------------------------------------------------------------------------
                0              1              2              3              4              7              11             18             27
1.FCFS
2.SJF
3.EXIT*/
