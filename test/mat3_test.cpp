
#include <rtest.h>

#include "glm.h"

SUITE(mat3_test)
{
    TEST(init)
    {
        glm::mat3 m;
        glm::mat3 r(1.0f, 0.0f, 0.0f, 
                    0.0f, 1.0f, 0.0f, 
                    0.0f, 0.0f, 1.0f);
        CHECK_EQUAL(r, m);
        
    }
}
