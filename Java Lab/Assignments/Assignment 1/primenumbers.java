public class primenumbers
{
	public static void main(String args[])
	{
		int i,j,n;
		int count=0;
		n=Integer.parseInt(args[0]);
		for(i=2;i<=n;i++)	
		{
			count=0;
			for(j=1;j<=i/2;j++)
			{
				if(i%j==0)
				{
					count++;
				}
			}
			if(count==1)
			{
				System.out.println(i);
			}
		}
	}
}
