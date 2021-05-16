#include<stdio.h>
#include<string.h>
void main()
{
		int i,j,n;
		printf("Enter the No. of students :");
		scanf("%d",&n);
		char name[n][50],temp[50];
		char a[n][50];
		for(i=0;i<n;i++)
		{
			printf("Enter the name :");
			scanf("%s",&name[i]);
		}	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)

			if(strcmp(name[j],name[j+1])>0)
			{
				strcpy(temp,name[j+1]);
				strcpy(name[j+1],name[j]);
				strcpy(name[j+1],temp);
			}					
		}
		printf("Output :\n");
		for(i=0;i<n;i++)
		{
			printf("%s  ",name[i]);
		}

}