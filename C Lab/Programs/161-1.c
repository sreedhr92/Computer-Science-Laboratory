#include<stdio.h>
void sort()
void main()
{
	int n;
	printf("Enter the number of passengers :");
	scanf("%d",&n);
	char name[n][30],source[n][30],desti[n][30];
	int age[n],dob[n],doj[n],id[n];
	float ticket[n];
	printf("\n\nRailway Reservation system :\n\n");
	for(i=0;i<n;i++)
	{
		printf("Passenger %d's Details\n\n ")
		printf("Enter the Name                                   :");
		scanf("%s",&name[i]);
		printf("Enter the Id                                     :");
		scanf("%d",&id[i]);
		printf("Enter the Age                                    :");
		scanf("%d",&age[i]);
		printf("Enter the Date of birth  (in the format ddmmyy)  :");
		scanf("%d",&dob[i]);
		printf("Enter the Date of jourey (in the format ddmmyy)  :");
		scanf("%d",&doj[i]);
		printf("Enter the source place                           :");
		scanf("%s",&source[i]);
		printf("Enter the destination place                      :");
		scanf("%s",&desti[i]);
		printf("Enter the ticket amount                          :");
		scanf("%f",&ticket[i]);
		printf("\n\n");
	}
	for(i=0;i<n;i++)
	{
		printf("Passenger %d's Details :\n")
		printf("Name        :%s",name[i]);
		printf("Id          :%d",id[i]);
		printf("Age         :%d",age[i]);
		printf("DOB         :%d",dob[i]);
		printf("DOJ   	    :%d",doj[i]);
		printf("Source      :%s",source[i]);
		printf("Destination :%s",desti[i]);
		printf("Ticket      :%f",&ticket[i]);
		printf("\n\n");
	}

