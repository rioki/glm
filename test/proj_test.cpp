
#include "rtest.h"

#include "glm.h"

SUITE(proj_test)
{
    TEST(ortho)
    {
        glm::mat4 proj = glm::ortho<float>(0, 100, 0, 100, 0, 100);
        
        glm::vec4 v(25, 25, 25, 1.0);
        
        glm::vec4 r = proj * v;
        
        CHECK_EQUAL(glm::vec4(-0.5, -0.5, -1.5, 1.0), r);        
    }    
    
    TEST(translate)
    {
        glm::mat4 m = glm::translate(1.0f, 2.0f, 3.0f);
        
        glm::mat4 rm(1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     1, 2, 3, 1);
        CHECK_EQUAL(rm, m);
        
        glm::vec4 r = m * glm::vec4(1, 1, 1, 1);
        
        CHECK_EQUAL(glm::vec4(2, 3, 4, 1), r);
    }
    
    TEST(translate2)
    {
        glm::mat4 m = glm::translate(glm::vec3(1, 2, 3));
        
        glm::mat4 rm(1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     1, 2, 3, 1);
        CHECK_EQUAL(rm, m);
        
        glm::vec4 r = m * glm::vec4(1, 1, 1, 1);
        
        CHECK_EQUAL(glm::vec4(2, 3, 4, 1), r);
    }
}
