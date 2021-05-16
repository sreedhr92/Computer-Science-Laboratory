#include"stackintf.h"
struct ExpTree
{
	char infix[100];
	char postfix[100];
	int value;
	struct nodestack *p;
	struct stack *s;
};
