//Assignment 4         Date:9/8/19                Regno:185001161

//1.Question 1..................


import java.util.Scanner;
class Person
{
	private String name;
	private String address;
	Person(String a,String b)
	{
		name=a;
		address=b;
	}
	public String getname()
	{
		return name;
	}
	public String getAddress()
	{
		return address;
	}
	public void setaddress(String a)
	{
		address=a;
	}
}
class Employee extends Person
{
	private int empid;
	private String dept;
	private int basic;
	Employee(String a,String b,int c,String d,int e)
	{
		super(a,b);
		empid=c;
		dept=d;
		basic=e;
	}	
	public int getEmpid()
	{
		return empid;
	}
	public String getDept()
	{
		return dept;
	}
	public int getBasic()
	{
		return basic;
	}
	public float calSalary()
	{
		float da,hra,pf,staff_fund,total,deduction,salary;
		da=(0.97f*basic);
		hra=(0.10f*basic);
		pf=(0.12f*basic);
		staff_fund=(0.001f*basic);	
		total=basic+da+hra;
		deduction=pf+staff_fund;
		salary=total-deduction;
		return salary;
	}
	public void setDept(String a)
	{
		dept=a;
	}
	public void setBasic(int a)
	{
		basic=a;
	}
}
class Faculty extends Employee
{
	private String designation;
	private String course;
	Faculty(String a,String b,int c,String d,int e,String f,String g)
	{
		super(a,b,c,d,e);
		designation=f;
		course=g;
	}
	public String getDesig()
	{
		return designation;
	}
	public String getcourse()
	{
		return course;
	}
	public void setDesig(String a)
	{
		designation=a;
	}
	public void setCourse(String b)
	{
		course=b;
	}
	public float calSalary()
	{
		return super.calSalary();
	}
}
interface Student
{
	public float[] getMarks();
	public float calcGPA();

}
class ResearchAssistant extends Employee implements Student
{
	Scanner obj =new Scanner(System.in);
	private String project;
	private String course;
	ResearchAssistant(String a,String b,int c,String d,int e,String g,String f)
	{
		super(a,b,c,d,e);
		project=g;
		course=f;
	}
	public String getProject()
	{
		return project;	
	}
	public String getcourse()
	{
		return course;
	}
	public void setCourse(String a)
	{
		course=a;
	}
	public float[] getMarks()
	{
		float mark[]= new float[3];
		System.out.print("Enter the marks 1:");
		mark[0]=obj.nextFloat();
		System.out.print("Enter the marks 2:");
		mark[1]=obj.nextFloat();
		System.out.print("Enter the marks 3:");
		mark[2]=obj.nextFloat();
		return mark;		
	}
	public float calcGPA()
	{	
		float gpa,total;
		System.out.print("Enter the total marks :");
		total=obj.nextFloat();
		gpa=total/10;
		return gpa;
	}
	public float calSalary()
	{
		 return super.calSalary();
	}
}
public class TestInterface
{
	public static void main(String args[])
	{
		int x,n;
		Scanner obj = new Scanner(System.in);
		do
		{
			System.out.print("\n1.Person\n2.employee\n3.faculty\n4.Research Assistant\n5.Exit\nEnter choice :");
			n=obj.nextInt();
			if(n==1)
			{
				String person_name,person_address;
				System.out.print("Enter name of person :");
				person_name=obj.next();	
				System.out.print("Enter address of person :"); 
				person_address=obj.next();
				Person p = new Person(person_name,person_address);
				do
				{
					System.out.print("\nOperations that can be performed\n1.Getname\n2.GetAddress\n3.SetAddress\n4.Exit\nEnter choice :");
					x=obj.nextInt();
					if(x==1)
						System.out.println("Name :"+p.getname());
					else if(x==2)
						System.out.println("Address :"+p.getAddress());
					else if(x==3)
						{
							System.out.print("Enter the new Address to modify :");
							String newadd = new String();
							newadd=obj.next();
							p.setaddress(newadd);
							System.out.println("The modified Detials :");
							System.out.println("Name :"+p.getname());
							System.out.println("Address :"+p.getAddress());
						}
				}while(x!=4);
			}
			if(n==2)
			{
				String employee_name,employee_address,employee_dept;
				int employee_empid;
				int employee_basic;
				System.out.print("Enter name of employee :");
				employee_name=obj.next();	
				System.out.print("Enter address of employee :"); 
				employee_address=obj.next();
				System.out.print("Enter Empid of employee  :");
				employee_empid=obj.nextInt();
				System.out.print("Enter basic of employee :");
				employee_basic=obj.nextInt();
				System.out.print("Enter dept of employee :");
				employee_dept=obj.next();
				Employee e = new Employee(employee_name,employee_address,employee_empid,employee_dept,employee_basic);
				do
				{
					System.out.print("\nOperations that can be performed\n1.GetEmpid\n2.GetBasic\n3.SetBasic\n4.getdept\n5.Setdept\n6.Calculate salary\n7.Exit\nEnter choice :");
					x=obj.nextInt();
					if(x==1)
						System.out.println("Empid :"+e.getEmpid());
					else if(x==2)
						System.out.println("Basic :"+e.getBasic());
					else if(x==3)
						{
							System.out.print("Enter the new Basic to modify :");
							int newbasic=obj.nextInt();
							e.setBasic(newbasic);
							System.out.println("Details Modified!!");
						}
					else if(x==4)
						{
							System.out.println("dept :"+e.getDept());
						}
					else if(x==5)
						{
							System.out.print("Enter the new dept to modify :");
							String newdept=obj.next();
							e.setDept(newdept);
							System.out.println("Details Modified!!");
						}
					else if(x==6)
						{
							System.out.println("salary ="+e.calSalary());
						}
				}while(x!=7);
			}
			else if(n==3)
	  		{
				String faculty_name,faculty_address,faculty_dept,faculty_designation,faculty_course;
				int faculty_empid,faculty_basic;
				System.out.print("Enter name of faculty :");
				faculty_name=obj.next();	
				System.out.print("Enter address of faculty :"); 
				faculty_address=obj.next();
				System.out.print("Enter Empid of faculty  :");
				faculty_empid=obj.nextInt();
				System.out.print("Enter basic of faculty :");
				faculty_basic=obj.nextInt();
				System.out.print("Enter dept of faculty :");
				faculty_dept=obj.next();
				System.out.print("Enter designation of faculty :");
				faculty_designation=obj.next();
				System.out.print("Enter course of faculty :");
				faculty_course=obj.next();
				Faculty f = new Faculty(faculty_name,faculty_address,faculty_empid,faculty_dept,faculty_basic,faculty_designation,faculty_course);
				do
				{
					System.out.print("\nOperations that can be performed\n1.GetDesignation\n2.GetCourse\n3.SetDesignation\n4.Setcouse\n5.Calculate salary\n6.Exit\nEnter choice :");
					x=obj.nextInt();
					if(x==1)
						System.out.println("Designation :"+f.getDesig());
					else if(x==2)
						System.out.println("Course :"+f.getcourse());
					else if(x==3)
						{
							System.out.print("Enter the new desig to modify :");
							String newdesig=new String();
							newdesig=obj.next();
							f.setDesig(newdesig);
							System.out.println("Details Modified!!");
						}
					else if(x==4)
						{
							System.out.print("Enter the new course to modify :");
							String newcourse=new String();
							newcourse=obj.next();
							f.setCourse(newcourse);
							System.out.println("Details Modified!!");
						}
					else if(x==5)
						{
							System.out.println("salary ="+f.calSalary());
						}
				}while(x!=6);
			}
			else if(n==4)
			{
			
				String researchAssistant_name,researchAssistant_address,researchAssistant_dept,researchAssistant_designation,researchAssistant_course;
				int researchAssistant_empid,researchAssistant_basic;
				System.out.print("Enter name of researchAssistant :");
				researchAssistant_name=obj.next();	
				System.out.print("Enter address of researchAssistant :"); 
				researchAssistant_address=obj.next();
				System.out.print("Enter Empid of researchAssistant  :");
				researchAssistant_empid=obj.nextInt();
				System.out.print("Enter basic of researchAssistant :");
				researchAssistant_basic=obj.nextInt();
				System.out.print("Enter dept of researchAssistant :");
				researchAssistant_dept=obj.next();
				System.out.print("Enter designation of researchAssistant :");
				researchAssistant_designation=obj.next();
				System.out.print("Enter course of researchAssistant :");
				researchAssistant_course=obj.next();
				ResearchAssistant r = new ResearchAssistant(researchAssistant_name,researchAssistant_address,researchAssistant_empid,researchAssistant_dept,researchAssistant_basic,researchAssistant_designation,researchAssistant_course);
				do
				{
					System.out.print("\nOperations that can be performed\n1.getProject\n2.getcourse\n3.Setcourse\n4.getMarks\n5.Calculate gpa\n6.calculate salary\n7.Exit\nEnter choice :");
					x=obj.nextInt();
					if(x==1)
						System.out.println("Project :"+r.getProject());
					else if(x==2)
						System.out.println("Course :"+r.getcourse());
					else if(x==3)
						{
							System.out.print("Enter the new course to modify :");
							String newcourse = new String();
							newcourse=obj.next();
							r.setCourse(newcourse);
							System.out.println("Details Modified!!");
						}
					else if(x==4)
						{
							float mark[] = new float[3];
							mark=r.getMarks();
							System.out.println("The marks are :");
							for(int i=0;i<3;i++)
							{
								System.out.println(mark[i]);
							}
						}
					else if(x==5)
							System.out.println("GPA ="+r.calcGPA());
					else if(x==6)
							System.out.println("salary ="+r.calSalary());
				}while(x!=7);
			}
		}while(n!=5);
	}				
}
/*Output
PS F:\Study\SSN\3rd Sem\Java\Assignments\A4> javac TestInterface.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\A4> java TestInterface

1.Person
2.employee
3.faculty
4.Research Assistant
5.Exit
Enter choice :1
Enter name of person :Sree
Enter address of person :chennai

Operations that can be performed
1.Getname
2.GetAddress
3.SetAddress
4.Exit
Enter choice :1
Name :Sree

Operations that can be performed
1.Getname
2.GetAddress
3.SetAddress
4.Exit
Enter choice :2
Address :chennai

Operations that can be performed
1.Getname
2.GetAddress
3.SetAddress
4.Exit
Enter choice :3
Enter the new Address to modify :Erode
The modified Detials :
Name :Sree
Address :Erode

Operations that can be performed
1.Getname
2.GetAddress
3.SetAddress
4.Exit
Enter choice :4

1.Person
2.employee
3.faculty
4.Research Assistant
5.Exit
Enter choice :2
Enter name of employee :RAM
Enter address of employee :karur
Enter Empid of employee  :234
Enter basic of employee :2345
Enter dept of employee :IT

Operations that can be performed
1.GetEmpid
2.GetBasic
3.SetBasic
4.getdept
5.Setdept
6.Calculate salary
7.Exit
Enter choice :1
Empid :234

Operations that can be performed
1.GetEmpid
2.GetBasic
3.SetBasic
4.getdept
5.Setdept
6.Calculate salary
7.Exit
Enter choice :2
Basic :2345

Operations that can be performed
1.GetEmpid
2.GetBasic
3.SetBasic
4.getdept
5.Setdept
6.Calculate salary
7.Exit
Enter choice :3
Enter the new Basic to modify :3432
Details Modified!!

Operations that can be performed
1.GetEmpid
2.GetBasic
3.SetBasic
4.getdept
5.Setdept
6.Calculate salary
7.Exit
Enter choice :4
dept :IT

Operations that can be performed
1.GetEmpid
2.GetBasic
3.SetBasic
4.getdept
5.Setdept
6.Calculate salary
7.Exit
Enter choice :5
Enter the new dept to modify :CSE
Details Modified!!

Operations that can be performed
1.GetEmpid
2.GetBasic
3.SetBasic
4.getdept
5.Setdept
6.Calculate salary
7.Exit
Enter choice :6
salary =6688.9683

Operations that can be performed
1.GetEmpid
2.GetBasic
3.SetBasic
4.getdept
5.Setdept
6.Calculate salary
7.Exit
Enter choice :7

1.Person
2.employee
3.faculty
4.Research Assistant
5.Exit
Enter choice :3
Enter name of faculty :Gokul
Enter address of faculty :London
Enter Empid of faculty  :678
Enter basic of faculty :23421
Enter dept of faculty :EEE
Enter designation of faculty :professor
Enter course of faculty :OOPS

Operations that can be performed
1.GetDesignation
2.GetCourse
3.SetDesignation
4.Setcouse
5.Calculate salary
6.Exit
Enter choice :1
Designation :professor

Operations that can be performed
1.GetDesignation
2.GetCourse
3.SetDesignation
4.Setcouse
5.Calculate salary
6.Exit
Enter choice :2
Course :OOPS

Operations that can be performed
1.GetDesignation
2.GetCourse
3.SetDesignation
4.Setcouse
5.Calculate salary
6.Exit
Enter choice :5
salary =45647.53

Operations that can be performed
1.GetDesignation
2.GetCourse
3.SetDesignation
4.Setcouse
5.Calculate salary
6.Exit
Enter choice :6

1.Person
2.employee
3.faculty
4.Research Assistant
5.Exit
Enter choice :4
Enter name of researchAssistant :Harry
Enter address of researchAssistant :Ooty
Enter Empid of researchAssistant  :321
Enter basic of researchAssistant :10000
Enter dept of researchAssistant :CIVIL
Enter designation of researchAssistant :teacher
Enter course of researchAssistant :DataStructure

Operations that can be performed
1.getProject
2.getcourse
3.Setcourse
4.getMarks
5.Calculate gpa
6.calculate salary
7.Exit
Enter choice :1
Project :teacher

Operations that can be performed
1.getProject
2.getcourse
3.Setcourse
4.getMarks
5.Calculate gpa
6.calculate salary
7.Exit
Enter choice :2
Course :DataStructure

Operations that can be performed
1.getProject
2.getcourse
3.Setcourse
4.getMarks
5.Calculate gpa
6.calculate salary
7.Exit
Enter choice :4
Enter the marks 1:23
Enter the marks 2:45
Enter the marks 3:12
The marks are :
23.0
45.0
12.0

Operations that can be performed
1.getProject
2.getcourse
3.Setcourse
4.getMarks
5.Calculate gpa
6.calculate salary
7.Exit
Enter choice :5
Enter the total marks :70
GPA =7.0

Operations that can be performed
1.getProject
2.getcourse
3.Setcourse
4.getMarks
5.Calculate gpa
6.calculate salary
7.Exit
Enter choice :6
salary =19490.0

Operations that can be performed
1.getProject
2.getcourse
3.Setcourse
4.getMarks
5.Calculate gpa
6.calculate salary
7.Exit
Enter choice :7

1.Person
2.employee
3.faculty
4.Research Assistant
5.Exit
Enter choice :5*/

//****************************************************************************\\

//2.Question 2


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