
#include <rtest.h>

#include "glm.h"

SUITE(mat2_test)
{
    TEST(init)
    {
        glm::mat2 m;
        glm::mat2 r(1.0f, 0.0f,
                    0.0f, 1.0f);
        CHECK_EQUAL(r, m);
        
    }
}
