#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory
{
	char name[10];
	char folder[5][10];
	//count is for folder count1 is for directory 
	int count,count1;
	char parent[10];
};
int check(char single_folder[10][10],char name[],int n)
{
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(single_folder[i],name)==0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
int check_directory(struct directory d[],char name[],int n)
{
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(d[i].name,name)==0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
void printtabs(int value)
{
	int i;
	for(i=0;i<value;i++)
	{
		printf("\t");
	}
}
void displaytree(struct directory d[],char root[],int count,int value)
{
	int i,j;
	for(i=0;i<count;i++)
	{
		if(strcmp(d[i].name,root)==0)
			break;
	}
	printf("\n");
	printtabs(value);
	printf("-+-%s\n",d[i].name);
	strcpy(root,d[i].name);
	for(j=0;j<d[i].count;j++)
	{
		printtabs(value);
		printf("     %s\n",d[i].folder[j]);
	}
	for(j=0;j<count;j++)
	{
		if(strcmp(root,d[j].parent)==0)
		{
			displaytree(d,d[j].name,count,value+1);
		}
	}
}
void main()
{
	int x,choice,i,j;
	char name[20];
	printf("\nFile Organization techniques\n");
	while(1)
	{
		printf("\n\n1.Single Level Directory\n2.Two Level Directory\n3.Tree Structured Directory\n4.DAG\n5.Exit\n\nEnter the option:");
		scanf("%d",&x);
		if(x==1)
		{
			struct directory d;
			d.count=0;
			while(1)
			{
				printf("\n\n1.Create a file\n2.List the file\n3.Exit\n\nEnter the opiton:");
				scanf("%d",&choice);
				if(choice==1)
				{
					printf("\n\nEnter the name of the file :  ");
					scanf("%s",name);
					if(check(d.folder,name,d.count)==1)
						printf("\n\nFile Already Exits!\n");
					else
					{
						strcpy(d.folder[d.count],name);
						d.count++;
					}	
				}
				else if(choice==2)
				{
					printf("\n\nFile Name\t\tLocation\n\n");
					for(i=0;i<d.count;i++)
					{
						printf("%s \t\t\t%d\n",d.folder[i],&d.folder[i]);
					}
				}
				else if(choice==3)
				{
					break;
				}
				else
				{
					printf("\n\nInvalid choice");
				}
			}
		}
		else if(x==2)
		{
			struct directory d[10];
			int count=0;
			while(1)
			{
				printf("\n\n1.Create a directory\n2.Create a file\n3.Searching a file\n4.List the file\n5.Exit\n\nEnter the opiton:");
				scanf("%d",&choice);
				if(choice==1)
				{
					printf("\n\nEnter the name of the directory:");
					scanf("%s",name);
					if(check_directory(d,name,count)==1)
						printf("\ndirectory exists\n");
					else
					{
						strcpy(d[count].name,name);
						d[count].count=0;
						count++;
					}
				}
				else if(choice==2)
				{
					int flag=0;
					printf("\n\nEnter the name of the directory:");
					scanf("%s",name);
					for(i=0;i<count;i++)
					{
						if(strcmp(d[i].name,name)==0)
							{flag=1;break;}
					}
					if(flag==0)
						printf("\nDirectory doesn't exists\n");
					else	
					{
						printf("\n\nEnter the name of the file:");
						scanf("%s",name);
						if(check(d[i].folder,name,d[i].count)==1)
							printf("\n\nFile Already Exits!\n");
						else
						{
							strcpy(d[i].folder[d[i].count],name);
							d[i].count++;
						}	
					}	
				}
				else if(choice==3)
				{
					int flag=0;
					printf("\n\nEnter the name of the file:");
					scanf("%s",name);
					for(i=0;i<count;i++)
					{
						for(j=0;j<d[i].count;j++)
						{
							if(strcmp(d[i].folder[j],name)==0)
								{flag=1;break;}
						}
						if(flag==1)
						{
							break;
						}
					}
					if(flag==0)
						printf("\n\nFile not exists\n\n");
					else
						printf("\nThe File %s is under the directory %s\n",name,d[i].name);
				}
				else if(choice==4)
				{
					for(i=0;i<count;i++)
					{
						printf("\n\nDirectory : %s\tLocation: %d\n\nFiles\t\t\tLocation:\n",d[i].name,&d[i]);
						for(j=0;j<d[i].count;j++)
						{
							printf("\n%s\t\t\t%d",d[i].folder[j],&d[i].folder[j]);
						}
					}
				}
				else if(choice==5)
				{
					break;
				}
				else
				{
					printf("\n\nInvalid choice");
				}
			}
		}
		else if(x==3)
		{
			int count=0;
			printf("\nEnter the root directory:");
			scanf("%s",name);
			struct directory d[10];
			strcpy(d[0].name,name);
			strcpy(d[0].parent,"PC");
			d[count].count=0;
			count++;
			char name1[10];
			while(1)
			{
				printf("\n\n1.Create a directory\n2.Create a file\n3.Searching a file\n4.List the file\n5.Exit\n\nEnter the opiton:");
				scanf("%d",&choice);
				if(choice==1)
				{
					printf("\nEnter the parent directory:");
					scanf("%s",name1);
					if(check_directory(d,name1,count)==1)
					{
						printf("\n\nEnter the name of the directory:");
						scanf("%s",name);
						for(i=0;i<count;i++)
						{
							if(strcmp(d[i].name,name1)==0)
								break;
						}
						if(check_directory(d,name,count)==1 && d[i].count1<6)
							printf("\ndirectory exists or limit reached\n");
						else
						{
							strcpy(d[count].parent,name1);
							strcpy(d[count].name,name);
							d[count].count=0;
							count++;
							d[i].count1++;
						}
					}
					else 
					{
						printf("\nParent directory doesn'y exit exists\n");
					}
				}
				else if(choice==2)
				{
					int flag=0;
					printf("\n\nEnter the name of the directory:");
					scanf("%s",name);
					for(i=0;i<count;i++)
					{
						if(strcmp(d[i].name,name)==0)
							{flag=1;break;}
					}
					if(flag==0)
						printf("\nDirectory doesn't exists\n");
					else	
					{
						printf("\n\nEnter the name of the file:");
						scanf("%s",name);
						if(check(d[i].folder,name,d[i].count)==1 && d[i].count <6)
							printf("\n\nFile Already Exits or limit reached for creation!\n");
						else
						{
							strcpy(d[i].folder[d[i].count],name);
							d[i].count++;
						}	
					}	
				}
				else if(choice==3)
				{
					int flag=0;
					printf("\n\nEnter the name of the file:");
					scanf("%s",name);
					for(i=0;i<count;i++)
					{
						for(j=0;j<d[i].count;j++)
						{
							if(strcmp(d[i].folder[j],name)==0)
								{flag=1;break;}
						}
						if(flag==1)
						{
							break;
						}
					}
					if(flag==0)
						printf("\n\nFile not exists\n\n");
					else
						printf("\nThe File %s is under the directory %s\n",name,d[i].name);
				}
				else if(choice==4)
				{
					displaytree(d,d[0].name,count,0);
				}
				else if(choice==5)
				{
					break;
				}
				else
				{
					printf("\n\nInvalid choice");
				}
			}
		}
		else if(x==4)
		{
			int count=0;
			printf("\nEnter the root directory:");
			scanf("%s",name);
			struct directory d[10];
			strcpy(d[0].name,name);
			strcpy(d[0].parent,"PC");
			d[count].count=0;
			count++;
			char name1[10];
			while(1)
			{
				printf("\n\n1.Create a directory\n2.Create a file\n3.Searching a file\n4.List the file\n5.Create a link\n6.Exit\n\nEnter the opiton:");
				scanf("%d",&choice);
				if(choice==1)
				{
					printf("\nEnter the parent directory:");
					scanf("%s",name1);
					if(check_directory(d,name1,count)==1)
					{
						printf("\n\nEnter the name of the directory:");
						scanf("%s",name);
						for(i=0;i<count;i++)
						{
							if(strcmp(d[i].name,name1)==0)
								break;
						}
						if(check_directory(d,name,count)==1 && d[i].count1<6)
							printf("\ndirectory exists or limit reached\n");
						else
						{
							strcpy(d[count].parent,name1);
							strcpy(d[count].name,name);
							d[count].count=0;
							count++;
							d[i].count1++;
						}
					}
					else 
					{
						printf("\nParent directory doesn't exit exists\n");
					}
				}
				else if(choice==2)
				{
					int flag=0;
					char name1[10];
					char currentfile[10];
					printf("\n\nEnter the name of the directory:");
					scanf("%s",name);
					for(i=0;i<count;i++)
					{
						if(strcmp(d[i].name,name)==0)
							{flag=1;break;}
					}
					if(flag==0)
						printf("\nDirectory doesn't exists\n");
					else	
					{
						printf("\n\nEnter the name of the file:");
						scanf("%s",name);
						if(check(d[i].folder,name,d[i].count)==1 && d[i].count <6)
							printf("\n\nFile Already Exits or limit reached for creation!\n");
						else
						{
							strcpy(currentfile,name);
							strcpy(d[i].folder[d[i].count],name);
							d[i].count++;
						}	
					}	
					int temp;
					printf("\nIs there any link between two files :\n1.Yes\n2.No\nEnter choice:\n");
					scanf("%d",temp);
					if(temp==1)
					{
						printf("Enter the directory name:");
						scanf("%s",name1);
						if(check_directory(d,name1,count)==1)
						{
							for(i=0;i<count;i++)
							{
								if(strcmp(d[i].name,name1)==0)
									break;
							}
							printf("Enter the File name:");
							scanf("%s",name);
							if(check(d[i].folder,name,d[i].count)==1 ||strcmp(currentfile,name)==0)
							{
								printf("\nLink has been created!");
							}
							else
							{
								printf("\nFile doesn't exists or Creation of link on the same file\n");
							}


						}
						else
						{
							printf("\nDirectory not found!");
						}
						
					}
				}
				else if(choice==3)
				{
					int flag=0;
					printf("\n\nEnter the name of the file:");
					scanf("%s",name);
					for(i=0;i<count;i++)
					{
						for(j=0;j<d[i].count;j++)
						{
							if(strcmp(d[i].folder[j],name)==0)
								{flag=1;break;}
						}
						if(flag==1)
						{
							break;
						}
					}
					if(flag==0)
						printf("\n\nFile not exists\n\n");
					else
						printf("\nThe File %s is under the directory %s\n",name,d[i].name);
				}
				else if(choice==4)
				{
					displaytree(d,d[0].name,count,0);
				}
				else if(choice==5)
				{
					break;
				}
				else
				{
					printf("\n\nInvalid choice");
				}
			}
		}
		else if(x==5)
		{
			break;
		}
		else
		{
			printf("\n\nInvalid choice");
		}
	}	
}
/*OUtput:
PS F:\Study\SSN\4thSem\OS> gcc file1.c -o a                                                                                                                   PS F:\Study\SSN\4thSem\OS> ./a                                                                                                                                
File Organization techniques


1.Single Level Directory
2.Two Level Directory
3.Tree Structured Directory
4.DAG
5.Exit

Enter the option:1


1.Create a file
2.List the file
3.Exit

Enter the opiton:1


Enter the name of the file :  Pc


1.Create a file
2.List the file
3.Exit

Enter the opiton:1


Enter the name of the file :  Admin


1.Create a file
2.List the file
3.Exit

Enter the opiton:1


Enter the name of the file :  File1


1.Create a file
2.List the file
3.Exit

Enter the opiton:2


File Name               Location

Pc                      6486650
Admin                   6486660
File1                   6486670


1.Create a file
2.List the file
3.Exit

Enter the opiton:3


1.Single Level Directory
2.Two Level Directory
3.Tree Structured Directory
4.DAG
5.Exit

Enter the option:2


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:1


Enter the name of the directory:Sree


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:1


Enter the name of the directory:PC


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:2


Enter the name of the directory:Sree


Enter the name of the file:FIN


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:2


Enter the name of the directory:Sree


Enter the name of the file:Admin


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:3


Enter the name of the file:Admin

The File Admin is under the directory Sree


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:4


Directory : Sree        Location: 6486640

Files                   Location:

FIN                     6486650
Admin                   6486660

Directory : PC  Location: 6486720

Files                   Location:


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:5
File Organization techniques


1.Single Level Directory
2.Two Level Directory
3.Tree Structured Directory
4.DAG
5.Exit

Enter the option:3

Enter the root directory:Root


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:1

Enter the parent directory:Root


Enter the name of the directory:Sree


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:2


Enter the name of the directory:Sree


Enter the name of the file:PC


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:2


Enter the name of the directory:Sree


Enter the name of the file:Admin


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:2


Enter the name of the directory:Root


Enter the name of the file:CPU


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:1

Enter the parent directory:Sree


Enter the name of the directory:BUS


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:4

-+-Root
     CPU

        -+-Sree
             PC
             Admin

                -+-BUS


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Exit

Enter the opiton:5


1.Single Level Directory
2.Two Level Directory
3.Tree Structured Directory
4.DAG
5.Exit

Enter the option:4

Enter the root directory:Root


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Create a link
6.Exit

Enter the opiton:1

Enter the parent directory:Root


Enter the name of the directory:Sree


1.Create a directory
2.Create a file
3.Searching a file
4.List the file
5.Create a link
6.Exit

Enter the opiton:2


Enter the name of the directory:Sree


Enter the name of the file:KILLBUGS

Is there any link between two files :
1.Yes
2.No
Enter choice:
2*/