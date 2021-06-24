#ifndef ENTITY_h_
#define ENTITY_h_
//per tenere la posizione e l'angolo delle enità
#include "geometry.hh"

namespace geo
{
    struct entity_info_t //contiene le informazioni condivise per ogni tipo di entità 
    {
        const mesh3D model; //[numero varianti]
        const short starting_health;
        const vec3 bounding_box_size;
        //da aggiungere: suoni, varianti di tipo
    };
    
    struct entity_t //contiene le informazioni specifiche di ogni entità
    {
        vec3 position;
        vec3 angle;
        const unsigned char //non so se funza
            entity_type : 6; //0 - 64 per il tipo di nemico
            entity_variant : 2; //0 - 4 per la variante (da implementare)
        unsigned short frame_n;
        short health;
    };
}

#endif



