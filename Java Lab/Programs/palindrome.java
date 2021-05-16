import java.util.Scanner;
public class palindrome
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		System.out.print("Enter the name :");
		String name = obj.next();
		int n=name.length();
		int i,k=0;
		char reverse[]=new char[n];
		for(i=n-1;i>=0;i--,k++)
		{
			reverse[k]=name.charAt(i);
		}
		String rev = new String(reverse);
		if(rev.equalsIgnoreCase(name))
		{
			System.out.print("Palindrome");
		}
	}
}