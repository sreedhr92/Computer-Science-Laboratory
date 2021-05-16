#include<stdio.h>
void avg(int b[],int m);
void main()
{
	int n,i;
	printf("Enter the no.of elements:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		{
			printf("Enter the elements:");
			scanf("%d",&a[i]);
		}
	printf("The average of the list is %f",avg(a[],n));
}		
void avg(int b[],int m)
{
	int i;
	float avg1,s=0;
	for(i=0;i<n;i++)
	{
		s+=b[i];
	}
	return avg1=s/m;
}