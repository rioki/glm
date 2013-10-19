
#include "projection.h"

#include "vec3.h"
#include "vec4.h"
#include "mat3.h"
#include "mat4.h"
#include <cmath>

const float PI      = 3.14159265358979f;
const float DEG2RAD = (PI * 2.0) / 360.0;

namespace glm
{    
    mat4 ortho(float l, float r, float b, float t, float n, float f)
    {
        return mat4(   2.0/(r-l),          0.0,          0.0, 0.0,
                             0.0,    2.0/(t-b),          0.0, 0.0,
                             0.0,          0.0,   -2.0/(f-n), 0.0,
                    -(r+l)/(r-l), -(t+b)/(t-b), -(f+n)/(f-n), 1.0);                          
    }
    
    mat4 perspective(float fov, float a, float n, float f)
    {
        float t = n * tanf(fov * PI / 360.0);
        float b = -t;
        float l = b * a;
        float r = t * a;
        
        return frustum(l, r, b, t, n, f);
    }
    
    mat4 frustum(float l, float r, float b, float t, float n, float f)
    {
        return mat4(2.0*n/(r-l),         0.0,              0.0,  0.0,        
                            0.0, 2.0*n/(t-b),              0.0,  0.0,
                    (r+l)/(r-l), (t+b)/(t-b),     -(f+n)/(f-n), -1.0,
                            0.0,         0.0, -(2.0*f*n)/(f-n),  0.0);
    }
    
    mat4 lookat(vec3 eye, vec3 center, vec3 up)
    {
        vec3 forward = normalize(center - eye);
        vec3 side    = normalize(cross(up, forward));
        vec3 up2     = normalize(cross(forward, side));
        
        mat4 rotation(    side[0],     side[1],     side[2], 0.0,
                           up2[0],      up2[1],      up2[2], 0.0,
                      -forward[0], -forward[1], -forward[2], 0.0,
                              0.0,         0.0,         0.0, 1.0);
        return rotation * translate(-eye);
    }
    
    mat4 translate(vec3 v)
    {
        return mat4( 1.0,  0.0,  0.0, 0.0,
                     0.0,  1.0,  0.0, 0.0,
                     0.0,  0.0,  1.0, 0.0,
                    v[0], v[1], v[2], 1.0);
    }
    
    mat4 translate(float x, float y, float z)
    {
        return mat4( 1.0,  0.0,  0.0, 0.0,
                     0.0,  1.0,  0.0, 0.0,
                     0.0,  0.0,  1.0, 0.0,
                       x,    y,    z, 1.0);
    }
    
    mat3 euler(vec3 v)
    {
        return euler(v[0], v[1], v[2]);
    }
    
    mat3 euler(float x, float y, float z)
    {
        float theta;
        
        theta = x * DEG2RAD;
        float sx = std::sin(theta);
        float cx = std::cos(theta);
        
        theta = y * DEG2RAD;
        float sy = std::sin(theta);
        float cy = std::cos(theta);
        
        theta = z * DEG2RAD;
        float sz = std::sin(theta);
        float cz = std::cos(theta);
        
        return mat3( cy*cz,  sx*sy*cz + cx*sz, -cx*sy*sx + sx*sz,
                    -cy*sz, -sx*sy*sz + cx*cz,  cy*sy*sz + sx*cz,
                        sy,            -sx*cy,             cx*cy);
    }
}