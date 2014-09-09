
#ifndef _GLM_QUATERNION_H_
#define _GLM_QUATERNION_H_

#include "vector.h"
#include <cmath>

namespace glm
{
    static const double pi = 3.14159265358979323846;

    template <typename T>
    T deg_to_rad(T value)
    {
        return value * (pi / 180.0f);
    }

    template <typename T>
    T rad_to_deg(T value)
    {
        return value * (180.0f / pi);
    }

    // quaternion multiplication
    template <typename T> 
    vector<T, 4> qmult(const vector<T, 4>& a, const vector<T, 4>& b)
    {
        float wa = a[0];
        float wb = b[0];
        vector<T, 3> va = vector<T, 3>(a[1], a[2], a[3]);
        vector<T, 3> vb = vector<T, 3>(b[1], b[2], b[3]);
        
        float wr = wa * wb - dot(va, vb);
        vector<T, 3> vr = vb * wa + va * wb + cross(va, vb);
        
        return vector<T, 4>(wr, vr[0], vr[1], vr[2]);
    }

    template <typename T>
    vector<T, 4> conjugate(const vector<T, 4>& q)
    {
        return vector<T, 4>(q[0], -q[1], -q[2], -q[3]);
    }

    template <typename T>
    vector<T, 3> qtransform(const vector<T, 4>& q, const vector<T, 3>& v)
    {
        vector<T, 4> vt(0.0, v[0], v[1], v[2]);

        vector<T, 4> vr = qmult(qmult(q, vt), conjugate(q));
        
        return vector<T, 3>(vr[1], vr[2], vr[3]);
    }

    template <typename T>
    vector<T, 4> axis_angle_to_quaternion(const vector<T, 3>& axis, T angle)
    {
        vector<T, 3> axis_n = normalize(axis);
        T angle_rad = deg_to_rad(angle);

        T wr = std::cos(angle_rad / static_cast<T>(2.0));
        vector<T, 3> vr = axis_n * std::sin(angle_rad / static_cast<T>(2.0));

        return vector<T, 4>(wr, vr[0], vr[1], vr[2]);
    }

    template <typename T>
    std::tuple<vector<T, 3>, T> quaternion_to_axis_angle(const vector<T, 4>& q)
    {
        vector<T, 4> qn = normalize(q);
        
        T cos_a = qn[0];
        T angle = std::acos(cos_a) * 2;
        T sin_a = std::sqrt( (T)1.0 - cos_a * cos_a );

        if (std::abs(sin_a) < (T)0.0005)
        {
            sin_a = 1;
        }

        vector<T, 3> axis;
        axis[0] = qn[1] / sin_a;
        axis[1] = qn[2] / sin_a;
        axis[2] = qn[3] / sin_a;

        if (std::abs(angle) < (T)0.0005)
        {
            return std::make_pair(glm::vec3((T)0.0, (T)0.0, (T)1.0), (T)0.0);
        }
        else
        {
            return std::make_pair(axis, rad_to_deg(angle));
        }        
    }

    typedef vector<float, 4> quat;
    typedef vector<float, 4> dquat;
}

#endif
