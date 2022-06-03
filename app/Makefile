CXX = g++
CXXFLAGS = -g3 -Wall -std=c++11
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

Response.o: directorios Response.cpp
	$(CXX) $(CXXFLAGS) -c Response.cpp -o build/Response.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o Response.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/Response.o  $(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all