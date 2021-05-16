/*E->TE'
E'-> +TE' | -TE' | epsilon
T->FT'
T'->*FT'| /FT' | epsilon
F->(E) | id*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char str[100];
int i=0;
int E();
int E1();
int T();
int T1();
int F();
int tab=0;
void print_tabs()
{
    int i;
    for(i=0;i<tab;i++)
        printf("\t");
}
void main()
{
    strcpy(str,"(i+i)");
    printf("\nThe Given String is %s\n",str);
    if(E(0))
        printf("\nThe String is Accepted!\n");
    else
        printf("\nThe String is not accepted!\n");
}
int E()
{
    tab++;
    print_tabs();
    printf("E() is called\n");
    if(T())
    {
        print_tabs();
        printf("T() is returned status :1\n");
        if(E1()){
            print_tabs();
            printf("E1() is returned status :1\n");
            return 1;
        }
        else
            {print_tabs();printf("Error at index %d\n",i);return 0;}
    }
    else
        {print_tabs();printf("Error at index %d\n",i);return 0;}    
}
int E1()
{
    tab++;
    print_tabs();
    printf("E1() is called\n");
    if(str[i]=='+')
    {
        print_tabs();
        printf("'+' is matched\n");
        i++;
        if(T())
        {
            print_tabs();
            printf("T() is returned status :1\n");
            if(E1())
            {
                print_tabs();
                printf("E1() is returned status :1\n");
                return 1;
            }
            else
                {print_tabs();printf("Error at index %d\n",i);return 0;}
        }
        else
            {print_tabs();printf("Error at index %d\n",i);return 0;}
    }
    else if(str[i]=='-')
    {
        print_tabs();
        printf("'-' is matched\n");
        i++;
        if(T())
        {
            print_tabs();
            printf("T() is returned status :1\n");
            if(E1()){
                print_tabs();
                printf("E1() is returned status :1\n");
                return 1;}
            else
                {print_tabs();printf("Error at index %d\n",i);return 0;}
        }
        else
            {print_tabs();printf("Error at index %d\n",i);return 0;}
    }
    else if(str[i]=='\0')
    {
        //i++;
        return 1;        
    }
}
int T()
{
    tab++;
    print_tabs();
    printf("T() is called\n");
     if(F())
    {
        print_tabs();
        printf("F() is returned status :1\n");
        if(T1())
        {
            print_tabs();
            printf("T1() is returned status :1\n");
            return 1;}
        else
            {print_tabs();printf("Error at index %d\n",i);return 0;}
    }
    else
        {print_tabs();printf("Error at index %d\n",i);return 0;} 
}
int T1()
{
    tab++;
    print_tabs();
    printf("T1() is called\n");
    if(str[i]=='*')
    {
        print_tabs();
        printf("'*' is matched\n");
        i++;
        if(F())
        {   print_tabs();
            printf("F() is returned status :1\n");
            if(T1())
            {
                print_tabs();
                printf("T1() is returned status :1\n");
                return 1;
            }
            else
                {print_tabs();printf("Error at index %d\n",i);return 0;}
        }
        else
            {print_tabs();printf("Error at index %d\n",i);return 0;}
    }
    else if(str[i]=='/')
    {
        print_tabs();
        printf("'/' is matched\n");
        i++;
        if(F())
        {
            print_tabs();
            printf("F() is returned status :1\n");
            if(T1())
            {
                print_tabs();
                printf("T1() is returned status :1\n");
                return 1;
            }
            else
                {print_tabs();printf("Error at index %d\n",i);return 0;}
        }
        else
            {print_tabs();printf("Error at index %d\n",i);return 0;}
    }
    else if(str[i]=='\0')
    {
        //i++;
        return 1;
    }
}
int F()
{
    tab++;
    print_tabs();
    printf("F() is called\n");
    if(str[i]=='(')
    {
        print_tabs();
        printf("'(' is matched\n");
        i++;
        if(E())
        {
            print_tabs();
            printf("E() is returned status :1\n");
            if(str[i]==')')
            {
                print_tabs();
                printf("')' is matched\n");
                i++;
                return 1;
            }
            else
                {printf("\nError at index %d\n",i);{print_tabs();printf("Error at index %d\n",i);return 0;}}
        }
        else
            {print_tabs();printf("Error at index %d\n",i);return 0;}
    }
    else if(str[i]=='i')
    {
        print_tabs();
        printf("'i' is matched\n");
        i++;
        return 1;
    }
}