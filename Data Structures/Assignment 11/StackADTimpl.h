struct stack* initstack()
{
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->top=0;
	s->capacity=100;
	//s->a=(char *)malloc(sizeof(char)*x);
	return s;
}
int isEmpty(struct stack *s)
{
	if(s->top==0)
		return 1;
	else
 		return 0;
}
int isFull(struct stack *s)
{
	if(s->top==s->capacity)
		return 1;
	else 	
		return 0;
}
void push(struct stack *s,char x[])
{
	if(isFull(s))
		printf("\n");
	else
	{	
		strcpy(s->a[s->top],x);
		s->top++;
		//printf("\nPushed!!");
	}
}
char* pop(struct stack *s)
{
	if(isEmpty(s))
		{printf("");return '\0';}
	else
	{
		s->top--;
	//	printf("\nElement poped out of the stack is ");
		return s->a[s->top];	
	}
}
char* peek(struct stack *s)
{
	return s->a[(s->top)-1];
}
	
					 					
