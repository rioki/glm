
#include "vec3.h"

#include <cstring>
#include <cmath>
#include <algorithm>

#include "vec2.h"
#include "vec4.h"

namespace glm
{
    vec3::vec3() {}
    
    vec3::vec3(float v)
    {
        data[0] = v;
        data[1] = v;
        data[2] = v;
    }
    
    vec3::vec3(float x, float y, float z)
    {
        data[0] = x;
        data[1] = y;
        data[2] = z;
    }
    
    vec3::vec3(const vec2& v, float z)
    {
        data[0] = v[0];
        data[1] = v[1];
        data[2] = z;
    }
        
    vec3::vec3(float x, const vec2& v)
    {
        data[0] = x;
        data[1] = v[0];
        data[2] = v[1];
    }
    
    vec3::vec3(const vec4& v)
    {
        data[0] = v[0];
        data[1] = v[1];
        data[2] = v[2];
    }
        
    vec3::vec3(const vec3& v)
    {
        std::memcpy(data, v.data, 3 * sizeof(float));
    }
        
    vec3::~vec3() {}
        
    const vec3& vec3::operator = (const vec3& v)
    {
        if (this != &v)
        {
            std::memcpy(data, v.data, 3 * sizeof(float));
        }
        return *this;
    }
    
    const vec3& vec3::operator += (const vec3& v)
    {
        data[0] += v.data[0];
        data[1] += v.data[1];
        data[2] += v.data[2];
        return *this;
    }

    const vec3& vec3::operator -= (const vec3& v)
    {
        data[0] -= v.data[0];
        data[1] -= v.data[1];
        data[2] -= v.data[2];
        return *this;
    }
        
    float& vec3::operator [] (unsigned int i)
    {
        return data[i];
    }
        
    float vec3::operator [] (unsigned int i) const
    {
        return data[i];
    }
        
    vec3 operator + (const vec3& v)
    {
        return v;
    }
    
    vec3 operator - (const vec3& v)
    {
        return vec3(-v[0], -v[1], -v[2]);
    }
    
    vec3 operator + (const vec3& a, const vec3& b)
    {
        vec3 tmp = a;
        tmp += b;
        return tmp;
    }
    
    vec3 operator - (const vec3& a, const vec3& b)
    {
        vec3 tmp = a;
        tmp -= b;
        return tmp;
    }
    
    vec3 operator * (const vec3& a, const vec3& b)
    {
        return vec3(a[0] * b[0], a[1] * b[1], a[2] * b[2]);
    }
    
    vec3 operator / (const vec3& a, const vec3& b)
    {
        return vec3(a[0] / b[0], a[1] / b[1], a[2] / b[2]);
    }    
    
    vec3 operator * (const vec3& v, float s)
    {
        return vec3(v[0] * s, v[1] * s, v[2] * s);
    }
    
    vec3 operator * (float s, const vec3& v)
    {
        return v * s;
    }
    
    float dot(const vec3& a, const vec3& b)
    {    
        return a[0] * b[0] + a[1] * b[1] + b[2] * b[2];
    }
    
    vec3 cross (const vec3& a, const vec3& b)
    {
        return vec3 ((a[1] * b[2]) - (a[2] * b[1]),
                     (a[2] * b[0]) - (a[0] * b[2]),
                     (a[0] * b[1]) - (a[1] * b[0]));
    }
    
    float length (const vec3& v)
    {
        return std::sqrt(dot(v, v));
    }

    float distance(const vec3& a, const vec3& b)
    {
        return length(a - b);
    }
    
    vec3 normalize(const vec3& v)
    {
        return v * (1 / length(v));
    }
    
    vec3 min(const vec3& a, const vec3& b)
    {
        return vec3(std::min(a[0], b[0]), std::min(a[1], b[1]), std::min(a[2], b[2]));
    }
    
    vec3 min(const vec3& a, float b)
    {
        return vec3(std::min(a[0], b), std::min(a[1], b), std::min(a[2], b));
    }
    
    vec3 max(const vec3& a, const vec3& b)
    {
        return vec3(std::max(a[0], b[0]), std::max(a[1], b[1]), std::max(a[2], b[2]));
    }
    
    vec3 max(const vec3& a, float b)
    {
        return vec3(std::max(a[0], b), std::max(a[1], b), std::max(a[2], b));
    }
    
    vec3 clamp(const vec3& a, const vec3& minVal, const vec3& maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    vec3 clamp(const vec3& a, float minVal, float maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    vec3 mix(const vec3& a, const vec3& b, const vec3& wb) 
    {    
       return a * (vec3(1.0) - wb) + b * wb;
    }
    
    vec3 mix(const vec3& a, const vec3& b, float wb) 
    {
        return a * vec3(1.0 - wb) + b * vec3(wb);
    }
}
