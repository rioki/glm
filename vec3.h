
#ifndef _GLM_VEC3_H_
#define _GLM_VEC3_H_

namespace glm
{
    class vec2;
    class vec4;

    class vec3
    {
    public:
    
        vec3();
        
        explicit vec3(float v);
        
        vec3(float x, float y, float z);
        
        vec3(const vec2& v, float z);
        
        vec3(float x, const vec2& v);
        
        explicit vec3(const vec4& v);
        
        vec3(const vec3& v);
        
        ~vec3();
        
        const vec3& operator = (const vec3& v);
        
        const vec3& operator += (const vec3& v);
        
        const vec3& operator -= (const vec3& v);
        
        float& operator [] (unsigned int i);
        
        float operator [] (unsigned int i) const;
    
    private:
        float data[4];        
    };
    
    vec3 operator + (const vec3& v);
    
    vec3 operator - (const vec3& v);
    
    vec3 operator + (const vec3& a, const vec3& b);
    
    vec3 operator - (const vec3& a, const vec3& b);
    
    vec3 operator * (const vec3& a, const vec3& b);
    
    vec3 operator / (const vec3& a, const vec3& b);
    
    vec3 operator * (const vec3& v, float s);
    
    vec3 operator * (float s, const vec3& v);
    
    float dot(const vec3& a, const vec3& b);
    
    vec3 cross (const vec3& a, const vec3& b);
    
    float length(const vec3& v);

    float distance(const vec3& a, const vec3& b);
    
    vec3 normalize(const vec3& v);
    
    vec3 min(const vec3& a, const vec3& b);
    
    vec3 min(const vec3& a, float b);
    
    vec3 max(const vec3& a, const vec3& b);
    
    vec3 max(const vec3& a, float b);
    
    vec3 clamp(const vec3& a, const vec3& minVal, const vec3& maxVal);
    
    vec3 clamp(const vec3& a, float minVal, float maxVal);
    
    vec3 mix(const vec3& a, const vec3& b, const vec3& wb);
    
    vec3 mix(const vec3& a, const vec3& b, float wb);
}

#endif
