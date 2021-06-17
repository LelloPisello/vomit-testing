#ifndef GEOMETRY_h_
#define GEOMETRY_h_
//header guards

namespace geo
{
    //vettore a tre componenti
    struct vec3
    {
        float x, y, z;

        //costruttori
        vec3(void);
        constexpr vec3(float, float, float);
        constexpr vec3(const vec3&);
        constexpr vec3(float);

        ~vec3(void) = default;

        //accesso via []
        operator float*(void);
        constexpr float at(unsigned) const;

        vec3& operator = (const vec3&) = default;

        vec3 operator + (const vec3&) const;
        vec3 operator - (const vec3&) const;
        vec3 operator * (const vec3&) const;
        vec3 operator / (const vec3&) const;

        vec3& operator += (const vec3 &);
        vec3& operator -= (const vec3 &);
        vec3& operator *= (const vec3 &);
        vec3& operator /= (const vec3 &);
    };

    float length(const vec3 &);
    vec3 normalize(const vec3 &);

    //prodotto scalare
    float dot(const vec3 &, const vec3 &);
    //prodotto vettoriale
    vec3 cross(const vec3 &, const vec3 &);
}

#endif