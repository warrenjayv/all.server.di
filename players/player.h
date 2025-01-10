#ifndef SRV_DI_PLYR
#define SRV_DI_PLYR

#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <vector>

class plyr
{
  public:
    string      key; 
    string      nick; 
    string      json; 
    sockaddr_in sock_in;  
}

class plyr_iface 
{
  public:
    static vector<plyr> list; 
}

#endif
