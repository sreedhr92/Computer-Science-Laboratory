#include<stdio.h>
void main()
{
	FILE *fp;
	char ch;
	fp=fopen("input.txt","r");
	while(!(feof(fp)))
	{
		ch=fgetc(fp);
		printf("%c",ch);
	}
	fclose(fp);
}
/*Ouput:
PS C:\TDM-GCC-64\myprogram\A7> gcc file1.c -o a
PS C:\TDM-GCC-64\myprogram\A7> ./a
Input File:

This is ssn college of engineering at chennai.
Chennai is otherwise called as singara chennai*/