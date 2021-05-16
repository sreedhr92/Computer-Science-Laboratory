#include<stdio.h>
void main()
{float fact=1;
 int i,n;
 printf("enter the number :");
 scanf("%d",&n);
 for(i=2;i<=n;i++)
 {
 	fact*=i;

 }
 printf("%f",fact);	
}