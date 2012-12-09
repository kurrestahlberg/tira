CC=g++
LDFLAGS=
CXXFLAGS=-Wall -c -g3 -O0 -I../UnitTest++/src
TEST_LDFLAGS=$(LDFLAGS) -L../UnitTest++/ -lUnitTest++

COMMON_SOURCES=treenode.cpp tree.cpp priorityqueue.cpp huffman.cpp

SOURCES=$(COMMON_SOURCES) main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=huffman

TEST_SOURCES=tests/testmain.cpp tests/testtreenode.cpp tests/testpriorityqueue.cpp \
			tests/testtree.cpp tests/testhuffman.cpp $(COMMON_SOURCES)
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)
TEST_EXECUTABLE=huffman_test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	
.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@
	
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLE)
	
test: $(TEST_SOURCES) $(TEST_EXECUTABLE)
	./huffman_test
	
$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) $(TEST_LDFLAGS) -o $@
	
