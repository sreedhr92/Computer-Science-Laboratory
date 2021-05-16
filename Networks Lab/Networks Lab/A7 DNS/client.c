#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<netdb.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT 7228

int main(int argc,char **argv)
{
    int sockfd,ret,len,n;

    struct sockaddr_in serverAddr;
    char buffer[1024];
    char str[1000];

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd < 0)
	{
		printf("-----Error in Connection-----.\n");
		exit(1);
	}
	//printf("-----Client Socket is Created!.\n");
	
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(7228);

    len = sizeof(serverAddr);
    int x;
    char domain[100];
    while(1)
    {
        printf("\n\n1.Request\n2.Exit \n Enter choice:");
        scanf("%d",&x);
        if (x==1)
        {
            printf("\nEnter the domain name:");
            scanf("%s",buffer);
            sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&serverAddr,len);
            recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&serverAddr,&len);
            printf("\nIP address :%s",buffer);
        }
        else if(x==2)
        {
            break;
        }
    }
}
/*Output:
sree@sree-VirtualBox:~/Desktop/Networks Lab/A7 DNS$ ./client


1.Request
2.Exit 
 Enter choice:1

Enter the domain name:www.yahoo.com

IP address :10.2.45.67

1.Request
2.Exit 
 Enter choice:2

 client :2
 sree@sree-VirtualBox:~/Desktop/Networks Lab/A7 DNS$ ./client


1.Request
2.Exit 
 Enter choice:1

Enter the domain name:www.google.com

IP address :142.89.78.66

1.Request
2.Exit 
 Enter choice:2*/