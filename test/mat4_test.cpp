
#include <rtest.h>

#include "glm.h"

using namespace glm;

SUITE(mat4_test)
{
    TEST(transpose)
    {
        mat4 o( 0,  1,  2,  3,
                4,  5,  6,  7,
                8,  9, 10, 11,
               12, 13, 14, 15);
        
        mat4 r = transpose(o);
        
        CHECK_EQUAL(o[0][0], r[0][0]);
        CHECK_EQUAL(o[0][1], r[1][0]);
        CHECK_EQUAL(o[3][2], r[2][3]);
    }
}
