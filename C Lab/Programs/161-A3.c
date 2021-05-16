s//1.Printing the Well ordered number.....
#include<stdio.h>
int count=0;
//Function declaration.....
int check(int n);
void main()
{
	int i;
	printf("The Possible Well ordered Three digit numbers are ");
	//Checking all 3 digit number each time.....
	for(i=100;i<1000;i++)
	{
		check(i);
	}
	printf("The total number of 3 digit well ordered numbers are %d",count);
}
//To split the number into individual digits an storing in an array...
int check(int n)
{
	int a[3],j,k=n;
	for(j=2;j>=0;j--)
	{
		a[j]=n%10;
		n/=10;
	}
//Checking whether the each digit is greater than the other.. 	
	if((a[0]<a[1]) && (a[1]<a[2]))
	{
		printf("%d\t",k);
		count++;
	}
}
/*Output :
PS C:\TDM-GCC-64\myprogram> gcc 31-wellordered.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
The Possible Well ordered Three digit numbers are 123   124     125     126
127     128     129     134     135     136     137     138     139     145
146     147     148     149     156     157     158     159     167     168
169     178     179     189     234     235     236     237     238     239
245     246     247     248     249     256     257     258     259     267
268     269     278     279     289     345     346     347     348     349
356     357     358     359     367     368     369     378     379     389
456     457     458     459     467     468     469     478     479     489
567     568     569     578     579     589     678     679     689     789
The total number of 3 digit well ordered numbers are 84*/

//2.Printing vertical histogram of digits.....
#include<stdio.h>
void main()
{
	int n,i,j,m=0;
	printf("Enter no.of digits :");
	scanf("%d",&n);
	printf("Enter %d Digits:\n",n);
	int a[n],b[10];
	//Getting each digit...
	for(i=0;i<n;i++)
	{
		printf("Enter a digit(0-9):");
		scanf("%d",&a[i]);
	//Input validation....	
		if(a[i]>9)
		{
			printf("Invalid input...Please re-enter the digit.. \n");
			i--;
		}
	}
	//Printing the inputed digits.....
	printf("\nYour digits are :\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	//Initialising the histogram as each element ie,Digit=0....
	for(i=0;i<10;i++)
	{
		b[i]=0;
	}
	//Updating the each elements in the histogram array......
	for(i=0;i<n;i++)
	{
		b[a[i]]++;
	}
	//Find the maximum value in the histogram array for plotting the y-axis....
	for(i=0;i<10;i++)
	{
		if(b[i]>m)
		{
			m=b[i];
		}
	}
	printf("\n\n");
	//printing the vertical histrogram of stars........
	for(i=0;i<m;i++)
	{
		for(j=0;j<10;j++)
		{
			if(m-i<=b[j])
			{
				printf("*  ");
			}
			else
			{
				printf("   ");
			}
		}	
		printf("\n");	
	}	
	//Printing the histogram values above the x axis....
	/*printf("\n\n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",b[i]);
	}*/
	//Giving the digits 0-9 as the x-axis....
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",i);
	}
}
/*Output:
PS C:\TDM-GCC-64\myprogram> gcc 32-verticalhistogram.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter no.of digits :13
Enter 13 Digits:
Enter a digit(0-9):1
Enter a digit(0-9):7
Enter a digit(0-9):2
Enter a digit(0-9):9
Enter a digit(0-9):6
Enter a digit(0-9):7
Enter a digit(0-9):1
Enter a digit(0-9):3
Enter a digit(0-9):7
Enter a digit(0-9):5
Enter a digit(0-9):7
Enter a digit(0-9):9
Enter a digit(0-9):0

Your digits are :

1,7,2,9,6,7,1,3,7,5,7,9,0,

                     *
                     *
   *                 *     *
*  *  *  *     *  *  *     *

0  1  2  3  4  5  6  7  8  9
*/

//3.Pushing all the zeros to the end of the array......
#include<stdio.h>
//Function declaration.......
void pushZerosToEnd(int arr[],int n);
void main()
{
	int i,n;
	printf("Enter no. of elements to be entered in the array :");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in the array :\n");
	//Getting input and storing it in an array.....
	for(i=0;i<n;i++)
	{
		printf("Enter the element :");
		scanf("%d",&arr[i]);
	}
	//Printing the ouput..
	printf("Input :");
	for(i=0;i<n;i++)
	{
		printf("[%d]  ",arr[i]);
	}
	pushZerosToEnd(arr,n);
}
//Pushing the zero to end of the same array by updating the same element in the array....
void pushZerosToEnd(int arr[],int n)
{
	int i,k=0;
	int a[n];
	printf("\nOutput:");
//Assigning the non-zero element orderly from first....... 	
	for(i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			arr[k]=arr[i];
			k++;
		}
	}
//Assigning the zero to end the array till the array length......
	for(i=k;i<n;i++)
	{
		arr[i]=0;
	}
//Printing the modified array.....	
	for(i=0;i<n;i++)
	{
		printf("[%d]  ",arr[i]);
	}
}
/*Output :
PS C:\TDM-GCC-64\myprogram> gcc 33-push.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter no. of elements to be entered in the array :8
Enter the elements in the array :
Enter the element :5
Enter the element :3
Enter the element :0
Enter the element :1
Enter the element :3
Enter the element :0
Enter the element :8
Enter the element :0
Input :[5]  [3]  [0]  [1]  [3]  [0]  [8]  [0]
Output:[5]  [3]  [1]  [3]  [8]  [0]  [0]  [0]
PS C:\TDM-GCC-64\myprogram> gcc 33-push.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter no. of elements to be entered in the array :7
Enter the elements in the array :
Enter the element :10
Enter the element :20
Enter the element :0
Enter the element :0
Enter the element :0
Enter the element :30
Enter the element :60
Input :[10]  [20]  [0]  [0]  [0]  [30]  [60]
Output:[10]  [20]  [30]  [60]  [0]  [0]  [0]
*/

//4.Calculating the exam marks of each students and average of the student and class average...............
#include<stdio.h>
void main()
{
	int n,m,i,j;
	//Getting input.......
	printf("Enter the number of students :");
	scanf("%d",&n);
	printf("Enter the number of tests :");
	scanf("%d",&m);
	char a[n][20];
	float b[m][100],g[m],total=0;
	//Storing the string in a two dimentional array......
	for(i=0;i<n;i++)
	{
		printf("Enter the name :");
		scanf("%s",&a[i]);
	}
	printf("\n");
	//Storing the exam marks in two dimentional array.......
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int k=j;
			printf("Enter the test %d marks for %s :",k+1,a[i]);
			scanf("%f",&b[i][j]);
			if(b[i][j]>100)
			{
				printf("Invalid input...please re-enter marks between(0-100) :\n");
				j--;
			}
		}	
		printf("\n");
	}
	//Calculating the sum of all subjects for each subject and average of each student.. and total of all student average.....
	for(i=0;i<n;i++)
	{
		float sum=0;
		for(j=0;j<m;j++)
		{
			sum+=b[i][j];
			if(j==m-1)
			{
				sum/=m;
				g[i]=sum;
				total+=sum;
				//printf("The average of %s is %f\n",a[i],sum);
			}
		}
	}
	printf("\nThe class average is %f\n\n",total/n);
	//Printing the Output as labelled in the Question.......
	for(i=0;i<n;i++)
	{
		printf("%s   ",a[i]);
		for(j=0;j<m;j++)
		{
			printf("%.2f  ",b[i][j]);
		}
		printf("avg=%f\n\n",g[i]);
	}
}
/*Output :
PS C:\TDM-GCC-64\myprogram> gcc 34-exam.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter the number of students :5
Enter the number of tests :7
Enter the name :Sree
Enter the name :Free
Enter the name :Tree
Enter the name :Yree
Enter the name :Hree

Enter the test 1 marks for Sree :69
Enter the test 2 marks for Sree :75
Enter the test 3 marks for Sree :96
Enter the test 4 marks for Sree :45
Enter the test 5 marks for Sree :65
Enter the test 6 marks for Sree :76
Enter the test 7 marks for Sree :23

Enter the test 1 marks for Free :87
Enter the test 2 marks for Free :90
Enter the test 3 marks for Free :93
Enter the test 4 marks for Free :91
Enter the test 5 marks for Free :89
Enter the test 6 marks for Free :100
Enter the test 7 marks for Free :82

Enter the test 1 marks for Tree :20
Enter the test 2 marks for Tree :40
Enter the test 3 marks for Tree :34
Enter the test 4 marks for Tree :43
Enter the test 5 marks for Tree :62
Enter the test 6 marks for Tree :35
Enter the test 7 marks for Tree :79

Enter the test 1 marks for Yree :40
Enter the test 2 marks for Yree :58
Enter the test 3 marks for Yree :67
Enter the test 4 marks for Yree :56
Enter the test 5 marks for Yree :76
Enter the test 6 marks for Yree :76
Enter the test 7 marks for Yree :35

Enter the test 1 marks for Hree :87
Enter the test 2 marks for Hree :78
Enter the test 3 marks for Hree :88
Enter the test 4 marks for Hree :74
Enter the test 5 marks for Hree :83
Enter the test 6 marks for Hree :75
Enter the test 7 marks for Hree :69


The class average is 67.314285

Sree   69.00  75.00  96.00  45.00  65.00  76.00  23.00  avg=64.142860

Free   87.00  90.00  93.00  91.00  89.00  100.00  82.00  avg=90.285713

Tree   20.00  40.00  34.00  43.00  62.00  35.00  79.00  avg=44.714287

Yree   40.00  58.00  67.00  56.00  76.00  76.00  35.00  avg=58.285713

Hree   87.00  78.00  88.00  74.00  83.00  75.00  69.00  avg=79.142860
	*/

//4.a Modifying the above program to get final score.......
#include<stdio.h>
void main()
{
	int n,m=6,i,j;
	printf("Enter the number of students :");
	scanf("%d",&n);
	char a[n][20];
	float b[m][100],g[m],f[m],total=0;
	//Getting input.......
	for(i=0;i<n;i++)
	{
	//Storing the string in a two dimentional array......	
		printf("Enter the name :");
		scanf("%s",&a[i]);
	}
	//printf("\n");
	//Storing the exam marks in two dimentional array.......
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int k=j;
			printf("Enter the test %d marks for %s :",k+1,a[i]);
			scanf("%f",&b[i][j]);
			if(b[i][j]>100)
			{
				printf("Invalid input...please re-enter marks between(0-100) :\n");
				j--;
			}
		}	
		printf("\n");
	}
	//Calculating the sum of all subjects for each subject and average of each student.. and total of all student average.....
	for(i=0;i<n;i++)
	{
		float sum=0;
		for(j=0;j<m;j++)
		{
			sum+=b[i][j];
			if(j==m-1)
			{
				sum/=m;
				g[i]=sum;
				total+=sum;
				//printf("The average of %s is %f\n",a[i],sum);
			}
		}
	}
	//Calculating the final scores of each students.........
	for(i=0;i<n;i++)
	{	
		float s=0,e=0;
		for(j=0;j<m;j++)
		{
			if(j<4)
			{
				s+=b[i][j];
			}
			else
			{
				e+=b[i][j];
			}
		}
		f[i]=(0.15*s)+(0.20*e);
		printf("The Final score of %s is %f\n",a[i],f[i]);
	}
}
/*Output :
PS C:\TDM-GCC-64\myprogram> gcc 34-mod-a-exam.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter the number of students :4
Enter the name :Adams
Enter the name :Browns
Enter the name :Davis
Enter the name :Fisher
Enter the test 1 marks for Adams :45
Enter the test 2 marks for Adams :80
Enter the test 3 marks for Adams :80
Enter the test 4 marks for Adams :95
Enter the test 5 marks for Adams :55
Enter the test 6 marks for Adams :75

Enter the test 1 marks for Browns :60
Enter the test 2 marks for Browns :50
Enter the test 3 marks for Browns :70
Enter the test 4 marks for Browns :75
Enter the test 5 marks for Browns :55
Enter the test 6 marks for Browns :80

Enter the test 1 marks for Davis :40
Enter the test 2 marks for Davis :30
Enter the test 3 marks for Davis :10
Enter the test 4 marks for Davis :45
Enter the test 5 marks for Davis :60
Enter the test 6 marks for Davis :55

Enter the test 1 marks for Fisher :0
Enter the test 2 marks for Fisher :5
Enter the test 3 marks for Fisher :5
Enter the test 4 marks for Fisher :0
Enter the test 5 marks for Fisher :10
Enter the test 6 marks for Fisher :5

The Final score of Adams is 71.000000
The Final score of Browns is 65.250000
The Final score of Davis is 41.750000
The Final score of Fisher is 4.500000*/	

//4.b Modifying the above program to print the deviation with respect class average......
#include<stdio.h>
void main()
{
	int n,m=6,i,j;
	//Getting input.......
	printf("Enter the number of students :");
	scanf("%d",&n);
	char a[n][20];
	float b[6][100],g[m],f[m],d[m],total=0;
	//Storing the string in a two dimentional array......
	for(i=0;i<n;i++)
	{
		printf("Enter the name :");
		scanf("%s",&a[i]);
	}
	//printf("\n");
	//Storing the exam marks in two dimentional array.......
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int k=j;
			printf("Enter the test %d marks for %s :",k+1,a[i]);
			scanf("%f",&b[i][j]);
			if(b[i][j]>100)
			{
				printf("Invalid input...please re-enter marks between(0-100) :\n");
				j--;
			}
		}	
		printf("\n");
	}
	//Calculating the sum of all subjects for each subject and average of each student.. and total of all student average.....
	for(i=0;i<n;i++)
	{
		float sum=0;
		for(j=0;j<m;j++)
		{
			sum+=b[i][j];
			if(j==m-1)
			{
				sum/=m;
				g[i]=sum;
				total+=sum;
				//printf("The average of %s is %f\n",a[i],sum);
			}
		}
	}
	//Calculating the final scores of each students.........
	for(i=0;i<n;i++)
	{	
		float s=0,e=0;
		for(j=0;j<m;j++)
		{
			if(j<4)
			{
				s+=b[i][j];
			}
			else
			{
				e+=b[i][j];
			}
		}
		f[i]=(0.15*s)+(0.20*e);
		//printf("The Final score of %s is %f\n",a[i],f[i]);
	}printf("\nThe class average is %f\n\n",total/n);
	//Calculating the deviation of each student with respect to the class average.......
	//Printing the Output as labelled in the Question.......
	for(i=0;i<n;i++)
	{
		d[i]=(total/n)-g[i];
		printf("%s   ",a[i]);
		for(j=0;j<m;j++)
		{
			printf("%.2f  ",b[i][j]);
		}
		printf("Final score = %0.3f   Deviation = %.3f\n",f[i],d[i]);
	}
}	
/*Output:
PS C:\TDM-GCC-64\myprogram> gcc 34-mod-b-exam.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter the number of students :4
Enter the name :Sree
Enter the name :Tree
Enter the name :Free
Enter the name :Dree
Enter the test 1 marks for Sree :45
Enter the test 2 marks for Sree :80
Enter the test 3 marks for Sree :80
Enter the test 4 marks for Sree :95
Enter the test 5 marks for Sree :55
Enter the test 6 marks for Sree :75

Enter the test 1 marks for Tree :60
Enter the test 2 marks for Tree :50
Enter the test 3 marks for Tree :70
Enter the test 4 marks for Tree :75
Enter the test 5 marks for Tree :55
Enter the test 6 marks for Tree :80

Enter the test 1 marks for Free :40
Enter the test 2 marks for Free :30
Enter the test 3 marks for Free :10
Enter the test 4 marks for Free :45
Enter the test 5 marks for Free :60
Enter the test 6 marks for Free :55

Enter the test 1 marks for Dree :0
Enter the test 2 marks for Dree :5
Enter the test 3 marks for Dree :5
Enter the test 4 marks for Dree :0
Enter the test 5 marks for Dree :10
Enter the test 6 marks for Dree :5


The class average is 45.208332

Sree   45.00  80.00  80.00  95.00  55.00  75.00  Final score = 71.000   Deviation = -26.458
Tree   60.00  50.00  70.00  75.00  55.00  80.00  Final score = 65.250   Deviation = -19.792
Free   40.00  30.00  10.00  45.00  60.00  55.00  Final score = 41.750   Deviation = 5.208
Dree   0.00  5.00  5.00  0.00  10.00  5.00  Final score = 4.500   Deviation = 41.042*/

//5.Rock paper scissor game....
#include<stdio.h>
#include<stdlib.h>
int b[2]={0,0};
//Declaration of function............
void check(int x,int r)
{
	char a[3][20]={"Player wins","Computer wins","Draw"};
	//Checking the basic rules for Rock paper Scissor game....
	if(x==0)
	{
		if(r==0)
		{
			printf("%s\n",a[2]);
		}
		else if(r==1)
		{
			printf("%s   ",a[1]);
			b[1]++;
		}
		else
		{
			printf("%s   ",a[0]);
			b[0]++;
		}
	}		
	else if(x==1)
	{
		if(r==0)
		{
			printf("%s   ",a[0]);
			b[0]++;
		}
		else if(r==1)
		{
			printf("%s   ",a[2]);
		}
		else
		{
			printf("%s   ",a[1]);
			b[1]++;
		}
	}	
	else
	{
		if(r==0)
		{
			printf("%s   ",a[1]);
			b[1]++;

		}
		else if(r==1)
		{
			printf("%s   ",a[0]);
			b[0]++;
		}
		else
		{
			printf("%s   ",a[2]);
		}
	}
	printf("Player =%d    ",b[0]);
	printf("Computer =%d   \n",b[1]);
}
void main()
{
	int i;
	printf("0.Rock\n1.Paper\n2.Scissors\n");
	//Getting input for 10 times...........
	for(i=0;i<10;i++)
	{
		int x,r;
		printf("\nInput :");
		scanf("%d",&x);
	//input validation............	
		if((x<3)&&(x>=0))
		{
			srand(time(0));
			r=rand()%3;
			printf("\nPlayer 1:%d      Computer:%d\nResult:",x,r);
			check(x,r);
		}
		else
		{
			printf("Invalid re-enter..\n");
			i--;
		}
	}
	//printing the result.....
	if(b[0]==b[1])
	{
		printf("Match draw computer plays as good as you");
	}
	else
	{
	(b[0]>b[1])?printf("Player is the Winner ,You are better than computer :)"):printf("Computer is the winner TRY AGAIN :(");
	}
}	
/*Output:
PS C:\TDM-GCC-64\myprogram> gcc 36-game.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
0.Rock
1.Paper
2.Scissors

Input :0

Player 1:0      Computer:1
Result:Computer wins   Player =0    Computer =1

Input :2

Player 1:2      Computer:2
Result:Draw   Player =0    Computer =1

Input :2

Player 1:2      Computer:0
Result:Computer wins   Player =0    Computer =2

Input :1

Player 1:1      Computer:0
Result:Player wins   Player =1    Computer =2

Input :2

Player 1:2      Computer:0
Result:Computer wins   Player =1    Computer =3

Input :0

Player 1:0      Computer:1
Result:Computer wins   Player =1    Computer =4

Input :1

Player 1:1      Computer:1
Result:Draw   Player =1    Computer =4

Input :2

Player 1:2      Computer:2
Result:Draw   Player =1    Computer =4

Input :0

Player 1:0      Computer:2
Result:Player wins   Player =2    Computer =4

Input :2

Player 1:2      Computer:0
Result:Computer wins   Player =2    Computer =5
Computer is the winner TRY AGAIN :(*/



