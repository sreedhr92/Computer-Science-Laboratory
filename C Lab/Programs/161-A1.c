//			Assignment number:1			Done by Roll number:18161                   On Date:28/01/2019
//1.Odd or even
#include<stdio.h>
void main()
{
        int a;
	printf("Enter a number :");
	scanf("%d",&a);
	//odd returns 1 and even returns 0...
	if(a%2==0)
	{
		printf("The number is even\n");
	}
	else
	{

		printf("The number is odd\n");
	}
}
/*Output:
Enter a number :4
The number is even

Enter a number :3



//2.Celcius to farenheit
#include<stdio.h>
void main()
{
	float c,f;
	printf("Enter celcius\n");
	scanf("%f",&c);
	//formula for convertion of celcius to farenheit...
	f=(((c*9)/5)+32);
	printf("Farenheit :%f",f);
}
/*Output :
Enter celcius :5
Farenheit :41.000000*/


//3.Modifying odd or even
#include<stdio.h>
void main()
{
        int a,flag;
	printf("Enter a number :");
	scanf("%d",&a);
	//flagging using ternary operator...
	flag=(a%2==0)?0:1;
	if(flag==0)
	printf("The number is Even\nflag=%d\n",flag);
	else if(flag==1)
	printf("The number is Odd\nflag=%d\n",flag);
}
/*Output:
Enter a number :4
The number is even
flag=0
Enter a number :3
The number is odd
flag=1*/

//4.Net pay calculation
#include<stdio.h>
void main()
{
	float red,GP,NP,BP,DA,HRA,PF,pHRA,pDA,pPF,AGP;
	printf("Enter the basic pay\n");
	scanf("%f",&BP);
	printf("Enter the Percentage of HRA,DA,PF\n");
	scanf("%f,%f,%f",&pHRA,&pDA,&pPF);
	printf("Enter the Acedemic Gross pay\n");
	scanf("%f",&AGP);
	PF=pPF/100;
	HRA=pHRA/100*BP;
	DA=pDA/100*BP;
	//netpay....
	GP=BP+HRA+DA+AGP;
	printf("THE GROSS PAY is %f\n",GP);
	//reducting the pf..
	red=PF*BP;
	NP=GP-red;
	printf("THE NET PAY is %f\n",NP);
}
/*Output:
Enter the basic pay
8000
Enter the percentage of HRA,DA,BF
10,20,10
Enter the Acedemic Gross Pay
5000
The Gross pay is 15400.000000
The Net pay is 14600.000000*/


//5.Modifying Netpay
#include<stdio.h>
void main()
{
	float red,GP,NP,BP,DA,HRA,PF,pHRA,pDA,pPF,AGP;
	char a,b;
	printf("Enter the basic pay\n");
	scanf("%f",&BP);
	printf("Enter the Percentage of DA,PF\n");
	scanf("%f,%f",&pDA,&pPF);
	PF=pPF/100;
	//Getting city type...
	printf("Choose city type\n1.metro(R)\n2.Corporation(C)\n3.Taluk(T)\n");
	scanf("%s",&a);
	if(a=='R')
	pHRA=10;
	else if(a=='C')
	pHRA=8;
	else if(a=='T')
	pHRA=5;
	else
	printf("Error TRY Again\n");
	//Getting designation....
	printf("Enter your designation\n1.Worker(W)\n2.Engineer(E)\n3.Manager(M)\n");
	scanf("%s",&b);
	if(b=='W')
	AGP=1000;
	else if(b=='E')
	AGP=2000;
	else if(b=='M')
	AGP=5000;
	else
	printf("Error TRY Again");
	HRA=pHRA/100*BP;
	DA=pDA/100*BP;
	GP=BP+HRA+DA+AGP;
	printf("THE GROSS PAY is %f\n",GP);
	//reducting pf....
	red=PF*BP;
	NP=GP-red;
	printf("THE NET PAY is %f\n",NP);
}
/*Output:
Enter the basic pay
10000
Enter the Percentage of DA,PF
20,10
Choose city type
1.metro(R)
2.Corporation(C)
3.Taluk(T)
R
Enter your designation
1.Worker(W)
2.Engineer(E)
3.Manager(M)
M
THE GROSS PAY is 18000.000000
THE NET PAY is 17000.000000*/


//6.Egg timer

#include<stdio.h>
void main()
{
	int N,i,j;
	printf("Enter the number for rows between 3 and 10 :");
	scanf("%d",&N);
	//printing of right angle triangle of spaces...
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
	//printing inverted trinagle of star of n decreasing rows... 	
		for(j=i;j<=N;j++)
		{
			printf("*");
			if(j<N)
				printf("_");
		}
		printf("\n");
	}
	//printing of inverted right angle triangle of spaces....
	for(i=2;i<=N;i++)
	{
		for(j=1;j<=N-i+1;j++)
		{
			printf(" ");
		}
	//printing of upright equilateral triangle of n-1 rows of star...	
		for(j=1;j<=i;j++)
		{
			printf("*");
			if(j<i)
				printf("_");
		}
		printf("\n");
	}
}
/*output:
Enter the number for rows between 3 and 10 :4
 *_*_*_*
  *_*_*
   *_*
    *
   *_*
  *_*_*
 *_*_*_*
*/

//7.Sum(version-1)
#include<stdio.h>
void main()
{
int i,sum=0,N,k;
printf("Enter the no of inputs :");
scanf("%d",&N);
//Getting each number until n and summing....
for(i=1;i<=N;i++)
{
   printf("Enter the input :");
   scanf("%d",&k);
   sum+=k;
}
printf("%d is the sum of your inputs",sum);
}
/*Enter the no of inputs :4
Enter the input :1
Enter the input :2
Enter the input :3
Enter the input :4
10 is the sum of your inputs*/

//7.Sum(Version-2)
#include<stdio.h>
void main()
{
int N,sum=0,k,i=1;
printf("Enter the no. of inputs ");
scanf("%d",&N);
//Getting each number until n and summing....
do
{
printf("Enter the number to add or press -999 to STOP :");
scanf("%d",&k);
//Sentinal value for terminating.....
if(k==-999)
break;
sum+=k;
i++;
}while(i<=N);
printf("%d is the sum of your inputs\n",sum);
}
 /*output :
Enter the no. of inputs:6
Enter the number to add or press -999 to STOP :6
Enter the number to add or press -999 to STOP :7
Enter the number to add or press -999 to STOP :5
Enter the number to add or press -999 to STOP :-8
Enter the number to add or press -999 to STOP :-999
10 is the sum of your inputs
*/

//7.Sum(version-3)
#include<stdio.h>
void main()
{
int N,sum=0,i=1,k;char h;
printf("Enter the no. of inputs :");
scanf("%d",&N);
//Getting each number until n and summing....
do
{
printf("Enter the +ve number below 100 to add :");
scanf("%d",&k);
sum+=k;
printf("To continue press 'y' or to stop press 'n' :");
scanf("%s",&h);
//Sentinal value for stopping...
if(h=='n')
break;
i++;
}while(i<=N);
printf("%d is the sum of your inputs\n",sum);
}
/*Output
Enter the no. of inputs :4
Enter the +ve number below 100 to add :-8
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :10
To continue press 'y' or to stop press 'n' :n
2 is the sum of your inputs*/

//7.Sum(version-4)
#include<stdio.h>
void main()
{
int N,sum=0,i=1,k;char h;
printf("Enter the no. of inputs :");
scanf("%d",&N);
//Getting each number until n and summing.....
do
{
printf("Enter the +ve number below 100 to add :");
scanf("%d",&k);
//Validation of the inputs.....
if(k<100 && k>0)
sum+=k;
printf("To continue press 'y' or to stop press 'n' :");
scanf("%s",&h);
//Sentinal value for termination...
if(h=='n')
break;
i++;
}while(i<=N);
printf("%d is the sum of your inputs\n",sum);
}
/*Output:
Enter the no. of inputs :5
Enter the +ve number below 100 to add :2
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :-2
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :107
To continue press 'y' or to stop press 'n' :n
2 is the sum of your inputs*/

//7.Sum(version-5)
#include<stdio.h>
void main()
{
int N,sum=0,i=1,k;char h;
printf("Enter the no. of inputs :");
scanf("%d",&N);
//Getting each number until n and summing....
do
{
printf("Enter the +ve number below 100 to add :");
scanf("%d",&k);
//Validation of the input......
if(k<100 && k>0)
sum+=k;
else
{
	printf("INVALID INPUT PROCESS TERMINIATED\n");
	break;
}
printf("To continue press 'y' or to stop press 'n' :");
scanf("%s",&h);
//Sentinal value for termination....
if(h=='n')
break;
i++;
}while(i<=N);
printf("%d is the sum of your inputs\n",sum);
}
/*Output:
Enter the no. of inputs :5
Enter the +ve number below 100 to add :5
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :3
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :8
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :-8
INVALID INPUT PROCESS TERMINIATED
16 is the sum of your inputs*/

//7.Sum(Version-6)
#include<stdio.h>
void main()
{
int N,sum=0,i=1,k;char h;
printf("Enter the no. of inputs :");
scanf("%d",&N);
//Getting each number until n and summing
do
{
printf("Enter the +ve number below 100 to add :");
scanf("%d",&k);
//Validation of the input
if(k<100 && k>0)
sum+=k;
//Skipping the entered value....
else
{
	printf("INVALID INPUT TRY ANOTHER INPUT\n");
	continue;
}
printf("To continue press 'y' or to stop press 'n' :");
scanf("%s",&h);
//Sentinal value of termination....
if(h=='n')
break;
i++;
}while(i<=N);
printf("%d is the sum of your inputs\n",sum);
}
/*Output:
Enter the no. of inputs :5
Enter the +ve number below 100 to add :3
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :1022
INVALID INPUT TRY ANOTHER INPUT
Enter the +ve number below 100 to add :4
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :-2
INVALID INPUT TRY ANOTHER INPUT
Enter the +ve number below 100 to add :99
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :6
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :5
To continue press 'y' or to stop press 'n' :y
117 is the sum of your inputs*/

//8.Calculator
#include<stdio.h>
#include<math.h>
void main()
{
	int a,b,c,x;
	printf("The options in the calculator are\n1.Addition\n2.Suntraction\n3.Multiplication\n4.Division\n5.Squaring\n");
	printf("Enter your choice number :");
	scanf("%d",&x);
	//Getting choice for using case expression....
	if(x<5)
	{
		printf("Enter the first number:");
		scanf("%d",&a);
		printf("Enter the Second number :");
		scanf("%d",&b);
	}
	//Getting input when squaring is selected....
	else
	{
		printf("Enter the number:");
		scanf("%d",&a);
	}
	//The value of x will be matched to a certain cases below and executed.....
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

//19. Consecutive 555s:
#include<stdio.h>
void main()
{
	int n,r,count=0,f;
	printf("Enter number :");
	scanf("%d",&n);
	//Splitting and checking each digit of the number....
    while(n!=0)
	{
		r=n%10;
		if(r==5)
			count+=1;
		else
			count=0;
	//flagging the count....	
		if(count==3)
		{
			f=0;
			break;
		}
		n/=10;
	}
	//printing the flaged value.....
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

//10.Odd or even Without condition:

#include<stdio.h>
void main()
{
    int n;
    printf("Enter the num:");
    scanf("%d",&n);
    //Special condition using logical operators.....
    if(n%2) && (printf("Odd");) || (printf("Even");)
}
/*Output:
Enter the num:4
Even
Enter the num:3
Odd*/

