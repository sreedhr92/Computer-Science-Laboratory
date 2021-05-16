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
		printf("Enter the subject %d marks",n+1);
		scanf("%d",stu.m[n]);
		n++;
		printf("Continue press 1 to stop press 0");
		scanf("%d",&x);
	}while(x!=0);
	return n;
}
void main()
{
	struct student stu;
	printf("Enter the student name :");
	scanf("%s",&stu.name);
	int n=input(stu);
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=stu.m[i];
	}
	printf("The Average of %s is %f",stu.name,stu.avg=sum/n);

}