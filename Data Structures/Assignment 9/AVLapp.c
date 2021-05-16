#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"AVLintf.h"
#include"AVLimpl.h"
struct wordMeaning input()
{
	struct wordMeaning x;
	printf("\nEnter the word    :");
	scanf("%s",&x.word);
	printf("\nEnter its meaning :");
	scanf("%s",&x.meaning);
	return x;
}
void main()
{
	struct AVLtree *t;
	t=NULL;
	struct wordMeaning x;
	int ch;
	char word[100];
	printf("\n---------DICTIONARY--------------\n");
	do
	{
		printf("\nOperations :\n1.Insert\n2.Display\n3.Search\n4.Exit\n\tEnter choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			x=input();
			t=insert(t,x);
			printf("\nInserted!!\n");
		}
		else if(ch==2)
			display(t,0);
		else if(ch==3)
		{
			printf("\nEnter the word to search :");
			scanf("%s",word);
			x=search(t,word);
			if(strcmp(x.word,"empty")==0)
				printf("\nInvalid name\n ");
			else
				display_word(x);
		}
		else if(ch==4)
			printf("\nExiting...Thank you.....");
		else
			printf("\nInvalid Option");	
	}while(ch!=4);
}
/*Output:
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 9> gcc AVLapp.c -o a                                                                           PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 9> ./a           
---------DICTIONARY--------------

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :Sarangi

Enter its meaning :love

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :Burtang

Enter its meaning :fire

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :jojerro

Enter its meaning :dope

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :maehejo

Enter its meaning :tell

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :bailar

Enter its meaning :dance

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :despacito

Enter its meaning :slowly

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :acabir

Enter its meaning :stop

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:1

Enter the word    :seinko

Enter its meaning :5

Inserted!!

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:2
Sarangi
        Burtang
        jojerro
                bailar
                        acabir
                        despacito
                maehejo
                        seinko

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:3

Enter the word to search :jojerro

Word    :jojerro

Meaning :dope

Operations :
1.Insert
2.Display
3.Search
4.Exit
        Enter choice:4

Exiting...Thank you....*/