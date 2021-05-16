struct Employee
{
	int id;
	char name[100];
	float salary;
};

struct Pqueue
{
	struct Employee *a;
	int capacity,size;
};
