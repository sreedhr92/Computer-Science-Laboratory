#include<stdio.h>
void main()
{
int N,sum=0,i=1,k;char h;
printf("Enter the no. of inputs :");
scanf("%d",&N);
do
{
printf("Enter the +ve number below 100 to add :");
scanf("%d",&k);
if(k<100 && k>0)
sum+=k;
else
{
	printf("INVALID INPUT PROCESS TERMINIATED\n");
	break;
}
printf("To continue press 'y' or to stop press 'n' :");
scanf("%s",&h);
if(h=='n')
break;
i++;
}while(i<=N);
printf("%d is the sum of your inputs\n",sum);
}
/*Output:
Enter the no. of inputs :5
Enter the +ve number below 100 to add :5
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :3
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :8
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :-8
INVALID INPUT PROCESS TERMINIATED
16 is the sum of your inputs*/