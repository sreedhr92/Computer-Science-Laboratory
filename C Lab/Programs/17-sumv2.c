#include<stdio.h>
void main()
{
int N,sum=0,k,i=1;
printf("Enter the no. of inputs ");
scanf("%d",&N);
do
{
printf("Enter the number to add or press -999 to STOP :");
scanf("%d",&k);
if(k==-999)
break;
sum+=k;
i++;
}while(i<=N);
printf("%d is the sum of your inputs\n",sum);
}
 /*output :
Enter the no. of inputs:6
Enter the number to add or press -999 to STOP :6
Enter the number to add or press -999 to STOP :7
Enter the number to add or press -999 to STOP :5
Enter the number to add or press -999 to STOP :-8
Enter the number to add or press -999 to STOP :-999
10 is the sum of your inputs
*/