#include"stackimpl.h"
struct ExpTree* init()
{
	struct ExpTree *t;
	t=(struct ExpTree*)malloc(sizeof(struct ExpTree));
	t->p=initialize_node();
	t->s=initialize();
	return t;
}
void infixpostfix(struct ExpTree *t)
{
	int i,k=0,n=0;
	n=strlen(t->infix);
	for(i=0;i<n;i++)
	{
		//if it is a digit then push
		if(isdigit(t->infix[i]))
		{
			t->postfix[k]=t->infix[i];
			k++;
		}
		else
		{
			//if stack is empty then push
			if(isempty(t->s))
			{
				push(t->s,t->infix[i]);
			}
			else
			{
				//if the operation in the string has higher precdence than in stack then push..
				if(precedence(t->s,t->infix[i])==0)
				{
					push(t->s,t->infix[i]);
				}
				else
				{
					while(1)
					{
						//pop until lower precendence operator comes or its empty
						if(precedence(t->s,t->infix[i])==0||isempty(t->s)==1)
						{
							push(t->s,t->infix[i]);
							break;
						}
						t->postfix[k]=pop(t->s);
						k++;
					}
				}
			}
		}
	}
	//pop out element in the stack to the string..
	while(!isempty(t->s))
	{
		t->postfix[k]=pop(t->s);
		k++;
	}
	t->postfix[k]='\0';	
}	
int evaluation(struct node *t)
{
	char o;
	int x,y;
	if(t->right==NULL && t->left==NULL)
	{
		return ((int)t->x)-48;
	}	
	else
	{
		o=t->x;
		x=(int)evaluation(t->left);
		y=(int)evaluation(t->right);
		return evaluate(x,y,o);
	}
}

void postfixtoExptree(struct ExpTree *t)
{
	int i=0;
	struct node *n;
	while(t->postfix[i]!='\0')
	{
		if(isdigit(t->postfix[i]))
		{
			n=create(t->postfix[i]);
			push_node(t->p,n);
		}
		else
		{
			n=create(t->postfix[i]);
			n->right=pop_node(t->p);
			n->left=pop_node(t->p);
			push_node(t->p,n);
		}
		i++;
	}
	struct node *root=pop_node(t->p);
	t->value=evaluation(root);
}

