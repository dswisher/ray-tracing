
CPP=g++
CPPFLAGS=-c -Wall -std=c++11
SOURCES=main.cc chaos.cc

OBJECTS=$(SOURCES:.cc=.o)

ray: $(OBJECTS) $(SOURCES)
	$(CPP) -o ray $(OBJECTS)

.cc.o:
	$(CPP) $(CPPFLAGS) $< -o $@

depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CPP) $(CPPFLAGS) -MM $^ > ./.depend;

clean:
	rm -f *.o
	rm -f ray
	rm ./.depend

-include .depend
