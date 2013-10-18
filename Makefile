
PACKAGE     = glm
VERSION     = 0.1.0
prefix     ?= /usr/local
CXX        ?= g++
CXXFLAGS   += -g -Wall -std=c++0x -I./src/
LDFLAGS    += 

inst_HEADERS     := src/glm.h src/mat2.h src/mat3.h src/mat4.h src/projection.h \
				    src/vec2.h src/vec3.h src/vec4.h
glm_SOURCES      := src/mat2.cpp src/mat3.cpp src/mat4.cpp src/projection.cpp \
				    src/vec2.cpp src/vec3.cpp src/vec4.cpp
test_SOURCES     := test/main.cpp test/mat4_test.cpp
test_LDADD       := -lrtest 
extra_dist_FILES := Makefile README.md

ifeq ($(MSYSTEM), MINGW32)
  EXEEXT     := .exe  
  LIBEXT     := .dll
else
  EXEEXT     :=
  LIBEXT     := .so  
endif

.PHONY: all clean check install uninstall

all: lib$(PACKAGE).a

lib$(PACKAGE).a: $(patsubst %.cpp, %.o, $(glm_SOURCES))
	ar rcs $@ $^
	
check: $(PACKAGE)-test$(EXEEXT)
	./$(PACKAGE)-test$(EXEEXT)
	
$(PACKAGE)-test$(EXEEXT): $(patsubst %.cpp, %.o, $(test_SOURCES)) lib$(PACKAGE).a
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(test_LDADD) -o $@

clean:
	rm -rf lib$(PACKAGE).a $(PACKAGE)-test$(EXEEXT) */*.o */*.d
	
install: lib$(PACKAGE).a
	mkdir -p $(prefix)/include/$(PACKAGE)
	cp $(inst_HEADERS) $(prefix)/include/$(PACKAGE)
	mkdir -p $(prefix)/lib
	cp lib$(PACKAGE).a $(prefix)/lib	

uninstall:
	rm -rf $(prefix)/include/$(PACKAGE)
	rm -f $(prefix)/lib/lib$(PACKAGE).a

dist:
	mkdir $(PACKAGE)-$(VERSION)
	cp $(headers) $(PACKAGE)-$(VERSION)
	cp $(srcs) $(PACKAGE)-$(VERSION)
	cp $(extra_dist) $(PACKAGE)-$(VERSION)
	tar -czvf $(PACKAGE)-$(VERSION).tar.gz $(PACKAGE)-$(VERSION)
	rm -rf $(PACKAGE)-$(VERSION)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -MD -c $< -o $@
	
ifneq "$(MAKECMDGOALS)" "clean"
-include $(patsubst %.cpp, %.d, $(srcs))
endif
