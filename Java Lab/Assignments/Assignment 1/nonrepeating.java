import java.util.Scanner;
public class nonrepeating
{
	Scanner obj = new Scanner(System.in);
	int a[],i,j,n,count=0,flag=0;
	public void initialization()
	{
		System.out.print("Enter no. of Elements :");
		n=obj.nextInt();
		a=new int[n];
	}	
	public void input()
	{
		System.out.println("Enter elements:");
		for(i=0;i<n;i++)
		{
			a[i]=obj.nextInt();
		}
	}
	public int compute()
	{
		for(i=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					continue;
				}
				if(a[i]==a[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				count++;
			}
		}
		return count;
	}
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		nonrepeating a = new nonrepeating();
		a.initialization();
		a.input();
		int total=a.compute();
		System.out.println("\nNumber of non repeating terms :"+total);

	}

}
/*

PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac nonrepeating.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> java nonrepeating
Enter no. of Elements :7
Enter elements:
1
2
3
4
3
5
2

Number of non repeating terms :3
*/


	