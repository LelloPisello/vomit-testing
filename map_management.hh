#ifndef MAP_h_
#define MAP_h_

#include "geometry.hh"
#include "texture.hh"
#include "entity.hh"
#include "utils.hh"
//caricamento mappe e strutture per contenere i dati sulla mappa

namespace geo
{
  //contiene tutte le informazioni sulla mappa
  /*
  pensavo di riempire una di queste strutture ogni volta che entro in una mappa
  contiene la palette della mappa, l'array delle entità, e l'array delle texture
  */
  
  struct BSP_sector_t
  {
    mesh3D geometry; //geometria del settore
    plane3D plane; //piano per il bsp
  };
  
  using BSP_tree_t = binary_tree_t
  <BSP_sector_t>; //albero binario contenente i settori bsp
  
  struct map_t
  {
    mesh3D* sectors; //settori dopo il BSP (da creare una classe sector)
    unsigned num_sectors; //numero di settori
    //palette_t palette; da infilare da qualche altra parte, tipo nella sezione di rendering
    palette_texture_list_t texture_list; //palette
    entity_list_t entity_list; //array contenente le entità, (si potrebbe escludere il numero di tipi da qua dentro)
    map_t(const map_t&);
    map_t(map_t&&);
    constexpr map_t(void) : sectors(nullptr), num_sectors(0) {}
    ~map_t(void);
  };
}
#endif
