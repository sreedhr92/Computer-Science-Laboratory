#include<stdio.h>
void ReverseNum(int n);
void main()
{
	int num;
	printf("Enter the number :");
	scanf("%d",&num);
	ReverseNum(num);
}
void ReverseNum(int n)
{
	int r;
	if(n>9)
	{
	   do
	   {
		r=n%10;
		printf("%d",r);
		n/=10;
	   }while(n!=0);
	}
	else
		printf("%d\n",n);
}