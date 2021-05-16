//1.Implementing the builtin function as user defined functions
#include<stdio.h>
//declaration of the functions
void strcat_(char a[],char b[]);
void strncpy_(char b[],char a[],int n);
void strchr_(char a[],char ch);
void strset_(char a[],char ch);
int strcmpi_(char a[],char b[]);
void strncat_(char a[],char b[],int n);
int strlen_(char a[]);
int isupper_(char ch);
char tolower_(char ch);
char toupper_(char ch);
void main()
{
	int n,x,i;
	char a[100],b[100],ch;
	printf("1.Strcat\n2.strncpy\n3.strchr\n4.strset\n5.strcmpi\n6.strncat\n");
	//Matching the cases for 6 times(6 functions)
	for(i=0;i<6;i++)
	{
		printf("Enter the choice :");
		scanf("%d",&x);
		switch(x)
		{
			case 1 :printf("Enter the first string :");
					scanf("%s",&a);		
					printf("Enter the second string :");
					scanf("%s",&b);
					strcat_(a,b);
		    		break;	
	    	case 2 :printf("Enter the source string :");
					scanf("%s",&a);
					printf("Enter the no. of characters to be copied to the destination(upto):");
					scanf("%d",&n);
					strncpy_(b,a,n);
	    			break;
	   	    case 3 :printf("Enter the string :");
	   		   		scanf("%s",&a);
	   		   		printf("\nEnter the character to find the positon :");
	   	    		scanf("%s",&ch);
	   	    		strchr_(a,ch);
	 		   		break;
	   		 case 4 :printf("Enter the string :");
	   	             scanf("%s",&a);
	   		         printf("Enter the character to be replaced in the string :");
	   		         scanf("%s",&ch);
	   		    	 strset_(a,ch);
	   		    	 break;
	   		 case 5 :printf("Enter the first string :");
					 scanf("%s",&a);
				     printf("Enter the second string :");
					 scanf("%s",&b);
					 printf("The return value is %d\n\n",strcmpi_(a,b));
			    	 break;
			 case 6 :printf("Enter the source string :");
				 	 scanf("%s",&a);
				 	 printf("Enter the destinaton string :");
				 	 scanf("%s",&b);
					 printf("Enter the no. of characters to be copied to the destnation(atmost):");
					 scanf("%d",&n);
					 strncat_(b,a,n);
	    			 break;	
	    	 default:printf("Invalid input..Retry\n");
	    	    	 i--;				
		}
	}
}
int strlen_(char a[])
{
	//null character specifies the end of the string till '\0' gives length
	int i=0;
	while(a[i]!='\0')
	{
		i++;
	}
	return i;
}
int isupper_(char ch)
{
	int as=ch;
	//Matching the ASCII values
	if((as>=65)&&(as<=90))
	{
		printf("YES it is a upper case");
		return 1;
	}
	else
	{
		printf("NO it is a lower case");
		return 0;
	}	
}
char tolower_(char ch)
{
	//ASCII of lower 32 greater than upper case
	int as=ch;
	return as+32;
}
char toupper_(char ch)
{
	//ASCII of upper 32 lower than lower case
	int as=ch;
	return as-32;
}
void strcat_(char a[],char b[])
{

	int i,n,m;
	//Calling the built-in strlen function to calculate the length
	n=strlen_(a);
	m=strlen_(b);
	char s[m+n];
	//Assigning the str1 to new string
	for(i=0;i<n;i++)
	{
		s[i]=a[i];
	}
	//Assigning the str2 to new string from the previous length
	for(i=0;i<=m;i++)
	{
		s[n]=b[i];
		n++;
	}
	printf("The concatenated string is %s\n\n",s);
}	
void strncpy_(char b[],char a[],int n)
{
	int i;
	//copying upto n character to the str2
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	printf("The Copied string is %s\n\n",b);
}
void strchr_(char a[],char ch)
{
	int i,n;
	n=strlen_(a);
	//traversing from the first character 
	for(i=0;i<=n;i++)
	{
		//returnig index if the traversed character is matched with entered one
		if(a[i]==ch)
		{
			printf("%d is the first occurance\n\n",i);
			break;
		}
	}
}
void strset_(char a[],char ch)
{
	int i,n;
	n=strlen_(a);
	//setting each character to the character entered
	for(i=0;i<n;i++)
	{
		a[i]=ch;
	}
	printf("The Modified string is %s\n\n",a);
}
int strcmpi_(char a[],char b[])
{
	int i,j,n,m,count=0;
	n=strlen_(a);
	m=strlen_(b);
	//Assigning all the character as lower case
	for(i=0;i<n;i++)
	{
		a[i]=tolower_(a[i]);
	}
	for(i=0;i<m;i++)
	{
		b[i]=tolower_(b[i]);
	}
	//if the string is equal length and same characters returning 0
	if(n==m)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
			{
				count++;
			}
		}
		if(count==n)
		{
			return 0;
		}
		//for unequal length of the strings
		else
		{
			int i=0;
			do
			{
				//checking the each character of the string1 and string2 siultaneously
				doit:
				//matches doit again
				if(a[i]==b[i])
				{
					i++;
					goto doit;
				}
				//lower means return -1
				else if(a[i]<b[i])
				{
					return -1;
				}
				//Greater means return 1
				else
				{
					return 1;
				}
			}while(i<n);
		}
	}
	else
	{
		//checking the each character of the string1 and string2 siultaneously
		int i=0;j=0;
		do
		{
			doit1:
			//matches doit again
			if(a[i]==b[j])
			{
				i++;
				j++;
				goto doit1;
			}
			//lower means return -1
			else if(a[i]<b[j])
			{
				return -1;
			}
			//Greater means return 1
			else
			{
				return 1;
			}
		}while((i<n)&&(j<m));
	}	
}
void strncat_(char a[],char b[],int n)
{
	//concatenating atmost n character 
	int p,m,i,j=n;
	p=strlen_(a);
	m=strlen_(b);
	if(p<n)
	{
		j=p;
	}
	for(i=0;i<j;i++)
	{
		b[m]=a[i];
		m++;
	}
	printf("The concatenated string is %s\n",b);
}