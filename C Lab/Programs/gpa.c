#include<stdio.h>
#include<string.h>
void main()
{
	int i=0,k=0,s,j;
	float b[5][100],temp;
	char a[200][100],t[100];
	do
	{
		printf("Enter the name :");
		scanf("%s",&a[i]);
		i++;
		k++;
		check:
		printf("Do you want to continue..press 1 to stop 0 :");
		scanf("%d",&s);
		if((s!=1)&&(s!=0))
		{
			printf("Invalid Input :\n" );
			goto check;
		}
	}while(s!=0);
	float g[k];
	printf("The names are:\n");
	for(i=0;i<k;i++)
	{
		printf("%d.%s\n",i+1,a[i]);
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("Enter the test(%d) mark(for 100) of %s :",j+1,a[i]);
			scanf("%f",&b[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<k;i++)
	{
		float sum=0;
		for(j=0;j<5;j++)
		{
			sum+=b[i][j];
			if(j==4)
			{
				sum/=50;
				g[i]=sum;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%.2f is the gpa of %s\n",g[i],a[i]);
	}	
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(g[i]<g[j])
			{
				temp=g[i];
				g[i]=g[j];
				g[j]=temp;
				strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
			}
		}
	}
	printf("\n");
	for(i=0;i<k;i++)
	{
		k=i;
		for(j=0;j<k;j++)
		{
			if(i==j){continue;}
		if(g[i]==g[j])
		{	
			printf("%-10s  %.2f is Rank %d \n",a[i],g[i],k+1);
			printf("%-10s  %.2f is Rank %d \n",a[i+1],g[i+1],k+1);
			k++;
		}	
		else
		{
			printf("%.2f is rank %d \n",g[k],k);	
		}
		}
	}	
}	

	