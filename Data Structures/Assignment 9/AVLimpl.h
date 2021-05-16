int height(struct AVLtree *t)
{
	if(t==NULL)
		return -1;
	else
		return t->height;
}
int max(int a,int b)
{
	if(a<b)
		return b;
	else 
		return a;
}
struct AVLtree* singlerotateleft(struct AVLtree *k2)
{
	struct AVLtree *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),height(k1->right))+1;
	return k1;
}

struct AVLtree* singlerotateright(struct AVLtree *k2)
{
	struct AVLtree *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),height(k1->right))+1;
	return k1;
}

struct AVLtree* doublerotateleft(struct AVLtree *k3)
{
	k3->left=singlerotateright(k3->left);

	return singlerotateleft(k3);
}

struct AVLtree* doublerotateright(struct AVLtree *k3)
{
	k3->left=singlerotateleft(k3->right);

	return singlerotateright(k3);
}
struct AVLtree* insert(struct AVLtree *t,struct wordMeaning x)
{
	int height_diff;
	if(t==NULL)
	{
		t=(struct AVLtree*)malloc(sizeof(struct AVLtree));
		t->a=x;
		t->left=NULL;
		t->right=NULL;
		return t;
	}
	else if(strcmp(t->a.word,x.word)==1)
	{
		t->left=insert(t->left,x);
		height_diff=height(t->left)-height(t->right);
		if(height_diff<0)
			height_diff=height_diff*(-1);
		if(height_diff==2)
		{
			if(strcmp(t->left->a.word,x.word)==1)
				t=singlerotateleft(t);
			else
				t=doublerotateleft(t);
		}
	}
	else if(strcmp(t->a.word,x.word)==-1)
	{
		t->right=insert(t->right,x);
		height_diff=height(t->left)-height(t->right);
		if(height_diff<0)
			height_diff=height_diff*-1;
		if(height_diff==2)
		{
			if(strcmp(t->right->a.word,x.word)==-1)
				t=singlerotateright(t);
			else
				t=doublerotateright(t);
		}
	}
	t->height=max(height(t->left),height(t->right)+1);
	return t;
}


void printtabs(int depth)
{
	for(int i=0;i<depth;i++)
		printf("\t");
}
void display(struct AVLtree *t,int depth)
{
	if(t!=NULL)
	{
		printtabs(depth);
		printf("%s\n",t->a.word);
		display(t->left,depth+1);	
		display(t->right,depth+1);
	}
}
struct wordMeaning search(struct AVLtree *t,char name[])
{
	if(t==NULL)
		{
			printf("Empty tree");
			struct wordMeaning x;
			strcpy(x.word,"empty");
			return x;
		}
	else if(strcmp(t->a.word,name)==1)
		return search(t->left,name);
	else if(strcmp(t->a.word,name)==-1)
		return search(t->right,name);
	else if(strcmp(t->a.word,name)==0)
		return t->a;
}
void display_word(struct wordMeaning x)
{
	printf("\nWord    :%s\n",x.word);
	printf("\nMeaning :%s\n",x.meaning);
}