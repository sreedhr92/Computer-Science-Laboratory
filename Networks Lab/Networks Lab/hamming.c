#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int get_r(int m)
{
    int r=0;
    while(1)
    {
        if (pow(2, r) >= m + r + 1)
            break;
        r++;
    }
    return r;
}
int get_r_by_len(int len)
{
    int r = 0;
    while(1)
    {
        if ( pow(2,r) >= len +1)
            break;
        r++;
    }
    return r;
}
int binary_to_BCD(char binary[])
{
    int i ;
    int value=0;
    int r = 0;
    for(i=strlen(binary)-1;i>=0;i--,r++)
    {
        if(binary[i]=='1')
            value+= pow(2,r); 
    }
    return value;
}
int check_error(char ham_code[])
{
    int r = get_r_by_len(strlen(ham_code));
    int m = strlen(ham_code) - r;
    int places[100];
    int i,j,count,val,val1;
    for (i = 0; i < r; i++)
    {
        places[i] = pow(2, i);
    }
    char *error;
    error = (char*)malloc(sizeof(char)*r);
    for (i = 0; i < r; i++)
    {
        val1 = places[i];
        count = 0;
        for (j = strlen(ham_code) - 1; j >= 0; j--)
        {
            val = val1;
            while (val > 0)
            {
                if (ham_code[j - val1 + 1] == '1')
                    count++;
                j--;
                val--;
            }
            j = j - val1 + 1;
        }
        if (count % 2 == 0)
            error[i] = '0';
        else
            error[i] = '1';
    }
    printf("\nError :%s",strrev(error));
    return binary_to_BCD(error);
}
char* redundant_bits(char hamming[],int places[],int r)
{
    char *redundant;
    redundant = (char*)malloc(sizeof(char)*r);
    int i,j;
    int val1,val;
    int count;
    for(i=0;i<r;i++)
    {
        val1 = places[i];
        count = 0;
        for(j = strlen(hamming)-1; j >=0; j--)
        {
            val = val1;
            while(val>0)
            {
                if (hamming[j-val1+1] == '1')
                    count++;
                j--;
                val--;
            }
            j = j - val1 +1;
        }
        if (count %2 ==0)
            redundant[i] = '0';
        else 
            redundant[i] = '1';
    }
    return redundant;
}
char *get_hamming_code(char message[])
{
    int m,r;
    m = strlen(message);
    r = get_r(m);
    int places[100];
    int i,j;
    for(i=0;i<r;i++)
    {
        places[i] = pow(2, i);
    }
    char *hamming;
    hamming = (char *)malloc(sizeof(char) * 100);
    int len = m+r;
    int k = r-1;
    int f = 0;
    for(i=0;i<m+r;i++)
    {
        if (places[k] == len)
        {
            hamming[i] = '0';
            k--;
        }
        else
        {
            hamming[i] = message[f];
            f++;
        }
        len--;       
    }
    char *redudant;
    redudant = redundant_bits(hamming,places,r);
    len = m+r;
    k = r-1;
    for(i=0;i<r+m;i++)
    {
        if(places[k]==len)
        {
            hamming[i] = redudant[k];
            k--;
        }
        len--;
    } 
    return hamming;
}
void main()
{
    char message[100];
    int e;
    printf("\nEnter the message bit:");
    scanf("%s",message);
    char *hamming;
    hamming = get_hamming_code(message);
    printf("\nThe Hamming Code = %s",hamming);
    printf("\nEnter the error bit :");
    scanf("%d",&e);
    if (hamming[strlen(hamming)-e] == '1')
        hamming[strlen(hamming) - e] = '0' ;
    else 
        hamming[strlen(hamming) - e] = '1';
    printf("\nThe error Hamming Code is %s",hamming);
    e = check_error(hamming);
    printf("\nThe Error bit is %d ",e);
    if (hamming[strlen(hamming) - e] == '1')
        hamming[strlen(hamming) - e] = '0';
    else
        hamming[strlen(hamming) - e] = '1';
    printf("\nThe error Hamming Code is %s", hamming);
}