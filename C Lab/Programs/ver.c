#include<stdio.h>
void main()
{
	int n,i,j,m=0;
	printf("Enter no.of digits :");
	scanf("%d",&n);
	printf("Enter %d Digits:\n",n);
	int a[n],b[10];
	//Getting each digit...
	for(i=0;i<n;i++)
	{
		printf("Enter a digit(0-9):");
		scanf("%d",&a[i]);
	//Input validation....	
		if(a[i]>9)
		{
			printf("Invalid input...Please re-enter the digit.. \n");
			i--;
		}
	}
	//Printing the inputed digits.....
	printf("\nYour digits are :\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	//Initialising the histogram as each element ie,Digit=0....
	for(i=0;i<10;i++)
	{
		b[i]=0;
	}
	//Updating the each elements in the histogram array......
	for(i=0;i<n;i++)
	{
		b[a[i]]++;
	}
	//Find the maximum value in the histogram array for plotting the y-axis....
	for(i=0;i<10;i++)
	{
		if(b[i]>m)
		{
			m=b[i];
		}
	}
	printf("\n\n");
	//printing the vertical histrogram of stars........
	for(i=0;i<m;i++)
	{
		for(j=0;j<10;j++)
		{
			if(m-i<=b[j])
			{
				printf("*  ");
			}
			else
			{
				printf("   ");
			}
		}	
		printf("\n");	
	}	
	//Printing the histogram values above the x axis....
	/*printf("\n\n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",b[i]);
	}*/
	//Giving the digits 0-9 as the x-axis....
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",i);
	}
}
/*Output:
PS C:\TDM-GCC-64\myprogram> gcc 32-verticalhistogram.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter no.of digits :13
Enter 13 Digits:
Enter a digit(0-9):1
Enter a digit(0-9):7
Enter a digit(0-9):2
Enter a digit(0-9):9
Enter a digit(0-9):6
Enter a digit(0-9):7
Enter a digit(0-9):1
Enter a digit(0-9):3
Enter a digit(0-9):7
Enter a digit(0-9):5
Enter a digit(0-9):7
Enter a digit(0-9):9
Enter a digit(0-9):0

Your digits are :

1,7,2,9,6,7,1,3,7,5,7,9,0,

                     *
                     *
   *                 *     *
*  *  *  *     *  *  *     *

0  1  2  3  4  5  6  7  8  9
*/