import java.util.Scanner;
public class Printtriangularpattern
{
	public static void main(String args[])
	{
		int i,j,n;
		Scanner obj = new Scanner(System.in);
		System.out.print("Enter value of n :");
		n=obj.nextInt();
		//System.out.print(" ");
		for(j=1;j<=n;j++)
		System.out.print(" ");
		for(i=2;i<=n;i++)
		{	for(j=1;j<i;j++)
			System.out.print(" ");
			for(j=1;j<=n-i;j++)
			System.out.print("* ");
		}
	}
}