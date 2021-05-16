

//1.Word Frequency count

#include<stdio.h>
#include<string.h>
int wcount(char *a,char *b);

void main()
{
char a[100],b[100];
int c;
printf("Enter a sentence:\n");//Reading Sentence
gets(a);
printf("Enter the word to be found:\n");//Reading word 
gets(b);
c=wcount(a,b);//function call
printf("%s is present %d times\n",b,c);
}


int wcount(char *a,char *b)
{
char temp[100];
int i=0,j=0,count=0,c;
while(*(a+i)!='\0')
	{
	//Separating word by word
	if(*(a+i)!=' ')
		{
		*(temp+j)=*(a+i);  
		*(temp+j+1)='\0';   
		j++;
		i++;	
		c=strcmp(temp,b);//comparing words
		if(c==0)
			count++;
		}
	else	
		{
		j=0;
		i++;
		}
	
	}
return count;
}

/*
Output:
Enter a sentence:
hello hello world
Enter the word to be found:
hello
hello is present 2 times
*/


//3.Modify 11.22
/* calculate the sum of the elements in two tables of integers */
/* each 2-dimensional array is processed as an array
of pointers to a set of 1-dimensional integer arrays */
#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 20
/* function prototypes */
void readinput (int *a[MAXROWS], int nrows, int ncols);
void compare(int *a[MAXROWS], int *b[MAXROWS],
int *c[MAXROWS], int nrows, int ncols);
void writeoutput(int *c[MAXROWS], int nrows, int ncols);
void main( )
{
int row, nrows, ncols;
/* pointer definitions */
int *a[MAXROWS], *b[MAXROWS], *c[MAXROWS];
printf( "How many rows? ");
scanf( "%d", &nrows);
printf("How many columns? ");
scanf("%d", &ncols);
/* allocate initial memory */
for (row = 0; row < nrows; ++row)
	{
	a[row] = (int *) malloc (ncols * sizeof(int));
	b[row] = (int *) malloc (ncols * sizeof(int));
	c[ row] = (int *) malloc (ncols * sizeof (int));
	}
printf("\nFirst table:\n");
readinput(a, nrows, ncols);
printf("\nSecond table:\n");
readinput(b, nrows, ncols);
compare(a, b, c, nrows, ncols);
printf ("\nTable of large elements:\n");
writeoutput(c, nrows, ncols); 
}
void readinput(int *a[MAXROWS], int m, int n)
/* read in a table of integers */
{
int row, col;
for (row = 0; row < m; ++row) 
	{
	printf("\nEnter data for row no. %2d\n", row + 1);
	for (col = 0; col < n; ++col)
		scanf("%d", (*(a + row) + col));
	}
return;
}
void compare(int *a[MAXROWS], int *b[MAXROWS], int *c[MAXROWS], int m, int n)
/* compare the elements of two integer tables */
{
int row, col;
for (row = 0; row < m; ++row)
	for (col = 0; col < n; ++col)
		*(*(c + row) + col) = (*(*(a + row) + col)>*(*(b + row) + col))?*(*(a + row) + col):*(*(b + row) + col);
return;
}
void writeoutput(int *a[MAXROWS], int m, int n)
/* write out a table of integers */
{
int row, col;
for (row = 0; row < m; ++row) 
{
	for (col = 0; col < n; ++col)
	printf("%4d", *(*(a + row) + col));
printf ("\n") ;
}
return; 
}

/*
Output:

How many rows? 2
How many columns? 2

First table:

Enter data for row no.  1
1
2
Enter data for row no.  2
10
9

Second table:

Enter data for row no.  1
8
7

Enter data for row no.  2
3
4

Table of large elements: 
   8   7
   10  9
  */

//4.days count

#include<stdio.h>                                                       
#include<stdlib.h>                                                      
void readinput(int *m, int *d, int *y);                               
int days(int *d, int *m, int *y);                                  

void main()
{
	int m1, d1, y1, m2, d2, y2, b;
	printf("\nEnter 0 0 0 To Stop");
	printf("\nEnter the dates as(dd mm yyyy)\n");
	readinput(&m1, &d1, &y1);
	if(m1==0 && d1==0 && y1==0)    
		goto stop;
	else
		readinput(&m2, &d2, &y2); 
	while(m1!=0 && m2!=0)                          // To check if the user enters wrong dates 
	{
		b = days(&m1, &d1, &y1) - days(&m2, &d2, &y2);
		if(b < 0)                              //Condition for when the user enters the dates in a wrong manner
			b = -b;                    
		printf("Number of days : %d",b);
		readinput(&m1, &d1, &y1);                                              
	if(m1==0 && d1==0 && y1==0)     
		goto stop;   
	else
		readinput(&m2, &d2, &y2);                                 
	}
stop:
	printf("End\n");
}

void readinput(int *m, int *d, int *y)                                      
{
	printf("\nEnter: date month year : ");
	scanf(" %d %d %d", m, d, y);		
}

int days(int *d, int *m, int *y)                                         
{
	int bd=1, bm=1, by=1900, ndays, nyb, nupto;
	nyb = (*y-by) % 4;                   // Number of years beyond the 4 year cycles.
	nupto = (*y-by) / 4;                 // Number of 4 year cycles.
	ndays = nupto * 1461;                // Number of days from the base date within the cycle of 4 yrs.
	if(nyb>0)                            //To include days beyond the cycle of 4 yrs
		ndays += 365 * nyb + 1;
	
    ndays += (long)(30.42 * (*m-1)) + *d;
	
	if(*m == 2) ++ndays;
	if(*m > 2 && *m < 8) --ndays;
	if(*m > 2 && ((*y-by)%4==0)) ++ndays;
	
	if(ndays>59)
		ndays--;
	return ndays;
}

/* OUTPUT:


Enter 0 0 0 To Stop
Enter the dates as(dd mm yyyy)

Enter: date month year : 04 12 2000

Enter: date month year : 04 12 2001
Number of days : 365
Enter: date month year : 0 0 0
End
*/