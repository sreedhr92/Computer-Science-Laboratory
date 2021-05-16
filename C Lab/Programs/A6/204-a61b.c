#include<stdio.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
};
void main()
{
	int n;
	struct student stu;
	printf("Enter the student name :");
	scanf("%s",&stu.name);
	printf("enter the no.of subject:");
	scanf("%d",&n);
	int i=0,sum=0;
	for(i=0;i<n;i++)
	{
		printf("Enter the subject %d marks:",i+1);
		scanf("%d",&stu.m[i]);
		sum+=stu.m[i];
	}
	stu.avg=sum/n;
	printf("The Average of %s is %.3f",stu.name,stu.avg);
}
/*output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 204-a61b.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the student name :yeshwa
enter the no.of subject:5
Enter the subject 1 marks:100
Enter the subject 2 marks:99
Enter the subject 3 marks:98
Enter the subject 4 marks:95
Enter the subject 5 marks:97
The Average of yeshwa is 97.000
*/