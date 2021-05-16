#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<time.h>

#define PORT 7228

struct input
{
    int option;
    int id;
};

int main(int argc,char **argv)
{
	int sockfd, ret,len,n,fromlen;
	struct sockaddr_in serverAddr;

	int newfd;
	struct sockaddr_in clientAddr;

	struct tm* local;

	//socklen_t addr_size;

	char buffer[1024];
	char str[1000];
	pid_t child;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
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

	fromlen = sizeof(struct sockaddr_in);

	len = sizeof(clientAddr);
	int no_clients=1;
	//time_t rawtime;
	//time(&rawtime); // 0 or NULL also works .....
	// printf(" Time = ",asctime(local));
	struct input i;
	int x;

	while(1)
	{
		n = recvfrom(sockfd,&i,sizeof(i),0,(struct sockaddr *)&clientAddr,&len);
		printf("\nRequest from Client %d\n",i.id);
		time_t rawtime;
		time(&rawtime);
		local = localtime(&rawtime);
		x = i.option;
		if (x == 1)
		{
			strftime(buffer,sizeof(buffer)," %x .",local);
		}
		else if(x == 2)
		{
			strftime(buffer,sizeof(buffer)," %A .",local);
		}
		else if(x == 3)
		{
			strftime(buffer,sizeof(buffer)," %B .",local);
		}
		else if(x == 4)
		{
			strftime(buffer,sizeof(buffer)," %Y .",local);
		}
		else if(x == 5)
		{
			strftime(buffer,sizeof(buffer)," %I:%M %p .",local);
		}
		else if(x == 6)
		{
			struct tm *t;
			time_t toronto;
			t = gmtime(&rawtime);
			t -> tm_hour -=4;
			toronto = mktime(t);
			t = localtime(&toronto);
			strftime(buffer,sizeof(buffer)," %c .",local);
		}
		printf("\nMessage sent to client %d\n",i.id);

		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&clientAddr,len);
	}
	return 0;
}





	