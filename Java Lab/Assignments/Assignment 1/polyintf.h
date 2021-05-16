struct term
{
	int coeff;
	int expo;
};
struct poly
{
	struct term r;
	struct poly *next;
};