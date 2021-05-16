struct numberADT
{
	int size;
	int *a;
};
void insertElements(struct numberADT *n,int x[]);

int  linearsearch(struct numberADT *n,int key);

void sort(struct numberADT *n);

int  binarysearch(struct numberADT *n,int key);

void display(struct numberADT *n);
