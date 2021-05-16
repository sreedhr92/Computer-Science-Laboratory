#include<stdio.h>
#include<stdlib.h>
#include"hashtableintf.h"
#include"hashtableimpl.h"
void main()
{
	int n,choice,val;
	struct hashtable *h;
	printf("\nEnter capacity :");
	scanf("%d",&n);
	h=init(n);
	while(1)
	{
		printf("\nOperations:\n1.Insert\n2.Find\n3.Display\nExit\n\tEnter choice :");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter value:");
			scanf("%d",&val);
			insert(h,val);
			printf("\nInserted!");
		}
		else if(choice==2)
		{
			printf("\nEnter value:");
			scanf("%d",&val);
			if(search(h,val))
				printf("\nValue Found :%d",val);
			else 	
				printf("\nValue not found");
		}
		else if(choice==3)
			disp(h);
		else if(choice==4)
			break;
		else
			printf("\nInvalid choice");
	}
}
/*Output:
PS C:\Users\sreed\Downloads> gcc hashtableapp.c -o a                          PS C:\Users\sreed\Downloads> ./a                                              
Enter capacity :10

Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:1

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:2

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:3

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:13

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:33

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:17

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:77

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:99

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:39

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:34

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :3

Hash table :

Index :0  ->
Index :1  ->1
Index :2  ->2
Index :3  ->33   13   3
Index :4  ->34
Index :5  ->
Index :6  ->
Index :7  ->77   17
Index :8  ->
Index :9  ->39   99
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:90

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:80

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:44

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:55

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:35

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:77

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:87

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :2

Enter value:77

Value Found :77
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :3

Hash table :

Index :0  ->80   90
Index :1  ->1
Index :2  ->2
Index :3  ->33   13   3
Index :4  ->44   34
Index :5  ->35   55
Index :6  ->
Index :7  ->87   77   77   17
Index :8  ->
Index :9  ->39   99
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :3

Hash table :

Index :0  ->80   90
Index :1  ->1
Index :2  ->2
Index :3  ->33   13   3
Index :4  ->44   34
Index :5  ->35   55
Index :6  ->
Index :7  ->87   77   77   17
Index :8  ->
Index :9  ->39   99
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :2

Enter value:8

Value not found
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :1
Enter value:22

Inserted

Inserted!
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :3

Hash table :

Index :0  ->80   90
Index :1  ->1
Index :2  ->22   2
Index :3  ->33   13   3
Index :4  ->44   34
Index :5  ->35   55
Index :6  ->
Index :7  ->87   77   77   17
Index :8  ->
Index :9  ->39   99
Operations:
1.Insert
2.Find
3.Display
Exit
        Enter choice :4*/			 

