#include<stdio.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
};
void inputmarks(struct student stu[],int k,int j,FILE *fp)
{
	int i;
	fp=fopen("Input1.txt","w");
	for(i=0;i<j;i++)
	{
		printf("Enter the Subject %d marks :",i+1);
		scanf("%d",&stu[k].m[i]);
		fprintf(fp,"%d",stu[k].m[i]);
	}
	fclose(fp);
}
void input(struct student stu[],int i,int m,FILE *fp)
{
	fp=fopen("Input1.txt","w");
	printf("Enter the student name :");
	scanf("%s",&stu[i].name);
	fprintf(fp,"%s",stu[i].name);
	inputmarks(stu,i,m,fp);
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
void output(struct student stu[],int n,FILE *fp1)
{
	fp1=fopen("Output1.txt","w");
	printf("The Average of %s is %.3f\n",stu[n].name,stu[n].avg);
	fclose(fp1);
}
void classaverage(struct student stu[],int n,FILE *fp1)
{
	int i;
	fp1=fopen("Output1","w");
	float total=0;
	for(i=0;i<n;i++)
	{
		total+=stu[i].avg;
	
	}
	printf("The Class average is %.3f",total/n);
	fprintf(fp1,"%f",stu[i].avg);
	fclose(fp1);
}
void main()
{
	int n,i,m;
	FILE *fp,*fp1;
	fp=fopen("Input1.txt","w");
	fp1=fopen("Output1.txt","w");
	printf("Enter the number of students :");
	scanf("%d",&n);
	fprintf(fp,"%d",n);
	printf("Enter the number of subjects :");
	scanf("%d",&m);
	fprintf(fp,"%d",n);
	struct student stu[n];
	for(i=0;i<n;i++)
	{
		input(stu,i,m,fp);
		average(stu,m,i);
	}
	for(i=0;i<n;i++)
	{
		output(stu,i,fp1);
	}
	classaverage(stu,n,fp1);
}