
#ifndef _MATRIX44_H_
#define _MATRIX44_H_

namespace glm
{
    class vec4;
    class mat2;
    class mat3;

    class mat4
    {
    public:

        mat4();
                       
        explicit mat4(float v);
        
        mat4(float v00, float v01, float v02, float v03, 
             float v04, float v05, float v06, float v07,
             float v08, float v09, float v10, float v11,
             float v12, float v13, float v14, float v15);
        
        explicit mat4(const float* v);
        
        mat4(const mat2& m);
        
        mat4(const mat3& m);
        
        mat4(const mat4& m);
        
        mat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3);
        
        ~mat4();
        
        const mat4& operator = (const mat4& m);
        
        const mat4& operator += (const mat4& v);
        
        const mat4& operator -= (const mat4& v);
        
        vec4 operator [] (unsigned int i) const;
        
    private:
        float data[16];
    };

    mat4 operator + (const mat4& a, const mat4& b);
    
    mat4 operator - (const mat4& a, const mat4& b);
    
    mat4 operator * (const mat4& a, const mat4& b);
    
    vec4 operator * (const mat4& m, const vec4& v);
    
    mat4 matrixCompMult(const mat4& a, const mat4& b);
    
    mat4 transpose(const mat4& m);    
}

#endif
