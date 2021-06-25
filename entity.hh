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
            //entity_type : 6; rimosso perchè viene dichiarato implicitamente durante il piazzamento nell'array delle entità 
            entity_variant;// : 2; //0 - 4 per la variante (da implementare)
        unsigned short frame_n;
        short health;
    };
    
    struct entity_list_t
    {
        entity_t*** entity_list; //triplo pointer, array sostanzialmente bidimensionale, dato che l'ultimo "passaggio" conterrà un entità sola.
        const unsigned short num_types; //le dimensioni dell'array principale saranno fisse
        //costruttori
        constexpr entity_list_t(void) : entity_list(nullptr) {}
        explicit entity_list_t(unsigned short num_types);
        explicit entity_list_t(const char* filename);
        entity_list_t(const entity_list_t&) = delete;
        entity_list_t(entity_list&&);
        ~entity_list_t(void);
        
        entity_list_t& from_file(const char* filename); 
        
        entity_list_t& operator = (const entity_list_t&) = delete;
        entity_list_t& operator = (entity_list_t&&);
    };
}

#endif



