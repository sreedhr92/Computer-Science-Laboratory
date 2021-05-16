#include<stdio.h>
#include<string.h>
void main()
{
	char a[100],b[100],c[100];
	int i,n,m,p,s,e,j=0,k=0;
	printf("Enter the Line of text :");
	gets(a);
	printf("Enter the string to be replaced :");
	gets(b);
	printf("Enter the replacement string :");
	gets(c);
	n=strlen(a);
	m=strlen(b);
	p=strlen(c);
	for(i=0;i<n;i++)
	{
		int temp=i;
		doit:
		if(a[temp]==b[j])
		{
			temp++;
			j++;
			if(j==m-1)
			{
				s=i;
			}
			goto doit;
		}
	}
	for(i=s;i<n-m;i++)
	{
		a[i]=a[i+m];
	}
	for(i=n-m;i>=s;i--)
	{
		a[i+p]=a[i];
	}
	
	for(i=0;i<p;i++)
	{
		a[i+s]=c[i];
	}
	a[n-m+p]='\0';
	printf("%s",a);
}
