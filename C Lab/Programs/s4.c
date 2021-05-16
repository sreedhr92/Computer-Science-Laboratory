#include<stdio.h>
#include<string.h>
void main()
{
	char a[100],b[100];
	int i,j,n,m,e;
	printf("Enter the Line of text :");
	gets(a);
	printf("Enter the string to find the oocurance :");
	scanf("%s",b);
	n=strlen(a);
	m=strlen(b);
	j=m-1;
	for(i=n-1;i>=0;i--)
	{
		doit:
		if(a[i]==b[j])
		{
			i--;
			j--;
			if(j==0)
			{
				e=i;
				break;
			}
			goto doit;
		}
	}
	printf("The last occurance is %d\n",e);
}