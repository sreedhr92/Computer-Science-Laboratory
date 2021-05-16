#include"BSTimpl.h"
void main()
{
	struct tree *t;
	t=NULL;
	int c;
	struct player x;
	char name[100];
	do
	{
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Preorder display\n6.Inorder display\n7.Postorder display\n8.Exit\nEnter choice :");
		scanf("%d",&c);
		if(c==1)
		{
			x=input();
			t=insert(t,x);
			printf("\nInserted!!\n");
		}
		else if(c==2)
		{
			printf("\nEnter Name :");
			scanf("%s",name);
			deletetree(t,name);
			printf("\nDeleted!!\n");
		}
		else if(c==3)
		{
			printf("\nEnter Name :");
			scanf("%s",name);
			x=search(t,name);
			if(strcmp(x.name,"empty")==0)
				printf("\nInvalid name\n ");
			else
				display_node(x);
		}
		else if(c==4)
		{
			display_tree(t,0);
		}
		else if(c==5)
		{
			preorder(t);
		}
		else if(c==6)
		{
			inorder(t);
		}
		else if(c==7)
		{
			postorder(t);
		}
		else if(c==8)
		{
			printf("\nExiting...Thank you.....");
		}
		else 
		{
			printf("\nInvalid option..");
		}
	}while(c!=8);
}	
/*Output:
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 7> gcc BSTapp.c -o a                                                                           PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 7> ./a           
1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :1

Enter player Name  :dhoni

Enter player Role  :keeper

Enter player Avgrr :99

Inserted!!

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :1

Enter player Name  :kohli

Enter player Role  :batsman

Enter player Avgrr :100

Inserted!!

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :1

Enter player Name  :dhawan

Enter player Role  :batsman

Enter player Avgrr :78

Inserted!!

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :1

Enter player Name  :hardik

Enter player Role  :allrounder

Enter player Avgrr :88

Inserted!!

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :1

Enter player Name  :shami

Enter player Role  :bowler

Enter player Avgrr :10

Inserted!!

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :4
dhoni
        dhawan
        kohli
                hardik
                shami

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :2

Enter Name :dhawan

Deleted!!

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :4
dhoni
        kohli
                hardik
                shami

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :5

Name   : dhoni

Avgrr  : 99.000000

Role   : keeper

Name   : kohli

Avgrr  : 100.000000

Role   : batsman

Name   : hardik

Avgrr  : 88.000000

Role   : allrounder

Name   : shami

Avgrr  : 10.000000

Role   : bowler

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :6

Name   : dhoni

Avgrr  : 99.000000

Role   : keeper

Name   : hardik

Avgrr  : 88.000000

Role   : allrounder

Name   : kohli

Avgrr  : 100.000000

Role   : batsman

Name   : shami

Avgrr  : 10.000000

Role   : bowler

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :7

Name   : hardik

Avgrr  : 88.000000

Role   : allrounder

Name   : shami

Avgrr  : 10.000000

Role   : bowler

Name   : kohli

Avgrr  : 100.000000

Role   : batsman

Name   : dhoni

Avgrr  : 99.000000

Role   : keeper

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :3

Enter Name :hardik

Name   : hardik

Avgrr  : 88.000000

Role   : allrounder

1.Insert
2.Delete
3.Search
4.Display
5.Preorder display
6.Inorder display
7.Postorder display
8.Exit
Enter choice :8

Exiting...Thank you.....*/