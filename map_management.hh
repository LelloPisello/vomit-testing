#ifndef MAP_h_
#define MAP_h_

#include "geometry.hh"
#include "texture.hh"
#include "entity.hh"
//caricamento mappe e strutture per contenere i dati sulla mappa

namespace geo
{
  //contiene tutte le informazioni sulla mappa
  /*
  pensavo di riempire una di queste strutture ogni volta che entro in una mappa
  contiene la palette della mappa, l'array delle entità, e l'array delle texture
  */
  struct map_t
  {
    mesh3D* sectors; //settori dopo il BSP (da creare una classe sector)
    unsigned num_sectors; //numero di settori
    palette_t palette; //palette
    palette_texture_list_t texture_list; //palette
    entity_info_t* entity_types;//tipi di entità 
    u16 num_entity_types;
    entity_list_t entity_list; //array contenente le entità, (si potrebbe escludere il numero di tipi da qua dentro)
    map_t(const map_t&);
    map_t(map_t&&);
    constexpr map_t(void) : sectors(nullptr), num_sectors(0) {}
    ~map_t(void);
  };
}
#endif
