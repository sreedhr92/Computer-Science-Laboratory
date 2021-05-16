#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct memoryBlock 
{
	int size,block_id;
	char name[10];
	int flag;
	struct memoryBlock *next; 
	struct memoryBlock *nextfile;
};
struct file
{
	char name[10];
	int size;
	int start,end;
};
struct memoryBlock* header()
{
	struct memoryBlock *h;
	h=(struct memoryBlock*)malloc(sizeof(struct memoryBlock));
	h->next=NULL;
	return h;
}
void insertend(struct memoryBlock *l,int value,int block_id)
{
	struct memoryBlock *temp,*temp1;
	temp=l;
	temp1=(struct memoryBlock*)malloc(sizeof(struct memoryBlock));
	temp1->size=value;
	temp1->block_id=block_id;
	temp1->flag=0;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp1->next=temp->next;
	temp->next=temp1;
}
void creatememoryBlock(struct memoryBlock *l,int n,int value)
{
	int i;
	for(i=0;i<n;i++)
	{
		insertend(l,value,i+1);
	}
}
int check(int random[],int num,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(random[i]==num)
			return 1;
	}
	return 0;
}
void print(struct memoryBlock *l)
{
	struct memoryBlock *temp;
	temp=l;
	printf("\n\n");
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("\tid=%d flag=%d",temp->block_id,temp->flag);
	}
}
void contiguous(struct memoryBlock *l,struct file f[],int total,int size,int n)
{
	printf("\nCONTIGUOUS ALLOCATION\nDirectory\n");
	printf("File name\tStart\tLength\n");
	int i,r,j,a;
	int flag;
	struct memoryBlock *temp;
	int blocks=total/size;
	srand(time(0));
	int allocated;
	//int random[blocks];
	int count,count1;
	//int k=0;
	struct memoryBlock *t;
	for(i=0;i<n;i++)
	{
		//print(l);
		//printf("\n\n");
		count1=0;
		label:
		if(count1==100)
		{
			printf("\nnot enough memory!\n");
			continue;
		}
		flag=0;
		allocated=0;
		temp=l;
		/*if(k>0)
		{
			label1:
			r=(rand()%blocks)+1;
			if(check(random,r,k)==0)
			{
				random[k]=r;
				k++;
			}
			else
			{
				goto label1;
			}
		}
		else
		{
			r=(rand()%blocks)+1;
			random[k]=r;
			k++;
		}*/
		r=(rand()%blocks)+1;
		count1++;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(r==temp->block_id)
				break;
		}
		t=temp;
		count=0;
		while(temp!=NULL)
		{
			if(temp->flag!=0)
			{
				flag=1;
				break;
			}
			allocated+=temp->size;
			temp=temp->next;
			count++;
			if(allocated>=f[i].size)
			{
				break;
			}
		}
		if(flag==1 || allocated < f[i].size)
			goto label;
		else
		{
			temp=t;
			printf("\n%s\t\t%d\t%d\n",f[i].name,temp->block_id,count);
			for(j=0;j<count;j++)
			{
				temp->flag=1;
				temp=temp->next;
			}
				//print(l);
				printf("\n");
				//printf("\n\n");
		}
	}
}
void linked(struct memoryBlock *l,struct file f[],int total,int size,int n)
{
	printf("\nLINKED ALLOCATION\nDirectory\n");
	printf("File name\tStart\tEND\n");
	int i,r,j,a=0;
	int flag;
	struct memoryBlock *temp;
	int blocks=total/size;
	srand(time(0));
	int allocated;
	int count,count1;
	int available=total;
	struct memoryBlock *t;
	for(i=0;i<n;i++)
	{
		t=NULL;
		if(f[i].size>available)
		{
			printf("%s\t\tNot Enough memory\n",f[i].name);
			continue;
		}
		allocated=0;
		count1=0;
		label:
		if(count1==100)
		{
			printf("\nnot enough memory!\n");
			continue;
		}
		flag=0;
		temp=l;
		r=(rand()%blocks)+1;
		count1++;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(r==temp->block_id)
				break;
		}
		if(temp->flag!=0)
		{
			flag=1;
		}
		else
		{
			if(a==0)
			{
				f[i].start=temp->block_id;
				a=1;
			}
			temp->nextfile=NULL;
			if(t!=NULL)
				t->nextfile=temp;
			t=temp;
			allocated+=temp->size;
			available-=temp->size;
			temp->flag=1;
		}	
		if(allocated>=f[i].size)
		{
			f[i].end=temp->block_id;
		}
		if(flag==1 || allocated < f[i].size)
			goto label;
		else
		{
			printf("%s\t\t%d\t%d\n",f[i].name,f[i].start,f[i].end);
			a=0;
		}
	}
	printf("\nIndividual File listing:\n");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t",f[i].name);
		temp=l;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(f[i].start==temp->block_id)
			{
				break;
			}
		}
		printf(" %d ->",temp->block_id);
		temp=temp->nextfile;
		while(temp!=NULL)
		{
			printf("%d ->",temp->block_id);
			temp=temp->nextfile;
		}
		printf("end\n");
	}
}
void indexed(struct memoryBlock *l,struct file f[],int total,int size,int n)
{
	printf("\nINDEXED ALLOCATION\nDirectory\n");
	printf("File name\tIndexed Block\n");
	int i,r,j=0,a=0;
	int flag;
	struct memoryBlock *temp;
	int blocks=total/size;
	srand(time(0));
	int allocated;
	int count,count1;
	int available=total;
	struct memoryBlock *t;
	int indexedBlock[n][blocks];
	int indexlength[n];
	for(i=0;i<n;i++)
	{
		t=NULL;
		a=0;
		if(f[i].size>available)
		{
			printf("%s\t\tNot Enough memory\n",f[i].name);
			f[i].start=-1;
			continue;
		}
		allocated=0;
		count1=0;
		label:
		if(count1==100)
		{
			printf("\nnot enough memory!\n");
			continue;
		}
		flag=0;
		temp=l;
		r=(rand()%blocks)+1;
		count1++;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(r==temp->block_id)
				break;
		}
		if(temp->flag!=0)
		{
			flag=1;
		}
		else
		{
			allocated+=temp->size;
			available-=temp->size;
			temp->flag=1;
			indexedBlock[j][a]=temp->block_id;
			a++;
		}	
		if(flag==1 || allocated < f[i].size)
			goto label;
		if(allocated >= f[i].size)
		{
			indexlength[j]=a;
			j++;
			printf("%s\t\t%d\n",f[i].name,i);
			continue;
		}
	}	
	j=0;
	printf("\nIndex table\n");
	for(i=0;i<n;i++)
	{
		printf("\n%s\tIndex Block :%d\t",f[i].name,j);
		if(f[i].start==-1)
			continue;
		for(r=0;r<indexlength[j];r++)
		{
				printf(" %d ->",indexedBlock[j][r]);
		}
		printf("end\n");
		j++;

	}

}
void main()
{
	int main_memory,size,no_files,i;
	struct memoryBlock *l;
	struct file *f;
	l=header();
	printf("****File Allocation Techniques******\n\n");
	printf("\nEnter the Main Memory size:");
	scanf("%d",&main_memory);
	printf("\nEnter the size of the each block :");
	scanf("%d",&size);
	creatememoryBlock(l,main_memory/size,size);
	printf("\nEnter the number of files to be allocated:");
	scanf("%d",&no_files);
	f=(struct file*)malloc(sizeof(struct file)*no_files);
	for(i=0;i<no_files;i++)
	{
		printf("\nName of the File %d :",i+1);
		scanf("%s",f[i].name);
		printf("\nSize of the File %d :",i+1);
		scanf("%d",&f[i].size);
		printf("\n\n");
	}
	int choice;
	while(1)
	{
		printf("\n1.Contiguous\n2.Linked\n3.Indexed\n4.Exit\n\tEnter the choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			contiguous(l,f,main_memory,size,no_files);
		}
		else if(choice==2)
		{
			linked(l,f,main_memory,size,no_files);
		}
		else if(choice==3)
		{
			indexed(l,f,main_memory,size,no_files);
		}
		else if(choice==4)
		{
			break;
		}
		else
		{
			printf("\nInvalod Choice\n");
		}
	}

}
/*OUTPUT
PS F:\Study\SSN\4thSem\OS> gcc file2.c -o a                                                                                                                   PS F:\Study\SSN\4thSem\OS> ./a                                                                                                                                ****File Allocation Techniques******


Enter the Main Memory size:20

Enter the size of the each block :2

Enter the number of files to be allocated:3

Name of the File 1 :a

Size of the File 1 :4



Name of the File 2 :b

Size of the File 2 :6



Name of the File 3 :c

Size of the File 3 :5



1.Contiguous
2.Linked
3.Indexed
4.Exit
        Enter the choice:1

CONTIGUOUS ALLOCATION
Directory
File name       Start   Length

a               3       2


b               5       3


c               8       3


1.Contiguous
2.Linked
3.Indexed
4.Exit
        Enter the choice:4
PS F:\Study\SSN\4thSem\OS> ./a                                                                                                                                ****File Allocation Techniques******


Enter the Main Memory size:20

Enter the size of the each block :2

Enter the number of files to be allocated:3

Name of the File 1 :a

Size of the File 1 :4



Name of the File 2 :b

Size of the File 2 :6



Name of the File 3 :c

Size of the File 3 :5



1.Contiguous
2.Linked
3.Indexed
4.Exit
        Enter the choice:2

LINKED ALLOCATION
Directory
File name       Start   END
a               2       7
b               1       6
c               9       10

Individual File listing:

a        2 ->7 ->end

b        1 ->3 ->6 ->end

c        9 ->5 ->10 ->end

1.Contiguous
2.Linked
3.Indexed
4.Exit
PS F:\Study\SSN\4thSem\OS> gcc file2.c -o a                                                                                                                   PS F:\Study\SSN\4thSem\OS> ./a                                                                                                                                ****File Allocation Techniques******


Enter the Main Memory size:20

Enter the size of the each block :2

Enter the number of files to be allocated:4

Name of the File 1 :a

Size of the File 1 :10



Name of the File 2 :b

Size of the File 2 :4



Name of the File 3 :c

Size of the File 3 :5



Name of the File 4 :d

Size of the File 4 :3



1.Contiguous
2.Linked
3.Indexed
4.Exit
        Enter the choice:3

INDEXED ALLOCATION
Directory
File name       Indexed Block
a               0
b               1
c               2
d               Not Enough memory

Index table

a       Index Block :0   7 -> 8 -> 1 -> 5 -> 4 ->end

b       Index Block :1   2 -> 9 ->end

c       Index Block :2   10 -> 6 -> 3 ->end

d       Index Block :3
1.Contiguous
2.Linked
3.Indexed
4.Exit
        Enter the choice:4*/