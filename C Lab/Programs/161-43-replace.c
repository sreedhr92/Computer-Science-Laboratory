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
	//getting the length of all strings
	n=strlen(a);
	m=strlen(b);
	p=strlen(c);
	//Traversing through each elements of the string
	for(i=0;i<n;i++)
	{
		//if first character of the both strings are matched doing until end of the replacing string
		int temp=i;
		doit:
		if(a[temp]==b[j])
		{
			temp++;
			j++;
			//last character of the replacing string is came getting the starting index of the string
			if(j==m-1)
			{
				s=i;
			}
			goto doit;
		}
	}
	//pushing the character to delete and replace the string
	for(i=s;i<n-m;i++)
	{
		a[i]=a[i+m];
	}
	for(i=n-m;i>=s;i--)
	{
		a[i+p]=a[i];
	}
	//assigning the characters of the replacement string the gap left 
	for(i=0;i<p;i++)
	{
		a[i+s]=c[i];
	}
	a[n-m+p]='\0';
	printf("%s",a);
}
/*Output:
Enter the Line of text :Sree is good boy
Enter the string to be replaced :good
Enter the replacement string :bad
Sree is bad boy*/
