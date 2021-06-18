#include "geometry.hh"
#include "cmath"

namespace geo
{
    //vec3:
        //costruttori
        constexpr vec3::vec3(float x, float y, float z) :
            x(x), y(y), z(z) {}
        constexpr vec3::vec3(const vec3& that) :
            x(that.x), y(that.y), z(that.z) {}
        constexpr vec3::vec3(float val) :
            x(val), y(val), z(val) {}
        vec3::vec3(void) = default;

        //operator overloading per le parentesi []
        vec3::operator float *(void)
        {
            return &x;
        }
        //parentesi [] ma costanti
        constexpr float vec3::at(unsigned index) const
        {
            switch(index)
            {
                case 0:
                    return x;
                case 1:
                    return y;
                default:
                    return z;
            }
        }
        //operator overloading per operazioni matematiche
        constexpr vec3 vec3::operator + (const vec3& that) const
        {
            return vec3(x + that.x, y + that.y, z + that.z);
        }
        constexpr vec3 vec3::operator-(const vec3 &that) const
        {
            return vec3(x - that.x, y - that.y, z - that.z);
        }
        constexpr vec3 vec3::operator*(const vec3 &that) const
        {
            return vec3(x * that.x, y * that.y, z * that.z);
        }
        constexpr vec3 vec3::operator/(const vec3 &that) const
        {
            return vec3(x / that.x, y / that.y, z / that.z);
        }
        //overload per assegnazione speciale
        vec3& vec3::operator+=(const vec3& that)
        {
            return *this = *this + that;
        }
        vec3 &vec3::operator+=(const vec3 &that)
        {
            return *this = *this - that;
        }
        vec3 &vec3::operator+=(const vec3 &that)
        {
            return *this = *this * that;
        }
        vec3 &vec3::operator+=(const vec3 &that)
        {
            return *this = *this / that;
        }
    
    //vec2
        //costruttori
        constexpr vec2::vec2(float x, float y) : x(x), y(y) {}
        constexpr vec2::vec2(const vec2& that) : x(that.x), y(that.y) {}
        constexpr vec2::vec2(float val) : x(val), y(val) {}
        vec2::vec2(void) = default;

        //accesso con []
        vec2::operator float *(void)
        {
            return &x;
        }
        constexpr float vec2::at(unsigned index) const
        {
            switch(index)
            {
                case 0:
                    return x;
                default:
                    return y;
            }
        }

        //overloading operazioni matematiche
        constexpr vec2 vec2::operator + (const vec2& that) const
        {
            return vec2(x + that.x, y + that.y);
        }
        constexpr vec2 vec2::operator-(const vec2 &that) const
        {
            return vec2(x - that.x, y - that.y);
        }
        constexpr vec2 vec2::operator*(const vec2 &that) const
        {
            return vec2(x + that.x, y + that.y);
        }
        constexpr vec2 vec2::operator/(const vec2 &that) const
        {
            return vec2(x + that.x, y + that.y);
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
            return that * m;
        }
        vec2 normalize(const vec2& that)
        {
            float m = 1. / length(that);
            return that * m;
        }

        constexpr float dot(const vec3& v1, const vec3& v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }
        constexpr float dot(const vec2& v1, const vec2& v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        constexpr vec3 cross(const vec3& v1, const vec3& v2)
        {
            return vec3
            {
                v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x
            };
        }
}