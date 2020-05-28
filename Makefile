main: tests.cpp Size.o Math.a Objects.a
	g++ tests.cpp Size.o Math.a Objects.a -o main

Objects.a: Object.o CircleObject.o
	ar rvs Objects.a Object.o CircleObject.o

Math.a: Vector.o Matrix.o
	ar rvs Math.a Vector.o Matrix.o


Object.o: lib/Object.cpp
	g++ -c lib/Object.cpp

CircleObject.o: lib/CircleObject.cpp
	g++ -c lib/CircleObject.cpp

Vector.o: lib/Vector.cpp
	g++ -c lib/Vector.cpp

Size.o: lib/Size.cpp
	g++ -c lib/Size.cpp

Matrix.o: lib/Matrix.cpp
	g++ -c lib/Matrix.cpp

clean:
	rm -rf *.o *.a main
