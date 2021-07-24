#include "texture.hh"
#include "utils.hh"

namespace vomit
{
  //sezione dedicata ad alcuni costruttori e funzioni della struttura palette_t
  palette_t::palette_t(const char* filename)
  {
    //da riempire con il codice per la lettura e il parsing dei file .plt 
  }
  palette_t& palette_t::from_file(const char* filename)
  {
    //da riempire con il codice analogo al costruttore (const char*) 
    return *this;
  }
  color32_t palette_t::operator[] (u8 index)
  {
    return range[index]; 
  }
  
  texture_t::texture_t(const char* filename)
  {
    //da riempire con codice per fare parsing di .png e .jpg 
  }
  texture_t::~texture_t(void)
  { //elimina i dati salvati in memoria dinamica con la texture
    for (int i = 0; i < image_size.x; ++i) delete[] image[i]; 
  }
  color32_t texture_t::from_uv(float x, float y)
  {//ritorna il colore della texture al punto x, y
    return image
      [
        int(x * (image_size.x - 1))
      ]
      [
        int(y * (image_size.y - 1))
      ];
  }
  
  //sezione texture con palette
  palette_texture_t::palette_texture_t(const char* filename)
  {
    //caricare dati da immagini di file .tex 
  }
  palette_texture_t::~palette_texture_t(void)
  {//elimina la parte di memoria dinamica della texture
    for(int i = 0; i < image_size.x; ++i) delete[] image[i];
  }
  u8 palette_texture_t::from_uv(float x, float y) // da sostituire unsigned char con byte_t 
  {
    //ritorna il colore della palette rispetto all'indice dato dalla texture
    return
      image
      [
        int(x * (image_size.x - 1))
      ]
      [
        int(y * (image_size.y - 1))
      ];
  }
  
  
  //lista di texture
  texture_list_t::texture_list_t(void) : texture_list(nullptr), texture_num(0) {}
  texture_list_t::texture_list_t(const char* filename) 
  {
    //da riempire con file .txl 
  }
  texture_list_t::~texture_list_t(void) 
  {
    //elimina la parte della lista in memoria dinamica
    delete[] texture_list; 
  }
  texture_list_t& texture_list_t::from_file(const char* filename)
  {
    //stessa roba
    return *this;
  }
  
  //lista di texture con palette
  palette_texture_list_t::palette_texture_list_t(void) : texture_list(nullptr), texture_num(0) {}
  palette_texture_list_t::palette_texture_list_t(const char* filename) 
  {
    //da riempire con file .txl 
  }
  palette_texture_list_t::~palette_texture_list_t(void) 
  {
    //elimina la parte della lista in memoria dinamica
    delete[] texture_list; 
  }
  palette_texture_list_t& palette_texture_list_t::from_file(const char* filename)
  {
    //stessa roba
    return *this;
  }
  
}//namespace geo
