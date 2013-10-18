
#ifndef _GLM_MAT3_H_
#define _GLM_MAT3_H_

namespace glm
{
    class vec3;
    class mat2;
    class mat4;

    class mat3
    {
    public:

        mat3();
                       
        explicit mat3(float v);
        
        mat3(float v00, float v01, float v02, 
             float v03, float v04, float v05, 
             float v06, float v07, float v08);
        
        explicit mat3(const float* v);
        
        mat3(const mat2& m);
        
        mat3(const mat4& m);
        
        mat3(const mat3& m);
        
        mat3(const vec3& v0, const vec3& v1, const vec3& v2);
        
        ~mat3();
        
        const mat3& operator = (const mat3& m);
        
        const mat3& operator += (const mat3& v);
        
        const mat3& operator -= (const mat3& v);
        
        vec3 operator [] (unsigned int i) const;
        
        const float* c_arr() const;
        
    private:
        float data[8];
    };

    mat3 operator + (const mat3& a, const mat3& b);
    
    mat3 operator - (const mat3& a, const mat3& b);
    
    mat3 operator * (const mat3& a, const mat3& b);
    
    vec3 operator * (const mat3& m, const vec3& v);
    
    mat3 matrixCompMult(const mat3& a, const mat3& b);
    
    mat3 transpose(const mat3& m);   
}

#endif
