#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
	int regno;
	char name[30];
	float mark1;
	float mark2;
	float mark3;
	float total;
	char result;
};

//creating a structure for listADT to contain the details of the students........
struct listADT
{
	struct student *a;
	int size,maxsize;
};

void initialize(struct listADT *l);

void insertfront(struct listADT *l,struct student s);

void insertend(struct listADT *l,struct student s);

void insertregno(struct listADT *l,struct student s,int regno);

struct student searchregno(struct listADT *l,int regno);

struct student *searchname(struct listADT *l,char name[]);

void deletestudent(struct listADT *l,int regno);

void computeresult(struct listADT *l);

struct student *listResult(struct listADT *l);

int listclass(struct listADT *l);
void initialize(struct listADT *l)
{
	l->maxsize=100;
	l->size=0;
	l->a =(struct student *)malloc(sizeof(struct student)*(l->maxsize)); 

}

//1.routine to insert a record at the front........
void insertfront(struct listADT *l, struct student s)
{
	int i;
	//checking whether the list is full or empty
	if(l->size-1==l->maxsize)
	{
		printf("NO more element can be added");
	}
	else if(l->size==0)
	{
		l->a[0]=s;
		l->size++;
	}
	else
	{
		for(i=l->size-1;i>=0;i--)
		{
			l->a[i+1]=l->a[i];
		}
		l->a[0]=s;
		l->size++;
	}
}

//2.routine to insert a record at the end........
void insertend(struct listADT *l,struct student s)
{
	int i;
	//checking whether the list is full or empty
	if(l->size==0)
	{
		l->a[0]=s;
	}
	else if(l->size==l->maxsize)
	{
		printf("NO more elements can be added to list");
	}
	else
	{
		l->a[l->size]=s;
		l->size++;
	}
}

//3.routine to insert a record with the insert regno......
void insertregno(struct listADT *l,struct student s,int regno)
{
	int i,j;
	//checking whether the list is full or empty
	if(l->size==l->maxsize)
	{
		printf("NO more element can be added");
	}	
	else if(l->size==0)
	{
		printf("List is empty no regno is searched");
	}
	else
	{
		for(i=0;i<l->size;i++)
		{
			if(regno==l->a[i].regno)
			{
				for(j=l->size-1;j>=i+1;j--)
				{
					l->a[j+1]=l->a[j];
				}
				l->a[i+1]=s;
				l->size++;
				break;
			}
		}
	}
}

//4.routine to search a student's regno and return student.............
struct student searchregno(struct listADT *l,int regno)
{
	int i,f=0;
	for(i=0;i<l->size;i++)
	{
		if(regno==l->a[i].regno)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		return l->a[i];
	}
	else
	{
		printf("Not found");
		struct student a={0,"\0",0,0,0,0,'\0'};
		return a;
	}
}

//5.routine to get structure of students which matches the name entered........
struct student *searchname(struct listADT *l,char name[])
{
	int i,j,temp,k=0,f=0;
	int regno[l->size];
	for(i=0;i<l->size;i++)
	{
		if(strcmp(name,l->a[i].name)==0)
		{
			regno[k]=l->a[i].regno;
			k++;
			f=1;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(regno[i]>regno[j])
			{
				temp=regno[j];
				regno[j]=regno[i];
				regno[i]=temp;
			}
		}
	}
	struct student *result;
	result =(struct student *)malloc(sizeof(struct student)*k); 
	for(i=0;i<(l->size);i++)
	{
		if(regno[i]==l->a[i].regno)
		{
			result[i]=l->a[i];
		}
	}
	if(f==1)
	{
		return result;
	}
	else
	{
		printf("NOt found");
		struct student a={0,"\0",0,0,0,0,'\0'};
		return &a;
	}
}
int search(struct listADT *l,char name[])
{
	int i,k=0;
	for(i=0;i<(l->size);i++)
	{
		if(strcmp(name,l->a[i].name)==0)
		{
			k++;
		}
	}
	return k;
}
//6.routine to delete a record in the listADT.......
void deletestudent(struct listADT *l,int regno)
{
	int i,j;
	for(i=0;i<(l->size);i++)
	{
		if(regno==l->a[i].regno)
		{
			for(j=i;j<l->size;j++)
			{
				l->a[j]=l->a[j+1];
			}
		}
	}
	l->size--;
}
//7.routine to compute result for all the students in listadt
void computeResult(struct listADT *l)
{
	int i,j;
	for(i=0;i<(l->size);i++)
	{
		l->a[i].total = l->a[i].mark1 + l->a[i].mark2 +l->a[i].mark3;
		if(l->a[i].mark1<50 && l->a[i].mark2<50 && l->a[i].mark3<50 == 1)
		{
			l->a[i].result='F';
		}
		else
		{
			l->a[i].result='P';
		}
	}
}

//8.routine to return the list of students who have passed.............
struct student *listResult(struct listADT *l)
{
	int i,k=0,f=0;
	struct student *result;
	for(i=0;i<(l->size);i++)
	{
		if(l->a[i].result=='P')
		{
			f=1;
			k++;
		}
	}
	result=(struct student *)malloc(sizeof(struct student)*k);
	for(i=0;i<(l->size);i++)
	{
		if(l->a[i].result=='P')
		{
			result[i]=l->a[i];
		}
	}
	if(f==1)
	{
		return result;
	}
	else
	{
		printf("Not found");
		struct student a={0,"\0",0,0,0,0,'\0'};
		return &a;
	}
}
int pass(struct listADT *l)
{
	int i,k=0;
	for(i=0;i<(l->size);i++)
	{
		if(l->a[i].result=='P')
		{
			k++;
		}
	}
	return k;
}
		
//9.routine to return the number of students woh passed in first class...........
int listclass(struct listADT *l)	
{
	int i,count =0;
	for(i=0;i<l->size;i++)
	{
		if(l->a[i].mark1>90 && l->a[i].mark2>90 && l->a[i].mark3 >90 ==1)
		{
			count++;
		}
	}		
	return count;
}



	


struct student input()
{
	struct student s;
	printf("Enter the regno:");
	scanf("%d",&s.regno);
	printf("Enter the Name:");
	scanf("%s",&s.name);
	printf("Enter the Mark 1:");
	scanf("%f",&s.mark1);
	printf("Enter the Mark 2:");
	scanf("%f",&s.mark2);
	printf("Enter the Mark 3:");
	scanf("%f",&s.mark3);
	return s;
}
void printstudentrecord(struct listADT *l)
{
	int i;
	for(i=0;i<l->size;i++)
	{
		printf("\nStudent %d\n",i+1);
		printf("Name:%s\n",l->a[i].name);
		printf("Regno:%d\n",l->a[i].regno);
		printf("Mark 1 :%f\n",l->a[i].mark1);
		printf("Mark 2 :%f\n",l->a[i].mark3);
		printf("Mark 3 :%f\n",l->a[i].mark3);
		printf("Total :%f\n",l->a[i].total);
		printf("Result :%c\n",l->a[i].result);
	}	
}
void printstudentrecord2(struct student *a,int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		printf("\nStudent %d\n",i+1);
		printf("Name    :%s\n",(a+i)->name);
		printf("Regno   :%d\n",(a+i)->regno);
		printf("Mark 1  :%f\n",(a+i)->mark1);
		printf("Mark 2  :%f\n",(a+i)->mark3);
		printf("Mark 3  :%f\n",(a+i)->mark3);
		printf("Total   :%f\n",(a+i)->total);
		printf("Result  :%c\n",(a+i)->result);
	}	
}

void print(struct student s)
{
		printf("Name   :%s\n",s.name);
		printf("Regno  :%d\n",s.regno);
		printf("Mark 1 :%f\n",s.mark1);
		printf("Mark 2 :%f\n",s.mark3);
		printf("Mark 3 :%f\n",s.mark3);
		printf("Total  :%f\n",s.total);
		printf("Result :%c\n",s.result);
}
void main()
{
	struct student s;
	struct listADT l;
	int x,regno,n;
	char name[30];
	initialize(&l);
	printf("\nMENU:\n1.Insert a record at the front of the list.\n2.Insert a record at the end of the list.\n3.Insert a record after a given Regno.\n4.List the records of students based on his register number.\n6.Delete a given student record given his register number.\n7.Calculate the total and result\n8.List of students passed\n9.Number of students secured first class\n10.Exit");
	do
	{
	printf("\nPress the option:");
	scanf("%d",&x);
	switch(x)
	{
		case 1: printf("Enter the details of the student to be entered in the list\n");
				s=input();
				insertfront(&l,s);
				printf("Inserted Successfully\n");
				printstudentrecord(&l);
				break;
		case 2: printf("Enter the details of the student to be entered in the list\n");
				s=input();
				insertend(&l,s);
				printf("Inserted Successfully\n");
				printstudentrecord(&l);
				break;	
		case 3:	printf("Enter the details of the student to be entered in the list\n");
				s=input();
				printf("\nEnter regno: ");
				scanf("%d",&regno);
				insertregno(&l,s,regno);
				printf("Inserted Successfully\n");
				printstudentrecord(&l);
				break;			
		case 4:	printf("\nEnter regno to search: ");
				scanf("%d",&regno);
				s=searchregno(&l,regno);
				print(s);
				break;
		case 5: printf("\nEnter the name to search :");
				scanf("%s",&name);
				int k=search(&l,name);
				printstudentrecord2(searchname(&l,name),k);		
				break;
		case 6: printf("\nEnter regno to Delete: ");
				scanf("%d",&regno);
				deletestudent(&l,regno);
				printf("Deleted Successfully\n");
				printstudentrecord(&l);
				break;
		case 7: computeResult(&l);	
				printstudentrecord(&l);	
				break;
		case 8:	n=pass(&l);
				printstudentrecord2(listResult(&l),n);
				break;
		case 9: printf("Number of students secured first class=%d",listclass(&l));	
				break;
		default:printf("Invalid option entered");				
	}
	}while(x!=10);
}

