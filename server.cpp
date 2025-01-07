#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <nlohmann/json.hpp>
#include "console.h"

// usages
using json = nlohmann::json; 

// macros
#define MAX   1024
#define PORT  50116

int main ( )
{
    // json macros
    string KEY = "msg";
    string NIK = "nick";
    
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
       // struct len 
       _len = sizeof(_cliaddr); 

       // receive data
       _recsz = recvfrom( sfd, (char *)buffer, MAX, MSG_WAITALL, (struct sockaddr *) &_cliaddr, &_len); 
       buffer[_recsz] = '\0';
      
       if ( _recsz > 0 ) 
       {
          // setup string stream
          json ex = json::parse((char*) buffer); 

          // print buffer
          printf("client: %s\n", buffer); 

          // check message
          if ( ex.contains(KEY)) 
          {
            string val = ex[KEY];
            string nik = ex[NIK];
            cout << nik << ":" << val << endl; 

            // formulate response 
            string _resp = nik + ":" + val;  
        
            // send buffer
            char _sbuff[_resp.length( )+1];
            strcpy( _sbuff, _resp.c_str()); 

            // check
            printf("sending: %s\n", _sbuff); 

            // send reply 
            int _sensz = sendto( sfd, _sbuff, strlen(_sbuff), 0, (sockaddr*)&_cliaddr, sizeof(_cliaddr));
            if (_sensz < 0)
            {
              cerr << "sendto failed: " << strerror(errno) << endl; 
              continue;  
            } 
            memset(_sbuff, 0, sizeof(_sbuff)); 
            
          }

       }
       usleep(1000000);
    }
    
    // close socket 
    close(sfd); 
}
