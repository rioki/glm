
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
        glm::mat4 m = glm::translate(glm::mat4(1), glm::vec3(1, 2, 3));
        
        glm::vec4 r = m * glm::vec4(1, 1, 1, 1);
        
        CHECK_EQUAL(glm::vec4(2, 3, 4, 1), r);
    }
    
    TEST(rotate) 
    {
        glm::mat4 m = glm::rotate<float>(glm::mat4(1), 90, glm::vec3(0, 0, 1));
        
        glm::vec4 r = m * glm::vec4(1, 0, 0, 0);
        CHECK(glm::abs(glm::vec4(0, 1, 0, 0) - r) < glm::vec4(1e-4));
    }
    
    TEST(scale) 
    {
        glm::mat4 m = glm::scale<float>(glm::mat4(1), 2, 3, 4);
        
        glm::vec4 r = m * glm::vec4(1, 1, 1, 1);
        CHECK_EQUAL(glm::vec4(2, 3, 4, 1), r);
    }  
}
