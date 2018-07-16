
CPP=g++
CPPFLAGS=-c -Wall
SOURCES=main.cc
HEADERS=vec3.h ray.h

OBJECTS=$(SOURCES:.cc=.o)

ray: $(OBJECTS) $(SOURCES) $(HEADERS)
	$(CPP) -o ray main.o

.cc.o:
	$(CPP) $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o
	rm ray
