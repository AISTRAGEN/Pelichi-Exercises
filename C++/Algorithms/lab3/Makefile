CPP=g++

CPPFLAGS=-Wall -Wextra


SOURCES=$(wildcard src/*.cpp)

PROGRAMS=$(patsubst src/%.cpp,%,$(SOURCES))


all: $(PROGRAMS)


$(PROGRAMS): %: src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


clean:
	rm -f $(PROGRAMS)
