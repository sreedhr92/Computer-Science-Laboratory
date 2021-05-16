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
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A64a.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :5
Enter the number of subjects :3
Enter the student name :fassil
Enter the Subject 1 marks :98
Enter the Subject 2 marks :97
Enter the Subject 3 marks :96
Enter the student name :kanomo
Enter the Subject 1 marks :96
Enter the Subject 2 marks :95
Enter the Subject 3 marks :100
Enter the student name :joseph
Enter the Subject 1 marks :66
Enter the Subject 2 marks :87
Enter the Subject 3 marks :90
Enter the student name :Rajan
Enter the Subject 1 marks :77
Enter the Subject 2 marks :88
Enter the Subject 3 marks :99
Enter the student name :surya
Enter the Subject 1 marks :99
Enter the Subject 2 marks :00
Enter the Subject 3 marks :99

Name :fassil    |Marks :98   97   96

Name :kanomo    |Marks :96   95   100

Name :joseph    |Marks :66   87   90

Name :Rajan     |Marks :77   88   99

Name :surya     |Marks :99   0    99

The Average of fassil is 97.000

The Average of kanomo is 97.000

The Average of joseph is 81.000

The Average of Rajan is 88.000

The Average of surya is 66.000

The Class average is 85.800

The passpercentage of the class is 80.000

The failpercentage of the class is 20.000

Name:fassil    |Avg: 97.000 |Rank:1

Name:kanomo    |Avg: 97.000 |Rank:2

Name:Rajan     |Avg: 88.000 |Rank:3

Name:joseph    |Avg: 81.000 |Rank:4

Name:surya     |Avg: 66.000 |Rank:FAIL*/