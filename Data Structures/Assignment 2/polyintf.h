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
struct poly *header();
void insertfront(struct poly *p,struct term x);
void insertend(struct poly *p,struct term x);
void insertafter(struct poly *p,struct term x,int exp);
void display(struct poly *p);
int maxepo(struct poly *p);
int evaluate(struct poly *p,int x);
void simplify(struct poly *p);
void add(struct poly *p1,struct poly *p2);
void multiply(struct poly *p1,struct poly *p2);
