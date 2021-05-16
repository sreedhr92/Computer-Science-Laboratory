import java.util.Scanner;
public class MatrixSub
{
	public static void main(String args[])
	{
		int a[][] = new int[3][3];
		int b[][] = new int[3][3];
		int c[][] = new int[3][3];

		Scanner ob = new Scanner(System.in);

		System.out.println("\nEnter matrix A :\n");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				a[i][j]=ob.nextInt();
			}
		}

		System.out.println("\nEnter matrix B :\n");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				b[i][j]=ob.nextInt();
			}
		}		

		System.out.println("\nMatrix C :");
		for(int i=0;i<3;i++)
		{
			System.out.println();
			for(int j=0;j<3;j++)
			{
				c[i][j]=a[i][j]-b[i][j];
				System.out.print(c[i][j]+" ");
			}
		}
		System.out.println();
	}
}