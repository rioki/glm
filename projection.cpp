
#include "projection.h"

#include "mat4.h"
#include "vec3.h"

namespace glm
{    
    mat4 ortho(float left, float right, float top, float bottom, float znear, float zfar)
    {
        return mat4(2.0f / (right - left), 0.0f, 0.0f, 0.0f,
                    0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
                    0.0f, 0.0f, -2.0f / (zfar - znear), 0.0f,
                    -(right + left) / (right - left), -(top + bottom) / (top - bottom),
                    -(zfar + znear) / (zfar - znear), 1.0f); 
    }
    
    mat4 look_at(vec3 eye, vec3 center, vec3 up)
    {
        vec3 forward = normalize(center - eye);
        vec3 side    = normalize(cross(forward, up));
        
        mat4 result(side[0], up[0], -forward[0], 0.0f,
                    side[1], up[1], -forward[1], 0.0f,
                    side[2], up[2], -forward[2], 0.0f,
                        0.0,   0.0,         0.0, 1.0f);
        
        return result * translation(-eye);
    }
    
    mat4 translation(vec3 v)
    {
        return mat4(1.0, 0.0, 0.0, v[0],
                    1.0, 1.0, 0.0, v[1],
                    0.0, 0.0, 1.0, v[2],
                    0.0, 0.0, 0.0, 1.0f);
    }
}