/*1. Write a java program to find the maximum value from the given type of elements using a
generic function.*/

class elements<T>
{
	T[] obj;
	elements(T[] a)
	{
		obj=a;
	}
	public static <T extends comparable<T>>T max()
	{
		/*int i;
		if(obj instanceof Integer)
		{
			int m=0,maxindex=0;
			for(i=0;i<obj.length();i++)
			{
				if(m>obj[i].intValue())
				{
					m=obj[i].intValue();
					maxindex=i;
				}
			}
			return obj[i].intValue();
		}
		if(obj instanceof Double)
		{
			double max=0;
			int maxindex=0;
			for(i=0;i<obj.length();i++)
			{
				if(max>obj[i].doubleValue())
				{
					max=obj[i].doubleValue();
					maxindex=i;
				}					       
			}
			return obj[i].doubleValue();
		}
		if(obj instanceof Float)
		{
			float max=0;
			int maxindex=0;
			for(i=0;i<obj.length();i++)
			{
				if(max>obj[i].floatValue())
				{
					max=obj[i].floatValue();
					maxindex=i;
				}
			}
			return obj[i].floatValue();
		}*/
		T m=obj[0];
		int i;
		for (i=1;i<obj.length;i++)
		{
			if(obj[i].compareTo(m)>0)
				m=obj[i];

		}
		return m;
	}
}
public class maxgen
{
	public static void main (String args[])
	{			
		Integer i[] = {1,2,3,4,5};
		elements<Integer> a= new elements<Integer>(i);
		System.out.println(a.max());
		Double a[] = {2.2,3,4,5,6,8};
		elements<Double> a1=new elements<Double>(a);
		System.out.println(a1.max());
		Float b[] = {23,31,53,13,1};
		elements<Float> a3=new elements<Float>(b);
		System.out.println(a3.max());
	}
}
		
		
