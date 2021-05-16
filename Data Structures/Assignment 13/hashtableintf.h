struct node
{
	int data;
	struct node *next;
};

struct hashtable
{
	int s;
	struct node *list[100];
};

