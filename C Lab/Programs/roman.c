#include<stdio.h>
void roman(int n);
void main()
{
	int n;
	do
	{
		printf("Enter the number(upto 20) to convert into roman numerals or press 0 to stop :");
		scanf("%d",&n);
		if((n>20)||(n==0))
		{printf("Invalid input\n");break;}
		else roman(n);
	}while(1);
}
void roman(int n)
{
	int r,i;
	char a[10][10]={"I","II","III","IV","V","VI","VII","VIII","IX","X"};
	if(n<11)
	{
		printf("%s\n",&a[n-1]);
	}
	if(n>10)
	{
		r=n%10;
		printf("%s",&a[9]);
		if(r==0)
		{
			printf("%s\n",&a[9]);
		}
		else
		{
			printf("%s\n",&a[r-1]);
		}
	}
}