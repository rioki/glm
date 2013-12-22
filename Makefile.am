
pkginclude_HEADERS = src/glm.h \
                     src/vector.h \
                     src/matrix.h

check_PROGRAMS     = glm-test
TESTS              = glm-test

glm_test_CXXFLAGS  = -Isrc
glm_test_LDADD     = @TEST_LIBS@
glm_test_SOURCES   = test/main.cpp \
                     test/vec2_test.cpp \
                     test/vec3_test.cpp \
                     test/vec4_test.cpp \
                     test/mat2_test.cpp \
                     test/mat3_test.cpp \
                     test/mat4_test.cpp

EXTRA_DIST         = README.md
