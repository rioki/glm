
#ifndef _GLM_MAT2_H_
#define _GLM_MAT2_H_

namespace glm
{
    class vec2;
    class mat3;
    class mat4;

    class mat2
    {
    public:

        mat2();
                       
        explicit mat2(float v);
        
        mat2(float v00, float v01, 
             float v02, float v03);
        
        explicit mat2(const float* v);
        
        mat2(const mat3& m);
        
        mat2(const mat4& m);
        
        mat2(const mat2& m);
        
        mat2(const vec2& v0, const vec2& v1);
        
        ~mat2();
        
        const mat2& operator = (const mat2& m);
        
        const mat2& operator += (const mat2& v);
        
        const mat2& operator -= (const mat2& v);
        
        vec2 operator [] (unsigned int i) const;
        
        const float* c_arr() const;
        
    private:
        float data[4];
    };

    mat2 operator + (const mat2& a, const mat2& b);
    
    mat2 operator - (const mat2& a, const mat2& b);
    
    mat2 operator * (const mat2& a, const mat2& b);
    
    vec2 operator * (const mat2& m, const vec2& v);
    
    mat2 matrixCompMult(const mat2& a, const mat2& b);
    
    mat2 transpose(const mat2& m);   
}

#endif
