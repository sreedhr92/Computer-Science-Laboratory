struct person
{
	int pin,age;
	char city[100];
	char name[30];
	char street[100];
	char sex[10];
};

struct personlist
{
	struct person t;
	struct personlist *lptr,*rptr;
};

struct ratio
{
	int male;
	int female;
}; 

struct personlist* header();

void insertfront(struct personlist *p,struct person x);

void display(struct personlist *p);

void sort(struct personlist *p);

struct ratio count(struct personlist *p);

void insertend(struct personlist *p,struct person x);

void insertafterpin(struct personlist *p,struct person x,int a);

void sort(struct personlist *p);

struct personlist *seniorperson(struct personlist *p);

struct personlist *locateperson(struct personlist *p,char s[]);

void display_1(struct personlist *p);