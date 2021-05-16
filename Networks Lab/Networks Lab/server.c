#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#define PORT 7228

int main(int argc ,char* argv)
{
    int sockfd,newfd,ret,len,n;
    pid_t child;

    char buffer[1000];

    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);

    ret = bind(sockfd, (struct sockaddr*)&serveraddr,sizeof(serveraddr));

    listen(sockfd,10);
    len = sizeof(clientaddr);

    while(1)
    {
        newfd = accept(sockfd ,(struct sockaddr*)&clientaddr,&len);
        if (newfd < 0)
        {
            break;
        }
        if ((child = fork()) == 0)
        {
            close(sockfd);
            while(1)
            {
                n = recv(newfd,buffer,)
            }
        }
    }

}
