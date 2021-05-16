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