import java.util.Scanner;
public class matrix
{
	Scanner obj = new Scanner(System.in);
	int a[][],b[][],c[][],n,i,j,k;
	public void initialize()
	{
		System.out.print("Enter the number of rows and columns :");
		n=obj.nextInt();
		a=new int[n][n];
		b=new int[n][n];
		c=new int[n][n];
	}
	public void input()
	{	
		System.out.println("\nInput");
		System.out.println("\nMatrix A :");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=obj.nextInt();
			}	
		}
		System.out.println("\nMatrix B :");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				b[i][j]=obj.nextInt();
			}	
		}
	}
	public void calculation(int x)
	{
		if(x==1)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					c[i][j]=a[i][j]+b[i][j];
				}	
			}
		}
		else if(x==2)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					for(k=0;k<n;k++)
					{
						c[i][j]+=a[i][k]+b[k][j];
					}
				}		
			}
		}
		else
		{
			System.out.println("Invalid choice");
		}
	}	
	public void display()
	{
		System.out.println("\nResult Matrix");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				System.out.print(c[i][j]+" ");
			}	
			System.out.println();
		}
	}
	public static void main(String args[])
	{
		int i;
		 Scanner obj = new Scanner(System.in);
		matrix a = new matrix();
		a.initialize();
		a.input();
		for(i=0;i<2;i++)
		{
			System.out.print("\n1.Addition\n2.Multiplication\nEnter the option :");
			int x=obj.nextInt();
			a.calculation(x);
			a.display();
		}	

	}

}
/*

PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac matrix.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> java matrix
Enter the number of rows and columns :3

Input

Matrix A :
4 5 6
3 5 2
1 1 4

Matrix B :
3 5 2
4 7 5
1 2 1

1.Addition
2.Multiplication
Enter the option :1

Result Matrix
7 10 8
7 12 7
2 3 5

1.Addition
2.Multiplication
Enter the option :2

Result Matrix
30 39 31
25 36 25
16 23 19
*/