public class sod
{
	public static void main(String args[])
	{
		int n=Integer.parseInt(args[0]);
		int sum=0,i,r;
		do
		{
			r=n%10;
			sum+=r;
			n=n/10;
		}while(n!=0);
		System.out.println("SUM="+sum);
	}
}