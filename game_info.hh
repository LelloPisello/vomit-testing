#ifndef GAME_INFO_h_
#define GAME_INFO_h_

#include "utils.hh"
#include "geometry.hh"
#include "texture.hh"
#include "entity.hh"

namespace geo
{
  //verrà riempita una struct di questo tipo all'avvio del motore o quando specificato in console
  struct game_info_t
  {
    palette_t palette;

    entity_info_t* entity_type_list;
    u8 entity_type_num;
  };
  
}

#endif
