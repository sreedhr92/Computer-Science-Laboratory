%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    int yylex(void);
    void yyerror(char *str);
    int label=1,t=1,count=0;
    struct data{
        char *code;
        char * var;
    };
%}

%token NUM IF ELSE INT FLOAT ID CHAR ELSE ARTHOP LOGOP RELOP