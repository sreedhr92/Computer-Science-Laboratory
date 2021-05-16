#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp,*fp1;
	char ch;
	fp=fopen("input.txt","r");
	fseek(fp,0,0);
	fp1=fopen("sample.txt","w");
	printf("Input file :\n\n");
	while(1)
	{
		ch=fgetc(fp);
		if(!feof(fp))
		{
			fprintf(fp1,"%c",ch);
			printf("%c",ch);
		}
		else
		{
			break;
		}
	}
	fclose(fp1);
	printf("\n\nSample file:\n");
	fopen("sample.txt","r");
	fseek(fp1,0,0);
	while(1)
	{
		ch=fgetc(fp1);
		if(!feof(fp1))
		{
			printf("%c",ch);
		}
		else
		{
			break;
		}	
	}
	fclose(fp1);
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A7> gcc file4.c -o a
PS C:\TDM-GCC-64\myprogram\A7> ./a
Input file :

This is ssn college of engineering at chennai.
Chennai is otherwise called as singara chennai

Sample file:
This is ssn college of engineering at chennai.
Chennai is otherwise called as singara chennai*/