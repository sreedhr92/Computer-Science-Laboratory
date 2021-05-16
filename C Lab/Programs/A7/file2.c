#include<stdio.h>
#include<conio.h>
//#include<input.h>
void main()
{
	FILE *fp;
	char ch;
	int x,sp=0,nc=0,nd=0;
	fp=fopen("input.txt","r+");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		x=ch;
		if(x==32)
		{
			sp++;
		}
		else if((x>47)&&(x<58))
		{
			nd++;
		}	
		else
		{
			nc++;
		}
	}
	fclose(fp);
	printf("Number of Characters :%d\nNumber of Digits :%d\nNumber of spaces :%d",nc,nd,sp);
}
/*Ouput:
PS C:\TDM-GCC-64\myprogram\A7> gcc file2.c -o a
PS C:\TDM-GCC-64\myprogram\A7> ./a
Input File:

This is ssn college of engineering at chennai.
Chennai is otherwise called as singara chennai 
Number of Characters :81
Number of Digits :0
Number of spaces :13
*/
