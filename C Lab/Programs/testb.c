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