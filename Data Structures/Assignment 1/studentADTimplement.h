//0.routine to allocate memory for the maxsize for list...
struct student
{
	int regno;
	char name[30];
	float marks;
	float marks2;
	float marks3;
	float total;
	char result;
};

//creating a structure for listADT to contain the details of the students........
struct listADT
{
	struct student *a;
	int size,maxsize;
};
void initialize(struct listADT *l)
{
	l->maxsize=100;
	l->size=0;
	l->a =(struct student)malloc(sizeof(struct student)*l->maxsize); 

}

//1.routine to insert a record at the front........
void insertfront(struct listADT *l, struct student s)
{
	int i;
	//checking whether the list is full or empty
	if(l->size==l->maxsize)
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
		l->a[l->size+1]=s;
		l->size++;
	}
}

//3.routine to insert a record with the insert regno......
void insertregno(struct listADt *l,struct student s,int regno)
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
				for(j=l->size-1;j>i;j--)
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

//5.routine to get structure of students which matches the nmae entered........
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
			if(i>j)
			{
				temp=regno[j];
				regno[j]=regno[i];
				regno[i]=temp;
			}
		}
	}
	struct student *result;
	result =(struct student)malloc(sizeof(struct student)*k); 
	for(i=0;i<i->size;i++)
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
		return a;
	}
}

//6.routine to delete a record in the listADT.......
void deletestudent(struct listADT *l,int regno)
{
	int i,j;
	for(i=0;i<l->size;i++)
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
void computeResult(struct listADT l)
{
	int i,j;
	for(i=0;i<l->size;i++)
	{
		l->a[i].float total = l->a[i].mark1 + l->a[i].mark2 +l->a[i].mark3;
		if(l->a[i].mark1<50 && l->a[i].mark2<50 && l->a[i].marks<50 == 1)
		{
			l->a[i].result="F";
		}
		else
		{
			l->a[i].result="P";
		}
	}
}

//8.routine to return the list of students who have passed.............
struct student *listResult(struct listADT l)
{
	int i,k=0,f=0;
	struct student *result;
	for(i=0;i<l->size;i++)
	{
		if(l->a[i].result=="P")
		{
			f=1;
			k++;
		}
	}
	result=(struct student)malloc(sizeof(struct student)*k);
	for(i=0;i<l->size;i++)
	{
		if(l->a[i].result=="P")
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
		return a;
	}

		
//9.routine to return the number of students woh passed in first class...........
int listclass(struct listADt l)	
{
	int i,count =0;
	for(i=0;i<l->size;i++)
	{
		if(l->a[i].mark>90 && l->a[i].mark2>90 && l->a[i].mark3 >90 ==1)
		{
			count++;
		}
	}		
	return count;
}



	
