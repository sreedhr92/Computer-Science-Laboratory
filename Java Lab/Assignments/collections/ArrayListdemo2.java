import java.util.*;
public class ArrayListdemo2
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		ArrayList<Integer> arr1 = new ArrayList<Integer>();
		ArrayList<Integer> arr2 = new ArrayList<Integer>();
		ArrayList<Integer> arr3 = new ArrayList<Integer>();
		ArrayList<Integer> arr4 = new ArrayList<Integer>();
		int choice;
		while(true)
		{
		System.out.print("\n1.Create list1\n2.Create list2\n3.Merge two list\n4.Union of two lists\n5.Intersection of two lists\n6.Compare 2 lists\n7.Exit\nEnter choice");
		choice=obj.nextInt();
		if(choice==1)
		{
			for(int i=0;i<5;i++)
			{
				arr1.add(i);
			}
			System.out.println("\nList 1 :"+arr1);
		}
		else if(choice==2)	
		{
			for(int i=0;i<10;i++)
			{
				arr2.add(i);
			}
			System.out.println("\nList 2 :"+arr2);
		}
		else if(choice==3)
		{	
		arr3.addAll(arr1);
		arr3.addAll(arr2);
		System.out.println("\nAfter Combine :"+arr3);
		}
		else if(choice==4)
		{
			System.out.println("\nUnion :");
			for(int i : arr1)
			{
				if(!arr4.contains(i))
				{
					arr4.add(i);
				}
			}	
			for(int i :arr2)
			{
				if(!arr4.contains(i))
				{
					arr4.add(i);
				}
			}
			System.out.print("After Union :");
		}
		else if(choice==5)
		{
			System.out.print("[");
			for(int i: arr1)
			{
				if(arr2.contains(i))
					System.out.print(i+"  ");
			}
			System.out.println("]");
		}
		else if(choice==6)
		{
			if(arr1.equals(arr2))
				System.out.println("\nboth list are equal");
			else
				System.out.println("\nBoth list are not equal ");
		}
		else if(choice==7)
		{
			break;
		}
	}	
	}
}
/*Output:
PS F:\Study\SSN\3rd Sem\Java\Assignments\collections> javac ArrayListdemo2.java                                                                             PS F:\Study\SSN\3rd Sem\Java\Assignments\collections> java ArrayListdemo2     
1.Create list1
2.Create list2
3.Merge two list
4.Union of two lists
5.Intersection of two lists
6.Compare 2 lists
7.Exit
Enter choice1

List 1 :[0, 1, 2, 3, 4]

1.Create list1
2.Create list2
3.Merge two list
4.Union of two lists
5.Intersection of two lists
6.Compare 2 lists
7.Exit
Enter choice2

List 2 :[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

1.Create list1
2.Create list2
3.Merge two list
4.Union of two lists
5.Intersection of two lists
6.Compare 2 lists
7.Exit
Enter choice3

After Combine :[0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

1.Create list1
2.Create list2
3.Merge two list
4.Union of two lists
5.Intersection of two lists
6.Compare 2 lists
7.Exit
Enter choice4

After Union :[0,1,2,3,4,5,6,7,8,9]

1.Create list1
2.Create list2
3.Merge two list
4.Union of two lists
5.Intersection of two lists
6.Compare 2 lists
7.Exit
Enter choice5
[0  1  2  3  4  ]

1.Create list1
2.Create list2
3.Merge two list
4.Union of two lists
5.Intersection of two lists
6.Compare 2 lists
7.Exit
Enter choice6

Both list are not equal

1.Create list1
2.Create list2
3.Merge two list
4.Union of two lists
5.Intersection of two lists
6.Compare 2 lists
7.Exit
Enter choice */