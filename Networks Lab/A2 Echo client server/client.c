#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>


int main(int argc, char  **argv)
{
	/* code */
	int len;
	int sockfd,n;
	struct sockaddr_in servaddr,cliaddr;
	char str[1000];
	char buff[1024];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		perror("cannot create a socket!");
	else
		printf("socket is created!\n");
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	servaddr.sin_port = htons(7228);

	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	//while(1)
	//{
		bzero( str,sizeof(str));
		bzero( buff,sizeof(buff));
		printf("\nEnter the message :");
		scanf("%[^\t]",buff);
		n = write(sockfd,buff,sizeof(buff));
		read(sockfd,str,sizeof(str));
		printf("\nRecieved message(from server) is %s\n",str);
		close(sockfd);
	//}	
	return 0;


}
/*Output:
admin@admin-PC /cygdrive/c/Users/admin/Desktop/sreedhar/networks
$ gcc client.c -o client
client.c: In function ‘main’:
client.c:26:29: warning: implicit declaration of function ‘inet_addr’; did you mean ‘ifr_addr’? [-Wimplicit-function-declaration]
   26 |  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
      |                             ^~~~~~~~~
      |                             ifr_addr
client.c:36:7: warning: implicit declaration of function ‘write’; did you mean ‘writev’? [-Wimplicit-function-declaration]
   36 |   n = write(sockfd,buff,sizeof(buff));
      |       ^~~~~
      |       writev
client.c:37:3: warning: implicit declaration of function ‘read’; did you mean ‘readv’? [-Wimplicit-function-declaration]
   37 |   read(sockfd,str,sizeof(str));
      |   ^~~~
      |   readv
client.c:39:3: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
   39 |   close(sockfd);
      |   ^~~~~
      |   pclose

admin@admin-PC /cygdrive/c/Users/admin/Desktop/sreedhar/networks
$ ./client 192.168.43.154
socket is created!

Enter the message :Hello
if im ruining you right now
please forgive me
you are not being punished
come here im your paradise


Recieved message(from server) is Hello
if im ruining you right now
please forgive me
you are not being punished
come here im your paradise


admin@admin-PC /cygdrive/c/Users/admin/Desktop/sreedhar/networks
$
*/