#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int ip_validity(char ip[100])
{
    int i=0;
    char token[4];
    int k=0,dot=0;
    int j=0;
    int flag=1;
    int num;
    while(ip[i]!='\0')
    {
        if(ip[i]=='.' || ip[i+1]=='\0')
        {
            if (ip[i+1]=='\0')
            {
                token[k]=ip[i];
                k++;
                i++;
                dot--;
            }
            if (k>3)
            {
                flag=0;
                break;
            }
            k=0;
            dot++;
            if (dot == 4)
            {
                flag=0;
                break;
            }
            // Checking for the characters other than number...
            for(j=0;j<strlen(token);j++)
            {
                if (isdigit(token[j])==0)
                {
                    flag=0;
                }         
            }
            if (flag==0)
                break;
            // Checking whether it is in the range...
            num = atoi(token);
            if (num < 0 || num > 255)
            {
                flag=0;
                break;
            }
            bzero(&token,sizeof(token));
        } 
        else
        {
            token[k]=ip[i];
            k++;   
        }
        i++;
    }
    return flag;
}
int mac_validity(char mac[100])
{
    int i=0;
    int flag=1;
    int count=0;
    char conv[100];
    if (strlen(mac) != 17)
        return 0;
    strcpy(conv,"0");
    strcat(conv,mac);
    i++;
    while(conv[i]!='\0')
    {
        if(i%3==0 && conv[i]!='-')
            {flag=0;break;}
        if(i%3 !=0 && isxdigit(conv[i])==0)
            {flag=0;break;}
        i++;
    }
    return flag;
}
int main()
{
    char ip[100];
    strcpy(ip,"09-DF-9y-26-6C-09");
    if(mac_validity(ip))
        printf("\nValid\n");
    else
    {
        printf("\nNot valid\n");
    }
    return 0;
}