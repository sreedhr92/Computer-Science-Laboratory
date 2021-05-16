import java.util.Scanner;
class Box
{
	float length,width,depth;
}
class BoxWeigth extends Box
{
	float weight;
}
public class BoxShipment extends BoxWeigth
{
	float cost;
	float volume()
	{
		float vol=length*width*depth;
		return vol;
	}
	float boxcost(float cost_per_kg)
	{
		float cost=weight*cost_per_kg;
		return cost;
	}
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		BoxShipment a = new BoxShipment();
		System.out.println("*** Volume and Cost for the Box shipment ***\n ");
		System.out.print("Enter the box length  :");
		a.length = obj.nextFloat();
		System.out.print("\nEnter the box width   :");
		a.width = obj.nextFloat();
		System.out.print("\nEnter the box depth   :");
		a.depth = obj.nextFloat();
		System.out.print("\nEnter the box weigth  :");
		a.weight = obj.nextFloat();
		System.out.print("\nEnter the cost per kg :");
		float cost_per_kg=obj.nextFloat();
		for(int i=0;i<2;i++)
		{
			System.out.print("\n1.Volume\n2.Cost of the shipment\n\nEnter the Option:");
			int x = obj.nextInt();
			if(x==1)
			{
				System.out.println("\nVolume ="+a.volume());
			}
			else
			{
				System.out.println("\nCost = Rs."+a.boxcost(cost_per_kg));
			}
		}

	}
}