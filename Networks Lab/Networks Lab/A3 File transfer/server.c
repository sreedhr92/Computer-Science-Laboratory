#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
	int len;
	int sockfd,newfd,n;
	struct sockaddr_in servaddr,cliaddr;
	char buff[1024];
	char str[1000];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		perror("cannot create socket!");
	else
		printf("socket is created!\n");
	bzero(&servaddr ,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	servaddr.sin_port=htons(7228);

	if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
		perror("Bind Error");

	listen(sockfd,2);
	len = sizeof(cliaddr);
	newfd = accept(sockfd,(struct sockaddr*)&cliaddr,&len);
	//while(1)
	//{
		FILE *fp;
		bzero(str,sizeof(str));
		printf("\nWaiting for client\n");
		n=read(newfd,buff,sizeof(buff));
		printf("\nFile to be transferred is %s",buff);
		fp = fopen(buff,"r");
		fscanf(fp,"%[^.]",str);
		write(newfd,str,sizeof(str));
		printf("\nFile Transfered!\n");
		close(sockfd);
		close(newfd);
	//}
	return 0;

}

/*Output:
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$ cat hi.txt
Hi this is networks lab session.
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$ gcc server.c -o server
server.c: In function ‘main’:
server.c:38:5: warning: implicit declaration of function ‘read’; did you mean ‘fread’? [-Wimplicit-function-declaration]
   n=read(newfd,buff,sizeof(buff));
     ^~~~
     fread
server.c:42:3: warning: implicit declaration of function ‘write’; did you mean ‘fwrite’? [-Wimplicit-function-declaration]
   write(newfd,str,sizeof(str));
   ^~~~~
   fwrite
server.c:44:3: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
   close(sockfd);
   ^~~~~
   pclose
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$ ./server
socket is created!

Waiting for client

File to be transferred is hi.txt
File Transfered!
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$*/
