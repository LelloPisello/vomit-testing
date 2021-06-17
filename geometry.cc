#include "geometry.hh"

namespace geo
{
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


}