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
    int num;
    socklen_t server_len=sizeof(server);
    printf("server waiting.....");
    if(recvfrom(sockfd,&num,100,0,(struct sockaddr*)&server,&server_len)<0)
    printf("Error in recvfrom()!");
    int i;
    int fact=1;
    for(i=1;i<=num;i++){
    fact=fact*i;}
    printf("factorial is %d",fact);
        return 0;
}
