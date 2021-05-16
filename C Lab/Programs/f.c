#include<stdio.h>
void main()
{
	int A = 3;
	int B; int *P = &A; int *Q = P; int *R = &B;
	printf(“Enter value:“); scanf(“%d”,R); printf(“%d %d\n”,A,B); printf(“%d %d %d\n”,   *P,*Q,*R); 
	int B; int *P = &A; int *Q = P; int *R = &B; 
 
Q = &B; if (P == Q)   printf(“1\n”); if (Q == R)   printf(“2\n”); if (*P == *Q)   printf(“3\n”); if (*Q == *R)   printf(“4\n”); if (*P == *R)   printf(“5\n”);  	
}