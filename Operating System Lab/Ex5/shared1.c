#include<sys/ipc.h>
#define NULL 0
#include<sys/shm.h> 
#include<sys/types.h> 
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<sys/wait.h> 
#include<ctype.h>
//#include<stdio_ext.h>
// parent writing a char in shared memory and child reads it and prints it.
int main()
{
int pid;
char *a,*b,c;
 int id,n,i;
 char name[20];
// you can create a shared memory between parent an d child here or you can create inside them separately.
id=shmget(111,50,IPC_CREAT | 00666); 
pid=fork();
if(pid>0)
{
// id=shmget(111,50,IPC_CREAT | 00666);
 a=shmat(id,NULL,0);
 printf("\nParent process is running ");
 printf("\nEnter the name :");
 scanf("%[^\n]s",name);
 strcpy(a,name);
 wait(NULL);
 shmdt(a);
 exit(0);
}
else
{
sleep(5);
printf("\nChild  process is running "); //id=shmget(111,50,0); 
b=shmat(id,NULL,0);
int n=strlen(b);
int i;
printf("\nChild converting the string to upper case :");
for(i=0;i<=n;i++)
{
	printf("%c",toupper(b[i]));
}
printf("\n");
shmdt(b);
exit(0);
}
}
