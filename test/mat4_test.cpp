
#include <rtest.h>

#include "glm.h"

SUITE(mat4_test)
{
    TEST(init)
    {
        glm::mat4 m;
        glm::mat4 r(1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f);
        CHECK_EQUAL(r, m);
        
    }    

    TEST(transpose)
    {
        glm::mat4 o( 0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15);
        
        glm::mat4 r = transpose(o);
        
        CHECK_EQUAL(o[0][0], r[0][0]);
        CHECK_EQUAL(o[0][1], r[1][0]);
        CHECK_EQUAL(o[3][2], r[2][3]);
    }
    
    TEST(access)
    {
        glm::mat4 m( 1,  2,  3, 4,
                     5,  6,  7, 8,
                     9, 10, 11, 12,
                    13, 14, 15, 16);
               
        CHECK_EQUAL(7.0, m[1][2]);
    }
    
    TEST(mulitply)
    {
        glm::mat4 a( 1,  2,  3, 4,
                     5,  6,  7, 8,
                     9, 10, 11, 12,
                    13, 14, 15, 16);
        
        glm::mat4 b(1, 2, 3, 4,
                    2, 3, 4, 5,
                    3, 4, 5, 6, 
                    4, 5, 6, 7);
        
        glm::mat4 r = a * b;       
        
        glm::mat4 ref( 90, 100, 110, 120,
                      118, 132, 146, 160,
                      146, 164, 182, 200, 
                      174, 196, 218, 240);
        
        CHECK_EQUAL(ref, r);
    }
    
    TEST(vector_multiply)
    {
        glm::mat4 m( 1,  2,  3, 4,
                     5,  6,  7, 8,
                     9, 10, 11, 12,
                    13, 14, 15, 16);
        glm::vec4 v(1, 2, 3, 4);
        
        glm::vec4 r = m * v;
        
        CHECK_EQUAL(glm::vec4(90, 100, 110, 120), r);
    }
}
