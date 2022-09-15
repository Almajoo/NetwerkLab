#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
int main(int argc,char* argv[])
{
    struct sockaddr_in server,client;
    if(argc!=2)
    printf("Input format not correct");
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==-1)
    printf("Error in socket();");
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(atoi(argv[1]));
    if(bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
    printf("Error in blind()! \n");
    char buffer[100];
    socklen_t server_len=sizeof(server);
    printf("server waiting.....");
    if(recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&server,&server_len)<0)
    printf("Error in recvfrom()!");
    printf("Got a datagram:%s",buffer);
    return 0;
}

/*
OUTPUT

s7csb-2@labb29:~/sneha31$ gcc udps.c -o s
s7csb-2@labb29:~/sneha31$ ./s 2050

server waiting.....Got a datagram:hai
*/    
