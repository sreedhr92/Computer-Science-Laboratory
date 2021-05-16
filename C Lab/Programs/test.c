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