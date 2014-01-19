
#ifndef _GLM_MATRIX_H_
#define _GLM_MATRIX_H_

#include <cassert>
#include <iostream>

#include "vprox.h"

namespace glm
{
    template <typename T, unsigned int N>
    class matrix
    {
    public:
    
        matrix()
        {
            for (unsigned int i = 0; i < N; i++)
            {
                for (unsigned int j = 0; j < N; j++)
                {
                    if (i == j)
                    {
                        data[i*N + j] = 1;
                    }
                    else
                    {
                        data[i*N + j] = 0;
                    }
                }
            }
        }
        
        matrix(T v)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                for (unsigned int j = 0; j < N; j++)
                {
                    if (i == j)
                    {
                        data[i*N + j] = v;
                    }
                    else
                    {
                        data[i*N + j] = 0;
                    }
                }
            }
        }
        
        matrix(float v00, float v01, 
               float v02, float v03)
        {
            assert(N == 2);
            data[0] = v00; data[1] = v01; 
            data[2] = v02; data[3] = v03; 
        }
        
        matrix(float v00, float v01, float v02, 
               float v03, float v04, float v05, 
               float v06, float v07, float v08)
        {
            assert(N == 3);
            data[0] = v00; data[1] = v01; data[2] = v02; 
            data[3] = v03; data[4] = v04; data[5] = v05; 
            data[6] = v06; data[7] = v07; data[8] = v08;
        }
        
        
        matrix(float v00, float v01, float v02, float v03, 
               float v04, float v05, float v06, float v07,
               float v08, float v09, float v10, float v11,
               float v12, float v13, float v14, float v15)
        {
            assert(N == 4);
            data[ 0] = v00; data[ 1] = v01; data[ 2] = v02; data[ 3] = v03;
            data[ 4] = v04; data[ 5] = v05; data[ 6] = v06; data[ 7] = v07;
            data[ 8] = v08; data[ 9] = v09; data[10] = v10; data[11] = v11;
            data[12] = v12; data[13] = v13; data[14] = v14; data[15] = v15;
        }
        
        template <typename T2, unsigned int N2>       
        matrix(const matrix<T2, N2>& o)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                for (unsigned int j = 0; j < N; j++)
                {
                    if (i < N2 && j < N2)
                    {
                        data[i*N + j] = o[i][j];
                    }
                    else if (i == j)
                    {
                        data[i*N + j] = 1;
                    }
                    else
                    {
                        data[i*N + j] = 0;
                    }
                }
            }
        }
        
        matrix(const matrix<T, N>& o)
        {
            for (unsigned int i = 0; i < N * N; i++)
            {
                data[i] = o.data[i];
            }
        }
        
        const matrix<T,N>& operator = (const matrix<T, N>& o)
        {
            for (unsigned int i = 0; i < N * N; i++)
            {
                data[i] = o.data[i];
            }
            return *this;
        }
        
        vprox<T, N> operator [] (unsigned int i)
        {
            assert(i < N);
            return vprox<T, N>(&data[i * N]);
        }
        
        // REVIEW check for const corectness
        const vprox<T, N> operator [] (unsigned int i) const
        {
            assert(i < N);
            return vprox<T, N>(const_cast<T*>(&data[i * N]));
        }
        
        bool operator == (const matrix<T, N>& m) const
        {
            for (unsigned int i = 0; i < N * N; i++)
            {
                if (data[i] != m.data[i]) 
                {
                    return false;
                }
            }
            return true;
        }
        
        bool operator != (const matrix<T, N>& m) const
        {
            return !(*this == m);
        }
        
        // for std::set, std::map and firends
        bool operator < (const matrix<T, N>& m) const
        {
            for (unsigned int i = 0; i < N * N; i++)
            {
                if (data[i] < m.data[i]) 
                {
                    return true;
                }
            }
            return false;
        }
        
        const matrix<T, N>& operator += (const matrix<T, N>& v)
        {
            for (unsigned int i = 0; i < N*N; i++)
            {
                data[i] += v.data[i];
            }
            return *this;
        }
        
        const matrix<T, N>& operator -= (const matrix<T, N>& v)
        {
            for (unsigned int i = 0; i < N*N; i++)
            {
                data[i] -= v.data[i];
            }
            return *this;
        }
        
        operator const T* () const
        {
            return data;
        }
        
    private:
        T data[N*N];
    };
    
    template <typename T, unsigned int N>
    matrix<T, N> operator + (const matrix<T, N>& a)
    {
        return a;
    }
    
    template <typename T, unsigned int N>
    matrix<T, N> operator - (const matrix<T, N>& a)
    {
        matrix<T, N> r;
        for (unsigned int i = 0; i < N; i++)
        {
            for (unsigned int j = 0; j < N; j++)
            {
                r[i][j] = -a[i][j];
            }
        }
        return r;
    }
    
    template <typename T, unsigned int N>
    matrix<T, N> operator + (const matrix<T, N>& a, const matrix<T, N>& b)
    {
        matrix<T, N> t = a;
        t += b;
        return t;
    }
    
    template <typename T, unsigned int N>
    matrix<T, N> operator - (const matrix<T, N>& a, const matrix<T, N>& b)
    {
        matrix<T, N> t = a;
        t -= b;
        return t;
    }
    
    template <typename T, unsigned int N>    
    matrix<T, N> operator * (const matrix<T, N>& a, const matrix<T, N>& b)
    {
        matrix<T, N> r(0);
        
        for (unsigned int i = 0; i < N; i++)
        {
            for (unsigned int j = 0; j < N; j++)
            {
                for (unsigned int k = 0; k < N; k++)
                {
                    r[i][j] += a[k][j] * b[i][k];
                }                
            }
        }
        
        return r;
    }
    
    template <typename T, unsigned int N>
    vector<T, N> operator * (const matrix<T, N>& m, const vector<T, N>& v)
    {
        vector<T, N> r(0);
        
        for (unsigned int i = 0; i < N; i++)
        {
            for (unsigned int j = 0; j < N; j++)
            {
               r[i] += m[j][i] * v[j]; 
            }
        }
        
        return r;
    }
    
    template <typename T, unsigned int N>
    matrix<T, N> matrixCompMult(const matrix<T, N>& a, const matrix<T, N>& b)
    {
        matrix<T, N> r(0);
        
        for (unsigned int i = 0; i < N; i++)
        {
            for (unsigned int j = 0; j < N; j++)
            {
                r[i][j] = a[i][j] * b[i][j];
            }
        }
        
        return r;
    }

    template <typename T, unsigned int N>
    matrix<T, N> transpose(const matrix<T, N>& m)
    {
        matrix<T, N> r(0);
        
        for (unsigned int i = 0; i < 4; i++)
        {
            for (unsigned int j = 0; j < 4; j++)
            {
                r[j][i] = m[i][j];
            }
        }
        
        return r;
    }
    
    template <typename T, unsigned int N>
    std::ostream& operator << (std::ostream& os, const matrix<T, N>& m)
    {
        os << "{";
        for (unsigned int i = 0; i < N; i++)
        {
            for (unsigned int j = 0; j < N; j++)
            {
                os << m[i][j];
                if (i != N-1)
                {
                    os << ", ";
                }
                else if (j != N-1)
                {
                    os << "; ";
                }
            }
        }
        os << "}";
        return os;
    }
    
    typedef matrix<bool, 2> bmat2;
    typedef matrix<bool, 3> bmat3;
    typedef matrix<bool, 4> bmat4;
    
    typedef matrix<int, 2> imat2;
    typedef matrix<int, 3> imat3;
    typedef matrix<int, 4> imat4;
    
    typedef matrix<unsigned int, 2> umat2;
    typedef matrix<unsigned int, 3> umat3;
    typedef matrix<unsigned int, 4> umat4;
    
    typedef matrix<float, 2> mat2;
    typedef matrix<float, 3> mat3;    
    typedef matrix<float, 4> mat4;
    
    typedef matrix<double, 2> dmat2;
    typedef matrix<double, 3> dmat3;    
    typedef matrix<double, 4> dmat4;
}

#endif
