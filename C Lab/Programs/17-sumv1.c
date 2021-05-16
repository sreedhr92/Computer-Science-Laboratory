#include<stdio.h>
void main()
{
int i,sum=0,N,k;
printf("Enter the no of inputs :");
scanf("%d",&N);
for(i=1;i<=N;i++)
{
   printf("Enter the input :");
   scanf("%d",&k);
   sum+=k;
}
printf("%d is the sum of your inputs",sum);
}
/*Enter the no of inputs :4
Enter the input :1
Enter the input :2
Enter the input :3
Enter the input :4
10 is the sum of your inputs*/