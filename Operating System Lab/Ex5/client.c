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
int fd;
id=shmget(111,100,IPC_CREAT | 00666); 
flag=shmget(150,10,IPC_CREAT | 00666);
a=shmat(id,NULL,0);
b=shmat(flag,NULL,0);
b[1]=0;
// if b[1]=0 means you should type the file name 
// if b[1]=1 means the server should read the file name and get the contents of the file
// if b[0]=1 means the client should continue the process and displays the content of the file
// if b[0]=0 means the server should wait for the next input from the user
while(1)
{
if(b[1]==0)
{
printf("\nEnter the file name:");
gets(name)
strcpy(a,name);
b[0]=0;
b[1]=1;
}
if(b[0]==1)
{
	printf("\nContents of the file: %s\n",a);
	printf("\nEnter the new file name :");
	gets(name);
	fd=open(name, O_WRONLY);//creates a new file
	write(fd,a,strlen(a)+1);//writes the buffer onto the file 
	close(fd);
	b[1]=0;
}
}
}
