import java.util.Scanner;
//Creating a separate encapsulated class for calculating bill.......
class billCalc
{
	String consumer_name;
	int consumer_no;
	int previous_reading;
	int current_reading;
	String connection_type;
	Scanner obj = new Scanner(System.in);

	//Method to get input........
	public void input()
	{
		System.out.println("Enter the Consumer name :");
		consumer_name=obj.nextLine();
		System.out.println("Enter the Consumer number :");
		consumer_no=obj.nextInt();
		System.out.println("Enter the previous month reading :");
		previous_reading=obj.nextInt();
		System.out.println("Enter the current month reading :");
		current_reading=obj.nextInt();
		System.out.println("Enter the type of the connection :");
		connection_type=obj.next();
	}

	//Method to calculate tariif and return to main.......
	public float CalcBill()
	{
		float total=0;
		int units = previous_reading - current_reading;
		units=(-1)*units;

		if(connection_type.equals("domestic"))
		{
			for(int i=1;i<=units;i++)
			{
				if(i<=100)
				{
					total+=1.0;
				}
				else if(i<=200 && i>100)
				{
					total+=2.5;
				}
				else if(i<=500 && i>200)
				{
					total+=4.0;
				}
				else
				{
					total+=7.0;
				}
			}
			return total;
		}

		else if(connection_type.equals("commercial"))
		{
			for(int i=1;i<=units;i++)
			{
				if(i<=100)
				{
					total+=2.0;
				}
				else if(i<=200 && i>100)
				{
					total+=4.5;
				}
				else if(i<=500 && i>200)
				{
					total+=6.0;	
				}
				else
				{
					total+=7.0;
				}
			}
			return total;
	 	}

		else
		{
			System.out.println("Enter the valid Credentials");
			return 0;
		}
	}

	//Method to print the bill data.......
	public void printBill(float tarrif)
	{
		int units =previous_reading - current_reading;
		units = (-1 )*units;
		System.out.println("\n**********Bill Info***********\n");
		System.out.println("Consumer name          :"+consumer_name);
		System.out.println("Consumer number        :"+consumer_no);
		System.out.println("Connection type        :"+connection_type);
		System.out.println("Previous month reading :"+previous_reading);
		System.out.println("Current month reading  :"+current_reading);
		System.out.println("Total units            :"+units);
		System.out.println("Tarrif                 :Rs."+tarrif+"\n");
	}
}
//Creation of main class.....
public class ElectricityBill
{
	public static void main(String args[])
	{
		//Creation of object for class billCalc......
		billCalc a = new billCalc();
		//Calling methods of class billCalc through object of that class.........
		a.input();
		float tarrif = a.CalcBill();
		a.printBill(tarrif);
	}
}
