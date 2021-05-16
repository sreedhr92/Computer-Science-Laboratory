import java.util.Scanner;
public class Printsquarepattern
{
	public static void main(String args[])
	{
		int i,j,n;
		Scanner obj = new Scanner(System.in);
		System.out.print("Enter value of n :");
		n=obj.nextInt();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==0||i==n-1)
				{
					System.out.print("* ");
				}
				else
				{
					if(j==0||j==n-1)
					{
						System.out.print("* ");
					}
					else
					{
						System.out.print("  ");
					}
				}
			}	
			System.out.println();
		}

	}
}