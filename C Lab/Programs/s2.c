#include<stdio.h>
void main()
{
	char a[100],temp;
	printf("Enter the string :");
	gets(a);
	int n=0,i;
	while(a[n]!='\0')
	{
		n++;
	}
	for(i=0;i<n/2;i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
	printf("The reversed string is %s",a);
}
