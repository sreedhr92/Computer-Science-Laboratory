#include<stdio.h>
struct student
{
	int m1,m2,m3;
	char name[100];
	float avg;
};
void main()
{
	struct student stu;
	printf("Enter the student name :");
	scanf("%s",stu.name);
	printf("Enter the mark of sub 1 :" );
	scanf("%d",&stu.m1);
	printf("Enter the mark of sub 2 :");
	scanf("%d",&stu.m2);
	printf("Enter the mark of sub 3 :");
	scanf("%d",&stu.m3);
	stu.avg=(stu.m1+stu.m2+stu.m3)/3;
	printf("The average of %s is %.3f",stu.name,stu.avg);
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A61a.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the student name :david
Enter the mark of sub 1 :78
Enter the mark of sub 2 :89
Enter the mark of sub 3 :78
The average of david is 81.000*/