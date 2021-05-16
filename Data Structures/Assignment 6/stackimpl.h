#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ExpressionTreeADTintf.h"
//initialize the stack..........
struct stack * initialize()
{
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->capacity=100;
	s->top=0;
	return s;
}

struct nodestack * initialize_node()
{
	struct nodestack *ns;
	ns=(struct nodestack*)malloc(sizeof(struct nodestack));
	ns->capacity=100;
	ns->top=0;
	return ns;
}
//routine to add a element to the stack......
void push(struct stack *s,char x)
{
	if(isfull(s)==1)
		printf("\nThe stack is full\n");
	else
		{s->a[s->top]=x;s->top++;}
}

void push_node(struct nodestack *ns,struct node *x)
{
	if(isfull_node(ns)==1)
		printf("\nThe stack is full\n");
	else
		{ns->a[ns->top]=x;ns->top++;}
}

//routine to pop out the top element of the stack.....
char pop(struct stack *s)
{
	if(isempty(s)==1)
		{printf("\nThe stack is empty\n");return '\0';}
	else
		{s->top--;return s->a[s->top];}
}
struct node* pop_node(struct nodestack *ns)
{
	if(isempty_node(ns)==1)
		{printf("\nThe stack is empty\n");return '\0';}
	else
		{ns->top--;return ns->a[ns->top];}
}
//display routine........
void display(struct stack *s)
{
	int i;
	for(i=s->top-1;i>=0;i--)
		printf("%c\n",s->a[i]);
}
//checks whether empty or not......
int isempty(struct stack *s)
{
	if(s->top==0)
		return 1;
	else
		return 0;
}
//checks whether full or not........
int isfull(struct stack *s)
{
	if(s->top==s->capacity)
		return 1;
	else
		return 0;
}

int isempty_node(struct nodestack *ns)
{
	if(ns->top==0)
		return 1;
	else
		return 0;
}

int isfull_node(struct nodestack *ns)
{
	if(ns->top==ns->capacity)
		return 1;
	else
		return 0;
}
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
int evaluate(int a,int b,char o)
{
	if(o=='+')
	{
		return a+b;
	}
	else if(o=='-')
	{
		return a-b;
	}
	else if(o=='*')
	{
		return a*b;
	}
	else if(o=='/')
	{
		return a/b;
	}
}
struct node *create(char a)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->x=a;
	n->left=NULL;
	n->right=NULL;
	return n;
}


