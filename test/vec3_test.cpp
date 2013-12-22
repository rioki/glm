
#include <rtest.h>

#include "glm.h"

SUITE(vec3)
{
    TEST(default)
    {
        glm::vec3 v;
        
        CHECK_EQUAL(0.0f, v[0]);
        CHECK_EQUAL(0.0f, v[1]);
        CHECK_EQUAL(0.0f, v[2]);
    }
    
    TEST(init2)
    {
        glm::vec3 v(1.0f, 2.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(0.0f, v[2]);
    }
    
    TEST(init3)
    {
        glm::vec3 v(1.0f, 2.0f, 3.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
    }
    
    TEST(add)
    {
        glm::vec3 a(1.0f, 2.0f, 3.0f);
        glm::vec3 b(3.0f, 4.0f, 5.0f);
        
        CHECK_EQUAL(glm::vec3(4.0f, 6.0f, 8.0f), a + b);
    }
    
    TEST(subst)
    {
        glm::vec3 a(1.0f, 2.0f, 3.0f);
        glm::vec3 b(3.0f, 4.0f, 5.0f);
        
        CHECK_EQUAL(glm::vec3(-2.0f, -2.0f, -2.0f), a - b);
    }
    
    TEST(mul_scal)
    {
        glm::vec3 a(1.0f, 2.0f, 3.0f);
        
        CHECK_EQUAL(glm::vec3(2.0f, 4.0f, 6.0f), a * 2.0f);
    }
}
