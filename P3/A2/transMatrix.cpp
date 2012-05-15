#include "main.h"

// Transponiert eine Matrix
void transMatrix(int dimension, double eingabeMatrix[MATRIX_SIZE][MATRIX_SIZE], double ausgabeMatrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for(int zeile = 0; zeile < dimension; ++ zeile)
	{
		for(int spalte = 0; spalte < dimension; ++ spalte)
		{
			ausgabeMatrix[zeile][spalte] = eingabeMatrix[spalte][zeile];
		}
	}
}
