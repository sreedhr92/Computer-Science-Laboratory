struct job
{
	char name;
	int cputime;
};
struct queue 
{
	int front,rear,capacity,size;
	struct job *a;
};

