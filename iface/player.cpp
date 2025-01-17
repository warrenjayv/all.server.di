#include "player.h"

bool plyr_iface::contain(std::string _name)
{
   auto it = std::find_if(plyr_iface::list.begin(), plyr_iface::list.end(), [&_name]( const plyr& _p )
   {
      return _p.nick == _name;
   });

   if ( it != plyr_iface::list.end())
   {
      return true;
   } 
   return false; 
}

void plyr_iface::add ( plyr _plr )
{
  plyr_iface::list.push_back(_plr);
}

plyr plyr_iface::pop ( )
{
  return plyr_iface::list.back( ); 
}

