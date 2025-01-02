#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "console.h"

// macros
#define MAX   1024
#define PORT  50116

int main ( )
{
    // parameters
    char buffer[MAX] = {0}; 
    struct sockaddr_in _srvaddr = { 0 };
    struct sockaddr_in _cliaddr = { 0 };

    // client 
    socklen_t _len; 
    int _recsz; 
    
    // create socket
    int sfd = socket( AF_INET, SOCK_DGRAM, 0 ); 
    if ( !csl::check( sfd, 0, "failed to create socket" )) { return 0; }

    // populate server info
    _srvaddr.sin_family      = AF_INET; 
    _srvaddr.sin_port        = htons(PORT);
    _srvaddr.sin_addr.s_addr = INADDR_ANY; 

    // bind 
    if ( !csl::check 
    ( 
       bind( sfd, (const struct sockaddr *) &_srvaddr, sizeof(_srvaddr)),
       0, 
       "failed to bind"
    )) { exit(EXIT_FAILURE); } 

    // daemon
    while ( true ) 
    {
       _len = sizeof(_cliaddr); 
       _recsz = recvfrom( sfd, (char *)buffer, MAX, MSG_WAITALL, (struct sockaddr *) &_cliaddr, &_len); 
       buffer[_recsz] = '\0';
       printf("client: %s\n", buffer); 
       usleep(1000000);
    }
    
    // close socket 
    close(sfd); 
}
