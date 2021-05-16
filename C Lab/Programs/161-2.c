#include<stdio.h>
#include<stdlib.h>
struct passenger 
{
	char name[30],source[30],desti[30];
	int age,dob,doj,id;
	float ticket;
};
void read(struct passenger *ptr,int n);
void write(struct passenger *ptr,int n);
void main()
{
	int n;
	printf("Enter the number of passengers :");
	scanf("%d",&n);
	struct passenger pass[n];
	struct passenger *ptr;
	ptr=(struct passenger*)malloc(n*sizeof(struct passenger));
	printf("\n\nRailway Reservation system :\n\n");
	read(ptr,n);
	write(ptr,n);
}
void read(struct passenger *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		printf("Passenger %d's Details\n\n",i+1);
		printf("Enter the Name                                   :");
		scanf("%s",ptr->name);
		printf("Enter the Id                                     :");
		scanf("%d",&ptr->id);
		printf("Enter the Age                                    :");
		scanf("%d",&ptr->age);
		printf("Enter the Date of birth  (in the format ddmmyy)  :");
		scanf("%d",&ptr->dob);
		printf("Enter the Date of jourey (in the format ddmmyy)  :");
		scanf("%d",&ptr->doj);
		printf("Enter the source place                           :");
		scanf("%s",ptr->source);
		printf("Enter the destination place                      :");
		scanf("%s",ptr->desti);
		printf("Enter the ticket amount                          :");
		scanf("%f",&ptr->ticket);
		ptr++;
		printf("\n\n");
	}
}	
void write(struct passenger *ptr,int n)
{
	int i;
	for(i=0;i<n;i++,ptr++)
	{
			printf("Passenger %d's Details :\n",i+1);
			printf("Name        :%s\n",ptr->name);
			printf("Id          :%d\n",ptr->id);
			printf("Age         :%d\n",ptr->age);
			printf("DOB         :%d\n",ptr->dob);
			printf("DOJ   	    :%d\n",ptr->doj);
			printf("Source      :%s\n",ptr->source);
			printf("Destination :%s\n",ptr->desti);
			printf("Ticket      :%.2f\n",ptr->ticket);
			printf("\n\n");
	}
}
