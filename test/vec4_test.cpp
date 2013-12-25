
#include <rtest.h>

#include "glm.h"

SUITE(vec4)
{
    TEST(default)
    {
        glm::vec4 v;
        
        CHECK_EQUAL(0.0f, v[0]);
        CHECK_EQUAL(0.0f, v[1]);
        CHECK_EQUAL(0.0f, v[2]);
        CHECK_EQUAL(0.0f, v[3]);
    }
    
    TEST(init2)
    {
        glm::vec4 v(1.0f, 2.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(0.0f, v[2]);
        CHECK_EQUAL(0.0f, v[3]);
    }
    
    TEST(init3)
    {
        glm::vec4 v(1.0f, 2.0f, 3.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
        CHECK_EQUAL(0.0f, v[3]);
    }
    
    TEST(init4)
    {
        glm::vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
        CHECK_EQUAL(4.0f, v[3]);
    }
    
    TEST(init41)
    {
        glm::vec4 v(1.0f, glm::vec3(2.0f, 3.0f, 4.0f));
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
        CHECK_EQUAL(4.0f, v[3]);
    }
    
    TEST(init42)
    {
        glm::vec4 v(1.0f, 2.0f, glm::vec2(3.0f, 4.0f));
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
        CHECK_EQUAL(4.0f, v[3]);
    }
    
    TEST(init43)
    {
        glm::vec4 v(1.0f, glm::vec2(2.0f, 3.0f), 4.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
        CHECK_EQUAL(4.0f, v[3]);
    }
    
    TEST(init44)
    {
        glm::vec4 v(glm::vec2(1.0f, 2.0f), 3.0f, 4.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
        CHECK_EQUAL(4.0f, v[3]);
    }
    
    TEST(init45)
    {
        glm::vec4 v(glm::vec3(1.0f, 2.0f, 3.0f), 4.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
        CHECK_EQUAL(3.0f, v[2]);
        CHECK_EQUAL(4.0f, v[3]);
    }
    
    TEST(add)
    {
        glm::vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
        glm::vec4 b(3.0f, 4.0f, 5.0f, 6.0f);
        
        CHECK_EQUAL(glm::vec4(4.0f, 6.0f, 8.0f, 10.0f), a + b);
    }
    
    TEST(subst)
    {
        glm::vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
        glm::vec4 b(3.0f, 4.0f, 5.0f, 6.0f);
        
        CHECK_EQUAL(glm::vec4(-2.0f, -2.0f, -2.0f, -2.0f), a - b);
    }
    
    TEST(mul_scal)
    {
        glm::vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
        
        CHECK_EQUAL(glm::vec4(2.0f, 4.0f, 6.0f, 8.0f), a * 2.0f);
    }    
}
