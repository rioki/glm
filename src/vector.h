
#ifndef _GLM_VECTOR_H_
#define _GLM_VECTOR_H_

#include <cassert>
#include <cmath>
#include <iostream>
#include <algorithm>

namespace glm
{
    template <typename T, unsigned int N>
    class vector
    {
    public:    
    
        vector()
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = 0;
            }
        }
        
        vector(T v)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = v;
            }        
        }
        
        vector(T x, T y)
        {            
            assert(N >= 2);
            
            data[0] = x;
            data[1] = y;
            
            for (unsigned int i = 2; i < N; i++)
            {
                data[i] = 0;
            }
        }
        
        vector(T x, T y, T z)
        {            
            assert(N >= 3);
            
            data[0] = x;
            data[1] = y;
            data[2] = z;
            
            for (unsigned int i = 3; i < N; i++)
            {
                data[i] = 0;
            }
        }
        
        vector(T x, T y, T z, T w)
        {            
            assert(N >= 3);
            
            data[0] = x;
            data[1] = y;
            data[2] = z;
            data[3] = w;
            
            for (unsigned int i = 4; i < N; i++)
            {
                data[i] = 0;
            }
        }
        
        vector(T x, const vector<T, N - 1> v)
        {
            assert(N >= 2);
            
            data[0] = x;
            for (unsigned int i = 1; i < N; i++)
            {
                data[i] = v[i - 1];
            }
        }
        
        vector(T x, T y, const vector<T, N - 2> v)
        {
            assert(N >= 3);
            
            data[0] = x;
            data[1] = y;
            for (unsigned int i = 2; i < N; i++)
            {
                data[i] = v[i - 2];
            }
        }
        
        vector(T x, const vector<T, N - 2> v, T u)
        {
            assert(N >= 3);
            
            data[0] = x;
            data[N-1] = u;
            for (unsigned int i = 1; i < N - 1; i++)
            {
                data[i] = v[i - 1];
            }
        }
        
        vector(const vector<T, N-1> v, T s)
        {
            assert(N >= 3);
            
            data[N-1] = s;
            for (unsigned int i = 0; i < N - 1; i++)
            {
                data[i] = v[i];
            }
        }
        
        vector(const vector<T, N - 2> v, T u, T s)
        {
            assert(N >= 3);
            
            data[N-2] = u;
            data[N-1] = s;
            for (unsigned int i = 0; i < N - 2; i++)
            {
                data[i] = v[i];
            }
        }
        
        vector(const vector<T, N>& v)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = v.data[i];
            }
        }
        
        template <typename T2, unsigned int N2>
        explicit 
        vector(const vector<T2, N2> v)
        {
            unsigned int n = std::min(N, N2);
            for (unsigned int i = 0; i < n; i++)
            {
                // the constructor is already explicit, 
                // so the case suppresses any compiler warnings
                data[i] = (T)v[i];
            }
            
            for (unsigned int i = n; i < N; i++)
            {
                data[i] = 0;
            }
        }
        
        const vector<T, N>& operator = (const vector<T, N>& v)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = v.data[i];
            }
            return *this;
        }       
        
        const vector<T, N>& operator += (const vector<T, N>& v)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] += v.data[i];
            }
            return *this;
        }
        
        const vector<T, N>& operator -= (const vector<T, N>& v)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] -= v.data[i];
            }
            return *this;
        }
        
        T& operator [] (unsigned int i)
        {
            assert(i < N);
            return data[i];
        }
        
        T operator [] (unsigned int i) const
        {
            assert(i < N);
            return data[i];
        }
        
    private:
        T data[N];
    };
    
    template <typename T, unsigned int N>
    bool operator == (const vector<T, N>& a, const vector<T, N>& b)
    {
        for (unsigned int i = 0; i < N; i++)
        {                
            if (a[i] != b[i])
            {
                return false;
            }
        }        
        return true;
    }

    template <typename T, unsigned int N>
    bool operator != (const vector<T, N>& a, const vector<T, N>& b)
    {
        return !(a == b);
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator + (const vector<T, N>& v)
    {
        return v;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator - (const vector<T, N>& v)
    {
        vector<T, N> r;
        
        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = -v[i];
        }  
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator + (const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> r(a);
        r += b;        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator - (const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> r(a);
        r -= b;        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator * (const vector<T, N>& a, T b)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = a[i] * b;
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator * (const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = a[i] * b[i];
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator / (const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = a[i] / b[i];
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    T dot(const vector<T, N>& a, const vector<T, N>& b)
    {
        T r = 0;
        
        for (unsigned int i = 0; i < N; i++)
        {                
            r += a[i] * b[i];
        } 
        
        return r;
    }
    
    template <typename T>
    vector<T, 3> cross (const vector<T, 3>& a, const vector<T, 3>& b)
    {
        return vector<T, 3>((a[1] * b[2]) - (a[2] * b[1]),
                            (a[2] * b[0]) - (a[0] * b[2]),
                            (a[0] * b[1]) - (a[1] * b[0]));
    }
    
    template <typename T, unsigned int N>
    T length(const vector<T, N>& v)
    {
        return std::sqrt(dot(v, v));
    }

    template <typename T, unsigned int N>
    T distance(const vector<T, N>& a, const vector<T, N>& b)
    {
        return length(a - b);
    }
    
    template <typename T, unsigned int N>
    vector<T, N> normalize(const vector<T, N>& v)
    {
        return v * (1 / length(v));
    }
    
    template <typename T, unsigned int N>
    vector<T, N> min(const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = std::min(a[i], b[i]);
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> min(const vector<T, N>& a, T b)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = std::min(a[i], b);
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> max(const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = std::max(a[i], b[i]);
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> max(const vector<T, N>& a, float b)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = std::max(a[i], b);
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> clamp(const vector<T, N>& a, const vector<T, N>& minVal, const vector<T, N>& maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    template <typename T, unsigned int N>
    vector<T, N> clamp(const vector<T, N>& a, float minVal, float maxVal)
    {
        return min(max(a, minVal), maxVal);
    }
    
    template <typename T, unsigned int N>
    vector<T, N> mix(const vector<T, N>& a, const vector<T, N>& b, const vector<T, N>& wb)
    {
        return a * (vector<T, N>(1.0) - wb) + b * wb;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> mix(const vector<T, N>& a, const vector<T, N>& b, float wb)
    {
        return a * vector<T, N>(1.0 - wb) + b * vector<T, N>(wb);
    }
    
    template <typename T, unsigned int N>
    vector<T, N> floor(const vector<T, N>& v)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = std::floor(v[i]);
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> ceil(const vector<T, N>& v)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {                
            r[i] = std::ceil(v[i]);
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> round(const vector<T, N>& v)
    {
        vector<T, N> r;

        for (unsigned int i = 0; i < N; i++)
        {             
            // WHY U NO std::round?!
            r[i] = ::round(v[i]);
        } 
        
        return r;
    }
    
    template <typename T, unsigned int N>
    std::ostream& operator << (std::ostream& os, const vector<T, N>& v)
    {
        os << "(";
        for (unsigned int i = 0; i < N; i++)
        {                
            os << v[i];
            if (i != N-1)
            {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
    
    typedef vector<bool, 2> bvec2;
    typedef vector<bool, 3> bvec3;
    typedef vector<bool, 4> bvec4;
    
    typedef vector<int, 2> ivec2;
    typedef vector<int, 3> ivec3;
    typedef vector<int, 4> ivec4;
    
    typedef vector<unsigned int, 2> uvec2;
    typedef vector<unsigned int, 3> uvec3;
    typedef vector<unsigned int, 4> uvec4;
    
    typedef vector<float, 2> vec2;
    typedef vector<float, 3> vec3;    
    typedef vector<float, 4> vec4;
    
    typedef vector<double, 2> dvec2;
    typedef vector<double, 3> dvec3;    
    typedef vector<double, 4> dvec4;
}

#endif
