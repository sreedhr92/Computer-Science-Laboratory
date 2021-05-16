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
