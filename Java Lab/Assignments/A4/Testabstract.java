import java.util.Scanner;
abstract class Base
{
	abstract float getArea();
	abstract float getPerimeter();
}
class Shape extends Base
{
	protected String color ="red";
	Shape()
	{
		color="red";
	}
	Shape(String a)
	{
		color=a;
	}
	public String getColor()
	{
		return color;
	}
	public void setColor(String a)
	{
		color=a;
	}
	float getArea()
	{
		return 0;
	}
	float getPerimeter()
	{
		return 0;
	}
}
class Circle extends Shape
{
	protected float radius =1.0f;
	Circle()
	{
		radius=1;
	}
	Circle(float r)
	{
		radius = r;
	}
	public float getRadius()
	{
		return radius;
	}
	public void setRadius(float a)
	{
		radius=a;
	}
	float getArea()
	{
		float area=3.14f*radius*radius;
		return area;
	}
	float getPerimeter()
	{
		float perimeter=2*3.14f*radius;
		return perimeter;
	}	
}
class Rectangle extends Shape
{
	protected float width =1.0f;
	protected float length =1.0f;
	Rectangle()
	{
		width=1.0f;
		length=1.0f;
	}
	Rectangle(float a,float b)
	{
		width=a;
		length=b;
	}
	Rectangle(float a,float b,String c)
	{
		width=a;
		length=b;
		color=c;
	}
	public float getWidth()
	{
		return width;
	}
	public float getLength()
	{
		return length;
	}
	public void setWidth(float a)
	{
		width=a;
	}
	public void setLength(float a)
	{
		length=a;
	}
	float getPerimeter()
	{
		float perimeter;
		perimeter=2*(length+width);
		return perimeter;
	}
	float getArea()
	{
		float area;
		area =length*width;
		return area;
	}
}
class Square extends Rectangle
{
	Square()
	{
		width=1.0f;
		length=1.0f;
	}
	Square(float a)
	{
		width=length=a;
	}
	Square(float a,String c)
	{
		width=length=a;
		color=c;
	}
	public float getSide()
	{
		return width;
	}
	public void setSide(float a)
	{
		width=length=a;
	} 
	float getArea()
	{
		float area=width*length;
		return area;
	}
	float getPerimeter()
	{
		float perimeter=(4*width);
		return perimeter;
	}
}
public class Testabstract
{
	public static void main(String args[])
	{
		int x,n,a;
		String color;
		float radius,width,length,side;
		Scanner obj = new Scanner(System.in);
		do
		{
			System.out.print("\n1.Shape\n2.Circle\n3.Rectangle\n4.Square\n5.Exit\nEnter the choice :");
			x=obj.nextInt();
			if(x==1)
			{
				Shape s=new Shape();
				do
				{
					System.out.print("\nOperation that can be done\n1.constructor initialization of color\n2.getColor\n3.setColor\n4.Exit\nEnter choice:");
					n=obj.nextInt();
					if(n==1)
					{
						System.out.print("\n1.Default color\n2.Custom color\nEnter Choice :");
						a=obj.nextInt();
						if(a==1)
						{
							s=new Shape();
							System.out.println("\nDone!!");
						}
						else
						{
							System.out.print("Enter the color :");
							color=obj.next();
							s=new Shape(color);
							System.out.println("\nDone!!");
						}

					}
					else if(n==3)
					{	
							System.out.print("Enter the color :");
							color=obj.next();
							s=new Shape();
							s.setColor(color);
							System.out.println("\nModified!!");
					}	
					else if(n==2)
					{
						System.out.println("Color :"+s.getColor());
					}
				}while(n!=4);
			}
			else if(x==2)
			{
				Circle c = new Circle();
				do
				{
					System.out.print("\nOperation that can be performed\n1.constructor initialization of radius\n2.getRadius\n3.setRadius\n4.get area\n5.getPerimeter\n6.Exit\nEnter choice:");
					n=obj.nextInt();
					if(n==1)
					{
						System.out.print("\n1.Default radius\n2.Custom radius\nEnter Choice:");
						a=obj.nextInt();
						if(a==1)
						{
							c=new Circle();
							System.out.println("\nDone!!");
						}
						else
						{
							System.out.print("Enter the radius :");
							radius=obj.nextFloat();
							c=new Circle(radius);
							System.out.println("\nDone!!");
						}
					}
					else if(n==2)
					{
						System.out.println("Radius :"+c.getRadius());
					}
					else if(n==3)
					{
						System.out.print("Enter the radius :");
						radius=obj.nextFloat();
						c.setRadius(radius);
						System.out.println("\nModified!!");
					}
					else if(n==4)
					{
						System.out.println("Area of Circle :"+c.getArea());
					}
					else if(n==5)
					{
						System.out.println("perimeter of Circle :"+c.getPerimeter());	
					}
				}while(n!=6);		
			}
			else if(x==3)
			{
				Rectangle r = new Rectangle();
				do
				{
					System.out.print("\nOperation that can be performed\n1.constructor initialization of len & breath\n2.getWidth\n3.setWidth\n4.getlength\n5.setlength\n6.get area\n7.getPerimeter\n8.Exit\nEnter choice:");
					n=obj.nextInt();
					if(n==1)
					{
						System.out.print("\n1.Default values\n2.Custom values\n3.Custom values with color\nEnter Choice:");
						a=obj.nextInt();
						if(a==1)
						{
							r=new Rectangle();
							System.out.println("\nDone!!");
						}
						else if(a==2)
						{
							System.out.print("Enter the width :");
							width=obj.nextFloat();
							System.out.print("Enter the length :");
							length=obj.nextFloat();
							r=new Rectangle(width,length);
							System.out.println("\nDone!!");
						}
						else if(a==3)
						{
							System.out.print("Enter the width :");
							width=obj.nextFloat();
							System.out.print("Enter the length :");
							length=obj.nextFloat();
							System.out.print("Enter the Color :");
							color=obj.next();
							r=new Rectangle(width,length,color);
							System.out.println("\nDone!!");
						}
					}
					else if(n==2)
					{
						System.out.println("Width :"+r.getWidth());
					}
					else if(n==3)
					{
						System.out.print("Enter the width :");
						width=obj.nextFloat();
						r.setWidth(width);
						System.out.println("\nModified!!");
					}
					else if(n==4)
					{
						System.out.println("Lenght :"+r.getLength());
					}
					else if(n==5)
					{
						System.out.print("Enter the width :");
						length=obj.nextFloat();
						r.setLength(length);
						System.out.println("\nModified!!");
					}

					else if(n==6)
					{
						System.out.println("Area of Rectangle :"+r.getArea());
					}
					else if(n==7)
					{
						System.out.println("perimeter of Rectangle :"+r.getPerimeter());	
					}
				}while(n!=8);		
			}
			else if(x==4)
			{
				Square sq = new Square();
				do
				{
					System.out.print("\nOperation that can be performed\n1.constructor initialization of Side\n2.getSide\n3.setSide\n4.get area\n5.getPerimeter\n6.Exit\nEnter choice:");
					n=obj.nextInt();
					if(n==1)
					{
						System.out.print("\n1.Default Side\n2.Custom Side3.Custom side with color\nEnter Choice:");
						a=obj.nextInt();
						if(a==1)
						{
							sq=new Square();
							System.out.println("\nDone!!");
						}
						else if(a==2)
						{
							System.out.print("Enter the Side :");
							side=obj.nextFloat();
							sq=new Square(side);
							System.out.println("\nDone!!");
						}
						else
						{
							System.out.print("Enter the Side :");
							side=obj.nextFloat();
							System.out.print("Enter the Color :");
							color=obj.next();
							sq=new Square(side,color);
							System.out.println("\nDone!!");
						}
					}
					else if(n==2)
					{
						System.out.println("Side :"+sq.getSide());
					}
					else if(n==3)
					{
						System.out.print("Enter the Side :");
						side=obj.nextFloat();
						sq.setSide(side);
						System.out.println("\nModified!!");
					}
					else if(n==4)
					{
						System.out.println("Area of Square :"+sq.getArea());
					}
					else if(n==5)
					{
						System.out.println("perimeter of Square :"+sq.getPerimeter());	
					}
				}while(n!=6);		
			}
		}while(x!=5);
	}
}		
/*Output:
PS F:\Study\SSN\3rd Sem\Java\Assignments\A4> javac Testabstract.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\A4> java Testabstract

1.Shape
2.Circle
3.Rectangle
4.Square
5.Exit
Enter the choice :1

Operation that can be done
1.constructor initialization of color
2.getColor
3.setColor
4.Exit
Enter choice:1

1.Default color
2.Custom color
Enter Choice :2
Enter the color :Blue

Done!!

Operation that can be done
1.constructor initialization of color
2.getColor
3.setColor
4.Exit
Enter choice:2
Color :Blue

Operation that can be done
1.constructor initialization of color
2.getColor
3.setColor
4.Exit
Enter choice:3
Enter the color :Green

Modified!!

Operation that can be done
1.constructor initialization of color
2.getColor
3.setColor
4.Exit
Enter choice:2
Color :Green

Operation that can be done
1.constructor initialization of color
2.getColor
3.setColor
4.Exit
Enter choice:4

1.Shape
2.Circle
3.Rectangle
4.Square
5.Exit
Enter the choice :2

Operation that can be performed
1.constructor initialization of radius
2.getRadius
3.setRadius
4.get area
5.getPerimeter
6.Exit
Enter choice:1

1.Default radius
2.Custom radius
Enter Choice:1

Done!!

Operation that can be performed
1.constructor initialization of radius
2.getRadius
3.setRadius
4.get area
5.getPerimeter
6.Exit
Enter choice:2
Radius :1.0

Operation that can be performed
1.constructor initialization of radius
2.getRadius
3.setRadius
4.get area
5.getPerimeter
6.Exit
Enter choice:4
Area of Circle :3.14

Operation that can be performed
1.constructor initialization of radius
2.getRadius
3.setRadius
4.get area
5.getPerimeter
6.Exit
Enter choice:5
perimeter of Circle :6.28

Operation that can be performed
1.constructor initialization of radius
2.getRadius
3.setRadius
4.get area
5.getPerimeter
6.Exit
Enter choice:6

1.Shape
2.Circle
3.Rectangle
4.Square
5.Exit
Enter the choice :3

Operation that can be performed
1.constructor initialization of len & breath
2.getWidth
3.setWidth
4.getlength
5.setlength
6.get area
7.getPerimeter
8.Exit
Enter choice:1

1.Default values
2.Custom values
3.Custom values with color
Enter Choice:3
Enter the width :4
Enter the length :5
Enter the Color :Yellow

Done!!

Operation that can be performed
1.constructor initialization of len & breath
2.getWidth
3.setWidth
4.getlength
5.setlength
6.get area
7.getPerimeter
8.Exit
Enter choice:2
Width :4.0

Operation that can be performed
1.constructor initialization of len & breath
2.getWidth
3.setWidth
4.getlength
5.setlength
6.get area
7.getPerimeter
8.Exit
Enter choice:4
Lenght :5.0

Operation that can be performed
1.constructor initialization of len & breath
2.getWidth
3.setWidth
4.getlength
5.setlength
6.get area
7.getPerimeter
8.Exit
Enter choice:6
Area of Rectangle :20.0

Operation that can be performed
1.constructor initialization of len & breath
2.getWidth
3.setWidth
4.getlength
5.setlength
6.get area
7.getPerimeter
8.Exit
Enter choice:7
perimeter of Rectangle :18.0

Operation that can be performed
1.constructor initialization of len & breath
2.getWidth
3.setWidth
4.getlength
5.setlength
6.get area
7.getPerimeter
8.Exit
Enter choice:8

1.Shape
2.Circle
3.Rectangle
4.Square
5.Exit
Enter the choice :4

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
Enter choice:1

1.Default Side
2.Custom Side3.Custom side with color
Enter Choice:3
Enter the Side :45
Enter the Color :Red

Done!!

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
Enter choice:2
Side :45.0

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
Enter choice:3
Enter the Side :3

Modified!!

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
Enter choice:2
Side :3.0

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
Enter choice:4
Area of Square :9.0

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
Enter choice:5
perimeter of Square :12.0

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
Enter choice:6

1.Shape
2.Circle
3.Rectangle
4.Square
5.Exit
Enter the choice :4

Operation that can be performed
1.constructor initialization of Side
2.getSide
3.setSide
4.get area
5.getPerimeter
6.Exit
*/