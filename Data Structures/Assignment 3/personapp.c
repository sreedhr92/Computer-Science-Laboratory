#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"personintf.h"
#include"personimpl.h"
struct person input()
{
	struct person temp;
	printf("\nEnter the name   :");
	scanf("%s",temp.name);
	printf("Enter the age    :");
	scanf("%d",&temp.age);
	printf("Enter the city   :");
	scanf("%s",temp.city);
	printf("Enter the street :");
	scanf("%s",temp.street);
	printf("Enter the sex    :");
	scanf("%s",temp.sex);
	srand(time(0));
	temp.pin=rand()%9000+1000;
	printf("Your PIN is %d",temp.pin);
	return temp;
}
void main()
{
	struct person x;
	struct personlist *p;
	p=header();
	int k=0,o;
	char a;
	do{
	printf("\n1.Input\n2.Senior persons\n3.Persons on given location\n4.Sort according to age\n5.Display the list\n6.Male & Female Ratio\n7.Exit\nEnter the option:");
	scanf("%d",&o);
	if(o==1){
	printf("\nEnter the details of the person");
	do
	{
		if(k==0)
		{
			printf("\nPerson %d :\n",k+1);
			x=input();
			insertfront(p,x);
			printf("\nInserted successfully!\nDo you want to insert more(y/n):");
			scanf("%s",&a);
			k++;
		}
		printf("\nPerson %d :\n",k+1);
		x=input();
		printf("\n1.Insert at front\n2.Insert at end\n3.Insert after a PIN\nEnter the option:");
		scanf("%d",&o);
		if(o==1)
		{
			insertfront(p,x);
		}
		else if(o==2)
		{
			insertend(p,x);
		}	
		else if(o==3)
		{
			int pin;
			printf("\nEnter the PIN:");
			scanf("%d",&pin);
			insertafterpin(p,x,pin);
		}
		printf("\nInserted successfully!\nDo you want to insert more(y/n):");
		scanf("%s",&a);
		k++;
	}while(a!='n');}
	else if(o==2)
	{
		struct personlist *senior;
		senior=seniorperson(p);
		printf("\nThe senior persons are:\n");
		display(senior);
	}
	else if(o==3)
	{
		char s[30];
		struct personlist *locate;
		printf("\nEnter the Locate :");
		scanf("%s",&s);
		locate=locateperson(p,s);
		printf("\nThe person in the given location are:\n");
		display(locate);
	}
	else if(o==4)
	{
		sort(p);
		printf("\nThe sorted order according to age :\n");
		display(p);
	}
	else if(o==5)
	{
		display_1(p);
	}
	else if(o==6)
	{
		struct ratio k;
		k=count(p);
		printf("\nThe ratio is %d:%d\n",k.male,k.female);
	}
	else
	{
		printf("\nEnter Invalid option\n");
	}
	}while(o!=7);
}	
