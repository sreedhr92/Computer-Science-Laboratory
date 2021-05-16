#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int start,end;
	int size;
	char status[100];
};
struct process
{
	char id[3];
	int size,start,end;
};
struct list
{
	struct node a;
	struct list *next;
};
void allocated_list(struct list *lp)
{
	printf("\n\nAllocated Memory\n\n");
	struct list *temp;
	temp=lp;
	int k=0,n,i;
	int address[30];
	char id[30][3];
	while(temp->next!=NULL)
	{
		temp=temp->next;
		address[k]=temp->a.start;
		strcpy(id[k],temp->a.status);
		k++;
	}
	address[k]=temp->a.end;
	n=k;
	int length = (14*n)+n;
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n");
	int place;
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0)
		{
			place=0;
			printf("|");
		}
		else
		{
			place++;
			if(place==6 && k<n)
			{
				printf("%s ",id[k]);
				k++;
			}
			else if(place>7 ||place<6)
				printf(" ");
		}	
	}
	printf("\n");
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n");
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0 && k<n+1 )
		{	
			printf("%d",address[k]);
			k++;
		}
		else if(i%14==1)
			continue;
		else
		{
			printf(" ");
		}	
	}
	printf("\n\n");
}
void free_pool(struct list *l)
{
	printf("\nFree Pool\n\n");
	struct list *temp;
	temp=l;
	int k=0,n,i;
	int address[30];
	char id[30][3];
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(strcmp(temp->a.status," H")==0)
		{
			address[k]=temp->a.start;
			strcpy(id[k],temp->a.status);
			k++;
		}	
	}
	address[k]=temp->a.end;
	n=k;
	int length = (14*n)+n;
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n");
	int place;
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0)
		{
			place=0;
			printf("|");
		}
		else
		{
			place++;
			if(place==6 && k<n)
			{
				printf("%s ",id[k]);
				k++;
			}
			else if(place>7 ||place<6)
				printf(" ");
		}	
	}
	printf("\n");
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n");
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0 && k<n+1 )
		{	
			printf("%d",address[k]);
			k++;
		}
		else if(i%14==1)
			continue;
		else
		{
			printf(" ");
		}	
	}

}
void physical_memory(struct list *l)
{
	printf("\n\nPhysical memory\n\n");
	struct list *temp;
	temp=l;
	int k=0,n,i;
	int address[30];
	char id[30][3];
	while(temp->next!=NULL)
	{
		temp=temp->next;
		address[k]=temp->a.start;
		strcpy(id[k],temp->a.status);
		k++;
	}
	address[k]=temp->a.end;
	n=k;
	int length = (14*n)+n;
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n");
	int place;
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0)
		{
			place=0;
			printf("|");
		}
		else
		{
			place++;
			if(place==6 && k<n)
			{
				printf("%s ",id[k]);
				k++;
			}
			else if(place>7 ||place<6)
				printf(" ");
		}	
	}
	printf("\n");
	for(i=0;i<length+1;i++)
	{
		printf("-");
	}
	printf("\n");
	k=0;
	for(i=0;i<length;i++)
	{
		if(i%14==0 && k<n+1 )
		{	
			printf("%d",address[k]);
			k++;
		}
		else if(i%14==1)
			continue;
		else
		{
			printf(" ");
		}	
	}
	printf("\n\n");
}
struct list* header()
{
	struct list *h;
	h=(struct list*)malloc(sizeof(struct list));
	h->next=NULL;
	return h;
}
int check_space(struct list *l,int size)
{
	struct list *temp;
	int flag=0;
	temp=l;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->a.size>=size)
		{
			flag=1;
			return flag;
		}
	}
	return flag;
}
struct list* find_previous(struct list *l,char status[])
{
	struct list *temp,*prev;
	temp=l->next;
	while(temp!=NULL)
	{
		if(strcmp(temp->a.status,status)==0)
			break;
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
	return prev;
}
void insertend(struct list *l,struct node a)
{
	struct list *temp,*temp1;
	temp=(struct list*)malloc(sizeof(struct list));
	temp1=l;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp->a=a;
	temp->next=temp1->next;
	temp1->next=temp;
}
void delete_node(struct list *l,char status[])
{
	struct list *temp1,*temp2;
	temp1=l->next;
	int flag=0;
	if(strcmp(temp1->a.status,status)==0)
	{
		flag=1;
		temp2=temp1->next;
		l->next=temp2;
	}
	if(flag==0)
	{
		struct list* prevElement,*currentElement;
		prevElement=find_previous(l,status);
		currentElement=prevElement->next;
		prevElement->next=currentElement->next;
	}	
}
void first_entry(struct list *l,struct process p,struct list *lp)
{
	struct list *temp;
	struct list *temp1,*temp2;
	temp1=(struct list*)malloc(sizeof(struct list));
	temp=l;
	int end;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		temp2=temp->next;
		if(temp->a.size > p.size && strcmp(temp->a.status," H")==0)
		{
			strcpy(temp->a.status,p.id);
			end=temp->a.end;
			temp->a.end=temp->a.start+p.size;
			temp->a.size=temp->a.size-p.size;
			temp1->a.start=temp->a.end;
			temp1->a.end=end;
			temp1->a.size=temp1->a.end-temp1->a.start;
			strcpy(temp1->a.status," H");
			temp->next=temp1;
			temp1->next=temp2;
			break;
		}
		else if(temp->a.size==p.size  && (strcmp(temp->a.status," H")==0))
		{
			strcpy(temp->a.status,p.id);
			break;
		}
	}
	insertend(lp,temp->a);
}
void best_entry(struct list *l,struct process p,struct list *lp)
{
	//for traversing through the list
	struct list *temp;
	//for creating a new node
	struct list *temp1;
	//for storing the best node 
	struct list *temp2;
	//for storing the next of the best node
	struct list *temp3;
	int end,best=100,flag=0;
	temp=l;
	temp1=(struct list*)malloc(sizeof(struct list));
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->a.size > p.size && strcmp(temp->a.status," H")==0)
		{
			if(temp->a.size - p.size < best)
			{
				temp2=temp;
				temp3=temp->next;
				best=temp->a.size-p.size;
			}
		}
		else if(temp->a.size==p.size  && (strcmp(temp->a.status," H")==0))
		{
			strcpy(temp->a.status,p.id);
			flag=1;
			insertend(lp,temp->a);
			break;
		}		
	}
	if(flag==0)
	{
			strcpy(temp2->a.status,p.id);
			end=temp2->a.end;
			temp2->a.end=temp2->a.start+p.size;
			temp2->a.size=temp2->a.size-p.size;
			temp1->a.start=temp2->a.end;
			temp1->a.end=end;
			temp1->a.size=temp1->a.end-temp1->a.start;
			strcpy(temp1->a.status," H");
			temp2->next=temp1;
			temp1->next=temp3;	
			insertend(lp,temp2->a);
	}
}
void worst_entry(struct list *l,struct process p,struct list *lp)
{
	//for traversing through the list
	struct list *temp;
	//for creating a new node
	struct list *temp1;
	//for storing the best node 
	struct list *temp2;
	//for storing the next of the best node
	struct list *temp3;
	int end,best=-1,flag=0;
	temp=l;
	temp1=(struct list*)malloc(sizeof(struct list));
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->a.size >= p.size && strcmp(temp->a.status," H")==0)
		{
			if(temp->a.size - p.size > best)
			{
				temp2=temp;
				temp3=temp->next;
				best=temp->a.size-p.size;
			}
		}	
	}
	if(temp2->a.size-p.size >0)
	{
			strcpy(temp2->a.status,p.id);
			end=temp2->a.end;
			temp2->a.end=temp2->a.start+p.size;
			temp2->a.size=temp2->a.size-p.size;
			temp1->a.start=temp2->a.end;
			temp1->a.end=end;
			temp1->a.size=temp1->a.end-temp1->a.start;
			strcpy(temp1->a.status," H");
			temp2->next=temp1;
			temp1->next=temp3;	
			insertend(lp,temp2->a);
	}
	else if(temp2->a.size - p.size == 0)
	{
			strcpy(temp2->a.status,p.id);
			insertend(lp,temp2->a);
	}
}
void coalescing_holes(struct list *l)
{
	struct list *temp,*temp1;
	temp=l;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->next!=NULL)
		{
			temp1=temp->next;
			if(strcmp(temp->a.status," H")==0 && strcmp(temp1->a.status," H")==0)
		{
			temp->a.end=temp1->a.end;
			temp->next=temp1->next;
		}
	}}
}
void deallocate(struct list *l,char id[],struct list *lp)
{
	struct list* temp;
	temp=l;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(strcmp(temp->a.status,id)==0)
		{
			strcpy(temp->a.status," H");
		}
	}
	delete_node(lp,id);
}
struct node input()
{
	struct node a;
	printf("\nEnter the starting address:");
	scanf("%d",&a.start);
	printf("\nEnter the ending address  :");
	scanf("%d",&a.end);
	a.size=a.end-a.start;
	strcpy(a.status," H");
	return a;
}
void main()
{
	int i,x,n,choice;
	struct list *l;
	struct list *lp;
	struct node a;
	char id[4];
	l=header();
	lp=header();
	printf("\nEnter the memory representation:\nEnter the no. of partitions in memory:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nPartition %d:",i+1);
		a=input();
		insertend(l,a);
	}
	free_pool(l);
	physical_memory(l);
	for(;;)
	{
		int k=0;
		struct process p;
		printf("\n************Memory Allocation Algorithm**********\n\n1.First fit\n2.Best Fit\n3.Worst Fit\n4.Exit from program\n\nEnter the choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			for(;;)
			{
				printf("\n\n1.Entry/Allocation\n2.Deallocate\n3.Display\n4.Coalescing Holes\n5.Back to algorithm\n\nEnter the choice:");
				scanf("%d",&x);
				if(x==1)
				{
					printf("\nEnter the process id:");
					scanf("%s",p.id);
					printf("\nEnter size needed   :");
					scanf("%d",&p.size);
					if(check_space(l,p.size)==1)
					{
						printf("\nMemory is allocated to %s\n",p.id);
						first_entry(l,p,lp);
						allocated_list(lp);
						free_pool(l);
						physical_memory(l);				
					}
					else
						printf("\nMemory is insufficient deallocate some process XD..\n");
				}
				else if(x==2)
				{
					printf("\nEnter the process id:");
					scanf("%s",id);
					deallocate(l,id,lp);
				}
				else if(x==3)
				{
					allocated_list(lp);
					free_pool(l);
					physical_memory(l);
				}
				else if(x==4)
				{
					coalescing_holes(l);
				}
				else if(x==5)
				{
					break;
				}
				else
				{
					printf("\nInvalid choice");
				}
			}	
		}
		else if(choice==2)
		{
			for(;;)
			{
				printf("\n\n1.Entry/Allocation\n2.Deallocate\n3.Display\n4.Coalescing Holes\n5.Back to algorithm\n\nEnter the choice:");
				scanf("%d",&x);
				if(x==1)
				{
					printf("\nEnter the process id:");
					scanf("%s",p.id);
					printf("\nEnter size needed   :");
					scanf("%d",&p.size);
					if(check_space(l,p.size)==1)
					{
						printf("\nMemory is allocated to %s\n",p.id);
						best_entry(l,p,lp);
						allocated_list(lp);
						free_pool(l);
						physical_memory(l);				
					}
					else
						printf("\nMemory is insufficient deallocate some process XD..\n");
				}
				else if(x==2)
				{
					printf("\nEnter the process id:");
					scanf("%s",id);
					deallocate(l,id,lp);
				}
				else if(x==3)
				{
					allocated_list(lp);
					free_pool(l);
					physical_memory(l);
				}
				else if(x==4)
				{
					coalescing_holes(l);
				}
				else if(x==5)
				{
					break;
				}
				else
				{
					printf("\nInvalid choice");
				}
			}	
		}
		else if(choice==3)
		{
			for(;;)
			{
				printf("\n\n1.Entry/Allocation\n2.Deallocate\n3.Display\n4.Coalescing Holes\n5.Back to algorithm\n\nEnter the choice:");
				scanf("%d",&x);
				if(x==1)
				{
					printf("\nEnter the process id:");
					scanf("%s",p.id);
					printf("\nEnter size needed   :");
					scanf("%d",&p.size);
					if(check_space(l,p.size)==1)
					{
						printf("\nMemory is allocated to %s\n",p.id);
						worst_entry(l,p,lp);
						allocated_list(lp);
						free_pool(l);
						physical_memory(l);				
					}
					else
						printf("\nMemory is insufficient deallocate some process XD..\n");
				}
				else if(x==2)
				{
					printf("\nEnter the process id:");
					scanf("%s",id);
					deallocate(l,id,lp);
				}
				else if(x==3)
				{
					allocated_list(lp);
					free_pool(l);
					physical_memory(l);
				}
				else if(x==4)
				{
					coalescing_holes(l);
				}
				else if(x==5)
				{
					break;
				}
				else
				{
					printf("\nInvalid choice");
				}
			}	
		}
		else if(choice==4)
		{
			break;
		}
		else
		{
			printf("\nInvalid choice");
		}
	}	

}
/*	temp=temp->next;
		if(temp->a.remaining>=p.size)
		{
			p.start=temp->a.start+(temp->a.size-temp->a.remaining);
			p.end=p.start+p.size;
			temp->a.remaining-=p.size;
			sprintf(buffer,"%d\t",p.end);
			strcpy(content,p.id);
			strcat(content,"\t|");
			strcat(content,buffer);
			strcat(temp->a.content,content);
		//	strcat(temp->a.content,"H");
		//	strcpy(temp->a.content,content);
			if(temp->a.remaining==0)
			{
				temp->a.content[(strlen(temp->a.content)-strlen(buffer))-2]='\0';
			}
			break;
		}*/
/*OUTPUT:
PS F:\Study\SSN\4thSem\OS> gcc memory.c -o a                                                                                                                  PS F:\Study\SSN\4thSem\OS> ./a                                                                                                                                
Enter the memory representation:
Enter the no. of partitions in memory:5

Partition 1:
Enter the starting address:100

Enter the ending address  :110

Partition 2:
Enter the starting address:110

Enter the ending address  :112

Partition 3:
Enter the starting address:112

Enter the ending address  :117

Partition 4:
Enter the starting address:117

Enter the ending address  :120

Partition 5:
Enter the starting address:120

Enter the ending address  :125

Free Pool

----------------------------------------------------------------------------
|      H       |      H       |      H       |      H       |      H       |
----------------------------------------------------------------------------
100            110            112            117            120            125

Physical memory

----------------------------------------------------------------------------
|      H       |      H       |      H       |      H       |      H       |
----------------------------------------------------------------------------
100            110            112            117            120            125


************Memory Allocation Algorithm**********

1.First fit
2.Best Fit
3.Worst Fit
4.Exit from program

Enter the choice:2


1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:1

Enter the process id:p1

Enter size needed   :3

Memory is allocated to p1


Allocated Memory

----------------
|     p1       |
----------------
117            120


Free Pool

-------------------------------------------------------------
|      H       |      H       |      H       |      H       |
-------------------------------------------------------------
100            110            112            120            125

Physical memory

----------------------------------------------------------------------------
|      H       |      H       |      H       |     p1       |      H       |
----------------------------------------------------------------------------
100            110            112            117            120            125



1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:1

Enter the process id:p2

Enter size needed   :6

Memory is allocated to p2


Allocated Memory

-------------------------------
|     p1       |     p2       |
-------------------------------
117            100            106


Free Pool

-------------------------------------------------------------
|      H       |      H       |      H       |      H       |
-------------------------------------------------------------
106            110            112            120            125

Physical memory

-------------------------------------------------------------------------------------------
|     p2       |      H       |      H       |      H       |     p1       |      H       |
-------------------------------------------------------------------------------------------
100            106            110            112            117            120            125



1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:1

Enter the process id:p3

Enter size needed   :1

Memory is allocated to p3


Allocated Memory

----------------------------------------------
|     p1       |     p2       |     p3       |
----------------------------------------------
117            100            110            111


Free Pool

-------------------------------------------------------------
|      H       |      H       |      H       |      H       |
-------------------------------------------------------------
106            111            112            120            125

Physical memory

----------------------------------------------------------------------------------------------------------
|     p2       |      H       |     p3       |      H       |      H       |     p1       |      H       |
----------------------------------------------------------------------------------------------------------
100            106            110            111            112            117            120            125



1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:2

Enter the process id:p3


1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:3


Allocated Memory

-------------------------------
|     p1       |     p2       |
-------------------------------
117            100            106


Free Pool

----------------------------------------------------------------------------
|      H       |      H       |      H       |      H       |      H       |
----------------------------------------------------------------------------
106            110            111            112            120            125

Physical memory

----------------------------------------------------------------------------------------------------------
|     p2       |      H       |      H       |      H       |      H       |     p1       |      H       |
----------------------------------------------------------------------------------------------------------
100            106            110            111            112            117            120            125



1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:4


1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:3


Allocated Memory

-------------------------------
|     p1       |     p2       |
-------------------------------
117            100            106


Free Pool

----------------------------------------------
|      H       |      H       |      H       |
----------------------------------------------
106            111            120            125

Physical memory

----------------------------------------------------------------------------
|     p2       |      H       |      H       |     p1       |      H       |
----------------------------------------------------------------------------
100            106            111            117            120            125



1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:4


1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:3


Allocated Memory

-------------------------------
|     p1       |     p2       |
-------------------------------
117            100            106


Free Pool

-------------------------------
|      H       |      H       |
-------------------------------
106            120            125

Physical memory

-------------------------------------------------------------
|     p2       |      H       |     p1       |      H       |
-------------------------------------------------------------
100            106            117            120            125



1.Entry/Allocation
2.Deallocate
3.Display
4.Coalescing Holes
5.Back to algorithm

Enter the choice:5

************Memory Allocation Algorithm**********

1.First fit
2.Best Fit
3.Worst Fit
4.Exit from program

Enter the choice:4
PS F:\Study\SSN\4thSem\OS>
*/