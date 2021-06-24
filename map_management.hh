#ifndef MAP_h_
#define MAP_h_

#include "geometry.hh"

//caricamento mappe e strutture per contenere i dati sulla mappa

namespace geo
{
  //contiene informazioni sulla mappa
  struct map_t
  {
    mesh3D* sectors; //settori dopo il BSP
    unsigned num_sectors; //numero di settori
    map_t(const map_t&);
    map_t(map_t&&);
    constexpr map_t(void) : sectors(nullptr), num_sectors(0) {}
    ~map_t(void);
  };

  struct map_loader_t //carica in memoria tutte le informazioni sulla mappa dal file file_location
  {
  private:
    const char* file_location;
  public:
    map_loader_t& open(const char*);
    const map_loader_t& operator >> (map_t&) const;
  };
}
#endif
