public class Cloth
{
	int x=10;
	int y=20;
	Cloth()
	{
		System.out.println(x);
		System.out.println(y);
	}
}
class Vest extends Cloth
{

		int p=100;
		int q=200;
		double r=8;
		int s=super.y;
		vest()
		{
			System.out.println(super.x);
			System.out.println(p);
			System.out.println(this.q);
		}
}
class Suit extends vest 
{
	int s=40;
	int r=50;
	int x=70;
	Suit()
	{
		System.out.println(this.r);
		System.out.println(super.r);
		System.out.println(s);
		System.out.println(super.s);
	}
}
public class garments
{
	public static void main(String args)
	{
		Cloth a = new Cloth();
		Vest b = new Vest();
		Suit c = new Suit();
	}
}

