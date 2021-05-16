#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct process
{
	int n,nr;
	char **pid;
	char *rid;
	int *available;
	int **allocated,**max,**need;
	int *flag;//indicating the process is completed or not
};

struct process read_data()
{
	struct process x;
	int i,j;
	printf("\nEnter the no. of process:");
	scanf("%d",&x.n);
	x.pid=(char**)malloc(sizeof(char*)*x.n);
	x.flag=(int*)malloc(sizeof(int)*x.n);
	printf("\nEnter the process_id in Sequence:\n");
	for(i=0;i<x.n;i++)
	{
		x.pid[i]=(char*)malloc(sizeof(char*)*3);
		printf("\nEnter id:");
		scanf("%s",x.pid[i]);
		x.flag[i]=0;
	}
	printf("\nEnter the no. of resources:");
	scanf("%d",&x.nr);
	x.rid=(char*)malloc(sizeof(char)*x.nr);
	x.available=(int*)malloc(sizeof(int)*x.nr);
	for(i=0;i<x.nr;i++)
	{
		printf("\nEnter name:");
		scanf(" %c",&x.rid[i]);
		printf("\nEnter the available instance:");
		scanf("%d",&x.available[i]);
	}
	x.allocated=(int**)malloc(sizeof(int*)*x.n);
	x.max=(int**)malloc(sizeof(int*)*x.n);
	x.need=(int**)malloc(sizeof(int*)*x.n);
	for(i=0;i<x.n;i++)
	{
		x.allocated[i]=(int*)malloc(sizeof(int)*x.nr);
		x.max[i]=(int*)malloc(sizeof(int)*x.nr);
		x.need[i]=(int*)malloc(sizeof(int)*x.nr);
	}
	printf("\nEnter the maximum requirement array:\n");
	for(i=0;i<x.n;i++)
	{
		printf("\nProcess ---> %s|\n",x.pid[i]);
		for(j=0;j<x.nr;j++)
		{
			printf("\nInstance of %c :",x.rid[j]);
			scanf("%d",&x.max[i][j]);
		}
	}
	printf("\nEnter the Allocated array:\n");
	for(i=0;i<x.n;i++)
	{
		printf("\nProcess ---> %s|\n",x.pid[i]);
		for(j=0;j<x.nr;j++)
		{
			printf("\nInstance of %c :",x.rid[j]);
			scanf("%d",&x.allocated[i][j]);
		}
	}
	//Calculating the need matrix
	for(i=0;i<x.n;i++)
	{
		for(j=0;j<x.nr;j++)
		{
			x.need[i][j]=x.max[i][j]-x.allocated[i][j];
		}
	}
	return x;
}

void print_data(struct process a)
{
	int i,j,k;
	printf("\nPid\tAllocated\tMaximum \t  Need   \t  Avail  \n");
	for(j=0;j<4;j++)
	{
		printf("   \t");
		for(i=0;i<a.nr;i++)
		{
			printf("%-3c",a.rid[i]);
		}
	}	
	for(i=0;i<a.n;i++)
	{
		printf("\n%-3s",a.pid[i]);
		for(k=0;k<4;k++)
		{
			printf("\t");
			for(j=0;j<a.nr;j++)
			{
				if(k==0)
					printf("%-3d",a.allocated[i][j]);
				else if(k==1)
					printf("%-3d",a.max[i][j]);
				else if(k==2)
					printf("%-3d",a.need[i][j]);
				else if(k==3 && i==0)
					printf("%-3d",a.available[j]);
			}
		}	
	}	

}
int completed(struct process a)
{
	int i;
	for(i=0;i<a.n;i++)
	{
		if(a.flag[i]==0)
			return 1;
	}
	return -1;
}
int get_pid_index(struct process a,char pid[])
{
	int i;
	for(i=0;i<a.n;i++)
	{
		if(strcmp(pid,a.pid[i])==0)
			return i;
	}
}
void safety_sequence(struct process a)
{
	int sequence[a.n];
	int i=0,j,flag=0,k=0,count=0,s=0,l;
	while(1)
	{
		flag=0;
		if(completed(a)==-1)
		{
			s=1;
			break;
		}
		if(count>100)
			break;
		for(j=0;j<a.nr;j++)
		{
			if(a.need[i][j]>a.available[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0 && a.flag[i]==0)
		{
			//printf("\nprocess :%d",i);
			for(j=0;j<a.nr;j++)
			{
				a.available[j]+=a.allocated[i][j];
			}
			sequence[k]=i;
			k++;
			a.flag[i]=1;
		}
		i=(i+1)%a.n;
		count++;
	}
	if(s==1)
	{
		printf("\nThe Saftey sequence is:|");
		for(i=0;i<a.n;i++)
		{
			printf(" %s  ",a.pid[sequence[i]]);
		}
		printf("|");
	}
	else
	{
		printf("\nCount =%d",count);
		printf("\nThe System is not in a safe state(Deadlock)");
	}	
}
void request(struct process a)
{
	int i,j,flag=0;
	int request[a.nr];
	char pid[3];
	printf("\nEnter the process id:");
	scanf("%s",pid);
	printf("Enter the request resouce :");
	flag=0;
	for(j=0;j<a.nr;j++)
	{
		printf("\nInstance of %c :",a.rid[j]);
		scanf("%d",&request[j]);
	}
	i=get_pid_index(a,pid);
	for(j=0;j<a.nr;j++)
	{
		if(request[j]>a.need[i][j])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		for(j=0;j<a.nr;j++)
		{
			if(request[j]>a.available[j])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		for(j=0;j<a.nr;j++)
		{
			a.available[j]-=request[j];
			a.allocated[i][j]+=request[j];
			a.need[i][j]-=request[j];
		}
		printf("\nProcess %s can be granted immediately because the system is in the safe state");
		safety_sequence(a);
	}
	else
	{
		printf("\nProcess %s can't be granted immediately it has to wait to undergo safety algorithm");
	}
}

void main()
{
	int x,n;
	struct process a;
	printf("\n\t********BANKER's Algorithm********");
	for(;;){
	printf("\n\n1.Read data\n2.Print data\n3.Safety Sequence\n4.Exit\nEnter the choice:");
	scanf("%d",&x);
	if(x==1)
		a=read_data();
	else if(x==2)
		print_data(a);
	else if(x==3)
	{
		int choice;
		printf("\n1.Request and safety sequence\n2.safety sequence\nEnter choice:");
		scanf("%d",&choice);
		if(choice==1)
			request(a);
		else
			safety_sequence(a);
	}
	else if(x==4)
		break;
	else
		printf("\nInvalid input");
	}

}
/*
PS F:\Study\SSN\4thSem\OS\Ass 7> gcc bankers.c -o a
PS F:\Study\SSN\4thSem\OS\Ass 7> ./a

        ********BANKER's Algorithm********

1.Read data
2.Print data
3.Safety Sequence
4.Exit
Enter the choice:1

Enter the no. of process:5

Enter the process_id in Sequence:

Enter id:p0

Enter id:p1

Enter id:p2

Enter id:p3

Enter id:p4

Enter the no. of resources:3

Enter name:A

Enter the available instance:3

Enter name:B

Enter the available instance:3

Enter name:C

Enter the available instance:2

Enter the maximum requirement array:

Process ---> p0|

Instance of A :7

Instance of B :5

Instance of C :2

Process ---> p1|

Instance of A :3

Instance of B :2

Instance of C :2

Process ---> p2|

Instance of A :9

Instance of B :0

Instance of C :2

Process ---> p3|

Instance of A :2

Instance of B :2

Instance of C :2

Process ---> p4|

Instance of A :4

Instance of B :3

Instance of C :3

Enter the Allocated array:

Process ---> p0|

Instance of A :0

Instance of B :1

Instance of C :0

Process ---> p1|

Instance of A :2

Instance of B :0

Instance of C :0

Process ---> p2|

Instance of A :3

Instance of B :0

Instance of C :2

Process ---> p3|

Instance of A :2

Instance of B :1

Instance of C :1

Process ---> p4|

Instance of A :0

Instance of B :0

Instance of C :2


1.Read data
2.Print data
3.Safety Sequence
4.Exit
Enter the choice:2

Pid     Allocated       Maximum           Need            Avail
        A  B  C         A  B  C         A  B  C         A  B  C
p0      0  1  0         7  5  2         7  4  2         3  3  2
p1      2  0  0         3  2  2         1  2  2
p2      3  0  2         9  0  2         6  0  0
p3      2  1  1         2  2  2         0  1  1
p4      0  0  2         4  3  3         4  3  1

1.Read data
2.Print data
3.Safety Sequence
4.Exit
Enter the choice:3

1.Request and safety sequence
2.safety sequence
Enter choice:2

The Saftey sequence is:| p1   p3   p4   p0   p2  |*/