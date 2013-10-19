
#include "vec4.h"

#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cfloat>

#include "vec2.h"
#include "vec3.h"

namespace glm
{
    vec4::vec4() {}
        
    vec4::vec4(float v)
    {
        data[0] = v;
        data[1] = v;
        data[2] = v;
        data[3] = v;
    }
    
    vec4::vec4(float x, float y, float z, float w)
    {
        data[0] = x;
        data[1] = y;
        data[2] = z;
        data[3] = w;
    }
    
    vec4::vec4(const vec2& v, float z, float w)
    {
        data[0] = v[0];
        data[1] = v[1];
        data[2] = z;
        data[3] = w;
    }
    
    vec4::vec4(float x, const vec2& v, float w)
    {
        data[0] = x;
        data[1] = v[0];
        data[2] = v[1];
        data[3] = w;
    }
    
    vec4::vec4(float x, float y, const vec2& v)
    {
        data[0] = x;
        data[1] = y;
        data[2] = v[0];
        data[3] = v[1];
    }
    
    vec4::vec4(const vec3& v, float w)
    {
        data[0] = v[0];
        data[1] = v[1];
        data[2] = v[2];
        data[3] = w;
    }
    
    vec4::vec4(float x, const vec3& v)
    {
        data[0] = x;
        data[1] = v[0];
        data[2] = v[1];
        data[3] = v[2];
    }
        
    vec4::vec4(const vec4& v)
    {
        std::memcpy(data, v.data, 4 * sizeof(float));
    }
        
    vec4::~vec4() {}
        
    const vec4& vec4::operator = (const vec4& v)
    {
        if (this != &v)
        {
            std::memcpy(data, v.data, 4 * sizeof(float));
        }
        return *this;
    }
    
    const vec4& vec4::operator += (const vec4& v)
    {
        data[0] += v.data[0];
        data[1] += v.data[1];
        data[2] += v.data[2];
        data[3] += v.data[3];
        return *this;
    }

    const vec4& vec4::operator -= (const vec4& v)
    {
        data[0] -= v.data[0];
        data[1] -= v.data[1];
        data[2] -= v.data[2];
        data[3] -= v.data[3];
        return *this;
    }
    
    bool vec4::operator == (const vec4& v)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            if (std::abs(data[i] - v.data[i]) > 1e-4)
            {
                return false;
            }
        }
        return true;
    }
        
    bool vec4::operator != (const vec4& v)
    {
        return !(*this == v);
    }
        
    float& vec4::operator [] (unsigned int i)
    {
        return data[i];
    }
        
    float vec4::operator [] (unsigned int i) const
    {
        return data[i];
    }
    
    const float* vec4::c_arr() const
    {
        return reinterpret_cast<const float*>(data);
    }
    
    vec4 operator + (const vec4& v)
    {
        return v;
    }
    
    vec4 operator - (const vec4& v)
    {
        return vec4(-v[0], -v[1], -v[2], -v[3]);    
    }
    
    vec4 operator + (const vec4& a, const vec4& b)
    {
        vec4 tmp = a;
        tmp += b;
        return tmp;
    }
    
    vec4 operator - (const vec4& a, const vec4& b)
    {
        vec4 tmp = a;
        tmp -= b;
        return tmp;
    }
    
    vec4 operator * (const vec4& a, const vec4& b)
    {
        return vec4(a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3]);
    }
    
    vec4 operator / (const vec4& a, const vec4& b)
    {
        return vec4(a[0] / b[0], a[1] / b[1], a[2] / b[2], a[3] / b[3]);
    }   
    
    vec4 operator * (const vec4& v, float s)
    {
        return vec4(v[0] * s, v[1] * s, v[2] * s, v[3] * s);
    }
    
    vec4 operator * (float s, const vec4& v)
    {
        return v * s;
    }
    
    float dot(const vec4& a, const vec4& b)
    {
        return a[0] * b[0] + a[1] * b[1] + b[2] * b[2] + a[3] * b[3];
    }
    
    float length(const vec4& v)
    {
        return std::sqrt(dot(v, v));
    }

    float distance(const vec4& a, const vec4& b)
    {
        return length(a - b);
    }
    
    vec4 normalize(const vec4& v)
    {
        return v * (1 / length(v));
    }
    
    vec4 min(const vec4& a, const vec4& b)
    {
        return vec4(std::min(a[0], b[0]), std::min(a[1], b[1]), std::min(a[2], b[2]), std::min(a[3], b[3]));
    }
    
    vec4 min(const vec4& a, float b)
    {
        return vec4(std::min(a[0], b), std::min(a[1], b), std::min(a[2], b), std::min(a[3], b));
    }
    
    vec4 max(const vec4& a, const vec4& b)
    {
        return vec4(std::max(a[0], b[0]), std::max(a[1], b[1]), std::max(a[2], b[2]), std::max(a[3], b[3]));
    }
    
    vec4 max(const vec4& a, float b)
    {
        return vec4(std::max(a[0], b), std::max(a[1], b), std::max(a[2], b), std::max(a[3], b));
    }
    
    vec4 clamp(const vec4& a, const vec4& minVal, const vec4& maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    vec4 clamp(const vec4& a, float minVal, float maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    vec4 mix(const vec4& a, const vec4& b, const vec4& wb) 
    {    
       return a * (vec4(1.0) - wb) + b * wb;
    }
    
    vec4 mix(const vec4& a, const vec4& b, float wb) 
    {
        return a * vec4(1.0 - wb) + b * vec4(wb);
    }
    
    std::ostream& operator << (std::ostream& os, const vec4& v)
    {
        const float* data = v.c_arr();
        os << "(";
        for (unsigned int i = 0; i < 4; i++)
        {
            os << data[i];
            if (i != 3)
            {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
}
