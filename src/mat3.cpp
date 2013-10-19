
#include "mat3.h"

#include <cstring>

#include "mat2.h"
#include "mat4.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace glm
{
    mat3::mat3() {}
    
    mat3::mat3(float v)
    {
        data[0] =     v; data[1] = 0.0f; data[2] = 0.0f; 
        data[3] =  0.0f; data[4] =    v; data[5] = 0.0f; 
        data[6] =  0.0f; data[7] = 0.0f; data[8] =    v; 
    }
        
    mat3::mat3(float v00, float v01, float v02, 
               float v03, float v04, float v05, 
               float v06, float v07, float v08)
    {
        data[0] = v00; data[1] = v01; data[2] = v02; 
        data[3] = v03; data[4] = v04; data[5] = v05; 
        data[6] = v06; data[7] = v07; data[8] = v08;
    }
    
    mat3::mat3(const float* v)
    {
        std::memcpy(data, v, 8 * sizeof(float));
    }
        
    mat3::mat3(const mat2& m)
    {
        data[0] = m[0][0]; data[1] = m[0][1]; data[2] = 0.0f; 
        data[3] = m[1][0]; data[4] = m[1][1]; data[5] = 0.0f; 
        data[6] =    0.0f; data[7] =    0.0f; data[8] = 1.0f;
    }
    
    mat3::mat3(const mat4& m)
    {
        data[0] = m[0][0]; data[1] = m[0][1]; data[2] = m[0][2]; 
        data[3] = m[1][0]; data[4] = m[1][1]; data[5] = m[1][2]; 
        data[6] = m[2][0]; data[7] = m[2][1]; data[8] = m[2][2];
    }
    
    mat3::mat3(const vec3& v0, const vec3& v1, const vec3& v2)
    {
        data[0] = v0[0]; data[1] = v0[1]; data[2] = v0[2]; 
        data[3] = v1[0]; data[4] = v1[1]; data[5] = v1[2]; 
        data[6] = v2[0]; data[7] = v2[1]; data[8] = v2[2];
    }
    
    mat3::mat3(const mat3& m)
    {
        std::memcpy(data, m.data, 8 * sizeof(float));
    }
    
    mat3::~mat3() {}
    
    const mat3& mat3::operator = (const mat3& m)
    {
        if (this != &m)
        {
            std::memcpy(data, m.data, 8 * sizeof(float));
        }
        return *this;
    }
                
    const mat3& mat3::operator += (const mat3& v)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            data[i] += v.data[i];
        }
        return *this;
    }
    
    const mat3& mat3::operator -= (const mat3& v)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            data[i] -= v.data[i];
        }
        return *this;
    }
    
    vec3 mat3::operator [] (unsigned int i) const
    {
        return vec3(data[i*3 + 0], data[i*3 + 1], data[i*3 + 2]);
    }
    
    const float* mat3::c_arr() const
    {
        return reinterpret_cast<const float*>(data);
    }
    
    mat3 operator + (const mat3& a, const mat3& b)
    {
        mat3 t = a;
        t += b;
        return t;
    }
    
    mat3 operator - (const mat3& a, const mat3& b)
    {
        mat3 t = a;
        t -= b;
        return t;
    }
    
    mat3 operator * (const mat3& a, const mat3& b)
    {
        float r[8];
        
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                float t = 0;
                for (unsigned int k = 0; k < 3; k++)
                {
                    // TODO performance? a vec3 is built for every call
                    t += a[k][j] * b[i][k];
                }
                r[i * 3 + j] = t;
            }
        }
        
        return mat3(r);
    }
    
    vec3 operator * (const mat3& m, const vec3& v)
    {
        vec3 r;
        
        for (unsigned int i = 0; i < 3; i++)
        {
            float t = 0;
            for (unsigned int j = 0; j < 3; j++)
            {
               t += m[j][i] * v[j]; 
            }
            r[i] = t;
        }
        
        return r;
    }
        
    mat3 matrixCompMult(const mat3& a, const mat3& b)
    {
        float r[8];
        
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                r[i * 3 + j] = a[i][j] * b[i][j];
            }
        }
        
        return mat3(r);
    }

    mat3 transpose(const mat3& m)
    {
        float r[8];
        
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                r[i * 3 + j] = m[i][j];
            }
        }
        
        return mat3(r);
    }
}
