#include<stdio.h>
#include<string.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
	int rank;
};
int input(struct student stu[],int i,int m)
{
	int k,flag=0;
	printf("Enter the student name :");
	scanf("%s",&stu[i].name);
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
		printf("\nName :%-10s|Marks :",stu[i].name);
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
	for(i=0;i<n;i++)
	{
		if(stu[i].rank!=0)
		{
			printf("\nName:%-10s|Avg: %-7.3f|Rank:%d\n",stu[i].name,stu[i].avg,stu[i].rank);
		}
		else
		{
			printf("\nName:%-10s|Avg: %-7.3f|Rank:FAIL\n",stu[i].name,stu[i].avg);
		}	
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
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A64b.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :7
Enter the number of subjects :2
Enter the student name :john
Enter the Subject 1 marks :99
Enter the Subject 2 marks :100
Enter the student name :jony
Enter the Subject 1 marks :100
Enter the Subject 2 marks :99
Enter the student name :ram
Enter the Subject 1 marks :100
Enter the Subject 2 marks :99
Enter the student name :mahi
Enter the Subject 1 marks :97
Enter the Subject 2 marks :96
Enter the student name :virot
Enter the Subject 1 marks :97
Enter the Subject 2 marks :96
Enter the student name :david
Enter the Subject 1 marks :77
Enter the Subject 2 marks :93
Enter the student name :maxwell
Enter the Subject 1 marks :33
Enter the Subject 2 marks :22

Name :john      |Marks :99   100

Name :jony      |Marks :100  99

Name :ram       |Marks :100  99

Name :mahi      |Marks :97   96

Name :virot     |Marks :97   96

Name :david     |Marks :77   93

Name :maxwell   |Marks :33   22

The Average of john is 99.000

The Average of jony is 99.000

The Average of ram is 99.000

The Average of mahi is 96.000

The Average of virot is 96.000

The Average of david is 85.000

The Average of maxwell is 27.000

The Class average is 85.857

The passpercentage of the class is 85.714

The failpercentage of the class is 14.286

Name:john      |Avg: 99.000 |Rank:1

Name:jony      |Avg: 99.000 |Rank:1

Name:ram       |Avg: 99.000 |Rank:1

Name:mahi      |Avg: 96.000 |Rank:4

Name:virot     |Avg: 96.000 |Rank:4

Name:david     |Avg: 85.000 |Rank:6

Name:maxwell   |Avg: 27.000 |Rank:FAIL*/