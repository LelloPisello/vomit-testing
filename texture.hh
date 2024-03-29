#ifndef TEXTURE_h_
#define TEXTURE_h_

#define PALETTE_SIZE 256
#include "utils.hh"
#include "geometry.hh"

namespace vomit
{
  struct color24_t //colore a 24 bit (come da schermo)
  {
    u8 r, g, b;
  };

  struct color32_t //colore a 32 bit (come da schermo ma con opacità)
  {
    u8 r, g, b, a;
  };

  struct palette_t
  {
  private: 
    color32_t range[PALETTE_SIZE]; //risparmio memoria usando texture da palette
  public:
    constexpr palette_t(void) : range{} {}
    palette_t(const char*);
    palette_t& from_file(const char* filename); //carica i colori della palette da un file di tipo .plt
    color32_t operator[](u8) const; //ritorna il colore della palette all'indice x
  };

  struct texture_t
  {
    color32_t** image;
    vec2 image_size;
    constexpr texture_t(void) : image(nullptr), image_size(vec2{0, 0}) {}
    ~texture_t(void);
    texture_t(const char* filename); //carica texture in memoria da file
    color32_t from_uv(float x, float y) const;
  };

  struct palette_texture_t //texture utilizzante 
  {
    u8** image;
    vec2 image_size;
    constexpr palette_texture_t(void) : image(nullptr), image_size(vec2{0, 0}) {}
    ~palette_texture_t(void);
    palette_texture_t(const char* filename); //carica texture in memoria da file di tipo .tex
    u8 from_uv(float x, float y) const;
  };

  struct texture_list_t
  {
    texture_t* texture_list;
    u8 texture_num;
    texture_list_t(void);
    texture_list_t(const char* filename);
    ~texture_list_t(void);
    texture_list_t& from_file(const char* filename); //carica la lista di texture da un file .txl (texture list)
  };

  struct palette_texture_list_t
  {
    palette_texture_t* texture_list;
    u8 texture_num;
    palette_texture_list_t(void);
    palette_texture_list_t(const char* filename);
    ~palette_texture_list_t(void);
    palette_texture_list_t& from_file(const char* filename); // carica la lista di texture da un file .ptxl (palette texture list)
  };

} //namespace geo

#endif
