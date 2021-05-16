#include<stdio.h>
int fact(int n);
void main()
{
	int n;
	printf("Enter the number :");
	scanf("%d",&n);
	printf("The right most non zero digit of the factorial of the entered number is %d",fact(n));
}
int fact(int n)
{
	int i,d;
	unsigned long int fact=1;
	for(i=1;i<=n;i++)
	{	
		fact*=i;		
	}
	while(fact!=0)
	{
	d=fact%10;
	if(d!=0)
	{
		return d;
	}
	else
	{
		fact/=10;
	}
    }

}	