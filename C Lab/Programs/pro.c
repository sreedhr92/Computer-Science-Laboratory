#include<stdio.h>
float p=1,k;
float product(int n)
{
	if(n>0)
	{
		printf("Enter the number greater than 0 else it will stop:");
		scanf("%f",&k);
		if(k>0)
		{
			p*=k;
			n--;
			product(n);
	    }
	    else
	    	printf("Invalid input\n");
	}    
	else
	 	return p;
}

void main()
{
	int a;
	printf("Enter the no. of inputs :");
	scanf("%d",&a);
	printf("the product is %f ",product(a));
}
