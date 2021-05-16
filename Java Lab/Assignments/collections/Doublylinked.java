import java.util.*;
public class Doublylinked
{
	public static void main(String args[])
	{
		LinkedList<Integer> list = new LinkedList<Integer>();
		int val,choice,index,val2;
		Scanner obj = new Scanner(System.in);
		while(true)
		{
			System.out.print("\n1.Insert at both end\n2.Delete element on both sides\n3. Insert an element at a particular position\n4.Delete a particular element\n5.Search for a particular element\n6.Display list in forward order and backward order\n7.Sort the elements in LinkedList\n8.Replace one element in the list with another list\n9. Remove duplicate elements\n10.Exit\n\tEnter choice:");
			choice=obj.nextInt();
			if(choice==1)
			{
				System.out.print("Enter the element :");
				val=obj.nextInt();
				list.addFirst(val);
				list.addLast(val);
			}
			else if(choice ==2)
			{
				list.removeFirst();
				list.removeLast();	
			}
			else if(choice==3)
			{
				System.out.print("Enter the element :");
				val=obj.nextInt();
				System.out.print("Enter the index :");
				index=obj.nextInt();
				list.add(index,val);
			}
			else if(choice==4)
			{
				System.out.print("Enter the element :");
				val=obj.nextInt();
				list.remove(val);
			}
			else if(choice==5)
			{
				System.out.print("Enter the element :");
				val=obj.nextInt();
				System.out.println("The element is found in the positon :"+list.indexOf(val));
			}
			else if(choice==6)
			{
				System.out.println("\nThe list printed in the forward direction :");
				ListIterator<Integer> itr = list.listIterator();
				while(itr.hasNext())
				{
					int element = itr.next();
					System.out.print(element +"  ");
				}
				System.out.println("\nThe list printed in the Reverse order");
				ListIterator<Integer> itr1 = list.listIterator();
				while(itr1.hasPrevious())
				{
					int element = itr1.previous();
					System.out.print(element+"  ");
				}
			}
			else if(choice==7)
			{
				Collections.sort(list);
				System.out.println("The Sorted Linked list is :"+list);
			}
			else if(choice==8)
			{
				System.out.print("Enter the Index  :");
				val=obj.nextInt();
				System.out.print("Enter the replacement value :");
				val2=obj.nextInt();
				list.set(val,val2);
			}
			else if(choice ==9)
			{
				LinkedList<Integer> listnew = new LinkedList<Integer>();
				ListIterator<Integer> itr = list.listIterator();
				while(itr.hasNext())
				{
					int element = itr.next();
					if(!listnew.contains(element))
						listnew.add(element);
				}
				System.out.println("\nFormatted List :"+listnew);
			}
			else if(choice==10)
			{
				break;
			}
		}
	}		
}
/*Output:
PS F:\Study\SSN\3rd Sem\Java\Assignments\collections> javac Doublylinked.java PS F:\Study\SSN\3rd Sem\Java\Assignments\collections> java Doublylinked       
1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:1
Enter the element :4

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:1
Enter the element :3

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:2

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:3
Enter the element :5
Enter the index :2

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:4
Enter the element :4
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:1
Enter the element :2

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:6

The list printed in the forward direction :
2  2
The list printed in the Reverse order

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:1
Enter the element :67

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:7
The Sorted Linked list is :[2, 2, 67, 67]

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:8
Enter the Index  :2
Enter the replacement value :67

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:9

Formatted List :[2, 67]

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:6

The list printed in the forward direction :
2  2  67  67
The list printed in the Reverse order

1.Insert at both end
2.Delete element on both sides
3. Insert an element at a particular position
4.Delete a particular element
5.Search for a particular element
6.Display list in forward order and backward order
7.Sort the elements in LinkedList
8.Replace one element in the list with another list
9. Remove duplicate elements
10.Exit
        Enter choice:*/