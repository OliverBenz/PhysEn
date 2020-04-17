main: main.o Vector.o Object.o
	g++ main.o Vector.o Object.o -o main

main.o: main.cpp
	g++ -c main.cpp

Vector.o: lib/Vector.cpp
	g++ -c lib/Vector.cpp

Object.o: lib/Object.cpp
	g++ -c lib/Object.cpp

clean:
	rm -rf *.o main