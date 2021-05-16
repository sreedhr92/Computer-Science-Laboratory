//initialize the stack..........
struct stack * initialize(struct stack *s,int x)
{
	s=(struct stack*)malloc(sizeof(struct stack));
	s->capacity=x;
	s->top=0;
	s->a=(char *)malloc(sizeof(char) * x);
	return s;
}
//routine to add a element to the stack......
void push(struct stack *s,char x)
{
	if(isfull(s)==1)
		printf("\nThe stack is full\n");
	else
		{s->a[s->top]=x;s->top++;}
}

//routine to pop out the top element of the stack.....
char pop(struct stack *s)
{
	if(isempty(s)==1)
		{printf("\nThe stack is empty\n");return '\0';}
	else
		{s->top--;return s->a[s->top];}
}

//display routine........
void display(struct stack *s)
{
	int i;
	for(i=s->top-1;i>=0;i--)
		printf("%c\n",s->a[i]);
}
//checks whether empty or not......
int isempty(struct stack *s)
{
	if(s->top==0)
		return 1;
	else
		return 0;
}
//checks whether full or not........
int isfull(struct stack *s)
{
	if(s->top==s->capacity)
		return 1;
	else
		return 0;
}

