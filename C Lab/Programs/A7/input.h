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