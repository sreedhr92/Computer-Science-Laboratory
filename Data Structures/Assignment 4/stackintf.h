struct stack
{
	int top;
	char *a;
	int capacity;
};

void push(struct stack *s,char x);

char pop(struct stack *s);

void display(struct stack *s);

struct stack * initialize(struct stack *s,int x);

int isempty(struct stack *s);

int isfull(struct stack *s);

char *infixtoPostfix(struct stack *s,char *a);

int evaluateExp(struct stack *s,char *postfix);