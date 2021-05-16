struct wordMeaning 
{
	char word[100];
	char meaning[100];
};
struct AVLtree 
{
	struct wordMeaning a;
	struct AVLtree *left,*right;
	int height;
};