%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int yyerror(char *err);
int yylex(void);
int flag=0;
int n=0;
%}

%token ID RL OP UN NL IF ELSE WHILE DO FOR

%%
G : X 
  | Y 
  | Z {printf("\nSyntactically correct");return 1;};
X : A ';' NL
  | I ';' NL
  | U ';' NL;
A : ID '=' ID OP ID;
I : ID '=' ID;
U : ID UN;
Y : IF '(' C ')' NL G ELSE NL G;
C : ID RL ID;
Z : FOR '(' I ';' C ';' U ')' NL '{' NL G '}' NL;
%%

void main()
{
  while(1){
    printf("\nSyntax checker : \n\n");
    yyparse();
    printf("\n\n");
  }
}

int yyerror(char *err)
{
  printf("\nInvalid - %s\n\n",err);
  exit(0);
}
