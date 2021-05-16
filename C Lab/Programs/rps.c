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



