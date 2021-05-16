//creating a structure for the student consisting of his details...............
struct student
{
	int regno;
	char name[30];
	float marks=0;
	float marks2=0;
	float marks3=0;
	float total=0;
	char result='\0';
};

//creating a structure for listADT to contain the details of the students........
struct listADT
{
	struct student *a;
	int size,maxsize;
};

//function prototype for all the routines to be used..........
void initialize(struct listADT *l);

void insertfront(struct listADT *l,struct student s);

void insertend(struct listADT *l,struct student s);

void insertregno(struct listADt *l,struct student s,int regno);

struct student searchregno(struct listADT *l,int regno);

struct student *searchname(struct listADT *l,char name[]);

void deletestudent(struct listADT *l,int regno);

void computeresult(struct listADT *l);

struct student *listResult(struct listADT *l);

int listclass(struct listADT *l);
