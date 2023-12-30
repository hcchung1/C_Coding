CC = g++
CFLAGS = -g -Wall

all: program

program: main.o matrixFunc.o vectorFunc.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

matrixFunc.o: matrixFunc.cpp
	$(CC) $(CFLAGS) -c $< -o $@

vectorFunc.o: vectorFunc.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o program
