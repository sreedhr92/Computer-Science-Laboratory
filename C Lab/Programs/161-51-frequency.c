#include<stdio.h>
#include<string.h>
int count(char *a,char *b);
void main()
{
	
	char a[100],b[100];
	printf("Enter the line of text:");
	gets(a);
	printf("Enter the text to be searched and counted :");
	gets(b);
	printf("The frequency is %d",count(a,b));
}
int count(char *a,char *b)
{
	int i,e,j,n,m,temp,count_=0;
    n=strlen(a);
	m=strlen(b);
	for(i=0;i<n;i++)
	{
		temp=i;
		e=0;
		for(j=0;j<m;j++,temp++)
			 
		{
			if(*(a+temp)==*(b+j))
				e++;
			else
				e=0;
		}
		if(e==m)
		{
			count_++;
		}
	}
	return count_;
}	
/*Output:
Enter the line of text:lion is animal ,lion is king of the jugle, save lion.
Enter the text to be searched and counted:lion
The frequency is 3*/