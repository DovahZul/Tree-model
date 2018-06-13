CC=gcc
CFLAGS=-c -Wall 
LDFLAGS=
SOURCES=main.cpp node.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=task

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o  $@ -lstdc++

.cpp.o:
	$(CC) $(CFLAGS) $< -o  $@
clear:
	rm *.o
