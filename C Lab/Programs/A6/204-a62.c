#include<stdio.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
};
void inputmarks(struct student stu[],int k,int j)
{
	int i;
	for(i=0;i<j;i++)
	{
		printf("Enter the Subject %d marks :",i+1);
		scanf("%d",&stu[k].m[i]);
	}
}
void input(struct student stu[],int i,int m)
{
	printf("Enter the student name :");
	scanf("%s",&stu[i].name);
	inputmarks(stu,i,m);
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
	float total=0;
	for(i=0;i<n;i++)
	{
		total+=stu[i].avg;
	
	}
	printf("The Class average is %.3f",total/n);
}
void main()
{
	int n,i,m;
	printf("Enter the number of students :");
	scanf("%d",&n);
	printf("Enter the number of subjects :");
	scanf("%d",&m);
	struct student stu[n];
	for(i=0;i<n;i++)
	{
		input(stu,i,m);
		average(stu,m,i);
	}
	for(i=0;i<n;i++)
	{
		output(stu,i);
	}
	classaverage(stu,n);
}
/*output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 204-a62.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :3
Enter the number of subjects :3
Enter the student name :candy
Enter the Subject 1 marks :98
Enter the Subject 2 marks :99
Enter the Subject 3 marks :99
Enter the student name :germs
Enter the Subject 1 marks :89
Enter the Subject 2 marks :98
Enter the Subject 3 marks :97
Enter the student name :goldy
Enter the Subject 1 marks :78
Enter the Subject 2 marks :89
Enter the Subject 3 marks :98
The Average of candy is 98.000
The Average of germs is 94.000
The Average of goldy is 88.000
The Class average is 93.333*/