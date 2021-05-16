


class PANRequiredException extends Exception
{
	float amount;
	PANRequiredException(float x)
	{
		amount=x;
	}
	public String toString()
	{
		return ("PANRequiredException :Rs."+amount+"Exceeded");
	}
}

class MiniBalRequiredException extends Exception
{
	float balance;
	MiniBalRequiredException(float x)
	{
		balance=x;
	}
	public String toString()
	{
		return ("MiniBalRequiredException  :Rs."+balance+" balance to low");
	}
}

class NotEnoughMonerInAccountException extends Exception
{
	float amount;
	NotEnoughMonerInAccountException(float x)
	{
		amount=x;
	}
	public String toString()
	{
		return ("NotEnoughMonerInAccountException  Rs."+amount+ "Exceedes the balance!");
	}
}

class AccountNotFoundException extends Exception
{
	int acc_no;
	AccountNotFoundException(int x)
	{
		acc_no=x;
	}
	public String toString()
	{
		return ("AccountNotFoundException  :"+acc_no+"Not found!");
	}
}

public class Account
{
	private String cname,branch;
	private int accno[],pan;
	private float balance[];
	float min_bal=500;
	int n;
	public Account(String a,String b,int[] c,float[] d,int e,int f)
	{
		cname=a;
		branch=b;
		accno=c;
		balance=d;
		pan=e;
		n=f;
	}
	public void deposit(int acc,float amount) throws PANRequiredException
	{
		int i;
		for(i=0;i<n;i++)
		{	
			if(accno[i]==acc)
			{
				if(amount>50000)
					throw new PANRequiredException(amount);
				balance[i]=balance[i]+amount;
				break;
			}
		}		

	}
	public void withdrawal(int acc,float amount) throws NotEnoughMonerInAccountException,MiniBalRequiredException
	{
		int i;
		for(i=0;i<n;i++)
		{	
			if(accno[i]==acc)
			{
				if(balance[i]<amount)
					throw new NotEnoughMonerInAccountException(amount);
				if(min_bal>balance[i]-amount)
					throw new MiniBalRequiredException(balance[i]-amount);
				else 
					balance[i]=balance[i]-amount;	 
				break;
			}
		}		
	}
	public void search(int a) throws AccountNotFoundException
	{
		int i,flag=0;

		for(i=0;i<n;i++)
		{
			if(accno[i]==a)
				flag=1;
		}
		if(flag==0)
			throw new AccountNotFoundException(a);
	}
	public String get_name()
	{
		return cname;
	}
	public String get_branch()
	{
		return branch;
	}
	public float[] get_balance()
	{
		return balance;
	}
	public int[] get_acc_no()
	{
		return accno;
	}
	public int get_pan()
	{
		return pan;
	}
}

