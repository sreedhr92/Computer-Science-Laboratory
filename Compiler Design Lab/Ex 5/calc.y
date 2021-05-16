%{
#include <stdio.h>
int flag=0;
int yyerror(char *er);
int yylex(void);
#include <math.h>
#include<stdlib.h>
%}
%token NUM LS RS GT LT LAND EQ NQ LOR ID
%left LOR
%left LAND
%left '|'
%left '&'
%left EQ NQ
%left '>' GT
%left '<' LT
%left LS RS
%left '+' '-' 
%left '*' '^' '/' '%'
%left '(' ')' 

%%
P : E {if(!flag){printf("\nValid Expression\n");}printf("Answer =%d\n\n",$$);return 0;};
E : NUM { $$ = $1;}
  | E '+' E {$$ = $1 + $3; }
  | E '-' E {$$ = $1 - $3; }
  | E '*' E {$$ = $1 * $3; }
  | E '/' E {$$ = $1 / $3; }
  | E '%' E {$$ = $1 % $3; }
  | E '^' E {$$ = pow($1,$3); }
  | '(' E ')' {$$ = $2 ; }
  | E GT E {$$ = $1>= $3; }
  | E '>' E {$$ = $1> $3; } 
  | E '<' E {$$ = $1< $3; } 
  | E LT E {$$ = $1<= $3; } 
  | E RS E {$$ = $1>>$3; } 
  | E LS E {$$ = $1<< $3; } 
  | E '&' E {$$ = $1 & $3; } 
  | E '|' E {$$ = $1 | $3; } 
  | E LAND E {$$ = $1 && $3; } 
  | E LOR E {$$ = $1 || $3; } 
%%
int main()
{
    while(1)
    {
        yyparse();
    }
    
    
    return 0;
}
int yyerror(char *er)
{
    flag=1;
    printf("\nInvalid character %s\n",er);
    exit(0);
}
