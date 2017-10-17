CC=gcc
CFLAGS= -Wall -Werror
SOURCES=expr.c
OBJECTS=$(SOURCES: .c=.o)
EXECUTABLE=expr

all: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

expr.o: expr.c
	$(CC) $(CFLAGS) expr.c

clean:
	rm  $(EXECUTABLE)