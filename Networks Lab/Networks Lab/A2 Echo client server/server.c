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
		bzero(str,sizeof(str));
		n=read(newfd,buff,sizeof(buff));
		printf("\nReceived Message(from client) is %s\n",buff);
		//printf("\nEnter the message:");
		//scanf("%[^\t]",str);
		write(newfd,buff,sizeof(buff));
		printf("\nMessage sent!:%s",buff);
		close(sockfd);
		close(newfd);
	//}
	return 0;

}

/*Output:
admin@admin-PC ~
$ cd C:/Users/admin/Desktop/sreedhar/networks

admin@admin-PC /cygdrive/c/Users/admin/Desktop/sreedhar/networks
$ gcc server.c -o server
server.c: In function ‘main’:
server.c:36:5: warning: implicit declaration of function ‘read’; did you mean ‘readv’? [-Wimplicit-function-declaration]
   36 |   n=read(newfd,buff,sizeof(buff));
      |     ^~~~
      |     readv
server.c:40:3: warning: implicit declaration of function ‘write’; did you mean ‘writev’? [-Wimplicit-function-declaration]
   40 |   write(newfd,buff,sizeof(buff));
      |   ^~~~~
      |   writev
server.c:42:3: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
   42 |   close(sockfd);
      |   ^~~~~
      |   pclose

admin@admin-PC /cygdrive/c/Users/admin/Desktop/sreedhar/networks
$ ./server
socket is created!

Received Message(from client) is Hello
if im ruining you right now
please forgive me
you are not being punished
come here im your paradise


Message sent!:Hello
if im ruining you right now
please forgive me
you are not being punished
come here im your paradise

admin@admin-PC /cygdrive/c/Users/admin/Desktop/sreedhar/networks
$
*/
