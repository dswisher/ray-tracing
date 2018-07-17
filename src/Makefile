
CPP=g++
CPPFLAGS=-c -Wall
SOURCES=main.cc
HEADERS=vec3.h ray.h

OBJECTS=$(SOURCES:.cc=.o)

ray: $(OBJECTS) $(SOURCES) $(HEADERS)
	$(CPP) -o ray main.o

.cc.o:
	$(CPP) $(CPPFLAGS) $< -o $@

depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CPP) $(CPPFLAGS) -MM $^ > ./.depend;

clean:
	rm -f *.o
	rm ray
	rm ./.depend

-include .depend
