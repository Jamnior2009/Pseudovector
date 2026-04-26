all: main

main: main.o vector.o
	g++ main.o vector.o -o main

main.o:
	g++ -c main.cpp -o main.o

vector.o:
	g++ -c vector.cpp -o vector.o

clean:
	rm -f main *.o

run:
	./main

.PHONY: all clean run