
#include <rtest.h>

#include "glm.h"

using namespace glm;

SUITE(proj_test)
{
    TEST(ortho)
    {
        mat4 proj = ortho(0, 100, 0, 100, 0, 100);
        
        vec4 v(25, 25, 25, 1.0);
        
        vec4 r = proj * v;
        
        CHECK_EQUAL(vec4(-0.5, -0.5, -1.5, 1.0), r);        
    }
    
    TEST(perspective)
    {
        mat4 proj = perspective(45, 800.0/600.0, 1.0, 100);
        
        vec4 v(1.0, 1.0, -10, 1.0);
        
        vec4 r = proj * v;
        r = r * (1 / r[3]);
        
        CHECK_EQUAL(vec4(0.181066, 0.241421, 0.818182, 1), r);        
    }
    
    TEST(translate)
    {
        mat4 m = translate(vec3(1, 2, 3));
        
        mat4 rm(1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                1, 2, 3, 1);
        CHECK_EQUAL(rm, m);
        
        vec4 r = m * vec4(1, 1, 1, 1);
        
        CHECK_EQUAL(vec4(2, 3, 4, 1), r);
    }
}
