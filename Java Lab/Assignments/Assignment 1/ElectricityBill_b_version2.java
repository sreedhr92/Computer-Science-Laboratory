import java.util.Scanner;

//Creating a separate encapsulated class ..........
class billCalc
{
	String consumer_name;
	int consumer_no;
	int previous_reading;
	int current_reading;
	String connection_type;
	Scanner obj = new Scanner(System.in);

	//Method to get input.........
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

	//Method to calculate tariff and return it to main...........
	public float CalcBill()
	{
		float total=0;
		float units = previous_reading - current_reading;
		units=(-1)*units;

		if(connection_type.equals("domestic"))
		{
			if(units<=100)
				total+=units*1.0;
			else if(units<=200 && units>100)
				total+=(100*1)+((units-100)*2.5);
			else if(units<=500 && units>200)
				total+=(100*1)+(100*2.5)+((units-300)*4.0);
			else
				total+=(100*1)+(100*2.5)+(300*4)+((units-500)*7.0);
			return total;
		}

		else if(connection_type.equals("commercial"))
		{
			if(units<=100)
				total+=units*2;
			else if(units<=200 && units>100)
				total+=(100*2)+((units-100)*4.5);
			else if(units<=500 && units>200)
				total+=(100*2)+(100*4.5)+((units-200)*6.0);
			else
				total+=(100*1)+(100*2.5)+(300*4.0)+((units-500)*7.0);
			return total;
	 	}

		else
		{
			System.out.println("Enter the valid Credentials");
			return 0;
		}
	}

	//Method to print the Bill date.....
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
//Creating a class for main.........
public class ElectricityBill_b_version2
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
/*
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac ElectricityBill_b_version2.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> java ElectricityBill_b_version2
Enter the Consumer name :
ram
Enter the Consumer number :
2312
Enter the previous month reading :
560
Enter the current month reading :
1200
Enter the type of the connection :
domestic

**********Bill Info***********

Consumer name          :ram
Consumer number        :2312
Connection type        :domestic
Previous month reading :560
Current month reading  :1200
Total units            :640
Tarrif                 :Rs.2530.0
*/