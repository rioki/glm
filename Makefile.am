
ACLOCAL_AMFLAGS    = -I m4

pkginclude_HEADERS = src/glm.h src/mat2.h src/mat3.h src/mat4.h \
                     src/projection.h src/vec2.h src/vec3.h src/vec4.h

lib_LTLIBRARIES    = libglm.la

libglm_la_LDFLAGS  = -no-undefined -version-info 0:0:0
libglm_la_SOURCES  = src/mat2.cpp src/mat3.cpp src/mat4.cpp src/projection.cpp \
                     src/vec2.cpp src/vec3.cpp src/vec4.cpp

check_PROGRAMS     = glm-test
TESTS              = glm-test

glm_test_CXXFLAGS  = -Isrc
glm_test_LDADD     = libglm.la @TEST_LIBS@
glm_test_SOURCES   = test/main.cpp test/mat4_test.cpp test/proj_test.cpp 

EXTRA_DIST         = README.md