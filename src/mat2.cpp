
#include "mat2.h"

#include <cstring>

#include "mat3.h"
#include "mat4.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace glm
{
    mat2::mat2() {}
    
    mat2::mat2(float v)
    {
        data[0] =     v; data[1] = 0.0f;
        data[2] =  0.0f; data[3] =    v;
    }
        
    mat2::mat2(float v00, float v01, 
               float v02, float v03)
    {
        data[0] = v00; data[1] = v01; 
        data[2] = v02; data[3] = v03; 
    }
    
    mat2::mat2(const float* v)
    {
        std::memcpy(data, v, 4 * sizeof(float));
    }
        
    mat2::mat2(const mat3& m)
    {
        data[0] = m[0][0]; data[1] = m[0][1]; 
        data[2] = m[1][0]; data[3] = m[1][1]; 
    }
    
    mat2::mat2(const mat4& m)
    {
        data[0] = m[0][0]; data[1] = m[0][1]; 
        data[2] = m[1][0]; data[3] = m[1][1]; 
    }
    
    mat2::mat2(const vec2& v0, const vec2& v1)
    {
        data[0] = v0[0]; data[1] = v0[1]; 
        data[2] = v1[0]; data[3] = v1[1];
    }
    
    mat2::mat2(const mat2& m)
    {
        std::memcpy(data, m.data, 4 * sizeof(float));
    }
    
    mat2::~mat2() {}
    
    const mat2& mat2::operator = (const mat2& m)
    {
        if (this != &m)
        {
            std::memcpy(data, m.data, 4 * sizeof(float));
        }
        return *this;
    }
                
    const mat2& mat2::operator += (const mat2& v)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            data[i] += v.data[i];
        }
        return *this;
    }
    
    const mat2& mat2::operator -= (const mat2& v)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            data[i] -= v.data[i];
        }
        return *this;
    }
    
    vec2 mat2::operator [] (unsigned int i) const
    {
        return vec2(data[i*2 + 0], data[i*2 + 1]);
    }
    
    const float* mat2::c_arr() const
    {
        return reinterpret_cast<const float*>(data);
    }
    
    mat2 operator + (const mat2& a, const mat2& b)
    {
        mat2 t = a;
        t += b;
        return t;
    }
    
    mat2 operator - (const mat2& a, const mat2& b)
    {
        mat2 t = a;
        t -= b;
        return t;
    }
    
    mat2 operator * (const mat2& a, const mat2& b)
    {
        float r[4];
        
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                float t = 0;
                for (unsigned int k = 0; k < 2; k++)
                {
                    // TODO performance? a vec2 is built for every call
                    t += a[k][j] * b[i][k];
                }
                r[i * 2 + j] = t;
            }
        }
        
        return mat2(r);
    }
    
    vec2 operator * (const mat2& m, const vec2& v)
    {
        vec2 r;
        
        for (unsigned int i = 0; i < 2; i++)
        {
            float t = 0;
            for (unsigned int j = 0; j < 2; j++)
            {
               t += m[j][i] * v[j]; 
            }
            r[i] = t;
        }
        
        return r;
    }
        
    mat2 matrixCompMult(const mat2& a, const mat2& b)
    {
        float r[4];
        
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                r[i * 2 + j] = a[i][j] * b[i][j];
            }
        }
        
        return mat2(r);
    }

    mat2 transpose(const mat2& m)
    {
        float r[4];
        
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                r[i * 2 + j] = m[i][j];
            }
        }
        
        return mat2(r);
    }
}
