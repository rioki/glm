
#ifndef _GLM_PROJECTION_H_
#define _GLM_PROJECTION_H_

#include <cmath>
#include "utils.h"
#include "vector.h"
#include "matrix.h"

namespace glm
{
    template <typename T>
    matrix<T, 4> ortho(T l, T r, T b, T t, T n, T f)
    {
        return matrix<T, 4>(   2.0/(r-l),          0.0,          0.0, 0.0,
                                     0.0,    2.0/(t-b),          0.0, 0.0,
                                     0.0,          0.0,   -2.0/(f-n), 0.0,
                            -(r+l)/(r-l), -(t+b)/(t-b), -(f+n)/(f-n), 1.0);                          
    }
    
    template <typename T>
    matrix<T, 4> frustum(T l, T r, T b, T t, T n, T f)
    {
        return matrix<T, 4>(2.0*n/(r-l),         0.0,              0.0,  0.0,        
                                    0.0, 2.0*n/(t-b),              0.0,  0.0,
                            (r+l)/(r-l), (t+b)/(t-b),     -(f+n)/(f-n), -1.0,
                                    0.0,         0.0, -(2.0*f*n)/(f-n),  0.0);
    }
    
    template <typename T>
    matrix<T, 4> perspective(T fov, T a, T n, T f)
    {
        
        T fh = n * std::tan(deg2rad(fov));
        T fw = fh * a;
        
        return frustum(-fw, fw, -fh, fh, n, f);
    }
    
    template <typename T>
    matrix<T, 4> lookat(vector<T, 3> eye, vector<T, 3> target, vector<T, 3> up)
    {
        vector<T, 3> zaxis = normalize(eye - target);    
        vector<T, 3> xaxis = normalize(cross(up, zaxis));
        vector<T, 3> yaxis = cross(zaxis, xaxis);     
     
        matrix<T, 4> orientation(
           xaxis[0], yaxis[0], zaxis[0], 0,
           xaxis[1], yaxis[1], zaxis[1], 0,
           xaxis[2], yaxis[2], zaxis[2], 0,
             0,       0,       0,     1);
         
        matrix<T, 4> translation(
                  1,       0,       0, 0,
                  0,       1,       0, 0, 
                  0,       0,       1, 0,
            -eye[0], -eye[1], -eye[2], 1);
     
        return orientation * translation;
    }
}

#endif
