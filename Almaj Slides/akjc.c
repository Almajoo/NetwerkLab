#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

// The channel's port
#define CHANNELPORT "4950"
// Our receiving buffer length
#define MAXBUFLEN   100
// Size of our frame
#define MAXMESGLEN  1

int main(int argc, char *argv[])
{
    int sockfd;                          
    struct addrinfo hints, *servinfo, *p; 
    int rv;                               
    int numbytes;                         
        socklen_t addr_len;                   
        struct sockaddr_storage their_addr;   

        char buf[MAXBUFLEN];                  
        char myframe[MAXMESGLEN];             

        char *mesg = "A";                     // Message to be sent

        
        fd_set fds;
        int rc;
        struct timeval timeout;


     
    memset(&hints, 0, sizeof hints);
    hints.ai_family   = AF_UNSPEC;        
    hints.ai_socktype = SOCK_DGRAM;      

        
    if ((rv = getaddrinfo("127.0.0.1", CHANNELPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    
    for(p = servinfo; p != NULL; p = p->ai_next) 
        {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        break;
    }

       
    if (p == NULL) {
        fprintf(stderr, "client: failed to bind socket\n");
        return 2;
    }

        myframe[0] = mesg[0];

      
    if ((numbytes = sendto(sockfd, myframe, MAXMESGLEN, 0,
                       p->ai_addr, p->ai_addrlen)) == -1) 
        {
        perror("talker: sendto");
        exit(1);
    }

        printf("Done Sending: %d\n", numbytes);

     
    freeaddrinfo(servinfo);
    close(sockfd);
    return 0;
}
