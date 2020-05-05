main: tests.o Vector.o Object.o CircleObject.o Size.o Matrix.o
	g++ tests.o Vector.o Object.o CircleObject.o Size.o Matrix.o -o main

tests.o: tests.cpp
	g++ -c tests.cpp

Vector.o: lib/Vector.cpp
	g++ -c lib/Vector.cpp

Object.o: lib/Object.cpp
	g++ -c lib/Object.cpp

CircleObject.o: lib/CircleObject.cpp
	g++ -c lib/CircleObject.cpp

Size.o: lib/Size.cpp
	g++ -c lib/Size.cpp

Matrix.o: lib/Matrix.cpp
	g++ -c lib/Matrix.cpp

clean:
	rm -rf *.o main