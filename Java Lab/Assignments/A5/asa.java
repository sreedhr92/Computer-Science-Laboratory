/*1. Create a package named myPack.CurrConvertor to implement the currency converter
(Dollar to INR, EURO to INR, Yen to INR and vice versa). Write a java program which uses this
package to convert the given currency into other currency type.
Use the pre-defined exception java.lang.NumberFormatException (checked) to throw
the error whenever the given input currency is not in the required format.*/

package myPack;

public class currConverter
{
	public float DollortoINR(float a)
	{
		return a*71.23f;
	}
	public float EurotoINR(float a)
	{
		return a*78.93f;
	}
	public float YentoINR(float a)
	{
		return a*10.11f;
	}
	public float INRtoDollor(float a)
	{
		return a/71.23f;
	}
	public float INRtoEuro(float a)
	{
		return a/78.93f;
	}
	public float INRtoYen(float a)
	{
		return a/10.11f;
	}
}

import java.util.Scanner;
import myPack.currConverter;
public class currencyConverter
{
	public static void main(String args[])
	{
		int choice;
		String input;
		float val=0;
		currConverter a = new currConverter();
		Scanner obj = new Scanner(System.in);
		System.out.print("\n****Currency Converter*****");
		do
		{
			System.out.print("\n\n  1.   Dollor to INR\n  2.   Euro to INR\n  3.   YEN to INR\n  4.   INR to Dollor\n  5.   INR to YEN\n  6.   INR to Euro\n  7.   Exit\n\nEnter choice :") ;
			choice=obj.nextInt();
			if(choice==1)
			{
				System.out.print("\nEnter the input (Dollor ) :");
				input=obj.next();
				try
				{
					val=Float.parseFloat(input);
				}
				catch(NumberFormatException e)
				{
					System.out.println("\nError! Enter the input in the correct format");				System.out.println("NumberFormatException");
					System.out.print(0+" INR");
					continue;
				}
				System.out.print(a.DollortoINR(val)+" INR");
			}
			else if(choice==2)
			{
				System.out.print("\nEnter the input (Euro ) :");
				input=obj.next();
				try
				{
					val=Float.parseFloat(input);
				}
				catch(NumberFormatException e)
				{
					System.out.println("\nError! Enter the input in the correct format");				System.out.println("NumberFormatException");
					System.out.print(0+" INR");
				}
				System.out.print(a.YentoINR(val)+" INR");continue;
			}
			else if(choice==3)
			{
				System.out.print("\nEnter the input (Yen ) :");
				input=obj.next();
				try
				{
					val=Float.parseFloat(input);
				}
				catch(NumberFormatException e)
				{
					System.out.println("\nError! Enter the input in the correct format");				System.out.println("NumberFormatException");
					System.out.print(0+" INR");continue;
				}
				System.out.print(a.EurotoINR(val)+" INR");
			}
			else if(choice==4)
			{
				System.out.print("\nEnter the input (INR ) :");
				input=obj.next();
				try
				{
					val=Float.parseFloat(input);
				}
				catch(NumberFormatException e)
				{
					System.out.println("\nError! Enter the input in the correct format");				System.out.println("NumberFormatException");
					System.out.print(0+" Dollors");continue;
				}
				System.out.print(a.INRtoDollor(val)+" Dollars");
			}
			else if(choice==5)
			{
				System.out.print("\nEnter the input (INR ) :");
				input=obj.next();
				try
				{
					val=Float.parseFloat(input);
				}
				catch(NumberFormatException e)
				{
					System.out.println("\nError! Enter the input in the correct format");				System.out.println("NumberFormatException");
					System.out.print(0+" YEN");continue;
				}
				System.out.print(a.INRtoEuro(val)+" YEN");
			}
			else if(choice==6)
			{
				System.out.print("\nEnter the input (INR ) :");
				input=obj.next();
				try
				{
					val=Float.parseFloat(input);
				}
				catch(NumberFormatException e)
				{
					System.out.println("\nError! Enter the input in the correct format");				System.out.println("NumberFormatException");
					System.out.print(0+" Euros");continue;
				}
				System.out.print(a.INRtoYen(val)+" Euros");
			}
			else if(choice==7)
			{
				System.out.println("Thank You!");
			}	
			else
			{
				System.out.println("Invalid option!");
			}
		}while(choice!=7);
	}
}	

/*Ouput
PS F:\Study\SSN\3rd Sem\Java\Assignments\A5> javac currencyConverter.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\A5> java currencyConverter

****Currency Converter*****

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :1

Enter the input (Dollor ) :3
213.69 INR

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :2

Enter the input (Euro ) :45
454.94998 INR

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :3

Enter the input (Yen ) :55
4341.15 INR

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :4

Enter the input (INR ) :77
1.0810051 Dollars

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :5

Enter the input (INR ) :223
2.8252883 YEN

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :6

Enter the input (INR ) :66666
6594.0654 Euros

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :1

Enter the input (Dollor ) :sqeqdq

Error! Enter the input in the correct format
NumberFormatException
0 INR

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :5

Enter the input (INR ) :3423g

Error! Enter the input in the correct format
NumberFormatException
0 YEN

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :3

Enter the input (Yen ) :50a

Error! Enter the input in the correct format
NumberFormatException
0 INR

  1.   Dollor to INR
  2.   Euro to INR
  3.   YEN to INR
  4.   INR to Dollor
  5.   INR to YEN
  6.   INR to Euro
  7.   Exit

Enter choice :7
Thank You!*/

//2.Question...........................
import java.util.Scanner;



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
 class Account
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
		System.out.println("Account Exists!");
	}
	public void deposit(int acc,float amount) throws PANRequiredException
	{
		int i;
		try
		{
			search(acc);
		}
		catch(AccountNotFoundException e)	
		{			
			System.out.println(e);
		}	
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
		System.out.println("Deposited Successfuly!");	

	}
	public void withdrawal(int acc,float amount) throws NotEnoughMonerInAccountException,MiniBalRequiredException
	{
		int i;
		try
		{
			search(acc);
		}
		catch(AccountNotFoundException e)	
		{			
			System.out.println(e);
		}
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
		System.out.println("Withdrawn Successfuly!");		
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


public class Bank
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		String customer_name,branch;
		int pan,n,i,choice,account,amount;
		int acc[];
		float balance[];
		System.out.println("\n*******BANK*********\n");
		System.out.print("Enter Name   :");
		customer_name=obj.next();
		System.out.print("Enter branch :");
		branch=obj.next();
		System.out.print("Enter PAN    :");
		pan=obj.nextInt();
		System.out.print("Enter no. of account owned by the Customer :");
		n=obj.nextInt();
		acc= new int[n];
		balance = new float[n];
		for(i=0;i<n;i++)
		{
			System.out.print("Enter Account ->  "+(++i)+"'s number  :");
			i--;
			acc[i]=obj.nextInt();
			System.out.print("Enter Account ->  "+(++i)+"'s balance :");
			i--;
			balance[i]=obj.nextFloat();
		}
		Account a = new Account(customer_name,branch,acc,balance,pan,n);
		do
		{
			System.out.print("\n1.Deposit\n2.Withdraw\n3.Search\n4.get all fields\n5.Exit\nEnter choice : ");
			choice=obj.nextInt();
			if(choice==1)
			{
				System.out.print("Enter Account no  :");
				account=obj.nextInt();
				System.out.print("Enter Amount     :");
				amount=obj.nextInt();
				try
				{
					a.deposit(account,amount);
				}
				catch(PANRequiredException e)
				{
					System.out.println(e);
				}
			}
			else if(choice==2)
			{
				System.out.print("Enter Account no  :");
				account=obj.nextInt();
				System.out.print("Enter Amount     :");
				amount=obj.nextInt();
				try
				{
					a.withdrawal(account,amount);
				}
				catch(NotEnoughMonerInAccountException e)
				{
					System.out.println(e);
				}
				catch(MiniBalRequiredException e)
				{
					System.out.println(e);
				}
			}
			else if(choice==3)
			{
				System.out.print("Enter Account no  :");
				account=obj.nextInt();
				try
				{
					a.search(account);
				}
				catch(AccountNotFoundException e)
				{
					System.out.println(e);
				}	
			}
			else if(choice==4)
			{
				System.out.println("Customer name :"+a.get_name());
				System.out.println("PAN           :"+a.get_pan());
				System.out.println("branch       :"+a.get_branch());
				int acc_1[]=a.get_acc_no();
				float balance_1[]=a.get_balance();
				for(i=0;i<n;i++)
				{
					System.out.println("\nAccount "+(i+1));
					System.out.println("\nAccount no :"+acc_1[i]);
					System.out.println("Balance      :"+balance_1[i]);
				}
			}
			else
			{
				System.out.println("Invalid option!");
			}
		}while(choice!=5);
	} 
}

/*Ouput:
PS F:\Study\SSN\3rd Sem\Java\Assignments\A5> javac Bank.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\A5> java Bank

*******BANK*********

Enter Name   :Sreedhar
Enter branch :chennai
Enter PAN    :9090
Enter no. of account owned by the Customer :3
Enter Account ->  1's number  :1111
Enter Account ->  1's balance :1000
Enter Account ->  2's number  :2222
Enter Account ->  2's balance :2000
Enter Account ->  3's number  :3333
Enter Account ->  3's balance :3000

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 1
Enter Account no  :1111
Enter Amount     :1000
Account Exists!
Deposited Successfuly!

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 1
Enter Account no  :2222
Enter Amount     :500000
Account Exists!
PANRequiredException :Rs.500000.0Exceeded

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 2
Enter Account no  :3333
Enter Amount     :4000
Account Exists!
NotEnoughMonerInAccountException  Rs.4000.0Exceedes the balance!

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 4
Customer name :Sreedhar
PAN           :9090
branch       :chennai

Account 1

Account no :1111
Balance      :2000.0

Account 2

Account no :2222
Balance      :2000.0

Account 3

Account no :3333
Balance      :3000.0

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 2
Enter Account no  :2222
Enter Amount     :1700
Account Exists!
MiniBalRequiredException  :Rs.300.0 balance to low

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 3
Enter Account no  :2222
Account Exists!

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 3
Enter Account no  :5555
AccountNotFoundException  :5555Not found!

1.Deposit
2.Withdraw
3.Search
4.get all fields
5.Exit
Enter choice : 5
Invalid option!
*/