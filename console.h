#include <string>
#include <iostream>
using namespace std;

class csl 
{ 
   /* check int value & print msg if invalid */
   public bool check ( int val, int con, string msg )
   {
      string err = "error: ";
      if ( val < con ) 
      { 
        cout  << err + msg << endl; 
        return false; 
      }
      return true; 
   }
}
