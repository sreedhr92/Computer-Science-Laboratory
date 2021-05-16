import java.util.Scanner;
class person
{
	private int aadhaar;
	private String name,address;
	private char gender;

	person(int a,String b,String c,char d)
	{
		aadhaar=a;
		name=b;
		address=c;
		gender=d;	
	}
	public String getName()
	{
		return name;	
	}
	public String getAddress()
	{
		return address;
	}
	public void setAddress(String addr)
	{
		address=addr;
	}
	public char getGender()
	{
		return gender;
	}
}
class Student extends person
{
	private String program;
	private int year;
	private double totalmark;

	Student(int a,String b,String c,char d,String e,int f,double g)
	{
		super(a,b,c,d);
		program=e;
		year=f;
		totalmark=g;
	}
	public String getprogram()
	{
		return program;
	}	
	public int getyear()
	{
		return year;
	}
	public double gettotal()
	{
		return totalmark;
	}
	public void setyear(int a)
	{
		year =a;
	}
	public void settotal(double d)
	{
		totalmark=d;
	}
	public double calGPA()
	{
		return totalmark/10;
	}
}
class faculty extends person
{
	private String desig,dept;
	private double bp;
	
	faculty(int a,String b,String c,char d,String e,String f,double g)
	{
		super(a,b,c,d);
		desig=e;
		dept=f;
		bp=g;
	}
	public String getdesig()
	{
		return desig;
	}
	public void setdesig(String d)
	{
		desig=d;
	}
	public void setbasic(double d)
	{
		bp=d;
	}
	public double getbasic()
	{
		return bp;
	}
	public double calsalary()
	{
		double gross,deduc,net;
		gross=bp*1.7;
		deduc=bp*0.165;
		net=gross-deduc;
		return net;
	}
}
public class TestInheritance
{
	public static void main(String Args[])
	{
		int a;
		String b;
		String c;	
		char d;
		String e,t;
		int f;
		double g;
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter student details");
		System.out.print("aadhaar no : ");
		a=obj.nextInt();
		
		System.out.print("Name :  ");
		b=obj.next();

		System.out.print("Address : ");
		c=obj.next();

		System.out.print("Gender : ");
		d=obj.next().charAt(0);

		System.out.print("Program : ");
		e=obj.next();

		System.out.print("Year : ");
		f=obj.nextInt();

		System.out.print("Total : ");
		g=obj.nextDouble();	
		
		Student s=new Student(a,b,c,d,e,f,g);
		

		System.out.println("Enter faculty details");
		System.out.print("aadhaar no : ");
		a=obj.nextInt();
		
		System.out.print("Name :  ");
		b=obj.next();

		System.out.print("Address : ");
		c=obj.next();

		System.out.print("Gender : ");
		d=obj.next().charAt(0);

		System.out.print("Designation : ");
		e=obj.next();

		System.out.print("Department : ");
		t=obj.next();

		System.out.print("Basic Pay : ");
		g=obj.nextDouble();	
		
		faculty F=new faculty(a,b,c,d,e,t,g);

		System.out.println("    TRYING ALL FUNCTIONS");
		System.out.println("1.ALL SET FUNCTION OF STUDENT");
		System.out.println("enter total : ");
		g=obj.nextDouble();
		s.settotal(g);
		System.out.println("enter year : ");
		f=obj.nextInt();
		s.setyear(f);
		
		System.out.println("2.ALL GET FUNCTIONS OF STUDENT");
		System.out.println("name : "+s.getName());
		System.out.println("address : "+s.getAddress());
		System.out.println("gender : "+s.getGender());
		System.out.println("Program : "+s.getprogram());
		System.out.println("year : "+s.getyear());
		System.out.println("total : "+s.gettotal());
		System.out.println("3.gpa calculation ");
		System.out.println("CGPA : "+s.calGPA());



		System.out.println("1.ALL SET FUNCTION OF FACULTY");
		System.out.println("enter basic : ");
		g=obj.nextDouble();
		F.setbasic(g);
		System.out.println("enter designation : ");
		b=obj.next();
		F.setdesig(b);
		
		System.out.println("2.ALL GET FUNCTIONS OF FACULTY");
		System.out.println("name : "+F.getName());
		System.out.println("address : "+F.getAddress());
		System.out.println("gender : "+F.getGender());
		System.out.println("Designation : "+F.getdesig());
		System.out.println("Basic Pay : "+F.getbasic());
		System.out.println("3.salary calculation ");
		System.out.println("Net salary : "+F.calsalary());
	}
}

