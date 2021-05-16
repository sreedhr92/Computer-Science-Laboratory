struct Pqueue* init(int x)
{
	struct Pqueue *q;
	q=(struct Pqueue*)malloc(sizeof(struct Pqueue));
	q->capacity=x;
	q->size=0;
	q->a=(struct Employee*)malloc(sizeof(struct Employee)*x);
	q->a[0].salary=-1;
	return q;
}

void insert(struct Pqueue *q,struct Employee x)
{
	int i;
	for(i=++q->size;q->a[i/2].salary>x.salary;i/=2)
		q->a[i]=q->a[i/2];
	q->a[i]=x;
}

struct Employee deletemin(struct Pqueue *q)
{
	int i,child;
	struct Employee min,last;
	min=q->a[1];
	last=q->a[q->size--];
	for(i=1;i*2<=q->size;i=child)
	{
		child=i*2;
		if(q->a[child+1].salary<q->a[child].salary)
			child++;
	 	if(last.salary>q->a[child].salary)
	 		q->a[i]=q->a[child];
	 	else
	 		break;
	 }
	 q->a[i]=last;
	 return min;					
}
void ptab(int x)
{
	int i;
	for(i=0;i<x;i++)
		printf("\t");
}
void display_emp(struct Employee e,int tab)
{
	ptab(tab);
	printf("%s\n",e.name);
	ptab(tab);
	printf("%f\n",e.salary);
	ptab(tab);
	printf("%d\n\n",e.id);
}	
		
void display(struct Pqueue *q,int x,int tab)
{
	display_emp(q->a[x],tab);
	if(x*2<=q->size)
	{
		display(q,x*2,tab+1);
	}
	if((x*2+1)<=q->size)
	{
		display(q,(x*2+1),tab+1);
	}	
}	
/*Output:
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 8> gcc priorityqueueADTapp.c -o a
PS F:\Study\SSN\3rd Sem\Data structure\Assignment\Assignment 8> ./a
Enter Capacity :10

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :1
Enter the name :Sreedhar
Enter id       :1
Enter Salary   :9090

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :1
Enter the name :Gia
Enter id       :2
Enter Salary   :7873

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :1
Enter the name :loki
Enter id       :99
Enter Salary   :9133

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :1
Enter the name :Foana
Enter id       :72
Enter Salary   :6242

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :1
Enter the name :Jiuf
Enter id       :88
Enter Salary   :7432

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :1
Enter the name :Daia
Enter id       :44
Enter Salary   :3000

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :3
Daia
3000.000000
44
        Jiuf
        7432.000000
        88
                Sreedhar
                9090.000000
                1
                Gia
                7873.000000
                2
        Foana
        6242.000000
        72
                loki
                9133.000000
                99

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :2
Daia
3000.000000
44

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :3
Foana
6242.000000
72
        Jiuf
        7432.000000
        88
                Sreedhar
                9090.000000
                1
                Gia
                7873.000000
                2
        loki
        9133.000000
        99

1.Insert
2.Delete
3.Display
4.Exit
Enter choice :4

Exiting Thank you...
*/


