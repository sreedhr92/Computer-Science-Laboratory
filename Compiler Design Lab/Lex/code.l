%{ 
#include<stdio.h> 
#include<string.h> 
%} 


/* Rules Section*/
%% 
0-9  {printf("DIGIT ");} 
%% 


int yywrap(void) {}

int main() 
{
    // The function that starts the analysis 
    yylex();
    return 0; 
}