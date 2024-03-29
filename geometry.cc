#include "geometry.hh"
#include <cmath>

namespace vomit
{
    //vec3:
        //costruttori
        vec3::vec3(void) = default;

        //operator overloading per le parentesi []
        vec3::operator float *(void)
        {
            return &x;
        }

        //overload per assegnazione speciale
        vec3& vec3::operator+=(const vec3& that)
        {
            return *this = *this + that;
        }
        vec3 &vec3::operator-=(const vec3 &that)
        {
            return *this = *this - that;
        }
        vec3 &vec3::operator*=(const vec3 &that)
        {
            return *this = *this * that;
        }
        vec3 &vec3::operator/=(const vec3 &that)
        {
            return *this = *this / that;
        }
    
    //vec2
        //costruttori
        vec2::vec2(void) = default;

        //accesso con []
        vec2::operator float *(void)
        {
            return &x;
        }

        //assegnazioni speciali
        vec2& vec2::operator+=(const vec2& that)
        {
            return *this = *this + that;
        }
        vec2 &vec2::operator-=(const vec2 &that)
        {
            return *this = *this - that;
        }
        vec2 &vec2::operator*=(const vec2 &that)
        {
            return *this = *this * that;
        }
        vec2 &vec2::operator/=(const vec2 &that)
        {
            return *this = *this / that;
        }

    //funzioni per i vettori
        float length(const vec3& that)
        {
            return sqrtf(that.x * that.x + that.y * that.y + that.z * that.z);
        }
        float length(const vec2& that)
        {
            return sqrtf(that.x * that.x + that.y * that.y);
        }
        
        vec3 normalize(const vec3& that)
        {
            float m = 1. / length(that);
            return that * vec3(m);
        }
        vec2 normalize(const vec2& that)
        {
            float m = 1. / length(that);
            return that * vec2(m);
        }

        mesh3D& mesh3D::operator=(const mesh3D& obj)
        {
            if(triangles) delete[] triangles;
            triangle_num = obj.triangle_num;
            triangles = new triangle3D[triangle_num];
            for(u16 i = 0; i < triangle_num; ++i)
            {
                triangles[i] = obj.triangles[i];
            }
            return *this;
        }
        mesh3D& mesh3D::operator=(mesh3D&& obj)
        {
            if(triangles) delete[] triangles;
            triangle_num = obj.triangle_num;
            triangles = obj.triangles;
            obj.triangles = nullptr;
            return *this;
        }
}