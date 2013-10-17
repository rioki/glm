
#ifndef _GLM_VEC2_H_
#define _GLM_VEC2_H_

namespace glm
{
    class vec3;
    class vec4;

    class vec2
    {
    public:
        
        vec2();
        
        explicit vec2(float v);
        
        vec2(float x, float y);
        
        explicit vec2(const vec3& v);
        
        explicit vec2(const vec4& v);
        
        vec2(const vec2& v);
        
        ~vec2();
        
        const vec2& operator = (const vec2& v);
        
        const vec2& operator += (const vec2& v);
        
        const vec2& operator -= (const vec2& v);
        
        float& operator [] (unsigned int i);
        
        float operator [] (unsigned int i) const;      

        const float* c_arr() const;
        
    private:
        float data[2];
    };
    
    vec2 operator + (const vec2& v);
    
    vec2 operator - (const vec2& v);
    
    vec2 operator + (const vec2& a, const vec2& b);
    
    vec2 operator - (const vec2& a, const vec2& b);
    
    vec2 operator * (const vec2& a, const vec2& b);
    
    vec2 operator / (const vec2& a, const vec2& b);
    
    vec2 operator * (const vec2& v, float s);
    
    vec2 operator * (float s, const vec2& v);
    
    float dot(const vec2& a, const vec2& b);
    
    float length(const vec2& v);

    float distance(const vec2& a, const vec2& b);
    
    vec2 normalize(const vec2& v);
    
    vec2 min(const vec2& a, const vec2& b);
    
    vec2 min(const vec2& a, float b);
    
    vec2 max(const vec2& a, const vec2& b);
    
    vec2 max(const vec2& a, float b);
    
    vec2 clamp(const vec2& a, const vec2& minVal, const vec2& maxVal);
    
    vec2 clamp(const vec2& a, float minVal, float maxVal);
    
    vec2 mix(const vec2& a, const vec2& b, const vec2& wb);
    
    vec2 mix(const vec2& a, const vec2& b, float wb);
}

#endif
