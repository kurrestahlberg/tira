CC=g++
LDFLAGS=
CXXFLAGS=-Wall -c -g3 -O0 -I../UnitTest++/src
TEST_LDFLAGS=$(LDFLAGS) -L../UnitTest++/ -lUnitTest++

SOURCES=treenode.cpp tree.cpp priorityqueue.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=huffman

TEST_SOURCES=tests/testmain.cpp tests/testtreenode.cpp tests/testpriorityqueue.cpp \
			tests/testtree.cpp
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)
TEST_EXECUTABLE=huffman_test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.o
	$(CC) $(LDFLAGS) $(OBJECTS) main.o -o $@
	
.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@
	
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLE)
	
test: $(SOURCES) $(TEST_SOURCES) $(TEST_EXECUTABLE)
	./huffman_test
	
$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(TEST_LDFLAGS) $(OBJECTS) $(TEST_OBJECTS) -o $@
	
