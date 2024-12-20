#include "console.h"

bool csl::check( int val, int con, string msg )
{
   string err = "error: ";
   if ( val < con )
   {
      cout << err + msg << endl;
      return false;
   }
   return true; 
}
