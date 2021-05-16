#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>
#include<ctype.h>

struct packet
{
    char desti_ip[100];
    char source_ip[100];
    char source_mac[100];
    char data[17];
};
int ip_validity(char ip[100])
{
    int i=0;
    char token[4];
    int k=0,dot=0;
    int j=0;
    int flag=1;
    int num;
    while(ip[i]!='\0')
    {
        if(ip[i]=='.' || ip[i+1]=='\0')
        {
            if (ip[i+1]=='\0')
            {
                token[k]=ip[i];
                k++;
                i++;
                dot--;
            }
            if (k>3)
            {
                flag=0;
                break;
            }
            k=0;
            dot++;
            if (dot == 4)
            {
                flag=0;
                break;
            }
            // Checking for the characters other than number...
            for(j=0;j<strlen(token);j++)
            {
                if (isdigit(token[j])==0)
                {
                    flag=0;
                }         
            }
            if (flag==0)
                break;
            // Checking whether it is in the range...
            num = atoi(token);
            if (num < 0 || num > 255)
            {
                flag=0;
                break;
            }
            bzero(&token,sizeof(token));
        } 
        else
        {
            token[k]=ip[i];
            k++;   
        }
        i++;
    }
    return flag;
}
int mac_validity(char mac[100])
{
    int i=0;
    int flag=1;
    int count=0;
    char conv[100];
    if (strlen(mac) != 17)
        return 0;
    strcpy(conv,"0");
    strcat(conv,mac);
    i++;
    while(conv[i]!='\0')
    {
        if(i%3==0 && conv[i]!='-')
            {flag=0;break;}
        if(i%3 !=0 && isxdigit(conv[i])==0)
            {flag=0;break;}
        i++;
    }
    return flag;
}
char *getMac(char *buffer)
{
    int i=0,j=0;
    int count = 0;
    char *mac;
    mac = (char*)malloc(sizeof(char)*100);
    while(buffer[i] != '\0')
    {
        if(buffer[i] == '|')
            count++;
        if (count == 3)
        {
            mac[j]=buffer[i];
            j++;
        }
        i++;
    }
    return mac;
}
int verify(char *buffer)
{
    int i=0,j=0;
    int count = 0,k=0;
    char ip[100];
    char mac[100];

    while(buffer[i] != '\0')
    {
        if(buffer[i] == '|')
            {count++;i++;continue;}
        if (count == 2)
        {
            ip[k]=buffer[i];
            k++;
        }
        if (count == 3)
        {
            mac[j]=buffer[i];
            j++;
        }
        i++;
    }
    mac[17]='\0';
    int a,b;
    a=ip_validity(ip);
    b=mac_validity(mac);
    if (a && b)
    {
        return 1;
    }
    else
    {
        if (a==0)
            printf("\nClient IP address is invalid\n");
        if (b==0)
            printf("\nClient MAC address is invalid\n");
        return 0;
    }
}

struct packet test()
{
    printf("\nEnter the details of packet received\n");
    struct packet p;
    printf("\nDestination IP :Automatically generated for testing\n");
    //scanf("%s",p.desti_ip);
    strcpy(p.desti_ip,"155.157.65.128");
    printf("\nSource IP      :Automatically generated for testing\n");
    //scanf("%s",p.source_ip);
    strcpy(p.source_ip,"123.128.34.56");
    printf("\nSource MAC     :Automatically generated for testing\n");
    //scanf("%s",p.source_mac);
    strcpy(p.source_mac,"AF-45-E5-00-97-12");
    printf("\n16-bit data    :Automatically generated for testing\n");
    strcpy(p.data,"1011110000101010");
    return p;
}
char* packet_generation(struct packet p)
{
    printf("\nDeveloping ARP Request packet\n");
    char *pack;
    pack = (char*)malloc(sizeof(char)*1000);
    sprintf(pack,"%s|%s|%s",p.source_ip,p.source_mac,p.desti_ip);
    printf("\n\t%s\n",pack);
    return pack;
}

#define PORT 7228

int main(int argc ,int **argv)
{
    int sockfd,ret,len,n;
    struct sockaddr_in serverAddr;

    int newfd;
    struct sockaddr_in clientAddr;

    char buffer[1024];
    char str[1000];
    // pid_t child;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0)
    {
        printf("----------Error in Connection.\n");
        exit(1);
    }    
    bzero(&serverAddr,sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    struct packet p;
    p = test();
    strcpy(buffer,packet_generation(p));

    ret = bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
    if(ret < 0)
    {
        printf("----------Error in Binding.\n");
        exit(1);
    } 
    listen(sockfd,10);
    len = sizeof(clientAddr);
    printf("\nThe ARP Request Packet is broadcasted\nWaiting for ARP Reply..\n");
    while(1)
    {
    newfd = accept(sockfd,(struct sockaddr*)&clientAddr,&len);
    //broadcasting message whoever connecting to server..

    send(newfd,buffer,sizeof(buffer),0);
    n=recv(newfd,buffer,sizeof(buffer),0);
    if(n>0)
    {
    printf("\nARP Reply received\n\n%s\n",buffer);
    if (verify(buffer))
    {
        strcat(buffer,"|");
        strcat(buffer,p.data);
        strcpy(str,getMac(buffer));
        printf("Sending the packet to :%s",str);
        send(newfd,buffer,sizeof(buffer),0);
        printf("\nPacket Sent :\n%s\n",buffer);
        break;
    }
    else
    {
        printf("\nProcess Terminated\n");
        break;
    }}
    }
    close(sockfd);
    close(newfd);
    return 0;    
}
