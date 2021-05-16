#include<stdio.h>
void ore(int n);
int so=0,se=0;
void main()
{
	int n,i,k;
	printf("Enter the number of inputs :");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the input :");
		scanf("%d",&k);
		ore(k);
	}
	printf("The sum of even num is %d\n",se);
	printf("The sum of odd num is %d\n",so);
}
void ore(int n)
{ 
	int flag,k;
	k=n;
	if(n%2==0)
	{
  		flag=1;
		se+=k;
	}
	else
	{
		flag=0;
		so+=k;
	}
	if(flag==1)
	{
		printf("The number is even and the flag is %d\n",flag);
	}	
	else
	{
		printf("The number is odd and the flag is %d\n",flag);
	}
}
