#include "main.h"

// Gibt eine ver�nderte Matrix aus, f�r die gilt:
// Wenn m[zeile, spalte] > grenzwert, dann
//   m[zeile, spalte] -= (grenzwert-max(m))/2,
//   wobei max(m) das gr��te Matrixelement ist.
//
// Gibt die Anzahl der ge�nderten Elemente zur�ck.
int printMatrix(int dimension, double matrix[MATRIX_SIZE][MATRIX_SIZE], double grenzwert);
