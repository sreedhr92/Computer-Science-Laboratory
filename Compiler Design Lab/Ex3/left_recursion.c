#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void detect(char prod[][30],int n)
{
    for(int i=0;i<n;++i)
   {    
        char p = prod[i][0];
        if(p==prod[i][3])
        {
            char *token = strtok(prod[i],"|");
            char alpha[10];
            int j=0;
            for(int itr=4;itr<strlen(token);itr++)
                alpha[j++]=token[itr];
            char beta[10][20];
            j=0;
            char buffer[20];
            while(token!=NULL)
            {
                strcpy(buffer,token);
                token=strtok(NULL,"|");
                if(token!=NULL)
                    strcpy(beta[j++],token);
                else
                    strcpy(beta[j++],buffer);
            }
            j--;
            if(!j)
            {
                printf("\n%c -> %c'",p,p);
                char alpha[10];
                int j=0;
                for(int itr=4;itr<strlen(prod[i]);itr++)
                    alpha[j++]=prod[i][itr];
                printf("\n%c'->%s %c' | (null)\n",p,alpha,p);
                continue;
            }
            printf("\n%c ->%s %c'",p,beta[0],p);
            for(int i=1;i<j;i++)
                printf("|%s %c'",beta[i],p);
            printf("\n%c'->%s %c' | (null)\n",p,alpha,p);
        }
        else
            printf("\n%s\n",prod[i]);
    }
}
int main()
{
    int n=0;
    char prod[20][30];

    printf("\n\tLeft Recursion_Elimation\n");
    int i=0;
    FILE *file = fopen("input.txt","r");
    char c;
    printf("\nGiven grammar\n");
    while(fscanf(file,"%c",&c)==1)
    {
        if(c=='\n')
        {
            prod[n][i]='\0';
            printf("\n%s\n",prod[n]);
            n++;
            i=0;
        }
        else
        {
            prod[n][i]=c;
            i++;
        }
    }
    printf("The set of productions in grammer after left recursion:\n");
    detect(prod,n);
    printf("\n");
    return 0;
}