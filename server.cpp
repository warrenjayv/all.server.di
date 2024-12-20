#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "console.h"

int main ( )
{
    int sfd = socket( AF_INET, SOCK_DGRAM, 0 ); 
    csl.check( sfd, 0, "failed to create socket" ); 
}
