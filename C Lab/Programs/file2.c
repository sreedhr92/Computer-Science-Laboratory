#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp,*fp1;
	char ch,a[200];
	int x,i=0;
	fp=fopen("input.txt","w");
	printf("Enter text to be input in File 1(input file):");
	do
	{
		scanf("%c",&a[i]);
		fprintf(fp,"%c",ch);
		i++;
	}while(a[i]!='');
	fp1=fopen("sample.txt","w");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		fprintf(fp1,"%c",ch);
		printf("%c",ch);
	}
	fclose(fp1);
	fclose(fp);
	fopen("sample.txt","r");
	while(!feof(fp1))
	{
		ch=fgetc(fp1);
		printf("%c",ch);
	}
	fclose(fp1);
}