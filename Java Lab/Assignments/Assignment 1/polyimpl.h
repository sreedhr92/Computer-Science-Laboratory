#include"polyintf.h"
#include<stdlib.h>
struct poly *header()
{
	struct poly *temp;
	temp=(struct poly*)malloc(sizeof(struct poly));
	temp->next=NULL;
	return temp;
}
void insert(struct poly *p,struct term x)
{
	struct poly *temp;
	temp=(struct poly*)malloc(sizeof(struct poly));
	temp->r=x;
	temp->next=p->next;
	p->next=temp;
}
void display(struct poly *p)
{
	struct poly *temp;
	temp=(struct poly*)malloc(sizeof(struct poly));
	temp=p->next;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%dX^%d ",temp->r.coeff,temp->r.expo);
		if(temp->next!=NULL)
		{
			printf("+ ");
		}
		temp=temp->next;
	}
}
struct poly *simplify(struct poly *p)
{
	struct poly *term,*t,*result;
	struct term s;
	temp=(struct poly*)malloc(sizeof(struct poly));
	temp=p->next;
	t=p->next;
	result=header();
	while(temp!NULL)
	{
		t=t->next;
		if(temp->r.expo==t->r.expo)
		{
			s.coeff = (temp->r.coeff) + (t->r.coff);
			s.expo = temp->r.expo;
			insert(result,s);
		}
		else
		{
			insert(result,temp->r);
		}
	}
	return result;
}