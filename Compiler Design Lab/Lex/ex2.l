%{ 
#include<stdio.h> 
#include<string.h> 
int i = 0;
int j = 0;
%} 
digit [-]?[0-9]+
/* Rules Section*/
%% 
[0] {printf("\nCount = %d\n",i); return 0;}
{digit} {if(atoi(yytext)>0)i++;}
%% 
int yywrap(void){} 
  
int main() 
{    
    // The function that starts the analysis
    yylex();
    return 0; 
}