#include<stdio.h>
void main()
{
	FILE *fp;
	fp=fopen("class.txt","w+");
	char ch;
	do
	{
		ch=getc(fp);
		printf("%c",ch);
	}while(!feof(fp));
	fclose(fp);
	
}
