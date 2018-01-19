
output: main.o determinant.o readMatrix.o
	g++ main.o determinant.o readMatrix.o -o output

main.o: main.cpp
	g++ -c main.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp determinant.hpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c readMatrix.cpp readMatrix.hpp

clean:
	rm *.o output