.PHONY: all clean format

CXX=g++
CXXFLAGS=-O2 -Wall -DNDEBUG -std=c++17
LDFLAGS= -lboost_program_options
PROJECT = Shifr
SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJECTS := $(SOURCES:%.cpp=%.o)

all : $(PROJECT)

$(PROJECT) : $(OBJECTS)
	$(CXX) $^ $(LDFLAGS) -o $@
	rm -f *.o *.orig

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJECTS) : $(HEADERS)

format:
	astyle *.cpp *.h
doxy:
	doxygen
clean:
	rm -f $(PROJECT) *.o *.orig

