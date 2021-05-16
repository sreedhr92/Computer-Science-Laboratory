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
	//checking the whole process in a reverse order
	j=m-1;
	for(i=n-1;i>=0;i--)
	{
		//if one character is matched doing it again for all chacrters untill the whole string is matched with the entered one
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
	//returning the last index  that gives you the staring of the last occurance
	printf("The last occurance is %d\n",e);
}
/*Output:
Enter the Line of text :boy is good and girl is bad than boy
Enter the string to find the oocurance :boy
The last occurance is 33*/