#include<stdio.h>
#include<string.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
	int rank;
	int regno;
};
int input(struct student stu[],int i,int m)
{
	int k,flag=0;
	printf("Enter the student name :");
	scanf("%s",&stu[i].name);
	printf("Enter the Regno :");
	scanf("%d",&stu[i].regno);
	for(k=0;k<m;k++)
	{
		printf("Enter the Subject %d marks :",k+1);
		scanf("%d",&stu[i].m[k]);
		if(stu[i].m[k]<50)
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		return 1;
	}	
	else
	{
		return 0;
	}
}
void average(struct student stu[],int n,int k)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=stu[k].m[i];
	}
	stu[k].avg=sum/n;
}
void output(struct student stu[],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\nRegno:%d     |Name :%-10s|Marks :",stu[i].regno,stu[i].name);
		for(j=0;j<m;j++)
		{
			printf("%-5d",stu[i].m[j]);
		}
		printf("\n");	
	}
	for(i=0;i<n;i++)
	{
		printf("\nThe Average of %s is %.3f\n",stu[i].name,stu[i].avg);
	}	
}
void classaverage(struct student stu[],int n)
{
	int i;
	float total;
	for(i=0;i<n;i++)
	{
		total+=stu[i].avg;
	}
	printf("\nThe Class average is %.3f\n",total/n);
}
void passpercentage(int fail[],int n)
{
	int i;
	float count=0,pp,fp;
	for(i=0;i<n;i++)
	{
		if(fail[i]!=0)
		{
			count++;
		}
	}
	fp=(count/n)*100;
	pp=100-fp;
	printf("\nThe passpercentage of the class is %.3f\n\nThe failpercentage of the class is %.3f\n",pp,fp);
}
void rank(struct student stu[],int n,int fail[])
{
	int i,j,k,te;
	float temp;
	char t[100];
	struct student temp1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg<stu[j].avg)
			{
				temp1=stu[i];
				stu[i]=stu[j];
				stu[j]=temp1;
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		if(fail[i]==1)
		{
			stu[i].rank=0;
		}
		else
		{
			stu[i].rank=i+1;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg==stu[j].avg)
			{
				stu[j].rank=stu[i].rank;
			}
		}
	}	
}
void searchrecord(struct student stu[],int n)
{
	int x,y,se,flag=0,r,i;
	char sea[100];
	printf("\nOptions to view the records:\n1.All records\n2.Particular Record\nEnter the option:");
	error:
	scanf("%d",&x);
	if(x==1)
	{
		for(i=0;i<n;i++)
		{
			if(stu[i].rank!=0)
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
			}
			else
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
			}	
		}
	}
	else if(x==2)
	{
		printf("Options to search Record:\n1.By Regno\n2.By Name\nEnter the Option:");
		e:	
		scanf("%d",&y);
		if(y==1)
		{
			printf("Enter the Regno:");
			a:
			scanf("%d",&se);
			for(i=0;i<n;i++)
			{
				if(stu[i].regno==se)
				{
					if(stu[i].rank!=0)
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
					}
					else
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
					}
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("Invalid Register no.! Please retry\nEnter the Register no. correctly atleast this time:");
				goto a;
			}
		}
		else if(y==2)
		{
			printf("Enter the Name(case sensitive!):");
			s:
			scanf("%s",sea);
			for(i=0;i<n;i++)
			{
				r=strcmp(stu[i].name,sea);
				if(r==0)
				{
					if(stu[i].rank!=0)
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
					}
					else
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
					}
					flag=1;
					break;
				}	
			}
			if(flag==0)
			{
				printf("Invalid Name! Please retry\nEnter the Name correctly atleast this time:");
				goto s;
			}
		}
		else
		{
			printf("Invalid Option! Please retry\nEnter the option correctly atleast this time:");
			goto e;
		}
	}
	else
	{
		printf("Invalid Option! Please retry\nEnter the option correctly atleast this time:");
		goto error;
	}
}
void main()
{
	int n,i,m;
	printf("Enter the number of students :");
	scanf("%d",&n);
	printf("Enter the number of subjects :");
	scanf("%d",&m);
	int fail[n];
	struct student stu[n];
	for(i=0;i<n;i++)
	{
		fail[i]=input(stu,i,m);
		average(stu,m,i);
	}
	output(stu,n,m);
	classaverage(stu,n);
	passpercentage(fail,n);
	rank(stu,n,fail);
	searchrecord(stu,n);
}