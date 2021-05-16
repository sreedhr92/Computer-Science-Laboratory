import java.util.Scanner;
public class search
{
	Scanner obj = new Scanner(System.in);
	int i,j,temp,n,a[];
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
	public int searching(int x)
	{
		int flag=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==x)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			return -1;
		else
			return i;
	}
	public void sorting()
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
	public int bsearch(int x)
	{
		int lower_limit=0,upper_limit=n-1,middle;
		middle=(lower_limit+upper_limit)/2;
		while(lower_limit<=upper_limit)
		{
			if(x<a[middle])
			{
				upper_limit=middle-1;
			}
			else if(a[middle]<x)
			{
				lower_limit=middle+1;
			}
			else if(x==a[middle])
			{
				return middle;
			}	
			middle=(lower_limit+upper_limit)/2;
		}
		return -1;
    }
    public void print1()
	{
		System.out.println("\nThe Sorted array is");
		for(i=0;i<n;i++)
		{
			System.out.print(i+" ");
			System.out.println(a[i]);
		}
	}	

	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		search a = new search();
		a.initialize();
		a.input();
		System.out.print("\nEnter the number to be searched :");	
		int x = obj.nextInt();
		System.out.print("\nEnter which type of method to search\n1.Linear\n2.Binary\nEnter the option :");
		int y = obj.nextInt();
		if(y==1)
		{
			int element=a.searching(x);
			if(element!=-1)
			{
				System.out.println("\nThe element is found in the positon "+element);
			}
			else
			{
				System.out.println("\n404.Not Found");
			}
		}
		else if(y==2)
		{
			a.sorting();
			a.print1();
			int element=a.bsearch(x);
			if(element!=-1)
			{
				System.out.println("The element is found in the positon "+element);
			}
			else
			{
				System.out.println("\n404.Not Found");
			}
		}
		else
		{
			System.out.println("Enter the option correctly");
		}
}
}
			
/*

PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac search.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> java search
Enter no. elements:
6

Enter elements:
2
4
5
3
1
6

Enter the number to be searched :1

Enter which type of method to search
1.Linear
2.Binary
Enter the option :2

The Sorted array is
0 1
1 2
2 3
3 4
4 5
5 6
The element is found in the positon 0

*/
