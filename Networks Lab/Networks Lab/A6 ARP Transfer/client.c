#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

struct address
{
    char ip[100];
    char mac[100];
};

struct address input()
{
    struct address a;
    printf("\nEnter the IP address  :");
    scanf("%s",a.ip);
    printf("\nEnter the Mac address :");
    scanf("%s",a.mac);
    return a;
}

int check_ip(char *buffer,struct address a)
{
    //Extracting IP address from the packet....
    int i=0;
    int count = 0,k=0;
    char ip[100];
    while(buffer[i] != '\0')
    {
        if(buffer[i] == '|')
            {count++;i++;continue;}
        if (count == 2)
        {
            ip[k]=buffer[i];
            k++;
        }
        i++;
    }
    if (strcmp(ip,a.ip)==0)
        return 1;
    else
        return 0;
}

int main(int argc,char **argv)
{
    int sockfd,ret,n;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    char str[1000];

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd < 0)
    {
        printf("-----Error in Connection-----.\n");
		exit(1);
    }
    printf("------Client Socket is created!.\n");

    bzero(&serverAddr,sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(7228);

    struct address a;
    a = input();

    ret = connect(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

    if(ret < 0)
    {
        printf("-----Error in Connection-----.\n");
        exit(1);
    }
    recv(sockfd,buffer,sizeof(buffer),0);
    printf("\nARP Request Received :%s\n",buffer);
    if (check_ip(buffer,a))
    {
        printf("\nIP addresss matches\n");
        strcat(buffer,"|");
        strcat(buffer,a.mac);
        send(sockfd,buffer,sizeof(buffer),0);
        printf("\nARP Reply Sent\n%s\n",buffer);
        recv(sockfd,buffer,sizeof(buffer),0);
        printf("\nReceived Packet is\n%s\n",buffer);
    }
    else
    {
        printf("\nIP address does not match.\n");
    }
    close(sockfd);
    return 0;    
}
