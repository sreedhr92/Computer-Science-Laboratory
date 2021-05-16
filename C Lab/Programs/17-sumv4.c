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
Enter the +ve number below 100 to add :2
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :-2
To continue press 'y' or to stop press 'n' :y
Enter the +ve number below 100 to add :107
To continue press 'y' or to stop press 'n' :n
2 is the sum of your inputs*/