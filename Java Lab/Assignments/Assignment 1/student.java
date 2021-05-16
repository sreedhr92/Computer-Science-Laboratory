import java.util.Scanner;
public class student
{
	Scanner obj = new Scanner(System.in);
	int regno;
	String name,dept;
	char grade;
	float mark1,mark2,mark3,total=0;
	public void input()
	{
		System.out.print("Enter Name   :");
		name = obj.next();
		System.out.print("Enter regno  :");
		regno = obj.nextInt();
		System.out.print("Enter Dept   :");
		dept = obj.next();
		System.out.print("Enter mark 1 :");
		mark1 = obj.nextFloat();
		System.out.print("Enter mark 2 :");
		mark2 = obj.nextFloat();
		System.out.print("Enter mark 3 :");
		mark3 = obj.nextFloat();
	}
	public void calculation()
	{
		total=mark1+mark2+mark3;
		//System.out.println("\nTOTAL      ="+total);
		if(total>270)
		{
			grade='O';
		}
		else if(total<270 && total >240)
		{
			grade='A';
		}
		else if(total<240 && total >210)
		{
			grade='B';
		}
		else if(total<150)
		{
			grade='F';
		}
		else
		{
			grade='C';
		}
		//System.out.println("\nGRADE      ="+grade);	
	}
	public int search(int id)
	{
		if(id==regno)
		{
			System.out.println("\nMatch found!\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	public int search(String dept_)
	{
		if(dept_.equals(dept))
		{
			System.out.println("\nMatch found!\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	public void display()
	{
		System.out.println("Name  :"+name);
		System.out.println("Regno :"+regno);
		System.out.println("Dept  :"+dept);
		System.out.println("Total :"+total);
		System.out.println("Grade :"+grade);
		System.out.println();
	}
	public static void main(String args[])
	{
		int i,x,flag=1;;
		Scanner obj = new Scanner(System.in);
		System.out.print("Enter the no. of students :");
		int n=obj.nextInt();
		student a[] = new student[n];
		for(i=0;i<n;i++)
		{
			a[i] = new student();
			System.out.println("Student "+(i+1));
			a[i].input();
			a[i].calculation();
		}
		System.out.print("Do you need to search through the student records :");
		String p = obj.next();
		if(p.equals("yes"))
		{
			do
			{
				System.out.print("\nHow do you like to search\n1.By ID\n2.Dep\n3.Exit\nEnter option :");
				x=obj.nextInt();
				flag=1;
				if(x==1)
				{
					System.out.print("Enter the ID :");
					int id = obj.nextInt();
					for(i=0;i<n;i++)
					{
						int o=a[i].search(id);
						if(o==1)
						{
							flag=0;
							break;
						}
					}
					if(flag==0)
					{	
						a[i].display();
					}
					else
					{
						System.out.print("Not found!");
					}
				}
				else if(x==2)
				{
					System.out.print("Enter the dept :");
					String dept =obj.next();
					flag=1;
					for(i=0;i<n;i++)
					{
						int o=a[i].search(dept);
						if(o==1)
						{
							flag=0;
							a[i].display();
						}
					}
					if(flag==1)
					{
						System.out.print("Not found!");	
					}
				}
				else if(x==3)
				{
					break;
				}
				else
				{
					System.out.print("Enter correct option !");
				}
			}while(x!=3);
		}		
	}
}
/*

PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac student .java
javac: file not found: .java
Usage: javac <options> <source files>
use -help for a list of possible options
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac student.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> java student
Enter the no. of students :2
Student 1
Enter Name   :sree
Enter regno  :23
Enter Dept   :CSE
Enter mark 1 :89
Enter mark 2 :78
Enter mark 3 :67
Student 2
Enter Name   :ram
Enter regno  :12
Enter Dept   :EEE
Enter mark 1 :76
Enter mark 2 :67
Enter mark 3 :78
Do you need to search through the student records :yes

How do you like to search
1.By ID
2.Dep
3.Exit
Enter option :1
Enter the ID :23

Match found!

Name  :sree
Regno :23
Dept  :CSE
Total :234.0
Grade :B


How do you like to search
1.By ID
2.Dep
3.Exit
Enter option :2
Enter the dept :EEE

Match found!

Name  :ram
Regno :12
Dept  :EEE
Total :221.0
Grade :B


How do you like to search
1.By ID
2.Dep
3.Exit
Enter option :3
*/