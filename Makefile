main: tests.o Vector.o Object.o CircleObject.o
	g++ tests.o Vector.o Object.o CircleObject.o -o main

tests.o: tests.cpp
	g++ -c tests.cpp

Vector.o: lib/Vector.cpp
	g++ -c lib/Vector.cpp

Object.o: lib/Object.cpp
	g++ -c lib/Object.cpp

CircleObject.o: lib/CircleObject.cpp
	g++ -c lib/CircleObject.cpp

clean:
	rm -rf *.o main