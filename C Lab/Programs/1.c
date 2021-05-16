#include<stdio.h>
void main()
{
	float red,GP,NP,BP,DA,HRA,PF,pHRA,pDA,pPF,AGP;
	char a,b;
	printf("Enter the basic pay\n");
	scanf("%f",&BP);
	printf("Enter the Percentage of DA,PF\n");
	scanf("%f,%f",&pDA,&pPF);
	PF=pPF/100;
	//Getting city type...
	printf("Choose city type\n1.metro(R)\n2.Corporation(C)\n3.Taluk(T)\n");
	scanf("%s",&a);
	if(a=='R')
	pHRA=10;
	else if(a=='C')
	pHRA=8;
	else if(a=='T')
	pHRA=5;
	else
	printf("Error TRY Again\n");
	//Getting designation....
	printf("Enter your designation\n1.Worker(W)\n2.Engineer(E)\n3.Manager(M)\n");
	scanf("%s",&b);
	if(b=='W')
	AGP=1000;
	else if(b=='E')
	AGP=2000;
	else if(b=='M')
	AGP=5000;
	else
	printf("Error TRY Again");
	HRA=pHRA/100*BP;
	DA=pDA/100*BP;
	GP=BP+HRA+DA+AGP;
	printf("THE GROSS PAY is %f\n",GP);
	//reducting pf....
	red=PF*BP;
	NP=GP-red;
	printf("THE NET PAY is %f\n",NP);
}