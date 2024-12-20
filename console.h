#ifndef SRVR_DI_CSL
#define SRVR_DI_CSL

#include <string>
#include <iostream>
using namespace std;

class csl 
{ 
   public:
     /* check int value & print msg if invalid */
     static bool check ( int val, int con, string msg );
};

#endif
