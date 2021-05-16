import java.util.*;

class Shape
{
	protected String colour="RED";
	
	Shape()
	{
		colour="BLUE";
	}
	Shape(String c)
	{
		colour=c;
	}
	
	String getColour()
	{
		return colour;
	}
	
	void setColour(String c)
	{
		colour=c;
	}
}


class Circle extends Shape
{
	protected double radius=1.0;
	
	Circle()
	{
		radius =1.0;
	}
	Circle(double r)
	{
		radius=r;
	}
	Circle(double r,String c)
	{
		super(c);
		radius=r;
	}
	double getRadius()
	{
		return radius;
	}
	void setRadius(double r)
	{
		radius=r;
	}	
	double getArea()
	{
		return (3.14*radius*radius);
	}
	double getPerimeter()
	{
		return (6.28*radius);
	}
}

class Rectangle extends Shape
{
	protected double width=1.0,length=1.0;

	Rectangle()
	{
		length =1.0;width=2.0;
	}
	Rectangle(double l,double w)
	{
		length=l;
		width=w;		
	}
	Rectangle(double l,double w,String c)
	{
		super(c);
		length=l;
		width=w;		
		
	}
	double getWidth()
	{
		return width;
	}
	double getLength()
	{
		return length;
	}
	void setWidth(double r)
	{
		width=r;
	}
	void setLength(double r)
	{
		length=r;
	}	
	double getArea()
	{
		return (length*width);
	}
	double getPerimeter()
	{
		return (2*(length+width));
	}


}


class Square extends Rectangle
{
	Square()
	{
		super(1.0,1.0);
	}
	Square(double s)
	{
		super(s,s);
	}
	Square(double s,String c)
	{
		super(s,s,c);
	}
	double getSide()
	{
		return getLength();
	}
	void setSide(double s)
	{
		setLength(s);
		setWidth(s);
	}
}


public class TestShape
{
	public static void main(String args[])
	{
		Circle C;
		Rectangle R;
		Square S;
		Scanner s=new Scanner(System.in);
		int ch,ch1;
		double x,y;
		String c;		
		do
		{
			System.out.print("\nMenu:\n1.Circle\n2.Rectangle\n3.Square\n4.Exit\n\nChoice: ");
			ch=s.nextInt();
			switch(ch)
			{
				case 1:
					System.out.print("\nCircle: 1.Default  2.Change radius  3. Change Radius and Colour \nChoice: ");ch1=s.nextInt();
					if(ch1==1)
					{	
						C=new Circle();
					}
					else if(ch1==2)
					{
						System.out.print("Radius: ");x=s.nextDouble();
						C=new Circle(x);
					}
					else
					{
						s.nextLine();System.out.print("Colour: ");c=s.nextLine();
						System.out.print("Radius: ");x=s.nextDouble();
						C=new Circle(x,c);
					
					}
					System.out.println("Area of the circle is: "+C.getArea()+"\nPerimeter of the circle is: "+C.getPerimeter());
					break;
		 
				case 2:
					System.out.print("\nRectangle: 1.Default  2.Change dimensions  3. Change dimensions and Colour \nChoice: ");ch1=s.nextInt();
					if(ch1==1)
					{	
						R=new Rectangle();
					}
					else if(ch1==2)
					{
						System.out.print("Length: ");x=s.nextDouble();
						System.out.print("Width: ");y=s.nextDouble();
						R=new Rectangle(x,y);
					}
					else
					{
						s.nextLine();System.out.print("Colour: ");c=s.nextLine();
						System.out.print("Length: ");x=s.nextDouble();
						System.out.print("Width: ");y=s.nextDouble();
						R=new Rectangle(x,y,c);
					
					}
					System.out.println("Area of the Rectangle is: "+R.getArea()+"\nPerimeter of the Rectangle is: "+R.getPerimeter());
					break;
				case 3:
					System.out.print("\nCircle: 1.Default  2.Change side  3. Change side and Colour \nChoice: ");ch1=s.nextInt();
					if(ch1==1)
					{	
						S=new Square();
					}
					else if(ch1==2)
					{
						System.out.print("Side: ");x=s.nextDouble();
						S=new Square(x);
					}
					else
					{
						s.nextLine();System.out.print("Colour: ");c=s.nextLine();
						System.out.print("Side: ");x=s.nextDouble();
						S=new Square(x,c);
					
					}
					System.out.println("Area of the Square is: "+S.getArea()+"\nPerimeter of the Square is: "+S.getPerimeter());
					break;
			}		
		}while(ch!=4);
	}
		
}

