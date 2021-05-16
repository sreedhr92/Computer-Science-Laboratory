#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"BSTintf.h"
struct tree* insert(struct tree *t,struct player x)
{
	if(t==NULL)
	{
		t=(struct tree*)malloc(sizeof(struct tree));
		t->a=x;
		t->left;
		t->right;
	}
	else if(strcmp(t->a.name,x.name)==1)
	{
		t->left=insert(t->left,x);
	}
	else if(strcmp(t->a.name,x.name)==-1)
	{
		t->right=insert(t->right,x);
	}
	return t;
}
struct player search(struct tree *t,char name[])
{
	if(t==NULL)
		{
			printf("Empty tree");
			struct player x;
			strcpy(x.name,"empty");
			return x;
		}
	else if(strcmp(t->a.name,name)==1)
		return search(t->left,name);
	else if(strcmp(t->a.name,name)==-1)
		return search(t->right,name);
	else if(strcmp(t->a.name,name)==0)
		return t->a;
}

struct tree* findmin(struct tree *t)
{
	if(t==NULL)
		return NULL;
	while(t->left!=NULL)
		t=t->left;
	return t;
}
struct tree* findmax(struct tree *t)
{
	if(t==NULL)
		return NULL;
	while(t->right!=NULL)
		t=t->right;
	return t;
}
struct tree* deletetree(struct tree *t,char name[])
{
	struct tree *temp;
	if(strcmp(t->a.name,name)==1)
		t->left=deletetree(t->left,name);
	else if(strcmp(t->a.name,name)==-1)
		t->right=deletetree(t->right,name);
	else if(t->left&&t->right)
	{
		temp=findmin(t->right);
		t->a=temp->a;
		t->right=deletetree(t->right,t->a.name);
	}
	else
	{
		temp=t;
		if(t->right==NULL)
			t=t->left;
		else  if(t->left==NULL)
			t=t->right;
		free(temp);
		return t;
	}		
}
void display_node(struct player t)
{
	printf("\nName   : %s\n",t.name);
	printf("\nAvgrr  : %f\n",t.avgrr);
	printf("\nRole   : %s\n",t.role);
}
void printtabs(int depth)
{
	int i;
	for(i=0;i<depth;i++)
		printf("\t");
}
void display_tree(struct tree *t,int depth)
{
	if(t!=NULL)
	{
		printtabs(depth);
		printf("%s\n",t->a.name);
		display_tree(t->left,depth+1);
	/*}	
	if(t!=NULL)
	{
		printtabs(depth);
		printf("%s\n",t->a.name);*/
		display_tree(t->right,depth+1);
	}
}
void inorder(struct tree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		display_node(t->a);
		inorder(t->right);
	}	
}
void preorder(struct tree *t)
{
	if(t!=NULL)
	{
		display_node(t->a);
		preorder(t->left);
		preorder(t->right);
	}
}
void postorder(struct tree *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);	}
}
struct player input()
{
	struct player x;
	printf("\nEnter player Name  :");
	scanf("%s",x.name);
	printf("\nEnter player Role  :");
	scanf("%s",x.role);
	printf("\nEnter player Avgrr :");
	scanf("%f",&x.avgrr);
	return x;
}

