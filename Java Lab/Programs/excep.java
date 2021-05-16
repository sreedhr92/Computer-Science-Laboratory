import java.util.Scanner;
class symboltable 
{
	Scanner obj = new Scanner(System.in);
	int n,k=0;
	String	symbolname[];
	String symbolvalue[];
	void initialize()
	{
		System.out.print("Enter the value of n:");
		n=obj.nextInt();
		symbolname = new String[n];
		symbolvalue = new String[n];
	}
	void setvalue(String a,String b)
	{
		symbolname[k]=a;
		symbolvalue[k]=b;
		k++;
	}
	String getvalue(String a)
	{
			int i;
			for(i=0;i<k;i++)
			{
				if(symbolname[i].equals(a))
				{
					if(symbolvalue[i]!=NULL)
						return symbolvalue[i];
					else
						throw new ValueNotFoundException(symbolvalue[i]);
				}
			}
	}
}
