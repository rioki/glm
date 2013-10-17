
#ifndef _GLM_VEC4_H_
#define _GLM_VEC4_H_

namespace glm
{
    class vec2;
    class vec3;

    class vec4
    {
    public:
    
        vec4();
        
        explicit vec4(float v);
        
        vec4(float x, float y, float z, float w);
        
        vec4(const vec2& v, float z, float w);
        
        vec4(float x, const vec2& v, float w);
        
        vec4(float x, float y, const vec2& v);
        
        vec4(const vec3& v, float w);
        
        vec4(float x, const vec3& v);
        
        vec4(const vec4& v);
        
        ~vec4();
        
        const vec4& operator = (const vec4& v);
        
        const vec4& operator += (const vec4& v);
        
        const vec4& operator -= (const vec4& v);
        
        float& operator [] (unsigned int i);
        
        float operator [] (unsigned int i) const;
        
        const float* c_arr() const;
        
    private:
        float data[4];
    };
    
    vec4 operator + (const vec4& v);
    
    vec4 operator - (const vec4& v);
    
    vec4 operator + (const vec4& a, const vec4& b);
    
    vec4 operator - (const vec4& a, const vec4& b);
    
    vec4 operator * (const vec4& a, const vec4& b);
    
    vec4 operator / (const vec4& a, const vec4& b);
    
    vec4 operator * (const vec4& v, float s);
    
    vec4 operator * (float s, const vec4& v);
    
    float dot(const vec4& a, const vec4& b);
    
    float length(const vec4& v);

    float distance(const vec4& a, const vec4& b);
    
    vec4 normalize(const vec4& v);
    
    vec4 min(const vec4& a, const vec4& b);
    
    vec4 min(const vec4& a, float b);
    
    vec4 max(const vec4& a, const vec4& b);
    
    vec4 max(const vec4& a, float b);
    
    vec4 clamp(const vec4& a, const vec4& minVal, const vec4& maxVal);
    
    vec4 clamp(const vec4& a, float minVal, float maxVal);
    
    vec4 mix(const vec4& a, const vec4& b, const vec4& wb);
    
    vec4 mix(const vec4& a, const vec4& b, float wb);
}

#endif
