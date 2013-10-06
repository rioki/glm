
#include "vec2.h"

#include <cstring>
#include <cmath>
#include <algorithm>

#include "vec3.h"
#include "vec4.h"

namespace glm
{
    vec2::vec2() {}
    
    vec2::vec2(float v) 
    {
        data[0] = v;
        data[1] = v;
    }
    
    vec2::vec2(float x, float y)
    {
        data[0] = x;
        data[1] = y;
    }
    
    vec2::vec2(const vec3& v)
    {
        data[0] = v[0];
        data[1] = v[1];
    }
        
    vec2::vec2(const vec4& v)
    {
        data[0] = v[0];
        data[1] = v[1];
    }
        
    vec2::vec2(const vec2& v)
    {
        std::memcpy(data, v.data, 2 * sizeof(float));
    }
        
    vec2::~vec2() {}
        
    const vec2& vec2::operator = (const vec2& v)
    {
        if (this != &v)
        {
            std::memcpy(data, v.data, 2 * sizeof(float));
        }
        return *this;
    }
    
    const vec2& vec2::operator += (const vec2& v)
    {
        data[0] += v.data[0];
        data[1] += v.data[1];
        return *this;
    }

    const vec2& vec2::operator -= (const vec2& v)
    {
        data[0] -= v.data[0];
        data[1] -= v.data[1];
        return *this;
    }
        
    float& vec2::operator [] (unsigned int i)
    {
        return data[i];
    }
        
    float vec2::operator [] (unsigned int i) const
    {
        return data[i];
    }
    
    vec2 operator + (const vec2& v)
    {
        return v;
    }
    
    vec2 operator - (const vec2& v)
    {
        return vec2(-v[0], -v[1]);
    }
    
    vec2 operator + (const vec2& a, const vec2& b)
    {
        vec2 tmp = a;
        tmp += b;
        return tmp;
    }
    
    vec2 operator - (const vec2& a, const vec2& b)
    {
        vec2 tmp = a;
        tmp -= b;
        return tmp;
    }
    
    vec2 operator * (const vec2& a, const vec2& b)
    {
        return vec2(a[0] * b[0], a[1] * b[1]);
    }
    
    vec2 operator / (const vec2& a, const vec2& b)
    {
        return vec2(a[0] / b[0], a[1] / b[1]);
    }
    
    vec2 operator * (const vec2& v, float s)
    {
        return vec2(v[0] * s, v[1] * s);
    }
    
    vec2 operator * (float s, const vec2& v)
    {
        return v * s;
    }
    
    float dot(const vec2& a, const vec2& b)
    {
        return a[0] * b[0] + b[1] * b[1];
    }
    
    float length(const vec2& v)
    {
        return std::sqrt(dot(v, v));
    }

    float distance(const vec2& a, const vec2& b)
    {
        return length(a - b);
    }
    
    vec2 normalize(const vec2& v)
    {
        return v * (1 / length(v));
    }
    
    vec2 min(const vec2& a, const vec2& b)
    {
        return vec2(std::min(a[0], b[0]), std::min(a[1], b[1]));
    }
    
    vec2 min(const vec2& a, float b)
    {
        return vec2(std::min(a[0], b), std::min(a[1], b));
    }
    
    vec2 max(const vec2& a, const vec2& b)
    {
        return vec2(std::max(a[0], b[0]), std::max(a[1], b[1]));
    }
    
    vec2 max(const vec2& a, float b)
    {
        return vec2(std::max(a[0], b), std::max(a[1], b));
    }
    
    vec2 clamp(const vec2& a, const vec2& minVal, const vec2& maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    vec2 clamp(const vec2& a, float minVal, float maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    vec2 mix(const vec2& a, const vec2& b, const vec2& wb) 
    {    
       return a * (vec2(1.0) - wb) + b * wb;
    }
    
    vec2 mix(const vec2& a, const vec2& b, float wb) 
    {
        return a * vec2(1.0 - wb) + b * vec2(wb);
    }
}
