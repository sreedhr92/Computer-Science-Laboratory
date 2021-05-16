%{
#include<stdio.h>
#include<string.h>
#include"syn_ch.tab.h"
%}

id ([a-zA-Z_][a-zA-Z0-9_]*|[0-9]+)
rl ("<"|"<="|">"|">="|"=="|"!=")
op ("+"|"-"|"*"|"/"|"%")
un ("++"|"--")
nl "\n"
ts "\t"|" "

%%
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"do" {return DO;}
"for" {return FOR;}
{id} {return ID;}
{rl} {return RL;}
{op} {return OP;}
{un} {return UN;}
{nl} {return NL;}
{ts} ;
. return yytext[0];
%%

int yywrap(){return 1;}
