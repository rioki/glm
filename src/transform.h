
#ifndef _GLM_TRANSFORM_H_
#define _GLM_TRANSFORM_H_

#include <cmath>
#include "utils.h"
#include "vector.h"
#include "matrix.h"

namespace glm
{    
    template <typename T>
    matrix<T, 4> translate(const matrix<T, 4>& m, T x, T y, T z)
    {
        matrix<T, 4> d( 1.0,  0.0,  0.0, 0.0,
                        0.0,  1.0,  0.0, 0.0,
                        0.0,  0.0,  1.0, 0.0,
                          x,    y,    z, 1.0);
    
        return m * d;
    }
    
    template <typename T>
    matrix<T, 4> translate(const matrix<T, 4>& m, const vector<T, 3> v)
    {
        return translate(m, v[0], v[1], v[2]);
    }    
    
    template <typename T>
    matrix<T, 4> rotate(const matrix<T, 4>& m, T angle,  vector<T, 3> v)
    {
        T a = deg2rad(angle);
        T c = std::cos(a);
		T s = std::sin(a);
        
        vector<T, 3> axis = normalize(v);

		vector<T, 3> t = axis * (1 - c);

		matrix<T, 4> d(1.0);
		d[0][0] = c + t[0] * axis[0];
		d[0][1] = 0 + t[0] * axis[1] + s * axis[2];
		d[0][2] = 0 + t[0] * axis[2] - s * axis[1];

		d[1][0] = 0 + t[1] * axis[0] - s * axis[2];
		d[1][1] = c + t[1] * axis[1];
		d[1][2] = 0 + t[1] * axis[2] + s * axis[0];

		d[2][0] = 0 + t[2] * axis[0] + s * axis[1];
		d[2][1] = 0 + t[2] * axis[1] - s * axis[0];
		d[2][2] = c + t[2] * axis[2];
        
        return m * d;
    }
    
    template <typename T>
    matrix<T, 4> rotate(const matrix<T, 4>& m, T angle,  T x, T y, T z)
    {
        return rotate(m, vector<T, 3>(x, y, z));
    }
    
    template <typename T>
    matrix<T, 4> scale(const matrix<T, 4>& m, T x, T y, T z)
    {
        matrix<T, 4> d(  x,  0.0,  0.0, 0.0,
                       0.0, y,  0.0, 0.0,
                       0.0,  0.0, z, 0.0,
                       0.0,  0.0,  0.0, 1.0);
        return m * d;
    }
    
    template <typename T>
    matrix<T, 4> scale(const matrix<T, 4>& m, vector<T, 3> v)
    {
        return scale(m, v[0], v[1], v[2]);
    }
}

#endif
