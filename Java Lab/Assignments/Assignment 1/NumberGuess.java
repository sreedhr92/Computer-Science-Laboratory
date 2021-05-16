//Importing Scanner to get input from the console.......
import java.util.Scanner;

public class NumberGuess
{
	public static void main(String args[])
	{
		int input,n=0;

		//Creating a object for the Scanner......
		Scanner obj = new Scanner(System.in);
		System.out.println("java NumberGuess\n");
		System.out.println("Java has Chosen a number\n");

		//Getting a random number of double type by Math.random()......
		double temp = Math.random();
		temp=temp*100;

		//Type conversion to int........
		int rand = (int)temp;

		//Getting input until the input is matched with the random number.....
		do
		{
			System.out.println("Key in your Guess :");
		    input = obj.nextInt();
			if(input<rand)
			{
				System.out.println("Try Higher !\n");
				n++;
			}
			else if(input>rand)
			{
				System.out.println("Try Lower !\n");
				n++;
			}
			else
			{
				n++;
				System.out.println("You got it in "+n+" trials");
			}
		}while(input!=rand);	
	}
}
/*

PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> javac NumberGuess.java
PS F:\Study\SSN\3rd Sem\Java\Assignments\Assignment 1> java NumberGuess
java NumberGuess

Java has Chosen a number

Key in your Guess :
5
Try Higher !

Key in your Guess :
40
Try Lower !

Key in your Guess :
30
Try Lower !

Key in your Guess :
25
Try Lower !

Key in your Guess :
15
Try Higher !

Key in your Guess :
20
Try Lower !

Key in your Guess :
18
Try Lower !

Key in your Guess :
17
You got it in 8 trials

*/