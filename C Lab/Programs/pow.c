#include<stdio.h>
float power(float p,int q);
void main()
{
	int n;
	float x;
	printf("Enter the base :");
	scanf("%f",&x);
	printf("Enter the exponent :");
	scanf("%d",&n);
	printf("%d",power(x,n));
}
float power(float p,int q)
{
	double y=1;
	int i;
	if(q<0)
	{
		for(i=1;i>=q;i--)
		{
			y*=1/p;
		}
		printf("%.1f base to the power %d is %f",p,q,y);

	}
	else if(q>0)
	{
		for(i=1;i<=q;i++)
		{
			y*=p;
		}
		printf("%.1f base to the power %d is %f",p,q,y);
    }
    else
    	return 1;
}    


