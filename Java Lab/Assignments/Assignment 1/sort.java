import java.util.Scanner;
public class sort
{
	Scanner obj = new Scanner(System.in);
	int i,j,k,temp,n,a[];
	public void initialize()
	{
		System.out.println("Enter no. elements:");
		n=obj.nextInt();
		a=new int[n];
	}
	public void input()
	{
		System.out.println("\nEnter elements:");
		for(i=0;i<n;i++)
		{
			a[i]=obj.nextInt();
		}
	}
	public void sorting(int x)
	{
		if(x==1)
		{
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(a[i]>a[j])
					{
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				}
			}
		}
		else if(x==2)
		{

			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(a[i]<a[j])
					{
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				}
			}
		}
		else
		{
			System.out.println("Enter the option correctly");	
		}	
	}	
	public void print()
	{
		System.out.println("\nThe Sorted array is");
		for(i=0;i<n;i++)
		{
			System.out.println(a[i]);
		}
	}
	public int end()
	{
		System.out.println("Wanna try again..\npress any key other than -1");
		int x=obj.nextInt();
		return x;
	}
	public static void main(String args[])
	{
		int i;
		Scanner obj = new Scanner(System.in);
		sort a = new sort();
		while(true){
		a.initialize();
		a.input();
		System.out.print("\nSorting type\n1.Ascending\n2.Descending");
		for(i=0;i<2;i++)
		{
			System.out.println("\nEnter the option");
			int x=obj.nextInt();
			a.sorting(x);
			a.print();
		}	
		int f=a.end();
		if(f==-1)
		{
			break;
		}
	}	
	}
}	
/*

PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac sort.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> java sort
Enter no. elements:
7

Enter elements:
1
5
2
3
7
6
4

Sorting type
1.Ascending
2.Descending
Enter the option
2

The Sorted array is
7
6
5
4
3
2
1

Enter the option
1

The Sorted array is
1
2
3
4
5
6
7
Wanna try again..
press any key other than -1
-1

*/