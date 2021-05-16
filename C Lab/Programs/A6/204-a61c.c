#include<stdio.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
};
int input(struct student stu[],int k)
{
	int n=0,x;
	do
	{
		printf("Enter the subject %d marks :",n+1);
		scanf("%d",&stu[k].m[n]);
		n++;
		printf("Continue press 1 to stop press 0 :");
		scanf("%d",&x);
	}while(x!=0);
	return n;
}
void main()
{
	struct student stu[100];
	int k=0,x;
	do
	{
	int n;
	printf("Enter the student name :");
	scanf("%s",&stu[k].name);
	n=input(stu,k);
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=stu[k].m[i];
	}
	printf("The Average of %s of %d subject is %.3f\n",stu[k].name,n,stu[k].avg=sum/n);
	k++;
	printf("To stop press 0 :");
	scanf("%d",&x);
	}while(x!=0);
}
/*output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 204-a61c.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the student name :yeshwa
Enter the subject 1 marks :98
Continue press 1 to stop press 0 :1
Enter the subject 2 marks :97
Continue press 1 to stop press 0 :1
Enter the subject 3 marks :95
Continue press 1 to stop press 0 :0
The Average of yeshwa of 3 subject is 96.000
*/
