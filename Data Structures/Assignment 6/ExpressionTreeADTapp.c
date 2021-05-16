#include"ExpressionTreeADTimpl.h"
void main()
{
	struct ExpTree *t;
	t=init();
	printf("\nEnter infix :");
	scanf("%s",t->infix);
	infixpostfix(t);
	postfixtoExptree(t);
	printf("\nPostfix :%s",t->postfix);
	printf("\nValue   :%d",t->value);

}
/*Output:
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 6> gcc ExpressionTreeADTapp.c -o a                                                                                   PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 6> ./a                      
Enter infix :3+4/2-6*8-2+5

Postfix :342/+68*-2-5+
Value   :-40*/