#include<stdio.h>
#include<string.h>
typedef struct student
{
	char name[30],place[30],gender[30];
	int age,dob,id;
	float score;
};
void histogram( student stu[],int n);
void main()
{
	int i,n;
	printf("Enter the number of students :");
	scanf("%d",&n);
    student stu[n];
	for(i=0;i<n;i++)
	{
		//printf("Student %d's Details\n\n ");
		printf("\n Enter the Name : ");
		scanf("%s",stu[i].name);
		/*printf("Enter the Id                                     :");
		scanf("%d",&stu[i].id);
		printf("Enter the Age                                    :");
		scanf("%d",&stu[i].age);
		printf("Enter the Gender                                 :");
		scanf("%s",&stu[i].gender);
		printf("Enter the Date of birth  (in the format ddmmyy)  :");
		scanf("%d",&stu[i].dob);*/
		printf("\n Enter the place : ");
		scanf("%s",stu[i].place);
		//printf("Enter the score                                  :");
		//scanf("%f",&stu[i].score);
		printf("\n\n");
	}
	histogram(stu,n);
}
void histogram(struct student stu[],int n)
{
	int i,j,k=0,c[10];
	char region[10][30],t[30];
	for(i=0;i<n;i++)
	{
		if(strcmp(stu[i].place,"#")==0)
		{
			i--;
			continue;
		}	
		c[i]=1;
		strcpy(t,stu[i].place);
		strcpy(region[k],t);
		k++;
		for(j=i+1;j<n;j++)
			
		{
			if(strcmp(t,stu[j].place)==0)
			{
				c[i]+=1;
				strcpy(stu[j].place,"\0");
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(region[i],"\0")==0)
		{
			strcpy(t,region[i+1]);
			strcpy(region[i+1],region[i]);
			strcpy(region[i],t);
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(region[i],"\0")!=0)
		{
			k++;
		}
	}	
	FILE *fp;
	fp=fopen("Output.txt","w");		
	for(i=0;i<k;i++)
	{
		fprintf(fp,"\n Region           : %s",region[i]);
		fprintf(fp,"\n No. of students  : %d",c[i]);
	}
	fclose(fp);
}
