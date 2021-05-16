import java.util.Scanner;
class Employee
{
	String emp_name;
	String address;
	String mail_id;
	String mobile_no;
	int emp_id;
	Scanner obj = new Scanner(System.in);
}
class Programmer extends Employee
{
	float bp,da,hra,pf,staff_fund,gross,deduction,net_salary;
	void input()
	{
		System.out.print("Enter Employee Name     :");
		emp_name=obj.next();
		System.out.print("Enter Employee id       :");
		emp_id=obj.nextInt();
		System.out.print("Enter address           :");
		address=obj.next();
		System.out.print("Enter mobile_no         :");
		mobile_no=obj.next();
		System.out.print("Enter mail_id           :");
		mail_id=obj.next();
	}
	void calculation(float x)
	{
		bp=x;
		da=(0.97f*bp);
		hra=(0.10f*bp);
		pf=(0.12f*bp);
		staff_fund=(0.001f*bp);	
	}
	void payslip()
	{
		float gross=bp+da+hra;
		float deduction=pf+staff_fund;
		float net_salary=gross-deduction;
		System.out.println("\n\n*********Salary Slip***********");
		System.out.println("\n\nEmployee name      :"+emp_name);
		System.out.println("Employee ID        :"+emp_id);
		System.out.println("Month and Year     :July and 2019");
		System.out.println("\nGross:");
		System.out.println("Basic              :"+bp);
		System.out.println("DA                 :"+da);
		System.out.println("HRA                :"+hra);
		System.out.println("\nNet Gross          :"+gross);
		System.out.println("\n\nDectections :");
		System.out.println("Provident Fund     :"+pf);
		System.out.println("Staff club fund    :"+staff_fund);
		System.out.println("\nTotal Dectections  :"+deduction);
		System.out.println("\n\nNet Salary         :"+net_salary);
	}
}
class Assistant_Professor extends Employee
{
	float bp,da,hra,pf,staff_fund,gross,deduction,net_salary;
	void input()
	{
		System.out.print("Enter Employee Name     :");
		emp_name=obj.next();
		System.out.print("Enter Employee id       :");
		emp_id=obj.nextInt();
		System.out.print("Enter address           :");
		address=obj.next();
		System.out.print("Enter mobile_no         :");
		mobile_no=obj.next();
		System.out.print("Enter mail_id           :");
		mail_id=obj.next();
	}
	void calculation(float x)
	{
		bp=x;
		da=(0.97f*bp);
		hra=(0.10f*bp);
		pf=(0.12f*bp);
		staff_fund=(0.001f*bp);	
	}
	void payslip()
	{
		float gross=bp+da+hra;
		float deduction=pf+staff_fund;
		float net_salary=gross-deduction;
		System.out.println("\n\n*********Salary Slip***********");
		System.out.println("\n\nEmployee name      :"+emp_name);
		System.out.println("Employee ID        :"+emp_id);
		System.out.println("Month and Year     :July and 2019");
		System.out.println("\nGross:");
		System.out.println("Basic              :"+bp);
		System.out.println("DA                 :"+da);
		System.out.println("HRA                :"+hra);
		System.out.println("\nNet Gross          :"+gross);
		System.out.println("\n\nDectections :");
		System.out.println("Provident Fund     :"+pf);
		System.out.println("Staff club fund    :"+staff_fund);
		System.out.println("\nTotal Dectections  :"+deduction);
		System.out.println("\n\nNet Salary         :"+net_salary);
	}
}
class Professor extends Employee
{
	float bp,da,hra,pf,staff_fund,gross,deduction,net_salary;
	void input()
	{
		System.out.print("Enter Employee Name     :");
		emp_name=obj.next();
		System.out.print("Enter Employee id       :");
		emp_id=obj.nextInt();
		System.out.print("Enter address           :");
		address=obj.next();
		System.out.print("Enter mobile_no         :");
		mobile_no=obj.next();
		System.out.print("Enter mail_id           :");
		mail_id=obj.next();
	}
	void calculation(float x)
	{
		bp=x;
		da=(0.97f*bp);
		hra=(0.10f*bp);
		pf=(0.12f*bp);
		staff_fund=(0.001f*bp);	
	}
	void payslip()
	{
		float gross=bp+da+hra;
		float deduction=pf+staff_fund;
		float net_salary=gross-deduction;
		System.out.println("\n\n*********Salary Slip***********");
		System.out.println("\n\nEmployee name      :"+emp_name);
		System.out.println("Employee ID        :"+emp_id);
		System.out.println("Month and Year     :July and 2019");
		System.out.println("\nGross:");
		System.out.println("Basic              :"+bp);
		System.out.println("DA                 :"+da);
		System.out.println("HRA                :"+hra);
		System.out.println("\nNet Gross          :"+gross);
		System.out.println("\n\nDectections :");
		System.out.println("Provident Fund     :"+pf);
		System.out.println("Staff club fund    :"+staff_fund);
		System.out.println("\nTotal Dectections  :"+deduction);
		System.out.println("\n\nNet Salary         :"+net_salary);
	}
}
class Associate_professor extends Employee
{
	float bp,da,hra,pf,staff_fund,gross,deduction,net_salary;
	void input()
	{
		System.out.print("Enter Employee Name     :");
		emp_name=obj.next();
		System.out.print("Enter Employee id       :");
		emp_id=obj.nextInt();
		System.out.print("Enter address           :");
		address=obj.next();
		System.out.print("Enter mobile_no         :");
		mobile_no=obj.next();
		System.out.print("Enter mail_id           :");
		mail_id=obj.next();
	}
	void calculation(float x)
	{
		bp=x;
		da=(0.97f*bp);
		hra=(0.10f*bp);
		pf=(0.12f*bp);
		staff_fund=(0.001f*bp);	
	}
	void payslip()
	{
		float gross=bp+da+hra;
		float deduction=pf+staff_fund;
		float net_salary=gross-deduction;
		System.out.println("\n\n*********Salary Slip***********");
		System.out.println("\n\nEmployee name      :"+emp_name);
		System.out.println("Employee ID        :"+emp_id);
		System.out.println("Month and Year     :July and 2019");
		System.out.println("\nGross:");
		System.out.println("Basic              :"+bp);
		System.out.println("DA                 :"+da);
		System.out.println("HRA                :"+hra);
		System.out.println("\nNet Gross          :"+gross);
		System.out.println("\n\nDectections :");
		System.out.println("Provident Fund     :"+pf);
		System.out.println("Staff club fund    :"+staff_fund);
		System.out.println("\nTotal Dectections  :"+deduction);
		System.out.println("\n\nNet Salary         :"+net_salary);
	}
}
public class Emp
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		Programmer p = new Programmer();
		System.out.println("1.Employee");
		p.input();
		System.out.print("Enter the Basic pay for Programmer :");
		float bp=obj.nextFloat();
		p.calculation(bp);
		p.payslip();

		Associate_professor a = new Associate_professor();
		System.out.println("2.Associate professor");
		a.input();
		System.out.print("Enter the Basic pay for Associate_professor :");
		bp=obj.nextFloat();
		a.calculation(bp);
		a.payslip();

		Assistant_Professor ap = new Assistant_Professor();
		System.out.println("3.Assistant Professor");
		ap.input();
		System.out.print("Enter the Basic pay for Assistant_Professor :");
		bp=obj.nextFloat();
		ap.calculation(bp);
		ap.payslip();

		Professor l = new Professor();
		System.out.println("4.Professor");
		l.input();
		System.out.print("Enter the Basic pay for Associate_professor :");
		bp=obj.nextFloat();
		l.calculation(bp);
		l.payslip();
	}
}