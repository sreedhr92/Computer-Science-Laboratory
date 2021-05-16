import java.util.Scanner;
public class Printstarpattern
{
	public static void main(String args[])
	{
		int i,j,n;
		Scanner obj = new Scanner(System.in);
		System.out.print("Enter value of n :");
		n=obj.nextInt();
		for(i=0;i<n;i++)
		{
			if(i%2==0)
			{
				System.out.print(" ");
			}
			for(j=0;j<n;j++)
			{
				System.out.print("* ");
			}
			System.out.println();
		}

	}
}