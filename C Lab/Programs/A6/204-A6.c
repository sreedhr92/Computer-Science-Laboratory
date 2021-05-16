  //Qno.1(a): 
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
/*output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 204-a61a.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the student name :yeshwa
Enter the mark of sub 1 :197
Enter the mark of sub 2 :198
Enter the mark of sub 3 :195
The average of yeshwa is 196.000*/

//Qno.1(b):
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

//Qno.1(c):
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

//Qno.2:
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

//Qno.3:
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
The Class average is 93.333
PS C:\TDM-GCC-64\myprogram\A6> gcc 204-a62.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ^C
PS C:\TDM-GCC-64\myprogram\A6> gcc 204-a63.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :3
Enter the number of subjects :2
Enter the student name :rohit
Enter the Subject 1 marks :56
Enter the Subject 2 marks :67
Enter the student name :dhoni
Enter the Subject 1 marks :100
Enter the Subject 2 marks :100
Enter the student name :singh
Enter the Subject 1 marks :89
Enter the Subject 2 marks :87
The Average of rohit is 61.000
The Average of dhoni is 100.000
The Average of singh is 88.000
The Class average is 83.000*/

//Qno.4(a):
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