%{
#include "calc.tab.h"
#include <stdio.h>
#include<string.h>
void yyerror(char *);
int yylval;
%}
num [0-9]+
tab "\t"|"\n"
GT ">="
LT "<="
LS "<<"
RS ">>"
LAND "&&"
LOR "||"
EQ "=="
NQ "!="
%%
{num} {yylval=atoi(yytext);return NUM;}
{tab} {return 0;}
. return yytext[0];
{GT} {return GT;}
{LT} {return LT;}
{LS} {return LS;}
{RS} {return RS;}
{LAND} {return LAND;}
{LOR} {return LOR;}
{NQ} {return NQ;}
{EQ} {return EQ;}
%%
int yywrap(void){return 1;}




