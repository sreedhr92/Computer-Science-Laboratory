struct stack
{
	int top;
	char a[100];
	int capacity;
};
struct node
{
	char x;
	struct node *left,*right;
}; 
struct nodestack
{
	int top;
	struct node *a[100];
	int capacity;
};
void push(struct stack *s,char x);

char pop(struct stack *s);

void display(struct stack *s);

struct stack * initialize();

struct nodestack * initialize_node();

int isempty(struct stack *s);

int isfull(struct stack *s);

int isempty_node(struct nodestack *s);

int isfull_node(struct nodestack *s);

char *infixtoPostfix(struct stack *s,char *a);

int evaluateExp(struct stack *s,char *postfix);

void push_node(struct nodestack *ns,struct node *x);

struct node* pop_node(struct nodestack *ns);