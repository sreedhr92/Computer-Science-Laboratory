#include <stdio.h>
#include<conio.h>
int main () {
   FILE *fp;
   fpos_t position;
   fp = fopen("file1.txt","w");
   fputs("Hello, World!", fp);
   fgetpos(fp, &position);
   fputs("Ruban!", fp);
   fsetpos(fp, &position);
   fputs("SSN", fp);
   fclose(fp);
 //  getch();
   return(0);
}