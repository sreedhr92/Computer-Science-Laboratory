#include<stdio.h>
void main()
{
	char a[100],temp;
	//getting a string...
	printf("Enter the string :");
	gets(a);
	int n=0,i;
	//finding its length
	while(a[n]!='\0')
	{
		n++;
	}
	//swapping the elements from first half to last half of the string....
	for(i=0;i<n/2;i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
	printf("The reversed string is %s",a);
}
/*Output:
Enter the string :Sreedhar is good boy
The reversed string is yob doog si rahdeerS*/
