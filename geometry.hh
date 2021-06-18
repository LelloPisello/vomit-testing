#ifndef GEOMETRY_h_
#define GEOMETRY_h_
//header guards



//IMPORTANTE: le funzioni constexpr vengono definite qua
namespace geo
{
    struct vec2
    {
        float x, y;

        //costruttori
        vec2(void);
        constexpr vec2(float x, float y) : x(x), y(y) {}
        constexpr vec2(const vec2& that) : x(that.x), y(that.y) {}
        constexpr vec2(float val) : x(val), y(val) {}

        ~vec2(void) = default;

        //accesso con []
        operator float *(void);
        constexpr float at(unsigned index) const
        {
            switch (index)
            {
            case 0:
                return x;
            default:
                return y;
            }
        }

        //operator overloading
        vec2 &operator=(const vec2 &) = default;

        constexpr vec2 operator+(const vec2& that) const
        {
            return vec2(x + that.x, y + that.y);
        }
        constexpr vec2 operator-(const vec2& that) const
        {
            return vec2(x - that.x, y - that.y);
        }
        constexpr vec2 operator*(const vec2& that) const
        {
            return vec2(x + that.x, y + that.y);
        }
        constexpr vec2 operator/(const vec2& that) const
        {
            return vec2(x + that.x, y + that.y);
        }

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
        constexpr vec3(float x, float y, float z) : x(x), y(y), z(z) {}
        constexpr vec3(const vec3& that) : x(that.x), y(that.y), z(that.z) {}
        constexpr vec3(float val) : x(val), y(val), z(val) {}

        ~vec3(void) = default;

        //accesso via []
        operator float*(void);
        //[] ma calcolato in compilazione
        constexpr float at(unsigned index) const
        {
            switch (index)
            {
            case 0:
                return x;
            case 1:
                return y;
            default:
                return z;
            }
        }

        vec3& operator = (const vec3&) = default;

        constexpr vec3 operator + (const vec3& that) const
        {
            return vec3(x + that.x, y + that.y, z + that.z);
        }
        constexpr vec3 operator - (const vec3& that) const
        {
            return vec3(x - that.x, y - that.y, z - that.z);
        }
        constexpr vec3 operator * (const vec3& that) const
        {
            return vec3(x * that.x, y * that.y, z * that.z);
        }
        constexpr vec3 operator / (const vec3& that) const
        {
            return vec3(x / that.x, y / that.y, z / that.z);
        }

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
    constexpr float dot(const vec3 &a, const vec3 &b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
    constexpr float dot(const vec2 &a, const vec2 &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    //prodotto vettoriale
    constexpr vec3 cross(const vec3 &a, const vec3 &b)
    {
        return vec3
        {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    struct vertex3D 
    {
        vec3 position;
        vec2 uv;
    };

    //lista di vertici e numero, caricato da file in header #TODO
    struct mesh3D
    {
        vertex3D *vertices;
        unsigned vert_num;
    };
}

#endif