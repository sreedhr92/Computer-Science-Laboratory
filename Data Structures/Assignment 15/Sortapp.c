#include<stdio.h>
#include<stdlib.h>
#include"Sortintf.h"
#include"Sortimpl.h"
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
		printf("\nOperations :\n1.Insert array\n2.Sort using selectionsort\n3.Sort using shellsort\n4.Display\n5.Exit\n\tEnter choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nEnter the element in the array :\n");
			for(i=0;i<size;i++)
			{
				printf("Enter element [%d] :",i);
				scanf("%d",&x[i]);
			}	
		}
		else if(choice==2)
		{
			insertElements(n,x);
			selsort(n);
		}
		else if(choice==3)
		{
			insertElements(n,x);
			shellsort(n);			
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
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 15> gcc Sortapp.c -o a                                                                         PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 15> ./a          
Enter the size of the array :7

Operations :
1.Insert array
2.Sort using selectionsort
3.Sort using shellsort
4.Display
5.Exit
        Enter choice:1

Enter the element in the array :
Enter element [0] :4
Enter element [1] :7
Enter element [2] :2
Enter element [3] :9
Enter element [4] :3
Enter element [5] :8
Enter element [6] :1

Operations :
1.Insert array
2.Sort using selectionsort
3.Sort using shellsort
4.Display
5.Exit
        Enter choice:2

The Elements are:
4  7  2  9  3  8  1
The Elements are:
1  7  2  9  3  8  4
The Elements are:
1  2  7  9  3  8  4
The Elements are:
1  2  3  9  7  8  4
The Elements are:
1  2  3  4  7  8  9
The Elements are:
1  2  3  4  7  8  9
The Elements are:
1  2  3  4  7  8  9
The Elements are:
1  2  3  4  7  8  9
Operations :
1.Insert array
2.Sort using selectionsort
3.Sort using shellsort
4.Display
5.Exit
        Enter choice:3

The Elements are:
4  7  2  9  3  8  1
Output after shellsort

The Elements are:
2  1  4  3  7  8  9
The Elements are:
1  2  4  3  7  8  9
The Elements are:
1  2  4  3  7  8  9
The Elements are:
1  2  3  4  7  8  9
The Elements are:
1  2  3  4  7  8  9
The Elements are:
1  2  3  4  7  8  9
The Elements are:
1  2  3  4  7  8  9
The Elements are:
1  2  3  4  7  8  9
Operations :
1.Insert array
2.Sort using selectionsort
3.Sort using shellsort
4.Display
5.Exit
        Enter choice:4

The Elements are:
1  2  3  4  7  8  9
Operations :
1.Insert array
2.Sort using selectionsort
3.Sort using shellsort
4.Display
5.Exit
        Enter choice:5

Exiting..*/
