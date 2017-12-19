#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "main.h"

int main( int argc, char ** argv )
{
    char   recv[RECV_SEND_LEN_MAX+1];
    int      connfd;
    int       nread;
    int       len;
    struct sockaddr_in servaddr;
    int loop;   
    int num;
   
    if( ( connfd= socket(  AF_INET, SOCK_DGRAM,0  ) ) == -1 )
    {
      printf("Socket error.. %d\n", errno);
       exit(EXIT_FAILURE );
    }
   
   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr=inet_addr(SERVER_IP);  
    servaddr.sin_port=htons(SERVER_PORT); 
     
       memset(recv, 0, sizeof( recv ) );
       strncpy(recv,send_msg,RECV_SEND_LEN_MAX);
   
    for(loop = 0 ; loop < RECV_SEND_CNT; loop ++)
    {
       sendto(connfd,recv, strlen(recv), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
    }

    close(connfd );
      
    return 0;
}
