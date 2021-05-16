#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp,*fp1;
	char ch;
	int n=-1,m,i=0;
	fp=fopen("sample.txt","r");
	fseek(fp,0,0);
	fp1=fopen("copy.txt","w");
	printf("Input file :\n");
	while(1)
	{
		if(!feof(fp))
		{
			ch=fgetc(fp);
			printf("%c",ch);
			n++;
		}
		else
		{
			break;
		}
	}
	m=n/2;
	printf("\n\nEnter the value of n :");
	scanf("%d",&n);
	fseek(fp,m-n,0);
	fseek(fp1,0,0);
	while(1)
	{
		ch=fgetc(fp);
		if(!feof(fp))
		{
			fprintf(fp1,"%c",ch);
			i++;
			if(i==2*n)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	fclose(fp1);
	printf("\nCopy file:\n");
	fopen("copy.txt","r");
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
PS C:\TDM-GCC-64\myprogram\A7> gcc file6.c -o a
PS C:\TDM-GCC-64\myprogram\A7> ./a
Input file :
This is ssn college of engineering at Tamilnadu.
 

Enter the value of n :9

Copy file:
lege of engineerin*/