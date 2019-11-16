CC=g++
CFLAGS=-c\
		-Wall\
		-Werror\
		-Wpedantic\
		-std=c++11
SOURCES=Main.cpp\
		Dialog.cpp\
		Polygon.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=polygon

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o polygon