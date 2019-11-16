CC=g++
CFLAGS=-c\
		-Wall\
		-Werror\
		-Wpedantic\
		-std=c++11
SOURCES=Main.cpp\
		Dialog.cpp\
		Polygon.cpp
TEST=check/Main.cpp
TESTOBJ=$(TEST:.cpp=.o)
TESTEXEC=check/test
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=polygon

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

check:
	$(CC) $(TEST) -o $(TESTOBJ)
	$(CC) $(TESTOBJ) -o $(TESTEXEC)
	./$(TESTEXEC)

clean:
	rm -rf *.o polygon