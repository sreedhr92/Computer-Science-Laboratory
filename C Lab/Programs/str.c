#include<stdio.h>
#include<string.h>
void main()
{
	char a[100],b[100],c[100];
	int l,m,n,s,e,i=0,j=0,k=0,z=0,f,t,x,y;
	printf("Enter the Line of text :");
	gets(a);
	printf("Enter the string to be replaced :");
	gets(b);
	printf("Enter the replacement string :");
	gets(c);
	l=strlen(a);
	m=strlen(b);
	n=strlen(c);
	for(i=0;i<l;i++)
	{
		f=0;
		j=0;
		if(a[i]==b[j])
		{
			s=i;
			t=s;
			x=1;
			for(j=1;j<m;j++)
			{
				if(a[t+1]==b[j])
				{
					x++;
					t++;
				}			
			}
			if(x==m)
			{
				f=1;
				e=t;
			}
			if(f==1)
			{
				for(k=s;k<e;k++) 
				{
					for(z=s;z<l;z++)
						a[z]=a[z+1];	
					l--;
				}
				for(k=s;k<s+n;k++)    
				{
					for(z=l;z>=k;z--)
						a[z+1]=a[z];
					a[z]=c[z-s];
					l++;
				}
			}
		}
	}
	printf("\n%s",a);
}
