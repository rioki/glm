
#ifndef _GLM_VPROX_H_
#define _GLM_VPROX_H_

#include <cassert>
#include <cmath>

#include "vector.h"

namespace glm
{
    template <typename T, unsigned int N>
    class vprox
    {
    public:
    
        explicit 
        vprox(T* d)
        : data(d) {}
        
        const vprox<T, N>& operator = (const vprox<T, N>& v)
        {
            for (unsigned int j; j < N; j++)
            {
                data[j] = v[j];
            }
            return *this;
        }
        
        const vprox<T, N>& operator = (const vector<T, N>& v)
        {
            for (unsigned int j; j < N; j++)
            {
                data[j] = v[j];
            }
            return *this;
        }
        
        T& operator [] (unsigned int j)
        {
            assert(j < N);
            return data[j];
        }
        
        T operator [] (unsigned int j) const
        {
            assert(j < N);
            return data[j];
        }
        
        operator vector<T, N> () const
        {
            vector<T, N> r;
            
            for (unsigned int j = 0; j < N; j++)
            {
                r[j] = data[j];
            }
            
            return r;
        }
        
        template <typename T2, unsigned int N2>
        operator vector<T2, N2> () const
        {
            vector<T2, N2> r;
            
            unsigned int n = std::min(N, N2);
            
            for (unsigned int j = 0; j < n; j++)
            {
                r[j] = data[j];
            }
            for (unsigned int j = n; j < N2; j++)
            {
                r[j] = 0;
            }
            
            return r;
        }
    
    private:
        T* data;        
    };
}

#endif
