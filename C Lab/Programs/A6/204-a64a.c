#include<stdio.h>
#include<string.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
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
	int i,j;
	float temp;
	char t[100];
	int te;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg<stu[j].avg)
			{
				temp=stu[i].avg;
				stu[i].avg=stu[j].avg;
				stu[j].avg=temp;
				strcpy(t,stu[i].name);
				strcpy(stu[i].name,stu[j].name);
				strcpy(stu[j].name,t);
				te=fail[i];
				fail[i]=fail[j];
				fail[j]=te;
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		if(fail[i]==0)
		{
			printf("\nName:%-10s|Avg: %-7.3f|Rank:%d\n",stu[i].name,stu[i].avg,i+1);
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
/*output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 204-a64a.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :4
Enter the number of subjects :2
Enter the student name :yesh
Enter the Subject 1 marks :99
Enter the Subject 2 marks :98
Enter the student name :krish
Enter the Subject 1 marks :97
Enter the Subject 2 marks :89
Enter the student name :killer
Enter the Subject 1 marks :88
Enter the Subject 2 marks :98
Enter the student name :sandy
Enter the Subject 1 marks :89
Enter the Subject 2 marks :89

Name :yesh      |Marks :99   98

Name :krish     |Marks :97   89

Name :killer    |Marks :88   98

Name :sandy     |Marks :89   89

The Average of yesh is 98.000

The Average of krish is 93.000

The Average of killer is 93.000

The Average of sandy is 89.000

The Class average is 93.250

The passpercentage of the class is 100.000

The failpercentage of the class is 0.000

Name:yesh      |Avg: 98.000 |Rank:1

Name:krish     |Avg: 93.000 |Rank:2

Name:killer    |Avg: 93.000 |Rank:3

Name:sandy     |Avg: 89.000 |Rank:4*/