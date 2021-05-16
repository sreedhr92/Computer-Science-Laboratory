 class Fibonacci{
	
	public int fibo(int n){
	
	if(n<=1)
	{return 1;}
	else
	{return fibo(n-1) + fibo(n-2);}	
	}
	}
public class fibonacciSeries{

	public static void main(String args[]){		
	Fibonacci e = new Fibonacci();	
	int i,n;
	n=Integer.parseInt(args[0]);
	for(i=0;i<n;i++){
		System.out.println(e.fibo(i));
	}
	}	
	}
			
		
		
