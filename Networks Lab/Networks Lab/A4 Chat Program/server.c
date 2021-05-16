#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 7228

int main(int argc,char **argv)
{
	int sockfd, ret,len,n;
	struct sockaddr_in serverAddr;

	int newfd;
	struct sockaddr_in clientAddr;

	//socklen_t addr_size;

	char buffer[1024];
	char str[1000];
	pid_t child;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("---------Error in connection.\n");
		exit(1);
	}
	//printf("---------Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	if (ret < 0)
	{
		printf("---------Error in connection.\n");
		exit(1);
	}
	//printf("-----Binding is complete\n");
	listen(sockfd,10);
	len = sizeof(clientAddr);
	while(1)
	{
		newfd = accept(sockfd,(struct sockaddr*)&clientAddr,&len);
		if(newfd < 0)
		{
			break;
			//exit(1);
		}
		printf("Connection Accepted from client %s\n" ,inet_ntoa(clientAddr.sin_addr));
		
		if( (child = fork()) == 0 )
		{
			close(sockfd);
			while(1)
			{
				/*bzero(str,sizeof(str));
				bzero(buffer,sizeof(buffer));
				n=recv(newfd,str,sizeof(str),0);
				if (strcmp(str,"exit")==0)
				{
					printf("Disconnected from client");
					break;
				}
				else
				{
					printf("Client : %s\n",str);
					printf("\n\nServer : ");
					//bzero(buffer,sizeof(buffer));
					scanf("%[^\n]%*c",buffer);
					n=send(newfd,buffer,sizeof(buffer),0);}*/
		
				n=recv(newfd,buffer,sizeof(buffer),0);
				printf("\n Client%d : %s",newfd,buffer);
				if(strcmp(buffer,"Bye")==0)
					break;		
				//Sending Message
				printf("\n\n Server  : ");
				scanf("%[^\n]%*c",buffer);	
				n=send(newfd,buffer,sizeof(buffer),0);
			}
		}
		
	}
	close(newfd);
	return 0;
}
			
	
	
	

/*Output:

*/
