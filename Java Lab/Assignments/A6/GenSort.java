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