/*1. Write a java program to find the maximum value from the given type of elements using a
generic function.*/
import java.util.*;
class GenFunc<T>
{
		
	public <T extends Comparable<T>> T FindMax(T[] obj)
	{
		T max=obj[0];	
		for(int i=1;i<obj.length;i++)
		{
			if(obj[i].compareTo(max)>0)
			max=obj[i];
		}
		return max;
	}
}
public class GenericsTest
{
	public static void main(String Args[])
	{
		Scanner obj=new Scanner(System.in);
		int n,x;
		do
		{
		System.out.println("1.String\n2.Integer\n3.Double\n4.Exit");
		x=obj.nextInt();	
		
		switch(x)
		{	
			case 1 :System.out.print("Enter size : ");
				n=obj.nextInt();
				String[] a1=new String[n]; 				
				for(int i=0;i<n;i++)
				{
					a1[i]=obj.next();
				}
				GenFunc<String> g1=new GenFunc<String>();
				System.out.println("Max: " + g1.FindMax(a1));
				break;
			case 2 :System.out.print("Enter size : ");
				n=obj.nextInt();
				Integer[] a=new Integer[n]; 				
				for(int i=0;i<n;i++)
				{
					a[i]=obj.nextInt();
				}
				
				GenFunc<Integer> g=new GenFunc<Integer>();
				System.out.println("Max: " + g.FindMax(a));
				break;
			case 3 :System.out.print("Enter size : ");
				n=obj.nextInt();
				Double[] a2=new Double[n]; 				
				for(int i=0;i<n;i++)
				{
					a2[i]=obj.nextDouble();
				}

				GenFunc<Double> g2=new GenFunc<Double>();

				System.out.println("Max : "+g2.FindMax(a2));
				break;	
			case 4 :break;
			default:System.out.println("Invalid option");	
		}
		}while(x!=4);
					
	}		
}	
//2.Question.........
	import java.util.Scanner;
class StackFullnessException extends Exception
{
	int val;
	StackFullnessException(int x)
	{
		val=x;
	}
	public String toString()
	{
		return "\nStack reached its maximum capacity ->"+val+" Error StackFullnessException";
	}	
}
class StackEmptinessException extends Exception
{
	int val;
	StackEmptinessException(int x)
	{
		val=x;
	}
	public String toString()
	{
		return "\nStack has no more elements ->"+val+" Error StackEmptinessException";
	}	
}
class Stack<T>
{
	int top;
	T a[];
	int capacity;
	Stack(int n,T d[])
	{
		top=0;
		capacity=n;	
		a=d;
	}	
	void push(T x) throws StackFullnessException
	{
		if(top==capacity)
			throw new StackFullnessException(top);
		else
		{
			a[top]=x;
			top++;
		}
	}
	T pop() throws StackEmptinessException
	{
		if(top==0)
			throw new StackEmptinessException(top);
		else
		{
			top--;
			return a[top];
		}
	}
	void display() throws StackEmptinessException
	{
		int i;
		if(top==0)
			throw new StackEmptinessException(top);
		System.out.println("\nThe Elements are :");
		for(i=top-1;i>=0;i--)
			System.out.println(a[i]);
	}		
}
public class GenStack		
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		System.out.print("\nEnter capacity of the Stack :");
		int n=obj.nextInt();
		int choice;
		do
		{
			System.out.print("\n\nType of Stacks :\n1.Integer\n2.Double\n3.String\n4.Exit\nEnter choice:");
			choice=obj.nextInt();
			if(choice==1)
			{
				Integer w[]=new Integer[n];
				Stack<Integer> a = new Stack<Integer>(n,w);
				do
				{
					System.out.print("\n\nStack operation----\n1.Push into the stack\n2.Pop out of the stack\n3.Display\n4.Exit\n\nEnter choice :");
					n=obj.nextInt();
					if(n==1)
					{
						System.out.print("\nEnter input :");
						int val=obj.nextInt();
						try
						{
							a.push(val);
							System.out.println("\npushed!!");
						}
						catch(StackFullnessException e)
						{
							System.out.println(e);
						}
					}	
					else if(n==2)
					{
						try
						{
							int val=a.pop();
							System.out.println("\nThe element is "+val);		
						}
						catch(StackEmptinessException e)
						{
							System.out.println(e);
						}
					}
					else if(n==3)
					{
						try
						{
							a.display();
						}
						catch(StackEmptinessException e)
						{
							System.out.println(e);	
						}					
					}
					else if(n==4)
					{
						System.out.println("Exiting.....");
					}
					else
					{
						System.out.println("Invalid Input.....");
					}
				}while(n!=4);
			}
			else if(choice==2)
			{
				Double w[]=new Double[n];
				Stack a = new Stack<Double>(n,w);
				do
				{
					System.out.print("\n\nStack operation----\n1.Push into the stack\n2.Pop out of the stack\n3.Display\n4.Exit\n\nEnter choice :");
					n=obj.nextInt();
					if(n==1)
					{
						System.out.print("\nEnter input :");
						double val=obj.nextDouble();
						try
						{
							a.push(val);
							System.out.println("\npushed!!");
						}
						catch(StackFullnessException e)
						{
							System.out.println(e);
						}
					}	
					else if(n==2)
					{
						try
						{
							System.out.println("\nThe element is "+a.pop());		
						}
						catch(StackEmptinessException e)
						{
							System.out.println(e);
						}
					}
					else if(n==3)
					{
						try
						{
							a.display();
						}
						catch(StackEmptinessException e)
						{
							System.out.println(e);	
						}					
					}
					else if(n==4)
					{
						System.out.println("Exiting.....");
					}
					else
					{
						System.out.println("Invalid Input.....");
					}
				}while(n!=4);
			}
			else if(choice==3)
			{
				String w[]=new String[n];
				Stack a = new Stack<String>(n,w);
				do
				{
					System.out.print("\n\nStack operation----\n1.Push into the stack\n2.Pop out of the stack\n3.Display\n4.Exit\n\nEnter choice :");
					n=obj.nextInt();
					if(n==1)
					{
						System.out.print("\nEnter input :");
						String val=obj.next();
						try
						{
							a.push(val);
							System.out.println("\npushed!!");
						}
						catch(StackFullnessException e)
						{
							System.out.println(e);
						}
					}	
					else if(n==2)
					{
						try
						{
							System.out.println("\nThe element is "+a.pop());		
						}
						catch(StackEmptinessException e)
						{
							System.out.println(e);
						}
					}
					else if(n==3)
					{
						try
						{
							a.display();
						}
						catch(StackEmptinessException e)
						{
							System.out.println(e);	
						}					
					}
					else if(n==4)
					{
						System.out.println("Exiting.....");
					}
					else
					{
						System.out.println("Invalid Input.....");
					}
				}while(n!=4);
			}
		}while(choice!=4);
	}
}
/*Output:
PS C:\Users\sreed\Downloads> javac GenStack.java                              Note: GenStack.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.
PS C:\Users\sreed\Downloads> java GenStack                                    
Enter capacity of the Stack :5


Type of Stacks :
1.Integer
2.Double
3.String
4.Exit
Enter choice:1


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :5

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :8

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :
5

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :54

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :56

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :2

The element is 56


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :2

The element is 54


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :3

The Elements are :
5
8
5


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :4
Exiting.....


Type of Stacks :
1.Integer
2.Double
3.String
4.Exit
Enter choice:2


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :6.7

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :5.0

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :33.2

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :2

The element is 33.2


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :2

The element is 5.0


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :23.1

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :3

The Elements are :
23.1
6.7


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :4
Exiting.....


Type of Stacks :
1.Integer
2.Double
3.String
4.Exit
Enter choice:3


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :sree

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :koas

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :sgss

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :2

The element is sgss


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :1

Enter input :sa

pushed!!


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :2

The element is sa


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :3

The Elements are :
koas
sree


Stack operation----
1.Push into the stack
2.Pop out of the stack
3.Display
4.Exit

Enter choice :4
Exiting.....


Type of Stacks :
1.Integer
2.Double
3.String
4.Exit
Enter choice:4
*/

	

//3.Question.................

import java.util.Scanner;
class Sorting<T>
{
	public <T extends Comparable<T>> void sort(T[] arr)
	{
		int i,j,pos;
		T small,temp;
		for(i=0;i<arr.length;i++)
		{
			small=arr[i];
			pos=i;
			for(j=i+1;j<arr.length;j++)
			{
				if(small.compareTo(arr[j])>0)
				{
					small=arr[j];
					pos=j;
				}
			}
			temp=arr[i];
			arr[i]=arr[pos];
			arr[pos]=temp;
		}
	} 
}
public class GenSort
{
	public static void main(String Args[])
	{
		Scanner obj=new Scanner(System.in);
		int n,x,i;
		do
		{
		System.out.println("1.String\n2.Integer\n3.Double\n4.Exit");
		x=obj.nextInt();	
		
		switch(x)
		{	
			case 1 :System.out.print("Enter size : ");
				n=obj.nextInt();
				String[] a1=new String[n]; 				
				for(i=0;i<n;i++)
				{
					a1[i]=obj.next();
				}
				Sorting<String> g1=new Sorting<String>();
				g1.sort(a1);
				for(i=0;i<n;i++)
				{
					System.out.print(a1[i]+" ");
				}
				System.out.println();
				break;
			case 2 :System.out.print("Enter size : ");
				n=obj.nextInt();
				Integer[] a=new Integer[n]; 				
				for(i=0;i<n;i++)
				{
					a[i]=obj.nextInt();
				}
				
				Sorting<Integer> g=new Sorting<Integer>();
				g.sort(a);
				for(i=0;i<n;i++)
				{
					System.out.print(a[i]+" ");
				}
				System.out.println();
				break;
			case 3 :System.out.print("Enter size : ");
				n=obj.nextInt();
				Double[] a2=new Double[n]; 				
				for(i=0;i<n;i++)
				{
					a2[i]=obj.nextDouble();
				}

				Sorting<Double> g2=new Sorting<Double>();
				g2.sort(a2);
				for(i=0;i<n;i++)
				{
					System.out.print(a2[i]+" ");
				}
				System.out.println();
				break;	
			case 4 :break;
			default:System.out.println("Invalid option");	
		}
		}while(x!=4);
					
	}		
}			
/*Output:
PS F:\Study\SSN\3rd Sem\Java\Assignments\A6> javac GenSort.java               PS F:\Study\SSN\3rd Sem\Java\Assignments\A6> java GenSort                     1.String
2.Integer
3.Double
4.Exit
1
Enter size : 4
dee
gee
bee
zee
bee dee gee zee
1.String
2.Integer
3.Double
4.Exit
2
Enter size : 5
2

43
1

5
2
1 2 2 5 43
1.String
2.Integer
3.Double
4.Exit
3
Enter size : 3
1.4
1.2
1.6
1.2 1.4 1.6
1.String
2.Integer
3.Double
4.Exit
4*/