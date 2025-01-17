#include "player.h"

void plyr_iface::add ( plyr _plr )
{
  plyr_iface::list.push_back(_plr);
}

plyr plyr_iface::pop ( )
{
  return plyr_iface::list.back( ); 
}
