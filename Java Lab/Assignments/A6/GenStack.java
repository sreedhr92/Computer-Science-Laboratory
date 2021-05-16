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

