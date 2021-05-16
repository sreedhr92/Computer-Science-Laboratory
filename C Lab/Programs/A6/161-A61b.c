#include<stdio.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
};
int input(struct student stu)
{
	int n=0,x;
	do
	{
		printf("Enter the subject %d marks:",n+1);
		scanf("%d",&stu.m[n]);
		n++;
		printf("Continue press 1 to stop press 0:");
		scanf("%d",&x);
	}while(x!=0);
	return n;
}
void main()
{
	int i,n;
	struct student stu;
	printf("Enter the student name :");
	scanf("%s",&stu.name);
	n=input(stu);
	float sum=0;
	for(i=0;i<n;i++)
	{
		sum+=stu.m[i];
	}
	stu.avg=sum/n;
	printf("The Average of %s is %.3f",stu.name,stu.avg);
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A61b.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the student name :david
Enter the subject 1 marks:34
Continue press 1 to stop press 0:1
Enter the subject 2 marks:56
Continue press 1 to stop press 0:1
Enter the subject 3 marks:45
Continue press 1 to stop press 0:1
Enter the subject 4 marks:89
Continue press 1 to stop press 0:0
The Average of david is 56.000*/