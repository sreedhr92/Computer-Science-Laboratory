#include<stdio.h>
int count=0;
//Function declaration.....
int check(int n);
void main()
{
	int i;
	printf("The Possible Well ordered Three digit numbers are ");
	//Checking all 3 digit number each time.....
	for(i=100;i<1000;i++)
	{
		check(i);
	}
	printf("The total number of 3 digit well ordered numbers are %d",count);
}
//To split the number into individual digits an storing in an array...
int check(int n)
{
	int a[3],j,k=n;
	for(j=2;j>=0;j--)
	{
		a[j]=n%10;
		n/=10;
	}
//Checking whether the each digit is greater than the other.. 	
	if((a[0]<a[1]) && (a[1]<a[2]))
	{
		printf("%d\t",k);
		count++;
	}
}
/*Output :
PS C:\TDM-GCC-64\myprogram> gcc 31-wellordered.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
The Possible Well ordered Three digit numbers are 123   124     125     126
127     128     129     134     135     136     137     138     139     145
146     147     148     149     156     157     158     159     167     168
169     178     179     189     234     235     236     237     238     239
245     246     247     248     249     256     257     258     259     267
268     269     278     279     289     345     346     347     348     349
356     357     358     359     367     368     369     378     379     389
456     457     458     459     467     468     469     478     479     489
567     568     569     578     579     589     678     679     689     789
The total number of 3 digit well ordered numbers are 84*/