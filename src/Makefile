CC=g++
LDFLAGS=
CXXFLAGS=-Wall -c

SOURCES=main.cpp treenode.cpp tree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=huffman

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@
	
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)