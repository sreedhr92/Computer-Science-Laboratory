class Box
{
	double height,width,depth;

public double volume(double height,double width,double depth)
{
	double volume =height*width*depth;
	return volume;
} 

Box(double a,double b,double c)
{
	height=a;
	width=b;
	depth=c;
	double volume =volume(height,width,depth);
	System.out.println("Volume ="+volume);
}
Box()
{
	height=width=depth=-1;
	double volume =volume(height,width,depth);
	System.out.println("Volume ="+volume);
}
}
class BoxWeight extends Box
{
	double weight;
	BoxWeight(double a,double b,double c,double d)
	{
		super.height=a;
		super.width=b;
		super.depth=c;
		weight=d;
		double result=height*width*depth;
		System.out.println("result="+result);
	}
{

}
} 
public class Calculation
{
	public static void main(String args[])
	{
		Box a=new Box();
		Box b=new Box(10,20,30);
		BoxWeight c=new BoxWeight(6,7,8,4);
	}
}