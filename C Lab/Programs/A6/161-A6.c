//question 1(a):
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

//qno.1(b):
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

//Q.no. 1(c):
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
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A61c.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the student name :brazil
Enter the subject 1 marks :89
Continue press 1 to stop press 0 :1
Enter the subject 2 marks :78
Continue press 1 to stop press 0 :1
Enter the subject 3 marks :76
Continue press 1 to stop press 0 :0
The Average of brazil of 3 subject is 81.000
To stop press 0 :1
Enter the student name :naveen
Enter the subject 1 marks :56
Continue press 1 to stop press 0 :1
Enter the subject 2 marks :87
Continue press 1 to stop press 0 :1
Enter the subject 3 marks :66
Continue press 1 to stop press 0 :0
The Average of naveen of 3 subject is 69.000
To stop press 0 :0*/

//Q.no.2:
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
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A62.c -o a
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
Enter the Subject 1 marks :66
Enter the Subject 2 marks :44
Enter the Subject 3 marks :23
The Average of hari is 85.000
The Average of money is 58.000
The Average of jaanmeri is 63.000
The Average of lolip is 44.000
The Class average is 62.500*/

//Q.NO:3:
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


//Q.NO:4(A):
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

//Q.NO:4(B):
#include<stdio.h>
#include<string.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
	int rank;
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
	int i,j,k,te;
	float temp;
	char t[100];
	struct student temp1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg<stu[j].avg)
			{
				temp1=stu[i];
				stu[i]=stu[j];
				stu[j]=temp1;
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		if(fail[i]==1)
		{
			stu[i].rank=0;
		}
		else
		{
			stu[i].rank=i+1;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg==stu[j].avg)
			{
				stu[j].rank=stu[i].rank;
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		if(stu[i].rank!=0)
		{
			printf("\nName:%-10s|Avg: %-7.3f|Rank:%d\n",stu[i].name,stu[i].avg,stu[i].rank);
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
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A64b.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :7
Enter the number of subjects :2
Enter the student name :john
Enter the Subject 1 marks :99
Enter the Subject 2 marks :100
Enter the student name :jony
Enter the Subject 1 marks :100
Enter the Subject 2 marks :99
Enter the student name :ram
Enter the Subject 1 marks :100
Enter the Subject 2 marks :99
Enter the student name :mahi
Enter the Subject 1 marks :97
Enter the Subject 2 marks :96
Enter the student name :virot
Enter the Subject 1 marks :97
Enter the Subject 2 marks :96
Enter the student name :david
Enter the Subject 1 marks :77
Enter the Subject 2 marks :93
Enter the student name :maxwell
Enter the Subject 1 marks :33
Enter the Subject 2 marks :22

Name :john      |Marks :99   100

Name :jony      |Marks :100  99

Name :ram       |Marks :100  99

Name :mahi      |Marks :97   96

Name :virot     |Marks :97   96

Name :david     |Marks :77   93

Name :maxwell   |Marks :33   22

The Average of john is 99.000

The Average of jony is 99.000

The Average of ram is 99.000

The Average of mahi is 96.000

The Average of virot is 96.000

The Average of david is 85.000

The Average of maxwell is 27.000

The Class average is 85.857

The passpercentage of the class is 85.714

The failpercentage of the class is 14.286

Name:john      |Avg: 99.000 |Rank:1

Name:jony      |Avg: 99.000 |Rank:1

Name:ram       |Avg: 99.000 |Rank:1

Name:mahi      |Avg: 96.000 |Rank:4

Name:virot     |Avg: 96.000 |Rank:4

Name:david     |Avg: 85.000 |Rank:6

Name:maxwell   |Avg: 27.000 |Rank:FAIL*/

//Q.NO:5:
#include<stdio.h>
#include<string.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
	int rank;
	int regno;
};
int input(struct student stu[],int i,int m)
{
	int k,flag=0;
	printf("Enter the student name :");
	scanf("%s",&stu[i].name);
	printf("Enter the Regno :");
	scanf("%d",&stu[i].regno);
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
		printf("\nRegno:%d     |Name :%-10s|Marks :",stu[i].regno,stu[i].name);
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
	int i,j,k,te;
	float temp;
	char t[100];
	struct student temp1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg<stu[j].avg)
			{
				temp1=stu[i];
				stu[i]=stu[j];
				stu[j]=temp1;
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		if(fail[i]==1)
		{
			stu[i].rank=0;
		}
		else
		{
			stu[i].rank=i+1;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg==stu[j].avg)
			{
				stu[j].rank=stu[i].rank;
			}
		}
	}	
}
void searchrecord(struct student stu[],int n)
{
	int x,y,se,flag=0,r,i;
	char sea[100];
	printf("\nOptions to view the records:\n1.All records\n2.Particular Record\nEnter the option:");
	error:
	scanf("%d",&x);
	if(x==1)
	{
		for(i=0;i<n;i++)
		{
			if(stu[i].rank!=0)
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
			}
			else
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
			}	
		}
	}
	else if(x==2)
	{
		printf("Options to search Record:\n1.By Regno\n2.By Name\nEnter the Option:");
		e:	
		scanf("%d",&y);
		if(y==1)
		{
			printf("Enter the Regno:");
			a:
			scanf("%d",&se);
			for(i=0;i<n;i++)
			{
				if(stu[i].regno==se)
				{
					if(stu[i].rank!=0)
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
					}
					else
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
					}
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("Invalid Register no.! Please retry\nEnter the Register no. correctly atleast this time:");
				goto a;
			}
		}
		else if(y==2)
		{
			printf("Enter the Name(case sensitive!):");
			s:
			scanf("%s",sea);
			for(i=0;i<n;i++)
			{
				r=strcmp(stu[i].name,sea);
				if(r==0)
				{
					if(stu[i].rank!=0)
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
					}
					else
					{
						printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
					}
					flag=1;
					break;
				}	
			}
			if(flag==0)
			{
				printf("Invalid Name! Please retry\nEnter the Name correctly atleast this time:");
				goto s;
			}
		}
		else
		{
			printf("Invalid Option! Please retry\nEnter the option correctly atleast this time:");
			goto e;
		}
	}
	else
	{
		printf("Invalid Option! Please retry\nEnter the option correctly atleast this time:");
		goto error;
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
	searchrecord(stu,n);
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A65.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :7
Enter the number of subjects :2
Enter the student name :john
Enter the Regno :1
Enter the Subject 1 marks :99
Enter the Subject 2 marks :100
Enter the student name :jony
Enter the Regno :2
Enter the Subject 1 marks :99
Enter the Subject 2 marks :100
Enter the student name :ram
Enter the Regno :3
Enter the Subject 1 marks :100
Enter the Subject 2 marks :99
Enter the student name :mahi
Enter the Regno :4
Enter the Subject 1 marks :97
Enter the Subject 2 marks :96
Enter the student name :virot
Enter the Regno :5
Enter the Subject 1 marks :97
Enter the Subject 2 marks :96
Enter the student name :maxwell
Enter the Regno :33
Enter the Subject 1 marks :22
Enter the Subject 2 marks :33
Enter the student name :david
Enter the Regno :7
Enter the Subject 1 marks :77
Enter the Subject 2 marks :93

Regno:1     |Name :john      |Marks :99   100

Regno:2     |Name :jony      |Marks :99   100

Regno:3     |Name :ram       |Marks :100  99

Regno:4     |Name :mahi      |Marks :97   96

Regno:5     |Name :virot     |Marks :97   96

Regno:33     |Name :maxwell   |Marks :22   33

Regno:7     |Name :david     |Marks :77   93

The Average of john is 99.000

The Average of jony is 99.000

The Average of ram is 99.000

The Average of mahi is 96.000

The Average of virot is 96.000

The Average of maxwell is 27.000

The Average of david is 85.000

The Class average is 85.857

The passpercentage of the class is 85.714

The failpercentage of the class is 14.286

Options to view the records:
1.All records
2.Particular Record
Enter the option:2
Options to search Record:
1.By Regno
2.By Name
Enter the Option:1
Enter the Regno:33

Regno:33     |Name:maxwell   |Avg: 27.000   |Rank:7*/

//QNO. 6:
#include<stdio.h>
#include<string.h>
//definition of the structure for a student... 
struct student
{
	int m[100];
	char name[100];
	float avg;
	int rank;
	int regno;
	int fail;
};
//Getting input from the function...
int input(struct student stu[],int i,int m)
{
	int k,flag=0;
	printf("Enter the student name :");
	scanf("%s",&stu[i].name);
	printf("Enter the Regno :");
	scanf("%d",&stu[i].regno);
	for(k=0;k<m;k++)
	{
		printf("Enter the Subject %d marks :",k+1);
		scanf("%d",&stu[i].m[k]);
		//setting 0s and 1s for the failures and no failures...
		if(stu[i].m[k]<50)
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		stu[i].fail=1;
	}	
	else
	{
		stu[i].fail=0;
	}
}
//finding average of the each struct by this function.....
void average(struct student stu[],int n,int k)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=stu[k].m[i];
	}
	stu[k].avg=sum/n;
}
//printing the output in a tabulated form......
void output(struct student stu[],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\nRegno:%-7d|Name :%-10s|Marks :",stu[i].regno,stu[i].name);
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
//finding the class average.........
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
//finding the pass percentage of the class...
void passpercentage(struct student stu[],int n)
{
	int i;
	float count=0,pp,fp;
	for(i=0;i<n;i++)
	{
		if(stu[i].fail!=0)
		{
			count++;
		}
	}
	fp=(count/n)*100;
	pp=100-fp;
	printf("\nThe passpercentage of the class is %.3f\n\nThe failpercentage of the class is %.3f\n",pp,fp);
}
//giving the rank and skipping the rank if they got same average.....
void rank(struct student stu[],int n)
{
	int i,j,k,te;
	float temp;
	char t[100];
	struct student temp1;
	//sorting the structures in a decending order based on the average got by the students...
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg<stu[j].avg)
			{
				temp1=stu[i];
				stu[i]=stu[j];
				stu[j]=temp1;
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		if(stu[i].fail==1)
		{
			stu[i].rank=0;
		}
		else
		{
			stu[i].rank=i+1;
		}
	}
	//skipping rank segment....
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i].avg==stu[j].avg)
			{
				stu[j].rank=stu[i].rank;
			}
		}
	}
	//printing the rank......
	for(i=0;i<n;i++)
	{
		if(stu[i].rank!=0)
		{
			printf("\nRegno:%-7d|Name:%-10s|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].rank);
		}
		else
		{
			printf("\nRegno:%-7d|Name:%-10s|Rank:FAIL\n",stu[i].regno,stu[i].name);
		}	
	}	
}
//Searching the record of students by name.....
void searchrecordbyname(struct student stu[],int n)
{
	int flag=0,r,i;
	char sea[100];
	printf("Enter the Name(case sensitive!):");
	s:
	scanf("%s",sea);
	for(i=0;i<n;i++)
	{
		r=strcmp(stu[i].name,sea);
		if(r==0)
		{
			if(stu[i].rank!=0)
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
			}
			else
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
			}
			flag=1;
			break;
		}
	}		
	if(flag==0)
	{
		printf("Invalid Name! Please retry\nEnter the Name correctly atleast this time:");
		goto s;
	}	
}
//searching the record by regno....
void searchrecordbyregno(struct student stu[],int n)
{
	int se,flag=0,i;
	printf("Enter the Regno:");
	a:
	scanf("%d",&se);
	for(i=0;i<n;i++)
	{
		if(stu[i].regno==se)
		{
			//if a person is fail in alteast one subject they given fail
			if(stu[i].rank!=0)
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:%d\n",stu[i].regno,stu[i].name,stu[i].avg,stu[i].rank);
			}
			else
			{
				printf("\nRegno:%d     |Name:%-10s|Avg: %-9.3f|Rank:FAIL\n",stu[i].regno,stu[i].name,stu[i].avg);
			}
			flag=1;
			break;
		}
	}	
	if(flag==0)
	{
		printf("Invalid Register no.! Please retry\nEnter the Register no. correctly atleast this time:");
		goto a;
	}	
}
//displaying the record of all students including their marks,average,rank,no of failures...
void Display(struct student stu[],int n,int m)
{
	int j,i,count=0;
	for(i=0;i<n;i++)
	{
		printf("\nRegno:%-5d|Name:%-10s|Marks:",stu[i].regno,stu[i].name);
		for(j=0;j<m;j++)
		{
				printf("%-5d",stu[i].m[j]);
		}	
		if(stu[i].rank!=0)
			{
				printf("|Avg: %-9.3f|Rank:%d\n",stu[i].avg,stu[i].rank);
			}
			else
			{
				printf("|Avg: %-9.3f|Rank:FAIL\n",stu[i].avg);
			}
	}
	//counting the no. of failures...		
	for(i=0;i<n;i++)
	{
		if(stu[i].fail==0)
		{
			count++;
		}
	}
	printf("\nNumbers of passed students:%d         Numbers of failures:%d\n",count,n-count);
}
void main()
{
	int n,i,m,x;
	printf("Enter the number of students :");
	scanf("%d",&n);
	printf("Enter the number of subjects :");
	scanf("%d",&m);
	//declaration of the structure variables....
	struct student stu[n];
	printf("MENU:\n1.Read Input\n2.Find Average\n3.Class Average\n4.Pass Percentage\n5.Rank\n6.Search By Regno\n7.Search By Name\n8.Display Student Records\n9.Exit");
	//forming a menu driven function....
	a:
	printf("\nEnter your Option:");
	scanf("%d",&x);
	if(x==9)
	{
		printf("\nBYE");
	}
	//getting the option......
	if(x!=9)
	{
		switch(x)
		{
			case 1:for(i=0;i<n;i++)
					{
						input(stu,i,m);
					}
					goto a;
			case 2:for(i=0;i<n;i++)
					{
						average(stu,m,i);
					}
					output(stu,n,m);
					goto a;
			case 3:	classaverage(stu,n);goto a;
			case 4: passpercentage(stu,n);goto a;
			case 5: rank(stu,n);goto a;
			case 7: searchrecordbyname(stu,n);goto a;	
			case 6: searchrecordbyregno(stu,n);goto a;
			case 8: Display(stu,n,m);goto a;
			default:printf("Invalid option!");goto a;
		}
	}	
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A66.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :7
Enter the number of subjects :3
MENU:
1.Read Input
2.Find Average
3.Class Average
4.Pass Percentage
5.Rank
6.Search By Regno
7.Search By Name
8.Display Student Records
9.Exit
Enter your Option:1
Enter the student name :mahi
Enter the Regno :1
Enter the Subject 1 marks :89
Enter the Subject 2 marks :98
Enter the Subject 3 marks :89
Enter the student name :virat
Enter the Regno :45
Enter the Subject 1 marks :Enter the Subject 2 marks :
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A66.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :7
Enter the number of subjects :3
MENU:
1.Read Input
2.Find Average
3.Class Average
4.Pass Percentage
5.Rank
6.Search By Regno
7.Search By Name
8.Display Student Records
9.Exit
Enter your Option:1
Enter the student name :mahi
Enter the Regno :1
Enter the Subject 1 marks :89
Enter the Subject 2 marks :98
Enter the Subject 3 marks :89
Enter the student name :virat
Enter the Regno :2
Enter the Subject 1 marks :45
Enter the Subject 2 marks :67
Enter the Subject 3 marks :1
Enter the student name :kohli
Enter the Regno :3
Enter the Subject 1 marks :90
Enter the Subject 2 marks :90
Enter the Subject 3 marks :96
Enter the student name :harshal
Enter the Regno :4
Enter the Subject 1 marks :78
Enter the Subject 2 marks :76
Enter the Subject 3 marks :78
Enter the student name :bhajji
Enter the Regno :5
Enter the Subject 1 marks :80
Enter the Subject 2 marks :80
Enter the Subject 3 marks :83
Enter the student name :sunny
Enter the Regno :78
Enter the Subject 1 marks :76
Enter the Subject 2 marks :78
Enter the Subject 3 marks :78
Enter the student name :gambor
Enter the Regno :7
Enter the Subject 1 marks :51
Enter the Subject 2 marks :51
Enter the Subject 3 marks :50

Enter your Option:2

Regno:1      |Name :mahi      |Marks :89   98   89

Regno:2      |Name :virat     |Marks :45   67   1

Regno:3      |Name :kohli     |Marks :90   90   96

Regno:4      |Name :harshal   |Marks :78   76   78

Regno:5      |Name :bhajji    |Marks :80   80   83

Regno:78     |Name :sunny     |Marks :76   78   78

Regno:7      |Name :gambor    |Marks :51   51   50

The Average of mahi is 92.000

The Average of virat is 37.000

The Average of kohli is 92.000

The Average of harshal is 77.000

The Average of bhajji is 81.000

The Average of sunny is 77.000

The Average of gambor is 50.000

Enter your Option:3

The Class average is 72.286

Enter your Option:4

The passpercentage of the class is 85.714

The failpercentage of the class is 14.286

Enter your Option:5

Regno:1      |Name:mahi      |Rank:1

Regno:3      |Name:kohli     |Rank:1

Regno:5      |Name:bhajji    |Rank:3

Regno:4      |Name:harshal   |Rank:4

Regno:78     |Name:sunny     |Rank:4

Regno:7      |Name:gambor    |Rank:6

Regno:2      |Name:virat     |Rank:FAIL

Enter your Option:6
Enter the Regno:4

Regno:4     |Name:harshal   |Avg: 77.000   |Rank:4

Enter your Option:7
Enter the Name(case sensitive!):virat

Regno:2     |Name:virat     |Avg: 37.000   |Rank:FAIL

Enter your Option:8

Regno:1    |Name:mahi      |Marks:89   98   89   |Avg: 92.000   |Rank:1

Regno:3    |Name:kohli     |Marks:90   90   96   |Avg: 92.000   |Rank:1

Regno:5    |Name:bhajji    |Marks:80   80   83   |Avg: 81.000   |Rank:3

Regno:4    |Name:harshal   |Marks:78   76   78   |Avg: 77.000   |Rank:4

Regno:78   |Name:sunny     |Marks:76   78   78   |Avg: 77.000   |Rank:4

Regno:7    |Name:gambor    |Marks:51   51   50   |Avg: 50.000   |Rank:6

Regno:2    |Name:virat     |Marks:45   67   1    |Avg: 37.000   |Rank:FAIL

Numbers of passed students:6         Numbers of failures:1

Enter your Option:9

BYE
*/