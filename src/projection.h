
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
        
        T t = n * std::tan(deg2rad(fov));
        T b = -t;
        T l = b * a;
        T r = t * a;
        
        return frustum(l, r, b, t, n, f);
    }
}

#endif
