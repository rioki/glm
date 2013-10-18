
#include "projection.h"

#include "mat4.h"
#include "vec3.h"
#include <cmath>

const float PI = 3.14159265358979f;

namespace glm
{    
    mat4 ortho(float left, float right, float top, float bottom, float znear, float zfar)
    {
        return mat4(           2.0f / (right - left),                             0.0f,                             0.0f, 0.0f,
                                                0.0f,            2.0f / (top - bottom),                             0.0f, 0.0f,
                                                0.0f,                             0.0f,           -2.0f / (zfar - znear), 0.0f,
                    -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(zfar + znear) / (zfar - znear), 1.0f); 
    }
    
    mat4 perspective(float fov, float a, float n, float f)
    {
        /*float ymax = znear * tanf(fov * PI / 360.0f);
        float ymin = -ymax;
        float xmin = ymin * aspect;
        float xmax = ymax * aspect;

        return furstrum(xmin, xmax, ymin, ymax, znear, zfar);*/
        
        float e = 1 / tan(fov/2);
        
        // NOTE this may need to be transposed.
        return mat4(  e, 0.0,            0.0,              0.0,
                    0.0, e/a,            0.0,              0.0,
                    0.0, 0.0, -((f+n)/(f-n)), -((2*f*n)/(f-n)),
                    0.0, 0.0,           -1.0,              0.0);
    }
    
    mat4 furstrum(float left, float right, float top, float bottom, float znear, float zfar)
    {
        return mat4(2.0f * znear / (right - left),                              0.0f,                                    0.0f,  0.0f,        
                                                 0.0f, 2.0f * znear / (top - bottom),                                    0.0f,  0.0f,
                    (right + left) / (right - left), (top + bottom) / (top - bottom),        -(zfar + znear) / (zfar - znear), -1.0f,
                                               0.0f,                            0.0f, -(2.0f * zfar * znear) / (zfar - znear),  0.0f);
    }
    
    mat4 lookat(vec3 eye, vec3 center, vec3 up)
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