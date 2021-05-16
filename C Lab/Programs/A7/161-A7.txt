//1. Write a C program to read the text file input.txt  and display it on the console.
#include<stdio.h>
void main()
{
	//creating file pointer........
	FILE *fp;
	char ch;
	fp=fopen("input.txt","r");
	//reading the file untill the end.....
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


//2. Modify Program.1 to count the number of characters, spaces, digits in that file 
#include<stdio.h>
#include<conio.h>
//#include<input.h>
void main()
{
	//creating the file pointer..
	FILE *fp;
	char ch;
	int x,sp=0,nc=0,nd=0;
	//opening the file in read mode...
	fp=fopen("input.txt","r+");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		x=ch;
		//counting the given aspects by accessing the each character's ASCII value..
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


//3. Modify Program.2 to count the number of words, lines in the same file
#include<stdio.h>
#include<conio.h>
void main()
{
	//creating the file pointer...
	FILE *fp;
	char ch;
	int x,sp=0,nd=0;
	//Opening the file in the read mode...
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		x=ch;
		//counting the given aspects by accessing the each character's ASCII value..
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
Number of Lines :2*/


//4. Copy the content of the file input.txt into another file  sample.txt. 
#include<stdio.h>
#include<conio.h>
void main()
{
	//creating the file pointers...
	FILE *fp,*fp1;
	char ch;
	//opening the input file file in the read mode....
	fp=fopen("input.txt","r");
	//setting the file pointer to the beginning of the file...
	fseek(fp,0,0);
	//creating the file sample file.....
	fp1=fopen("sample.txt","w");
	//printing the contents of the input file.. 
	printf("Input file :\n\n");
	while(1)
	{
		ch=fgetc(fp);
		if(!feof(fp))
		{
			//copying the contents to sample files...
			fprintf(fp1,"%c",ch);
			printf("%c",ch);
		}
		else
		{
			break;
		}
	}
	fclose(fp1);
	//printing the contents of the sample files...
	printf("\n\nSample file:\n");
	fopen("sample.txt","r");
	//setting the file pointer to the beginning of the file...
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


//5. Search for the content for the occurrence of vowel characters and replace it with ‘z’. And display the content on the screen
#include<stdio.h>
void main()
{
	//creating the file pointer...
	FILE *fp;
	char ch;
	int i;
	//opening the input file in the read mode.....
	fp=fopen("input.txt","r+");
	//setting the pointer to the beginning of the file...
	fseek(fp,0,0);
	//displaying the contents of the input file...
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
	//setting back the file pointer to the beginning the file...
	fseek(fp,0,0);
	while(!0)
	{
		if(!feof(fp))
		{	
			//Checking whether the character is vowel or not......
			ch=fgetc(fp);
			if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')||(ch=='A')||(ch=='E')||(ch=='I')||(ch=='O')||(ch=='U'))
			{
				//modifying the character as "Z"
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
	//printing the modified form of the file input...
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


//6. Search for the middle content of the file say m be the location of it. Copy (m-n) to (m+n)contents to another file called copy.txt using fseek().
#include<stdio.h>
#include<conio.h>
void main()
{
	//creating file pointers..
	FILE *fp,*fp1;
	char ch;
	int n=-1,m,i=0;
	//opening the file in the read mode...
	fp=fopen("sample.txt","r");
	fseek(fp,0,0);
	//creating the file copy
	fp1=fopen("copy.txt","w");
	printf("Input file :\n");
	//printing the contents of the input file....
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
	//calculating the middle character of the file.....
	m=n/2;
	printf("\n\nEnter the value of n :");
	scanf("%d",&n);
	//setting the file pointer to the m-n th positon.....
	fseek(fp,m-n,0);
	fseek(fp1,0,0);
	while(1)
	{
		ch=fgetc(fp);
		if(!feof(fp))
		{
			//copying untill m+nth position....
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
	//displaying the file copy.....
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



//7. Redo 2nd problem of A6 using files. (fread, fwrite). Read the input from file and write output to another file
#include<stdio.h>
struct student
{
	int m[100];
	char name[100];
	float avg;
};
void inputmarks(struct student stu[],int k,int j,FILE *fp)
{
	int i;
	fp=fopen("Input1.txt","w");
	for(i=0;i<j;i++)
	{
		printf("Enter the Subject %d marks :",i+1);
		scanf("%d",&stu[k].m[i]);
		fprintf(fp,"%d",stu[k].m[i]);
	}
	fclose(fp);
}
void input(struct student stu[],int i,int m,FILE *fp)
{
	fp=fopen("Input1.txt","w");
	printf("Enter the student name :");
	scanf("%s",&stu[i].name);
	fprintf(fp,"%s",stu[i].name);
	inputmarks(stu,i,m,fp);
}
void average(struct student stu[],int n,int k)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=stu[k].m[i];
	}
	stu[k].avg=sum/n;
}
void output(struct student stu[],int n,FILE *fp1)
{
	fp1=fopen("Output1.txt","w");
	printf("The Average of %s is %.3f\n",stu[n].name,stu[n].avg);
	fclose(fp1);
}
void classaverage(struct student stu[],int n,FILE *fp1)
{
	int i;
	fp1=fopen("Output1","w");
	float total=0;
	for(i=0;i<n;i++)
	{
		total+=stu[i].avg;
	
	}
	printf("The Class average is %.3f",total/n);
	fprintf(fp1,"%f",stu[i].avg);
	fclose(fp1);
}
void main()
{
	int n,i,m;
	FILE *fp,*fp1;
	fp=fopen("Input1.txt","w");
	fp1=fopen("Output1.txt","w");
	printf("Enter the number of students :");
	scanf("%d",&n);
	fprintf(fp,"%d",n);
	printf("Enter the number of subjects :");
	scanf("%d",&m);
	fprintf(fp,"%d",n);
	struct student stu[n];
	for(i=0;i<n;i++)
	{
		input(stu,i,m,fp);
		average(stu,m,i);
	}
	for(i=0;i<n;i++)
	{
		output(stu,i,fp1);
	}
	classaverage(stu,n,fp1);
}
/*Output:
PS C:\TDM-GCC-64\myprogram\A6> gcc 161-A62.c -o a
PS C:\TDM-GCC-64\myprogram\A6> ./a
Enter the number of students :4
Enter the number of subjects :3
Enter the student name :hari
Enter the Subject 1 marks :78
Enter the Subject 2 marks :89
Enter the Subject 3 marks :90
Enter the student name :money
Enter the Subject 1 marks :56
Enter the Subject 2 marks :34
Enter the Subject 3 marks :86
Enter the student name :jaanmeri
Enter the Subject 1 marks :55
Enter the Subject 2 marks :100
Enter the Subject 3 marks :34
Enter the student name :lolip
Enter the Subject 1 marks :66
Enter the Subject 2 marks :44
Enter the Subject 3 marks :23
The Average of hari is 85.000
The Average of money is 58.000
The Average of jaanmeri is 63.000
The Average of lolip is 44.000
The Class average is 62.500*/

//8.question...
// C program to find and replace all occurrences of a word in file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* Function declaration */
void replaceAll(char *str, const char *oldWord, const char *newWord);


int main()
{
    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];


    printf("Enter path of source file: ");
    scanf("%s", path);

    printf("Enter word to replace: ");
    scanf("%s", oldWord);

    printf("Replace '%s' with: ",oldword);
    scanf("%s", newWord);


    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
       Read line from source file and write to destination 
       file after replacing given word.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Replace all occurrence of word from current line
        replaceAll(buffer, oldWord, newWord);

        // After replacing write it to temp file.
        fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("replace.tmp", path);

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", oldWord, newWord);

    return 0;
}




 // Replace all occurrences of a given a word in string.
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);


      //Repeat till all occurrences are replaced. 
     
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        // Bakup current line
        strcpy(temp, str);

        // Index of current found word
        index = pos - str;

        // Terminate str after word found index
        str[index] = '\0';

        // Concatenate str with new word 
        strcat(str, newWord);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(str, temp + index + owlen);
    }
}