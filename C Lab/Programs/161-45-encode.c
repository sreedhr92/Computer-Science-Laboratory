#include<stdio.h>
#include<stdlib.h>

void main()
{
    char line[50];
    int key;
    printf("Enter a line of text : ");
    scanf("%[^'\n']",line);
    //getting random values from computer..
    srand(time(0));
    key=rand()%256;
    for(int l=0;line[l]!='\0';l++)
    {
        //adding the ASCII values to character to the random values
        int i;
        i=line[l];
        i+=key;
        if(i>255)
            i%=256;
        line[l]=i;
    }
    printf("Encoded message : %s",line);
    for(int l=0;line[l]!='\0';l++)
    {
        //substracting the ASCII values to character to the random values
        int i;
        i=line[l];
        i-=key;
        line[l]=i;
    }
    printf("\nDecoded string : %s",line);
}

/*Output:
PS D:\C Programming\A4> ./q5
Enter a line of text : Qwerty1729!@#$%
Encoded message : æ╖Ñ▓┤╣qwryaÇcde
Decoded string : Qwerty1729!@#$% */