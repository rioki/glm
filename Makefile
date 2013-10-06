
PACKAGE     = glm
VERSION     = 0.1.0
prefix     ?= /usr/local
CXX        ?= g++
CXXFLAGS   += -g -Wall -std=c++0x 
LDFLAGS    += 

headers     := $(wildcard *.h)
srcs        := $(wildcard *.cpp)
extra_dist  := Makefile README.md

.PHONY: all clean install uninstall

all: lib$(PACKAGE).a

lib$(PACKAGE).a: $(patsubst %.cpp, %.o, $(srcs))
	ar rcs $@ $^
	
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -MD -c $< -o $@

clean:
	rm -rf *.a *.o
	
install: lib$(PACKAGE).a
	mkdir -p $(prefix)/include/$(PACKAGE)
	cp *.h $(prefix)/include/$(PACKAGE)
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
	
ifneq "$(MAKECMDGOALS)" "clean"
-include $(patsubst %.cpp, %.d, $(srcs))
endif
