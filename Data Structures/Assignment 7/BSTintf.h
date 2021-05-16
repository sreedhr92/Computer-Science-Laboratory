struct player
{
	char name[100];
	char role[100];
	float avgrr;
};
struct tree
{
	struct player a;
	struct tree *left,*right;
};