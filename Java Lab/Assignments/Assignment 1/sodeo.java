public class sodeo
{
	public static void main(String args[])
	{
		int n=Integer.parseInt(args[0]);
		int sume=0,sumo=0,i,r;
		do
		{
			r=n%10;
			if(r%2==0)
			{
				sume+=r;
			}
			else
			{
				sumo+=r;
			}	
			n=n/10;
		}while(n!=0);
		System.out.println("SUM of the even digits ="+sume);
		System.out.println("SUM of the odd digits ="+sumo);	
	}
}