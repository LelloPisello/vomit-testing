#ifndef ENTITY_h_
#define ENTITY_h_
//per tenere la posizione e l'angolo delle enità
#include "geometry.hh"

// struct di base da cui derivano tutte le entità
struct entity_t
{
    geo::vec3 position;
    geo::vec3 angle;
    unsigned short frame_n;
};
//struct derivata per entita di tipo mostro 
struct monster_t:entity_t
{
    short health;
    unsigned char variant;
};




#endif



