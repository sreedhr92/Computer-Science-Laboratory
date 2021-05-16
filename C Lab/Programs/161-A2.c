
//1.Sum of Odd and Even inputs :
#include<stdio.h>
//Declaration of the funcion...
void CheckOddEven(int num);
int so=0,se=0;
void main()
{
	int n,i,k;
	printf("Enter the number of inputs :");
	scanf("%d",&n);
	//Getting the input for each time....
	for(i=1;i<=n;i++)
	{
		printf("Enter the input :");
		scanf("%d",&k);
	//Calling the function for each i....	
		CheckOddEven(k);
	}
	printf("The sum of even num is %d\n",se);
	printf("The sum of odd num is %d\n",so);
}
//Definition of the function...
void CheckOddEven(int num)
{ 
	int flag,k;
	k=num;
	//Adding even inputs by checking condtion...
	if(num%2==0)
	{
  		flag=1;
		se+=k;
	}
	else
	{
		flag=0;
		so+=k;
	}
	//Flagging whether odd or even..
	if(flag==1)
	{
		printf("The number is even and the flag is %d\n",flag);
	}	
	else
	{
		printf("The number is odd and the flag is %d\n",flag);
	}
}

/*Output:
nter the number of inputs :5
Enter the input :1
The number is odd and the flag is 0
Enter the input :2
The number is even and the flag is 1
Enter the input :3
The number is odd and the flag is 0
Enter the input :4
The number is even and the flag is 1
Enter the input :5
The number is odd and the flag is 0
The sum of even num is 6
The sum of odd num is 9*/

//2.Reversing the entered digits:
#include<stdio.h>
//Declaration of the function...
void ReverseNum(int n);
void main()
{
	int num;
	printf("Enter the number :");
	scanf("%d",&num);
	ReverseNum(num);
}
//Definition of the function...
void ReverseNum(int n)
{
	int r;
	if(n>9)
	{
	//printing the last digit of the number by mod operator if it is a two digit number...
	   do
	   {
		r=n%10;
		printf("%d",r);
		n/=10;
	   }while(n!=0);
	}
	//printing the last digit...
	else
		printf("%d\n",n);
}
 
/*Output :
Enter the number :7654321
1234567*/

//3.Calculating the powers of floating point and the negative numbers:
#include<stdio.h>
//Declaration of the function....
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
//Defining the function power to get exponent for various values of base and exponent....
float power(float p,int q)
{
	double y=1;
	int i;
	//when exponent is negative....
	if(q<0)
	{
		for(i=1;i>=q;i--)
		{
			y*=1/p;
		}
		printf("%.1f base to the power %d is %f",p,q,y);

	}
	//when exponent is positive....
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

/*Output:
1.Enter the base :2
  Enter the exponent :3
  2.0 base to the power 3 is 8.0000000
2.Enter the base :-3
  Enter the exponent :7
  -3.0 base to the power 7 is -2187.0000000
3.Enter the base :0.2
  Enter the exponent :-5
  0.2 base to the power -5 is 78125.0000000
4.Enter the base :2
  Enter the exponent :-5
  2.0 base to the power -5 is 0.0078130*/

//4.Product of n floating numbers :
#include<stdio.h>
float p=1,k;
float product(int n);
void main()
{
	int a;
	printf("Enter the no. of inputs :");
	scanf("%d",&a);
	printf("the product is %f ",product(a));
}
//definition of the funcion
float product(int n)
{
	//Setting a sentinal value to stop the recursion....
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
	//Base condition....
	else
	 	return p;
}

/*Output:
1.Enter the no. of inputs :4
  Enter the number greater than 0 else it will stop:1.1
  Enter the number greater than 0 else it will stop:1.2
  Enter the number greater than 0 else it will stop:1.3
  Enter the number greater than 0 else it will stop:1.4
  the product is 2.402400.
2.Enter the no. of inputs :5
  Enter the number greater than 0 else it will stop:2.5
  Enter the number greater than 0 else it will stop:6
  Enter the number greater than 0 else it will stop:-6
  Invalid input
  the product is 0.000000*/

//5.Recursion to print N to 0:

#include<stdio.h>
int rev(int n);
void main()
{
	long int n;
	printf("Enter a number :");
	scanf("%d",&n);
	rev(n);
}
int rev(int n)
{
	//printing the current value of n....
	if(n>=0)
	{
		printf("%d",n);
		n--;
		rev(n);
	}
	else
		return 0;
}

/*Output:
Enter a number :10
109876543210*/

//6.Finding the right most non Zero digit of a factorial.

#include<stdio.h>
//Declaration of the function.....
int fact(int n);
void main()
{
	int n;
	printf("Enter the number :");
	scanf("%d",&n);
	printf("The right most non zero digit of the factorial of the entered number is %d",fact(n));
}
int fact(int n)
{
	int i,d;
    int fact=1;
	//Finding the factorial....
	for(i=1;i<=n;i++)
	{	
		fact*=i;
		while(fact%10==0)
		{
			fact/=10;
			fact%10;
		}			
	}
	//Getting its right most non zero digit....
	/*while(fact!=0)
	{
	d=fact%10;
	if(d!=0)
	{
		return d;
	}
	else
	{
		fact/=10;
	}
    }*/

}	

/*Output:
Enter the number :13
The right most non zero digit of the factorial of the entered number is 4*/



