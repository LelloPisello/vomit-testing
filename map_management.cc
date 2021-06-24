#include "map_management.hh"

namespace geo
{
  //costruttore di copia
  map_t::map_t(const map_t& that) : num_sectors(that.num_sectors), sectors(new mesh3D[that.num_sectors])
  {
    for(unsigned short i = 0; i < num_sectors; ++i)
    {
      sectors[i] = that.sectors[i]; 
    }
  }
  //costruttore move
  map_t::map_t(map_t&& that) : num_sectors(that.num_sectors), sectors(that.sectors)
  {
    that.sectors = nullptr;
  }
  //distruttore (pulisce anche la mappa dalla memoria dinamica)
  map_t::~map_t(void)
  {
    delete[] sectors; 
  }
}
