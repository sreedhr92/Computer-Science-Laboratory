import java.util.Scanner;
class Person
{
	Scanner obj = new Scanner(System.in);
	String name;
	int age;
	String DOB;
	String address ;
	void input()
	{
		System.out.print("Enter the name :");
		name = obj.next();
		System.out.print("Enter the age :");
		age = obj.nextInt();
		System.out.print("Enter DOB  :");
		DOB = obj.next();
		System.out.print("Enter address  :");
		address = obj.next();
		
	}
	void calculate_performance(char grade)
	{
		if(grade=='A')
			System.out.println("Performance is Outstanding");
		else if(grade=='B')
			System.out.println("Performance is Excellent");
		else if(grade=='C')
			System.out.println("Performance is good");
		else
			System.out.println("Performance is fair");
	}
	
	
}
class Student extends Person
{
	String dept;
	int marks,extra;
	char grade_calc(int marks,int extrac)
	{
		char grade;
		if(marks>90||extrac>4)
			grade='A';
		else if(marks>80||extrac>3)
			grade='B';
		else if(marks>70||extrac>2)
			grade='C';
		else
			grade='D';
		return grade;
	}
}
class Professor extends Person
{
	int project,pub;
	String dept;
	char grade_calc(int pro,int pub)
	{
		char grade;
		if(pro>4||pub>4)
			grade='A';
		else if(pro>3||pub>3)
			grade='B';
		else if(pro>2||pub>2)
			grade='C';
		else
			grade='D';
		return grade;
	}
}
public class performance
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		int i;
		System.out.print("Enter the Number of students :");
		int n=obj.nextInt();
		Student a[] = new Student[n];
		for(i=0;i<n;i++)
		{
			a[i]= new Student();
		}
		for(i=0;i<n;i++)
		{
		int k=i+1;
		System.out.println("Enter the Details of student :"+k);
		a[i].input();
		System.out.print("Enter the department :");
		a[i].dept=obj.next();
		System.out.print("Enter the marks :");
		a[i].marks=obj.nextInt();
		System.out.print("Enter the extra :");
		a[i].extra=obj.nextInt();
		a[i].calculate_performance(a[i].grade_calc(a[i].marks,a[i].extra));
		}
		System.out.print("Enter the Number of Professor :");
		n=obj.nextInt();
		Professor b[] = new Professor[n];
		for(i=0;i<n;i++)
		{
			b[i]= new Professor();
		}
		for(i=0;i<n;i++)
		{
		int k=i+1;
		System.out.println("Enter the Details of Professor :"+k);
		b[i].input();
		System.out.print("\nEnter the department :");
		b[i].dept=obj.next();
		System.out.print("Enter no of projects :");
		b[i].project=obj.nextInt();
		System.out.print("Enter no of publicaton:");
		b[i].pub=obj.nextInt();
		b[i].calculate_performance(b[i].grade_calc(b[i].project,b[i].pub));
		}
	}
}
