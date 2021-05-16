#include<stdio.h>
void main()
{
	int n,r,count=0,f;
	printf("Enter number :");
	scanf("%d",&n);
    while(n!=0)
	{
		r=n%10;
		if(r==5)
			count+=1;
		else
			count=0;
		if(count==3)
		{
			f=0;
			break;
		}
		n/=10;
	}

	if(f!=1)
		printf("YES");
	else
		printf("NO");
}
/*Output
Enter number :5551
YES
Enter number :12345
No*/