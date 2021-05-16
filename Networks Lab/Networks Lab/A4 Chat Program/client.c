#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>


int main(int argc, char  **argv)
{
	/* code */
	int sockfd , ret,n;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	char str[1000];
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		printf("-----Error in Connection-----.\n");
		exit(1);
	}
	printf("-----Client Socket is Created!.\n");
	
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(7228);
	
	ret = connect(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	
	if(ret <0)
	{
		printf("-----Error in Connection-----.\n");
		exit(1);
	}
	printf("-----Connected to server.\n");
	
	while(1)
	{
		/*bzero(buffer,sizeof(buffer));
		bzero(buffer,sizeof(str));
		printf("Client: ");
		scanf("%[^\n]%*c",buffer);
		n=send(sockfd,buffer,sizeof(buffer),0);
		
		if (strcmp(buffer,"exit")==0)
		{
			printf("[.] Disconnected from server.\n");
			close(sockfd);
			exit(1);
		}
		if(recv(sockfd,str,sizeof(str),0) < 0)
		{
			printf("-----Error in receiving data.\n");
		}
		else
		{
			printf("Server: %s\n",str);
		}*/
		printf("\n Client : ");
		scanf("%[^\n]%*c",buffer);
		//Sending Message
		n=send(sockfd,buffer,sizeof(buffer),0);

		if(strcmp(buffer,"Bye")==0){
			close(sockfd);
			break;
		}

		//Receiving Message
		n=recv(sockfd,buffer,sizeof(buffer),0);
		printf("\n Server : %s\n",buffer);
	}
	return 0;
}
/*Output:

*/
