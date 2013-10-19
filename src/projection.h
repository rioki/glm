
#ifndef _GLM_PROJECTION_H_
#define _GLM_PROJECTION_H_

namespace glm
{
    class vec3;
    class mat3;
    class mat4;

    mat4 ortho(float left, float right, float bottom, float top, float znear, float zfar);
    
    mat4 perspective(float fov, float aspect, float znear, float zfar);
    
    mat4 frustum(float left, float right, float bottom, float top, float znear, float zfar);
    
    mat4 lookat(vec3 eye, vec3 center, vec3 up);
    
    mat4 translate(vec3 v);
    mat4 translate(float x, float y, float z);
    
    mat3 euler(vec3 v);
    mat3 euler(float x, float y, float z);
}

#endif
