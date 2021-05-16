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