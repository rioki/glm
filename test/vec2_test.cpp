
#include <rtest.h>

#include "glm.h"

SUITE(vec2)
{
    TEST(default)
    {
        glm::vec2 v;
        
        CHECK_EQUAL(0.0f, v[0]);
        CHECK_EQUAL(0.0f, v[1]);
    }
    
    TEST(init2)
    {
        glm::vec2 v(1.0f, 2.0f);
        
        CHECK_EQUAL(1.0f, v[0]);
        CHECK_EQUAL(2.0f, v[1]);
    }
    
    TEST(add)
    {
        glm::vec2 a(1.0f, 2.0f);
        glm::vec2 b(3.0f, 4.0f);
        
        CHECK_EQUAL(glm::vec2(4.0f, 6.0f), a + b);
    }
    
    TEST(subs)
    {
        glm::vec2 a(1.0f, 2.0f);
        glm::vec2 b(3.0f, 4.0f);
        
        CHECK_EQUAL(glm::vec2(-2.0f, -2.0f), a - b);
    }
    
    TEST(mul_scal)
    {
        glm::vec2 a(1.0f, 2.0f);
        
        CHECK_EQUAL(glm::vec2(2.0f, 4.0f), a * 2.0f);
    }
    
    TEST(floor)
    {
        glm::vec2 r = glm::floor(glm::vec2(1.5f, 2.3f));
        CHECK_EQUAL(glm::vec2(1.0f, 2.0f), r);
    }
    
    TEST(ceil)
    {
        glm::vec2 r = glm::ceil(glm::vec2(1.5f, 2.3f));
        CHECK_EQUAL(glm::vec2(2.0f, 3.0f), r);
    }

    TEST(round)
    {
        glm::vec2 r = glm::round(glm::vec2(1.5f, 2.3f));
        CHECK_EQUAL(glm::vec2(2.0f, 2.0f), r);
    }    
}
