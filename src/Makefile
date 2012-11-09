CC=g++
LDFLAGS=
CXXFLAGS=-Wall -c -g3 -O0

SOURCES=main.cpp treenode.cpp tree.cpp priorityqueue.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=huffman

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@
	
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)