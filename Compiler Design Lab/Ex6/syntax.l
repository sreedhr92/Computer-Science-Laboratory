%{
#include "syntax.tab.h"
#include <stdio.h>
#include<string.h>
void yyerror(char *);
int yylval;
int n=0;
%}
%%
\n {n++;}
[ \t]+ ;
int|float|char|double {return DATATYPE;}
if {return IF;}
else {return ELSE;}                                                  
[0-9]+ {yylval = atoi(yytext); return INT;}
["].+["] {return STR;}
[a-zA-Z_]+[0-9]*? {return ID;}
[,=;] {return yytext[0];}
"<"|"<="|">"|">="|"=="|"!=" {return RELOP;}
"+"|"-"|"*"|"/" {return ARITHOP;}
"++"|"--" {return UNOP;}
"(" {return *yytext;}
")" {return *yytext;}
"{" {return *yytext;}
"}" {return *yytext;}
%%

int yywrap (void) 
{
    printf("\nThe given program is syntactically correct.\t\n");
    return 1;
}

void yyerror(char *s)
{
    printf("\n Syntax error\n");
    exit(1);
}

