
#include "mat4.h"

#include <cstring>
#include <cmath>
#include <cfloat>
#include <iostream>

#include "mat2.h"
#include "mat3.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace glm
{
    mat4::mat4() {}
    
    mat4::mat4(float v)
    {
        data[ 0] =     v; data[ 1] = 0.0f; data[ 2] = 0.0f; data[ 3] = 0.0f;
        data[ 4] =  0.0f; data[ 5] =    v; data[ 6] = 0.0f; data[ 7] = 0.0f;
        data[ 8] =  0.0f; data[ 9] = 0.0f; data[10] =    v; data[11] = 0.0f;
        data[12] =  0.0f; data[13] = 0.0f; data[14] = 0.0f; data[15] =    v;
    }
        
    mat4::mat4(float v00, float v01, float v02, float v03, 
               float v04, float v05, float v06, float v07,
               float v08, float v09, float v10, float v11,
               float v12, float v13, float v14, float v15)
    {
        data[ 0] = v00; data[ 1] = v01; data[ 2] = v02; data[ 3] = v03;
        data[ 4] = v04; data[ 5] = v05; data[ 6] = v06; data[ 7] = v07;
        data[ 8] = v08; data[ 9] = v09; data[10] = v10; data[11] = v11;
        data[12] = v12; data[13] = v13; data[14] = v14; data[15] = v15;
    }
    
    mat4::mat4(const float* v)
    {
        std::memcpy(data, v, 16 * sizeof(float));
    }
        
    mat4::mat4(const mat2& m)
    {
        data[ 0] = m[0][0]; data[ 1] = m[0][1]; data[ 2] = 0.0f; data[ 3] = 0.0f;
        data[ 4] = m[1][0]; data[ 5] = m[1][1]; data[ 6] = 0.0f; data[ 7] = 0.0f;
        data[ 8] =    0.0f; data[ 9] =    0.0f; data[10] = 1.0f; data[11] = 0.0f;
        data[12] =    0.0f; data[13] =    0.0f; data[14] = 0.0f; data[15] = 1.0f;
    }
    
    mat4::mat4(const mat3& m)
    {
        data[ 0] = m[0][0]; data[ 1] = m[0][1]; data[ 2] = m[0][2]; data[ 3] = 0.0f;
        data[ 4] = m[1][0]; data[ 5] = m[1][1]; data[ 6] = m[1][2]; data[ 7] = 0.0f;
        data[ 8] = m[2][0]; data[ 9] = m[2][1]; data[10] = m[2][2]; data[11] = 0.0f;
        data[12] =    0.0f; data[13] =    0.0f; data[14] = 0.0f; data[15] = 1.0f;
    }
    
    mat4::mat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3)
    {
        data[ 0] = v0[0]; data[ 1] = v0[1]; data[ 2] = v0[2]; data[ 3] = v0[3];
        data[ 4] = v1[0]; data[ 5] = v1[1]; data[ 6] = v1[2]; data[ 7] = v1[3];
        data[ 8] = v2[0]; data[ 9] = v2[1]; data[10] = v2[2]; data[11] = v2[3];
        data[12] = v3[0]; data[13] = v3[1]; data[14] = v3[2]; data[15] = v3[3];
    }
    
    mat4::mat4(const mat4& m)
    {
        std::memcpy(data, m.data, 16 * sizeof(float));
    }
    
    mat4::~mat4() {}
    
    const mat4& mat4::operator = (const mat4& m)
    {
        if (this != &m)
        {
            std::memcpy(data, m.data, 16 * sizeof(float));
        }
        return *this;
    }
                
    const mat4& mat4::operator += (const mat4& v)
    {
        for (unsigned int i = 0; i < 16; i++)
        {
            data[i] += v.data[i];
        }
        return *this;
    }
    
    const mat4& mat4::operator -= (const mat4& v)
    {
        for (unsigned int i = 0; i < 16; i++)
        {
            data[i] -= v.data[i];
        }
        return *this;
    }
    
    bool mat4::operator == (const mat4& m)
    {        
        for (unsigned int i = 0; i < 16; i++)
        {
            if (std::abs(data[i] - m.data[i]) > FLT_EPSILON)
            {
                return false;
            }
        }
        return true;
    }
        
    bool mat4::operator != (const mat4& m)
    {
        return !(*this == m);
    }
    
    vec4 mat4::operator [] (unsigned int i) const
    {
        return vec4(data[i*4 + 0], data[i*4 + 1], data[i*4 + 2], data[i*4 + 3]);
    }
    
    const float* mat4::c_arr() const
    {
        return reinterpret_cast<const float*>(data);
    }
    
    mat4 operator + (const mat4& a, const mat4& b)
    {
        mat4 t = a;
        t += b;
        return t;
    }
    
    mat4 operator - (const mat4& a, const mat4& b)
    {
        mat4 t = a;
        t -= b;
        return t;
    }
    
    mat4 operator * (const mat4& a, const mat4& b)
    {
        float r[16];
        
        for (unsigned int i = 0; i < 4; i++)
        {
            for (unsigned int j = 0; j < 4; j++)
            {
                float t = 0;
                for (unsigned int k = 0; k < 4; k++)
                {
                    // TODO performance? a vec4 is built for every call
                    t += a[i][k] * b[k][j];
                }
                r[i * 4 + j] = t;
            }
        }
        
        return mat4(r);
    }
    
    vec4 operator * (const mat4& m, const vec4& v)
    {
        vec4 r;
        
        for (unsigned int i = 0; i < 4; i++)
        {
            float t = 0;
            for (unsigned int j = 0; j < 4; j++)
            {
               t += m[i][j] * v[j]; 
            }
            r[i] = t;
        }
        
        return r;
    }
        
    mat4 matrixCompMult(const mat4& a, const mat4& b)
    {
        float r[16];
        
        for (unsigned int i = 0; i < 4; i++)
        {
            for (unsigned int j = 0; j < 4; j++)
            {
                r[i * 4 + j] = a[i][j] * b[i][j];
            }
        }
        
        return mat4(r);
    }

    mat4 transpose(const mat4& m)
    {
        float r[16];
        
        for (unsigned int i = 0; i < 4; i++)
        {
            for (unsigned int j = 0; j < 4; j++)
            {
                r[j * 4 + i] = m[i][j];
            }
        }
        
        return mat4(r);
    }
    
    std::ostream& operator << (std::ostream& os, const mat4& m)
    {
        const float* data = m.c_arr();
        os << "(";
        for (unsigned int i = 0; i < 16; i++)
        {
            os << data[i];
            if (i != 15)
            {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
}
