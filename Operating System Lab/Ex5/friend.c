#include<sys/ipc.h>
#define NULL 0
#include<sys/shm.h> 
#include<sys/types.h> 
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<sys/wait.h> 
int main()
{
char *a;
int *b;
int id,flag;
char name[20];
id=shmget(111,50,IPC_CREAT | 00666); 
flag=shmget(150,10,IPC_CREAT | 00666);
a=shmat(id,NULL,0);
b=shmat(flag,NULL,0);
while(1)
{
if(b[0]==0)
{
	printf("\nFriend's msg: %s\n",a);
}
if(b[1]==1)
{
printf("\nYou:");
gets(name);
strcpy(a,name);
b[0]=1;
b[1]=0;
}
}
}
