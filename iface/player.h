#ifndef SRV_DI_PLYR
#define SRV_DI_PLYR

#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <stdint.h>
#include <vector>

class plyr
{
  public:
    string      key; 
    string      nick; 
    string      json; 
    sockaddr_in sock_in;  

    plyr( string _k, string _n, string _j ) 
    {
      key = _k; nick = _n; json = _j; 
    }
};

class plyr_iface 
{
  public:
    static vector<plyr> list; 
    static void add ( plyr _plr );
};

#endif
