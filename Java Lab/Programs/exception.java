import java.util.Scanner;
class exception
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		double a[] = new double[3];
		try
		{
			a[1]='a';
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Array index out of bounds");
		}
		catch(ArrayStoreException e)
		{
			System.out.println("Assignment to an array element of an incompatible type");
			
		}
		//System.out.print("The value of a="+a);
	}
}