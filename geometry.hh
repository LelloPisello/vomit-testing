#ifndef GEOMETRY_h_
#define GEOMETRY_h_
//header guards

namespace geo
{
    struct vec2
    {
        float x, y;

        //costruttori
        vec2(void);
        constexpr vec2(float, float);
        constexpr vec2(const vec2 &);
        constexpr vec2(float);

        ~vec2(void) = default;

        //accesso con []
        operator float *(void);
        constexpr float at(unsigned) const;

        //operator overloading
        vec2 &operator=(const vec2 &) = default;

        vec2 operator+(const vec2 &) const;
        vec2 operator-(const vec2 &) const;
        vec2 operator*(const vec2 &) const;
        vec2 operator/(const vec2 &) const;

        vec2 &operator+=(const vec2 &);
        vec2 &operator-=(const vec2 &);
        vec2 &operator*=(const vec2 &);
        vec2 &operator/=(const vec2 &);
    };
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
    float length(const vec2 &);
    vec3 normalize(const vec3 &);
    vec2 normalize(const vec2 &);
    //prodotto scalare
    float dot(const vec3 &, const vec3 &);
    float dot(const vec2 &, const vec2 &);
    //prodotto vettoriale
    vec3 cross(const vec3 &, const vec3 &);

    struct vertex3D 
    {
        vec3 position;
        vec2 uv;
    };
}

#endif