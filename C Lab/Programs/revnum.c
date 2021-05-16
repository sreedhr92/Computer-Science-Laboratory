#include<stdio.h>
int rev(int n);
void main()
{
	long int n;
	printf("Enter a number :");
	scanf("%d",&n);
	rev(n);
}
int rev(int n)
{
	if(n>=0)
	{
		printf("%d",n);
		n--;
		rev(n);
	}
	else
		return 0;
}