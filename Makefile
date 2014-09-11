
CXX      ?= g++
CXXFLAGS += -std=c++0x -Iglm
prefix   ?= /usr/local

glm_HEADERS 	  = glm/glm.h \
                    glm/matrix.h \
                    glm/projection.h \
                    glm/quaternion.h \
                    glm/transform.h \
                    glm/utils.h \
                    glm/vector.h
				
glm_test_SOURCES  = test/main.cpp \
                    test/mat2_test.cpp \
                    test/mat3_test.cpp \
                    test/mat4_test.cpp \
                    test/proj_test.cpp \
                    test/vec2_test.cpp \
                    test/vec3_test.cpp \
                    test/vec4_test.cpp

all: 
	@echo "Nothing to do, run make check or make installl"

check: glm-test
	./glm-test
	
glm-test: $(patsubst %.cpp, .obj/%.o, $(glm_test_SOURCES))
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -lrtest -o $@

clean:
	rm -rf glm-test* .obj
	
install:
	mkdir -p $(prefix)/include/glm
	cp $(glm_HEADERS) $(prefix)/include/glm

uninstall:
	rm -r $(prefix)/include/glm
	
.obj/%.o : %.cpp	
	mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -MD -c $^ -o $@

ifneq "$(MAKECMDGOALS)" "clean"
-include $(patsubst %.cpp, obj/%.d, $(glm_test_SOURCES))
endif
