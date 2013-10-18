
#ifndef _GLM_PROJECTION_H_
#define _GLM_PROJECTION_H_

namespace glm
{
    class mat4;
    class vec3;

    mat4 ortho(float left, float right, float top, float bottom, float znear, float zfar);
    
    mat4 perspective(float fov, float aspect, float znear, float zfar);
    
    mat4 furstrum(float left, float right, float top, float bottom, float znear, float zfar);
    
    mat4 lookat(vec3 eye, vec3 center, vec3 up);
    
    mat4 translation(vec3 v);
}

#endif
