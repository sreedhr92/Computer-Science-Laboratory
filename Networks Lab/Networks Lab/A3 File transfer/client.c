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
		char path[100];
		FILE *f;
		bzero( str,sizeof(str));
		bzero( buff,sizeof(buff));
		printf("\nEnter the path of the file:");
		scanf("%s",buff);
		n = write(sockfd,buff,sizeof(buff));
		read(sockfd,str,sizeof(str));
		printf("\nFile Transfered!\n");
		printf("\nSave the file in path:");
		scanf("%s",path);
		f = fopen(path,"w");
		fprintf(f,"%s",str);
		close(sockfd);
	//}	
	return 0;


}
/*Output:
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$ cat newhi.txt
cat: newhi.txt: No such file or directory
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$ gcc client.c -o client
client.c: In function ‘main’:
client.c:26:29: warning: implicit declaration of function ‘inet_addr’; did you mean ‘h_addr’? [-Wimplicit-function-declaration]
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
                             ^~~~~~~~~
                             h_addr
client.c:38:7: warning: implicit declaration of function ‘write’; did you mean ‘fwrite’? [-Wimplicit-function-declaration]
   n = write(sockfd,buff,sizeof(buff));
       ^~~~~
       fwrite
client.c:39:3: warning: implicit declaration of function ‘read’; did you mean ‘fread’? [-Wimplicit-function-declaration]
   read(sockfd,str,sizeof(str));
   ^~~~
   fread
client.c:45:3: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
   close(sockfd);
   ^~~~~
   pclose
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$ ./client 10.0.2.15
socket is created!

Enter the path of the file:hi.txt

File Transfered!

Save the file in path:newhi.txt
sree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$ cat newhi.txt
Hi this is networks lab sessionsree@sree-VirtualBox:~/Desktop/Networks Lab/A3 File transfer$*/

