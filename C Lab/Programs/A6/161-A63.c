#include<stdio.h>
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
void output(struct student stu[],int n)
{
	printf("The Average of %s is %.3f\n",stu[n].name,stu[n].avg);
}
void classaverage(struct student stu[],int n)
{
	int i;
	float total;
	for(i=0;i<n;i++)
	{
		total+=stu[i].avg;
	}
	printf("The Class average is %.3f\n",total/n);
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
	printf("The passpercentage of the class is %.3f\nThe failpercentage of the class is %.3f",pp,fp);
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
	for(i=0;i<n;i++)
	{
		output(stu,i);
	}
	classaverage(stu,n);
	passpercentage(fail,n);
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A63.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :4
Enter the number of subjects :3
Enter the student name :hari
Enter the Subject 1 marks :78
Enter the Subject 2 marks :89
Enter the Subject 3 marks :90
Enter the student name :money
Enter the Subject 1 marks :56
Enter the Subject 2 marks :34
Enter the Subject 3 marks :86
Enter the student name :jaanmeri
Enter the Subject 1 marks :55
Enter the Subject 2 marks :100
Enter the Subject 3 marks :34
Enter the student name :lolip
Enter the Subject 1 marks :84
Enter the Subject 2 marks :66
Enter the Subject 3 marks :44
The Average of hari is 85.000
The Average of money is 58.000
The Average of jaanmeri is 63.000
The Average of lolip is 64.000
The Class average is 67.500
The passpercentage of the class is 25.000
The failpercentage of the class is 75.000*/