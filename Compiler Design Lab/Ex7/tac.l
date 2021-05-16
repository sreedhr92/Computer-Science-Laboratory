%{
struct info{
        char *var;
        char *code;
        int val;
    };
#include <stdio.h>
#include<string.h>
#include "tac.tab.h"
void yyerror(char *);
extern YYSTYPE yylval;
%}
id ([a-zA-Z_][a-zA-Z0-9_]*|[0-9]+)
num [0-9]+
GT ">="
LT "<="
LS "<<"
RS ">>"
LAND "&&"
LOR "||"
EQ "=="
NQ "!="
CHAR ['][a-zA-Z0-9][']
%%
begin {return BEG;}
end {return END;}
if {return IF;}
then {return THEN;}
else {return ELSE;}
end_if {return ENDIF;}
integer {return INT;}
real {return REAL;}
char {return CHAR;}
var {return VAR;}
{num} {yylval.temp.val=atoi(yytext);return NUM;}
{id} {yylval.temp.var=(char*)malloc(10);strcpy(yylval.temp.var,yytext);return ID;}
{GT} {return GT;}
{LT} {return LT;}
{LS} {return LS;}
{RS} {return RS;}
{LAND} {return LAND;}
{LOR} {return LOR;}
{NQ} {return NQ;}
{EQ} {return EQ;}
[{};()]  {return *yytext;}
[-+*/^()=&|%:;] {return *yytext;}
{CHAR} {yylval.temp.var=(char*)malloc(10);strcpy(yylval.temp.var,yytext);return CH;} 
[\t] ;
[\n] ;
[ ] ;

%%
int yywrap(void){return 1;}




