#include<stdio.h>
#include<string.h>
void main()
{
	int i,e,j,n,m,count=0;
	char a[100],b[100];
	printf("Enter the line of text:");
	gets(a);
	printf("Enter the text to be searched and counted :");
	gets(b);
	n=strlen(a);
	m=strlen(b);
	for(i=0;i<n;i++)
	{
		e=0;
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				i++;
				e++;
			}
			if(e==m-1)
			{
				count++;
			}
		}
	}
	printf("The frequency is %d",count);
}