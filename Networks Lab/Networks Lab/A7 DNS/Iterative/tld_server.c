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

#define PORT 2000

struct table
{
    char ip[100];
    char server[100];
};
int n=0;
struct table *create_table(int n)
{
    int i;
    char test[100];
    strcpy(test,"Automatically generated for testing !");
    //printf("\nEnter the no.of server names to be Added: %s",test);
    //scanf("%d",&n);
    struct table *t;
    t = (struct table*)malloc(sizeof(struct table)*n);
    /*for(i=0;i<n;++i)
    {
        printf("\nEnter Domain name:");
        scanf("%s",t[i].server);
        printf("\nEnter Ip address :");
        scanf("%s",t[i].ip);
        printf("\n");
    }*/
    /*strcpy(t[0].server,"www.yahoo.com");
    strcpy(t[0].ip,"10.2.45.67");
    strcpy(t[1].server,"www.annauniv.edu");
    strcpy(t[1].ip,"197.34.53.122");
    strcpy(t[2].server,"www.google.com");
    strcpy(t[2].ip,"142.89.78.66");
    print_table(n,t);*/
    return t;
}
char *get_ip(char buff[],struct table t[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(buff,t[i].server)==0)
        {
            return t[i].ip;
        }
    }
    return NULL;
}
void update_table(struct table *t,char ip[],char domain[])
{
    strcpy(t[n].ip,ip);
    strcpy(t[n].server,domain);
    n++;
}

int main(int argc,char **argv)
{
    int sockfd,ret,no,len;
    struct sockaddr_in serverAddr;

    int newfd;
    struct sockaddr_in clientAddr;

    char buffer[1024];
    char str[1000];

    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    if (sockfd < 0)
    {
        printf("\n Error in Connection\n");
    }
    printf("\nServer Socket is created\n");

    bzero(&serverAddr,sizeof(serverAddr));
    serverAddr.sin_addr.s_addr=INADDR_ANY;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(PORT);

    ret = bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

    int n;
    int x;
    char test[100];
    strcpy(test,"Automatically generated for testing !");
    printf("\nEnter the no.of server names to be Added: %s",test);
    //scanf("%d",&n);
    n=3;
    struct table *t;
    t = create_table(100);
    /*while(1)
    {
        printf("\n1.Modify\n2.Exit \n Enter choice:");
        scanf("%d",&x);
        if (x==1)
        {
            t=modify(n,t);
        }
        else if(x==2)
        {
            break;
        }
    }*/        
    printf("\nTLD_server listening ....\n");
    len = sizeof(clientAddr);
    char domain[100];
    while(1)
    {
        no = recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&clientAddr,&len);
        if (get_ip(buffer,t,n)==NULL)
        {
            printf("\n**The Ip is not available in the TLD server redirecting the address of Authoritative server to local server..**\n");
            // port 1000 is authoritative server...
            strcpy(buffer,"1000");
            sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&clientAddr,len);
        }
        else
            strcpy(buffer,get_ip(buffer,t,n));
        sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&clientAddr,len);
    }
    return 0;

}