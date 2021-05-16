#include<stdio.h>
void main()
{
	FILE *fp;
	char ch;
	int i;
	fp=fopen("input.txt","r+");
	fseek(fp,0,0);
	printf("Input File:\n\n");
	while(!0)
	{
		if(!feof(fp))
		{
			ch=fgetc(fp);
			printf("%c",ch);
		}
		else
		{
			break;
		}
	}
	fseek(fp,0,0);
	while(!0)
	{
		if(!feof(fp))
		{	
			ch=fgetc(fp);
			if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')||(ch=='A')||(ch=='E')||(ch=='I')||(ch=='O')||(ch=='U'))
			{
				ch='z';
				fseek(fp,-1,1);
				fputc(ch,fp);
				fseek(fp,1,1);
			}		
		}
		else
		{
			break;
		}	
	}
	fclose(fp);
	printf("\n\nThe Modified form of input file:\n\n");
	fp=fopen("input.txt","r");
	fseek(fp,0,0);
	while(!0)
	{
		if(!feof(fp))
		{
			ch=fgetc(fp);
			printf("%c",ch);
		}
		else
		{
			break;
		}
	}
	fclose(fp);

}
/*Output:
PS C:\TDM-GCC-64\myprogram\A7> gcc file5.c -o a
PS C:\TDM-GCC-64\myprogram\A7> ./a
Input File:

This is ssn college of engineering at chennai.
Chennai is otherwise called as singara chennai 

The Modified form of input file:

Thzs zs ssn czllzgz zf zngznzerzng zt chznnzi.
Chznnzi zs zthzrwzsz czllzd zs szngzrz chznnzi
*/