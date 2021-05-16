import java.util.*;
public class ArrayListdemo
{
	public static void main(String args[])
	{
		Scanner obj = new Scanner(System.in);
		ArrayList<String> arr = new ArrayList<String>();
		int choice,index;
		String val;
		String val2;
		while(true)
		{
			System.out.print("\n1.Append at end\n2.Insert at a particular index\n3.Index of element(Search)\n4.Display \n5.Strings starts with the givn letter\n6.strings that has the substring\n7.Sort\n8.Remove\n9.Replace\n10.Remove duplicate\n11.Exit\n\tEnter choice :");
			choice=obj.nextInt();
			if(choice==1)
			{
				System.out.print("Enter the name :");
				val=obj.next();
				arr.add(val);
			}
			else if(choice==2)
			{
				System.out.print("Enter the name :");
				val=obj.next();
				System.out.print("Enter the index :");
				index=obj.nextInt();
				arr.add(index,val);
			}
			else if(choice==3)
			{
				System.out.print("Enter the name :");
				val=obj.next();
				if(arr.indexOf(val)!=-1)
					System.out.println("The element found at the index "+arr.indexOf(val));
				else
					System.out.println("NOT FOUND");
			}
			else if(choice==4)
				System.out.println("ArrayList :"+arr);
			else if(choice==5)
			{
				System.out.print("Enter the starting letter :");
				val=obj.next();
				for(String a : arr)
				{
					if(a.startsWith(val))
					{
						System.out.print(a+"  ");
					}

				}
			}
			else if(choice==6)
			{
				System.out.print("Enter the Substring :");
				val=obj.next();
				for(String a : arr)
				{
					if(a.contains(val))
					{
						System.out.print(a+"  ");
					}

				}
				
			}
			else if(choice==7)
			{	
				Collections.sort(arr);
				System.out.println("Sorted ArrayList :"+arr);
			}
			else if(choice==8)
			{
				System.out.print("Enter the element :");
				val=obj.next();
				arr.remove(val);
			}	
			else if(choice==9)
			{
				System.out.print("Enter the Index :");
				index=obj.nextInt();
				System.out.print("Enter the replacement String :");
				val2=obj.next();
				arr.set(index,val2);
			}
			else if(choice==10)
			{
				ArrayList<String> arrnew = new ArrayList<String>();
				for(String a : arr)
				{
					if(!arrnew.contains(a))
					{
						arrnew.add(a);
					}
				}
				System.out.println("Formatted List :"+arrnew);
			}
			else if(choice==11)
			{
				break;
			}
		}
	}
}
/*Ouput:
PS F:\Study\SSN\3rd Sem\Java\Assignments\collections> javac ArrayListdemo.java                                                                              PS F:\Study\SSN\3rd Sem\Java\Assignments\collections> java ArrayListdemo      
1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :1
Enter the name :Sree

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :1
Enter the name :Free

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :1
Enter the name :Lree

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :2
Enter the name :Gree
Enter the index :2

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :4
ArrayList :[Sree, Free, Gree, Lree]

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :3
Enter the name :Gree
The element found at the index 2

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :5
Enter the starting letter :G
Gree
1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :1
Enter the name :Sreeisthebest

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :1
Enter the name :Nreeisthebest

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :6
Enter the Substring :best
Sreeisthebest  Nreeisthebest
1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :7
Sorted ArrayList :[Free, Gree, Lree, Nreeisthebest, Sree, Sreeisthebest]

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :8
Enter the element :Lree

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :4
ArrayList :[Free, Gree, Nreeisthebest, Sree, Sreeisthebest]

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :9
1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :

1
Enter the name :Sree

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :1
Enter the name :Sree

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :1
Enter the name :Sree

1.Append at end
2.Insert at a particular index
3.Index of element(Search)
4.Display
5.Strings starts with the givn letter
6.strings that has the substring
7.Sort
8.Remove
9.Replace
10.Remove duplicate
11.Exit
        Enter choice :10
Formatted List :[Sree]*/  