
#ifndef _GLM_UTILS_H_
#define _GLM_UTILS_H_

namespace glm
{
    template <typename T>
    T deg2rad(T d)
    {		
        T pi = static_cast<T>(3.1415926535897932384626433832795);
        return d * (pi / static_cast<T>(180));
    }

    template <typename T>
    T step(T edge, T x)
    {
        if (x < edge)
        {
            return 0.0;
        }
        else 
        {
            return 1.0;
        }
    }

    template <typename T>
    T clamp(T a, float minVal, float maxVal)
    {
        return std::min<T>(std::max<T>(a, minVal), maxVal);
    }

    template <typename T>
    T smoothstep(T edge0, T edge1, T x)
    {
        T t = clamp<T>((x - edge0) / (edge1 - edge0), 0.0, 1.0);
        return t * t * (3.0 - 2.0 * t);
    }
}

#endif
