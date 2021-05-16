%{
#include <stdio.h>
int yyerror(char *er);
int yylex(void);
#include <math.h>
#include<stdlib.h>
%}
%token INT STR ID RELOP ARITHOP UNOP DATATYPE IF ELSE

%%
S   : DATATYPE VAR';'|VAR';'|CONDT
VAR : VAR ',' INIT | INIT
INIT : ID | EXPR 
EXPR : ID'='ST | ID UNOP | ID'='ID ARITHOP ST | ID'='ID | ID ARITHOP '=' INT
ST : INT|STR|ID
CONDT :IF '(' CONDT_EXP ')' | ELSE 
CONDT_EXP : ID RELOP CONDT_EXP | INT RELOP CONDT_EXP | ID | INT
%%
int main()
{
    while(1)
    {
        yyparse();
    }
    return 0;
}