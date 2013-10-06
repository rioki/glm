
#ifndef _GLM_PROJECTION_H_
#define _GLM_PROJECTION_H_

namespace glm
{
    class mat4;
    class vec3;

    mat4 ortho(float left, float right, float top, float bottom, float znear, float zfar);
    
    mat4 look_at(vec3 eye, vec3 center, vec3 up);
    
    mat4 translation(vec3 v);
}

#endif
