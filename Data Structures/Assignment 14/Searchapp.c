#include<stdio.h>
#include<stdlib.h>
#include"Searchintf.h"
#include"Searchimpl.h"
void main()
{
	struct numberADT *n;
	int choice,size,key,i,val;
	printf("\nEnter the size of the array :");
	scanf("%d",&size);
	int x[100];
	n=init(size);
	while(1)
	{
		printf("\nOperations :\n1.Insert array\n2.Search using linearsearch\n3.Search using binarysearch\n4.Display\n5.Exit\n\tEnter choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nEnter the element in the array :\n");
			for(i=0;i<size;i++)
			{
				printf("Enter element [%d] :",i);
				scanf("%d",&x[i]);
			}
			insertElements(n,x);	
		}
		else if(choice==2)
		{
			printf("\nEnter the Key to search:");
			scanf("%d",&key);
			int element=linearsearch(n,key);
			if(element!=-1)
			{
				printf("\nThe element is found in the positon %d",element);
			}
			else
			{
				printf("\n404.Not Found");
			}
		}
		else if(choice==3)
		{
			printf("\nEnter the Key to search:");
			scanf("%d",&key);
			int element=binarysearch(n,key);
			if(element!=-1)
			{
				printf("\nThe element is found in the positon %d",element);
			}
			else
			{
				printf("\n404.Not Found");
			}
		}
		else if(choice==4)
		{
			display(n);
		}
		else if(choice==5)
		{
			printf("\nExiting..");
			break;
		}
		else
		{
			printf("\ninvalid Choice\n");
		}	

	}
}
/*Output:
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 14> gcc Searchapp.c -o a                                                                       PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 14> ./a          
Enter the size of the array :6

Operations :
1.Insert array
2.Search using linearsearch
3.Search using binarysearch
4.Display
5.Exit
        Enter choice:1

Enter the element in the array :
Enter element [0] :3
Enter element [1] :1
Enter element [2] :2
Enter element [3] :4
Enter element [4] :5
Enter element [5] :6

The Elements are:
3  1  2  4  5  6
Operations :
1.Insert array
2.Search using linearsearch
3.Search using binarysearch
4.Display
5.Exit
        Enter choice:2

Enter the Key to search:4

The element is found in the positon 3
Operations :
1.Insert array
2.Search using linearsearch
3.Search using binarysearch
4.Display
5.Exit
        Enter choice:3

Enter the Key to search:5

The element is found in the positon 4
Operations :
1.Insert array
2.Search using linearsearch
3.Search using binarysearch
4.Display
5.Exit
        Enter choice:4

The Elements are:
1  2  3  4  5  6
Operations :
1.Insert array
2.Search using linearsearch
3.Search using binarysearch
4.Display
5.Exit
        Enter choice:5

Exiting..*/