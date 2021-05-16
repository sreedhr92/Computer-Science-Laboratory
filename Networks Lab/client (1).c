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


int main(int argc, char  **argv)
{
	/* code */
	int sockfd , ret,n,len;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	char str[1000];

    struct input i;

    printf("\nEnter the client id :");
    scanf("%d",&i.id);

    struct tm* local;
	
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

    printf("\nRequesting to the server!");
    //time_t rawtime;
	//time(&rawtime);
    char ans;

    int x;
    while(1)
    {

        printf("\n1.Date\n2.Day\n3.Month\n4.Year\n5.Time\n6.Toronto\nEnter your option:");
        scanf("%d",&i.option);
        x = i.option;
        if (x < 1|| x > 6)
            continue;
        sendto(sockfd,&i,sizeof(i),0,(struct sockaddr *)&serverAddr,len);
        recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&serverAddr,&len);
        if (x==1)
            printf("\nThe Date is %s\n",buffer);
        else if (x==2)
            printf("\nThe Day is %s\n",buffer);
        else if (x==3)
            printf("\nThe Month is %s\n",buffer);
        else if (x==4)
            printf("\nThe year is %s\n",buffer);
        else if (x==5)
            printf("\nThe Time is %s\n",buffer);
        else if (x==6)
        {
            time_t rawtime;
	        time(&rawtime);
            local = localtime(&rawtime);
            strftime(str,sizeof(str),"%c ",local);
            printf("\nThe Local time is %s\n",str);
            printf("\nThe Toronto time is %s\n",buffer);
        }
        printf("\nDo you want to continue(1/0):");
        scanf("%d",&x);
        if (x == 0 )
            break;
    }
}



