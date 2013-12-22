
#ifndef _GLM_VPROX_H_
#define _GLM_VPROX_H_

#include <cassert>

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
            return this;
        }
        
        const vprox<T, N>& operator = (const vector<T, N>& v)
        {
            for (unsigned int j; j < N; j++)
            {
                data[j] = v[j];
            }
            return this;
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
            
            for (unsigned int j; j < N; j++)
            {
                r[j] = data[j];
            }
            
            return r;
        }
    
    private:
        T* data;        
    };
}

#endif
