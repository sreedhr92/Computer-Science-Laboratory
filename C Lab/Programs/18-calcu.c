#include<stdio.h>
#include<math.h>
void main()
{
	int a,b,c,x;
	printf("The options in the calculator are\n1.Addition\n2.Suntraction\n3.Multiplication\n4.Division\n5.Squaring\n");
	printf("Enter your choice number :");
	scanf("%d",&x);
	if(x<5)
	{
		printf("Enter the first number:");
		scanf("%d",&a);
		printf("Enter the Second number :");
		scanf("%d",&b);
	}
	else
	{
		printf("Enter the number:");
		scanf("%d",&a);
	}
	switch(x)
	{
		case 1:c=a+b;
		       printf("%d is the sum",c);
		       break;
		case 2:c=a-b;
		       printf("%d is the diff",c);
		       break;
		case 3:c=a*b;
		       printf("%d is the product ",c);
		       break;
		case 4:c=a/b;
		       x=a%b;
		       printf("%d is the quotient",c);
		       printf("%d is the reminder",x);
		       break;  
		case 5:c=pow(a,2);
		       printf("%d is the squared value",c);
		       break;
		default:printf("Sorry given choice is not availabe :p");

	}
}
/*Output
The options in the calculator are
1.Addition
2.Suntraction
3.Multiplication
4.Division
5.Squaring
Enter your choice number :5
Enter the number :3
9 is the squared value*/