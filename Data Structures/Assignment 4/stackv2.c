#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"stackintf.h"
#include"stackimpl.h"

//returning the precedence of the operators.........

int precedence(struct stack *s,char b)
{
	char x;
	if(isempty(s))
	{
		return 0;
	}
	x=*(s->a+s->top-1);
	if((x=='+'||x=='-')&&(b=='*'||b=='/'))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}	

//routine to return the postfix form of the expression...

char *infixtoPostfix(struct stack *s,char *a)
{
	int i,k=0,n;
	n=strlen(a);	
	char *postfix;
	postfix=(char *)malloc(sizeof(char)*n);
	for(i=0;i<n;i++)
	{
		//if it is a digit then push
		if(isdigit(a[i])==1)
		{
			postfix[k]=a[i];
			k++;
		}
		else
		{
			//if stack is empty then push
			if(isempty(s)==1)
			{
				push(s,a[i]);
			}
			else
			{
				//if the operation in the string has higher precdence than in stack then push..
				if(precedence(s,a[i])==0)
				{
					push(s,a[i]);
				}
				else
				{
					while(1)
					{
						//pop until lower precendence operator comes or its empty
						if(precedence(s,a[i])==0||isempty(s)==1)
						{
							push(s,a[i]);
							break;
						}
						postfix[k]=pop(s);
						k++;
					}
				}
			}
		}
	}
	//pop out element in the stack to the string..
	while(!isempty(s))
	{
		postfix[k]=pop(s);
		k++;
	}
	postfix[k]='\0';
	return postfix;
}	

//returning the result of the operation.......

int evaluate(int a,int b,char o)
{
	if(o=='+')
	{
		return a+b;
	}
	else if(o=='-')
	{
		return a-b;
	}+



	
	else if(o=='*')
	{
		return a*b;
	}
	else if(o=='/')
	{
		return a/b;
	}
}

//routine to return the value of the expression.....

int evaluateExp(struct stack *s,char *postfix)
{
	int i,n,a,b,result;
	n=strlen(postfix);
	for(i=0;i<n;i++)
	{
		if(isdigit(postfix[i]))
		{
			//pushing as ASCII value of the character to stack...
			push(s,(int)(postfix[i])-48);
		}
		else
		{
			char y=pop(s);
			char x=pop(s);
			char o=postfix[i];
			a=x;
			b=y;
			//typecast to char.....
			result=evaluate(a,b,o);
			char r =(char)result;
			push(s,result);
		}
	}
	return pop(s);	
}			
void main()
{
	struct stack *s;
	char a[100];
	int x;
	printf("Enter the infix :");
	scanf("%s",a);
	x=strlen(a);
	s=initialize(s,x);
	printf("\nThe postfix form:%s",infixtoPostfix(s,a));
	printf("\nThe Value of the Expression is %d",evaluateExp(s,infixtoPostfix(s,a)));
}
/*Output
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 4> gcc stackv2.c
-o a
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 4> ./a
Enter the infix :3*2+2*4

The postfix form:32*24*+
The Value of the Expression is 14
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 4> ./a
Enter the infix :6+7*5-2+6

The postfix form:675*+2-6+
The Value of the Expression is 45*/