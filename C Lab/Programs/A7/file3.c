#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp;
	char ch;
	int x,sp=0,nc=0,nd=0;
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		x=ch;
		if(x==32)
		{
			sp++;
		}
		else if(x==10)
		{
			nd++;
		}	
	}
	fclose(fp);
	printf("Number of Words :%d\nNumber of Lines :%d",sp+1,nd+1);
}
/*output:
PS C:\TDM-GCC-64\myprogram\A7> gcc file3.c -o a
PS C:\TDM-GCC-64\myprogram\A7> ./a
Input file:
This is ssn college of engineering at chennai.
Chennai is otherwise called as singara chennai
Number of Words :14
Number of Lines :2