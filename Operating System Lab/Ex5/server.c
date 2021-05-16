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
int fd;
char name[20],b[100];
id=shmget(111,50,IPC_CREAT | 00666); 
flag=shmget(150,10,IPC_CREAT | 00666);
a=shmat(id,NULL,0);
b=shmat(flag,NULL,0);
while(1)
{
	if(b[1]==1 && b[0]==0)
	{
		fd=open(a, O_RDONLY);//opens the file
		read(fd,b,100);
		close(fd);
		strcpy(a,b);//copies the contents to the shared memory
		b[0]=1;
	}
}
}
