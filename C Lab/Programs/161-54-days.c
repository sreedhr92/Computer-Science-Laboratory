
#include<stdio.h>
#include<stdlib.h>
long convert(int mm,int dd,int yy);
void main()
{
	long *a,*b,j,k;
	int *m,*y,*d,mm,yy,dd;
	a=&j;
	b=&k;
	m=&mm;
	y=&yy;
	d=&dd;
	printf("enter 1st date dd /mm /yy:");
	scanf("%d%d%d",d,m,y);
	*a=convert(*m,*d,*y);
	printf("enter 2nd date dd /mm /yy:");
	scanf("%d%d%d",d,m,y);
	*b=convert(*m,*d,*y);
	int c=*b-*a;
	if(c>0)
	printf("days=%d",c);
	else
	printf("days=%d",-1*c);
	
}

long convert(int mm,int dd,int yy)
{
	long ndays;
	long ncycles;
	int nyears;
	int day;
	yy-=1900;
	ndays=(long)(30.42*(mm-1))+dd;
	if(mm==2)
	++ndays;
	if((mm>2)&(mm<8))
	--ndays;
	if((yy%4==0)&&mm>2)
	++ndays;
	ncycles=yy/4;
	ndays+=ncycles*1461;
	nyears=yy%4;
	if(nyears>0)
	ndays+=365*nyears+1;
	if(ndays>59)
	--ndays;
	return ndays;
}
/*Output:
enter 1st date dd /mm /yy:18 08 2000
enter 2nd date dd /mm /yy:21 03 2019
days=6789*/
