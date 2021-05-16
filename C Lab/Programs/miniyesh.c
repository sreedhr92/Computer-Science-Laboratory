#include<stdio.h>
#include<string.h>
#include<time.h>
struct ddate
{
	int day,month,year,hrs,mins,sec;
	char day_[9],month_[10];

};
void main()
{
struct ddate details(char z[24]);
struct ddate dd;
time_t t;
time(&t);
char z[24];
sprintf(z,"%s",ctime(&t));
dd=details(z);
printf("%s",z);
printf("the date is %d/%d/%d,the time is %d:%d:%d",dd.day,dd.month,dd.year,dd.hrs,dd.mins,dd.sec);
}
struct ddate details(char z[24])
{
struct ddate kk;
int i=0;
char v[3],m[3];
for(i=0;i<3;i++)
v[i]=z[i];
if(strcmp(v,"Mon")==0)
	strcpy(kk.day_,"Monday");
else if(strcmp(v,"Tue")==0)
	strcpy(kk.day_,"Tuesday");
else if(strcmp(v,"Wed")==0)
	strcpy(kk.day_,"Wednesday");
else if(strcmp(v,"Thu")==0)
	strcpy(kk.day_,"Thursday");
else if(strcmp(v,"Fri")==0)
	strcpy(kk.day_,"Friday");
else if(strcmp(v,"Sat")==0)
	strcpy(kk.day_,"Saturday");
else if(strcmp(v,"Sun")==0)
	strcpy(kk.day_,"Sunday");
int k=0;
for(i=4;i<7;i++)
	{
		m[k]=z[i];
		k++;
	}
if(strcmp(m,"Jan")==0)
	{
		strcpy(kk.month_,"January");
		kk.month=1;
	}
if(strcmp(m,"Feb")==0)
	{
		strcpy(kk.month_,"February");
		kk.month=2;
	}
if(strcmp(m,"Mar")==0)
	{
		strcpy(kk.month_,"March");
		kk.month=3;
	}
if(strcmp(m,"Apr")==0)
	{
		strcpy(kk.month_,"April");
		kk.month=4;
	}	
if(strcmp(m,"May")==0)
	{
		strcpy(kk.month_,"May");
		kk.month=5;
	}	
if(strcmp(m,"Jun")==0)
	{
		strcpy(kk.month_,"June");
		kk.month=6;
	}	
if(strcmp(m,"Jul")==0)
	{
		strcpy(kk.month_,"July");
		kk.month=7;
	}	
if(strcmp(m,"Aug")==0)
	{
		strcpy(kk.month_,"August");
		kk.month=8;
	}	
if(strcmp(m,"Sep")==0)
	{
		strcpy(kk.month_,"September");
		kk.month=9;
	}	
if(strcmp(m,"Oct")==0)
	{
		strcpy(kk.month_,"October");
		kk.month=10;
	}	
if(strcmp(m,"Nev")==0)
	{
		strcpy(kk.month_,"November");
		kk.month=11;
	}	
if(strcmp(m,"Dec")==0)
	{
		strcpy(kk.month_,"December");
		kk.month=12;
	}	
int s=0,c=0,l=0,n=0,o=0;
s+=z[8]-48;
s*=10;
s+=z[9]-48;
kk.day=s;
c+=(z[20]-48)*1000+(z[21]-48)*100+(z[22]-48)*10+(z[23]-48);
kk.year=c;
l+=z[11]-48;
l*=10;
l+=z[12]-48;
kk.hrs=l;
n+=z[14]-48;
n*=10;
n+=z[15]-48;
kk.mins=n;
o+=z[17]-48;
o*=10;
o+=z[18]-48;
kk.sec=o;
return kk;
}