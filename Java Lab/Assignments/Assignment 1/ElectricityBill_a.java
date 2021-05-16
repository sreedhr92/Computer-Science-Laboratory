import java.util.Scanner;
public class ElectricityBill_a
{
	public static void main(String args[])
	{
		
		Scanner obj = new Scanner(System.in);
	
		//getting input....	
		System.out.println("Enter the Consumer name :");
		String consumer_name=obj.nextLine();
		System.out.println("Enter the Consumer number :");
		int consumer_no=obj.nextInt();
		System.out.println("Enter the previous month reading :");
		int previous_reading=obj.nextInt();
		System.out.println("Enter the current month reading :");
		int current_reading=obj.nextInt();
		System.out.println("Enter the type of the connection :");
		String connection_type=obj.next();

		//Calculating tariff.....	
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
 		}

		else
		{
			System.out.println("Enter the valid Credentials");
		}
		
		//Printing bill info........
			int unit =previous_reading - current_reading;
			unit = (-1 )*unit;
			System.out.println("\n**********Bill Info***********\n");
			System.out.println("Consumer name          :"+consumer_name);
			System.out.println("Consumer number        :"+consumer_no);
			System.out.println("Connection type        :"+connection_type);
			System.out.println("Previous month reading :"+previous_reading);
			System.out.println("Current month reading  :"+current_reading);
			System.out.println("Total units            :"+unit);
			System.out.println("Tarrif                 :Rs."+total+"\n");
		}	
}
