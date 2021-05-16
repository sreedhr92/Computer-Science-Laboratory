#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list
{
	int value;
	struct list *next;
};
struct list* header()
{
	struct list *h;
	h=(struct list*)malloc(sizeof(struct list));
	h->next=NULL;
	return h;
}
void insertfront(struct list *l)
{
	struct list *temp,*temp1;
	temp=l->next;
	temp1=(struct list*)malloc(sizeof(struct list));
	temp1->value=-1;
	l->next=temp1;
	temp1->next=temp;
}
void create_list(struct list *l,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		insertfront(l);
	}
}
int check_frame(struct list *l,int value)
{
	struct list *temp;
	temp=l;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->value==value)
		{
			return 1;
		}
	}
	return 0;
}
void display(struct list *l,int ref_str,int pf)
{
	struct list *temp;
	temp=l;
	printf("  %-8d->",ref_str);
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->value==-1)
			printf("-      ");
		else
			printf("%-7d",temp->value);
	}
	if(pf==-1)
		printf("-> - \n");
	else
		printf("-> %d\n",pf);
}
void FIFO(struct list *l,int no_free_frames,int no_frames_process,int ref_str[],int k)
{
	printf("\n\nPage Ref  ->\t\tMemory       \t-> Page fault\n\n");
	struct list *temp;
	int i,page_fault=0;
	temp=l->next;
	for(i=0;i<k;i++)
	{
		if(page_fault==no_free_frames)
			break;
		if(temp->value==-1&&i < no_frames_process)
		{
			temp->value=ref_str[i];
			page_fault++;
			display(l,ref_str[i],page_fault);
			temp=temp->next;
			if(temp==NULL)
			{
				temp=l->next;
			}
		}
		else
		{
			if(check_frame(l,ref_str[i])==1)
				display(l,ref_str[i],-1);
			else 
			{
				temp->value=ref_str[i];
				page_fault++;
				display(l,ref_str[i],page_fault);
				temp=temp->next;
				if(temp==NULL)
				{
					temp=l->next;
				}
			}
		}
	}
	printf("\n\nThe total number page faults = %d",page_fault);

}
int get_optimal_frame(struct list *l,int ref_str[],int k,int n)
{
	struct list *temp;
	int index=k,value,i;
	temp=l;
	int flag;
	while(temp->next!=NULL)
	{
		flag=0;
		temp=temp->next;
		for(i=k;i<n;i++)
		{
			if(temp->value==ref_str[i])
			{
				flag=1;
				if(i > index)
				{
					value=temp->value;
					index=i;
				}	
				break;
			}
		}
		if(flag==0)
		{
			return temp->value;
		}
	}
	return value;
}
void OPTIMAL(struct list *l,int no_free_frames,int no_frames_process,int ref_str[],int k)
{
	printf("\n\nPage Ref  ->\t\tMemory       \t-> Page fault\n\n");
	struct list *temp;
	int i,page_fault=0,optimal;
	temp=l->next;
	for(i=0;i<k;i++)
	{
		if(page_fault==no_free_frames)
			break;
		if(i < no_frames_process && temp->value==-1)
		{
			temp->value=ref_str[i];
			page_fault++;
			display(l,ref_str[i],page_fault);
			temp=temp->next;
			if(temp==NULL)
			{
				temp=l->next;
			}
		}
		else
		{
			if(check_frame(l,ref_str[i])==1)
			{
				display(l,ref_str[i],-1);
			}
			else if(check_frame(l,ref_str[i])==0)
			{
				optimal=get_optimal_frame(l,ref_str,i,k);
				temp=l;
				page_fault++;
				while(temp->next!=NULL)
				{
					temp=temp->next;
					if(temp->value==optimal)
					{
						temp->value=ref_str[i];
						break;
					}
				}
				display(l,ref_str[i],page_fault);
			}
		}
	}
	printf("\n\nThe total number page faults = %d",page_fault);
}
int get_lru_frame(struct list *l,int ref_str[],int k,int n)
{
	struct list *temp;
	int index=k,value,i;
	temp=l;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		for(i=k-1;i>=0;i--)
		{
			if(temp->value==ref_str[i])
			{
				if(i < index)
				{
					value=temp->value;
					index=i;
				}	
				break;
			}
		}
	}
	return value;
}
void LRU(struct list *l,int no_free_frames,int no_frames_process,int ref_str[],int k)
{
	printf("\n\nPage Ref  ->\t\tMemory       \t-> Page fault\n\n");
	struct list *temp;
	int i,page_fault=0,lru;
	temp=l->next;
	for(i=0;i<k;i++)
	{
		if(page_fault==no_free_frames)
			break;
		if(i < no_frames_process && temp->value==-1)
		{
			temp->value=ref_str[i];
			page_fault++;
			display(l,ref_str[i],page_fault);
			temp=temp->next;
			if(temp==NULL)
			{
				temp=l->next;
			}
		}
		else
		{
			if(check_frame(l,ref_str[i])==1)
			{
				display(l,ref_str[i],-1);
			}
			else if(check_frame(l,ref_str[i])==0)
			{
				lru=get_lru_frame(l,ref_str,i,k);
				temp=l;
				page_fault++;
				while(temp->next!=NULL)
				{
					temp=temp->next;
					if(temp->value==lru)
					{
						temp->value=ref_str[i];
						break;
					}
				}
				display(l,ref_str[i],page_fault);
			}
		}
	}
	printf("\n\nThe total number page faults = %d",page_fault);
}
int get_lfu_frame(struct list *l,int ref_str[],int k,int n)
{
	struct list *temp;
	int count=100,count1,value,i;
	temp=l;
	while(temp->next!=NULL)
	{
		count1=0;
		temp=temp->next;
		for(i=k-1;i>=0;i--)
		{
			if(temp->value==ref_str[i])
			{
				count1++;
				if(count1 < count)
				{
					value=temp->value;
					count=count1;
				}	
			}
		}
	}
	return value;
}
void LFU(struct list *l,int no_free_frames,int no_frames_process,int ref_str[],int k)
{
	printf("\n\nPage Ref  ->\t\tMemory       \t-> Page fault\n\n");
	struct list *temp;
	int i,page_fault=0,lfu;
	temp=l->next;
	for(i=0;i<k;i++)
	{
		if(page_fault==no_free_frames)
			break;
		if(i < no_frames_process && temp->value==-1)
		{
			temp->value=ref_str[i];
			page_fault++;
			display(l,ref_str[i],page_fault);
			temp=temp->next;
			if(temp==NULL)
			{
				temp=l->next;
			}
		}
		else
		{
			if(check_frame(l,ref_str[i])==1)
			{
				display(l,ref_str[i],-1);
			}
			else if(check_frame(l,ref_str[i])==0)
			{
				lfu=get_lfu_frame(l,ref_str,i,k);
				temp=l;
				page_fault++;
				while(temp->next!=NULL)
				{
					temp=temp->next;
					if(temp->value==lfu)
					{
						temp->value=ref_str[i];
						break;
					}
				}
				display(l,ref_str[i],page_fault);
			}
		}
	}
	printf("\n\nThe total number page faults = %d",page_fault);
}
void main()
{
	int choice;
	int no_free_frames,no_frames_process;
	//int *free_frames;
	struct list *l;
	l=header();
	char reference_string[30];
	int ref_str[50],i,k=0;
	printf("\n*************Page Replacement algorithms*******\n");
	while(1)
	{
		printf("\n\n1.Read input\n2.FIFO\n3.OPTIMAL\n4.LRU\n5.LFU\n6.EXIT\n\nEnter the choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nEnter the number of free frames:");
			scanf("%d",&no_free_frames);
			printf("\nEnter the number of frames required by the process:");
			scanf("%d",&no_frames_process);
			//free_frames=(int*)malloc(sizeof(int)*no_free_frames);
			create_list(l,no_frames_process);
			printf("\nEnter the reference_string:");
			//scanf(" %[^\n]", reference_string);
			strcpy(reference_string,"7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1");
			i=0;
			while(reference_string[i]!='\0')
			{
				if((int)reference_string[i]-48==-16)
				{
					i++;
					continue;
				}	
				ref_str[k]=(int)reference_string[i]-48;
				k++;
				i++;
			}
			printf("\n\n\tThe reference string:");
			for(i=0;i<k;i++)
			{
				printf("%d ",ref_str[i]);
			}
		}
		else if(choice==2)
		{
			FIFO(l,no_free_frames,no_frames_process,ref_str,k);
		}
		else if(choice==3)
		{
			OPTIMAL(l,no_free_frames,no_frames_process,ref_str,k);
		}
		else if(choice==4)
		{
			LRU(l,no_free_frames,no_frames_process,ref_str,k);
		}
		else if(choice==5)
		{
			LFU(l,no_free_frames,no_frames_process,ref_str,k);
		}
		else if(choice==6)
		{
			break;
		}
		else 
		{
			printf("\n\nInvalid Choice:\n\n");
		}
	}
}
/*Output
PS F:\Study\SSN\4thSem\OS> gcc pagereplacement.c -o a                         PS F:\Study\SSN\4thSem\OS> ./a                                                
*************Page Replacement algorithms*******


1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:1

Enter the number of free frames:10

Enter the number of frames required by the process:4

Enter the reference_string:

        The reference string:7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:2


Page Ref  ->            Memory          -> Page fault

  7       ->7      -      -      -      -> 1
  0       ->7      0      -      -      -> 2
  1       ->7      0      1      -      -> 3
  2       ->7      0      1      2      -> 4
  0       ->7      0      1      2      -> -
  3       ->3      0      1      2      -> 5
  0       ->3      0      1      2      -> -
  4       ->3      4      1      2      -> 6
  2       ->3      4      1      2      -> -
  3       ->3      4      1      2      -> -
  0       ->3      4      0      2      -> 7
  3       ->3      4      0      2      -> -
  2       ->3      4      0      2      -> -
  1       ->3      4      0      1      -> 8
  2       ->2      4      0      1      -> 9
  0       ->2      4      0      1      -> -
  1       ->2      4      0      1      -> -
  7       ->2      7      0      1      -> 10


The total number page faults = 10

1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:6
PS F:\Study\SSN\4thSem\OS> ./a                                                
*************Page Replacement algorithms*******


1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:1

Enter the number of free frames:10

Enter the number of frames required by the process:4

Enter the reference_string:

        The reference string:7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:3


Page Ref  ->            Memory          -> Page fault

  7       ->7      -      -      -      -> 1
  0       ->7      0      -      -      -> 2
  1       ->7      0      1      -      -> 3
  2       ->7      0      1      2      -> 4
  0       ->7      0      1      2      -> -
  3       ->3      0      1      2      -> 5
  0       ->3      0      1      2      -> -
  4       ->3      0      4      2      -> 6
  2       ->3      0      4      2      -> -
  3       ->3      0      4      2      -> -
  0       ->3      0      4      2      -> -
  3       ->3      0      4      2      -> -
  2       ->3      0      4      2      -> -
  1       ->1      0      4      2      -> 7
  2       ->1      0      4      2      -> -
  0       ->1      0      4      2      -> -
  1       ->1      0      4      2      -> -
  7       ->1      0      7      2      -> 8
  0       ->1      0      7      2      -> -
  1       ->1      0      7      2      -> -


The total number page faults = 8

1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:6
PS F:\Study\SSN\4thSem\OS> ./a                                                
*************Page Replacement algorithms*******


1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:1

Enter the number of free frames:10

Enter the number of frames required by the process:4

Enter the reference_string:

        The reference string:7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:4


Page Ref  ->            Memory          -> Page fault

  7       ->7      -      -      -      -> 1
  0       ->7      0      -      -      -> 2
  1       ->7      0      1      -      -> 3
  2       ->7      0      1      2      -> 4
  0       ->7      0      1      2      -> -
  3       ->3      0      1      2      -> 5
  0       ->3      0      1      2      -> -
  4       ->3      0      4      2      -> 6
  2       ->3      0      4      2      -> -
  3       ->3      0      4      2      -> -
  0       ->3      0      4      2      -> -
  3       ->3      0      4      2      -> -
  2       ->3      0      4      2      -> -
  1       ->3      0      1      2      -> 7
  2       ->3      0      1      2      -> -
  0       ->3      0      1      2      -> -
  1       ->3      0      1      2      -> -
  7       ->7      0      1      2      -> 8
  0       ->7      0      1      2      -> -
  1       ->7      0      1      2      -> -


The total number page faults = 8

1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT


Enter the choice:6
PS F:\Study\SSN\4thSem\OS> ./a                                                
*************Page Replacement algorithms*******


1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:1

Enter the number of free frames:10

Enter the number of frames required by the process:4

Enter the reference_string:

        The reference string:7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

1.Read input
2.FIFO
3.OPTIMAL
4.LRU
5.LFU
6.EXIT

Enter the choice:5


Page Ref  ->            Memory          -> Page fault

  7       ->7      -      -      -      -> 1
  0       ->7      0      -      -      -> 2
  1       ->7      0      1      -      -> 3
  2       ->7      0      1      2      -> 4
  0       ->7      0      1      2      -> -
  3       ->3      0      1      2      -> 5
  0       ->3      0      1      2      -> -
  4       ->4      0      1      2      -> 6
  2       ->4      0      1      2      -> -
  3       ->3      0      1      2      -> 7
  0       ->3      0      1      2      -> -
  3       ->3      0      1      2      -> -
  2       ->3      0      1      2      -> -
  1       ->3      0      1      2      -> -
  2       ->3      0      1      2      -> -
  0       ->3      0      1      2      -> -
  1       ->3      0      1      2      -> -
  7       ->7      0      1      2      -> 8
  0       ->7      0      1      2      -> -
  1       ->7      0      1      2      -> -*/