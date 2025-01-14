#ifndef SRV_DI_PLYR
#define SRV_DI_PLYR

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdint.h>
#include <vector>

class plyr
{
  public:
    std::string key; 
    std::string nick; 
    std::string json; 
    sockaddr_in sock_in;  

    plyr( std::string _k, std::string _n, std::string _j, sockaddr_in _in ) 
    {
      key = _k; nick = _n; json = _j; 
      sock_in = _in; 
    }
};

class plyr_iface 
{
  
  private:
    static std::vector<plyr> list; 

  public:
    static void add ( plyr _plr )
    {
       list.push_back(_plr); 
    }

    static plyr pop ( )
    {
       list.pop_back( ); 
    }
};

#endif
