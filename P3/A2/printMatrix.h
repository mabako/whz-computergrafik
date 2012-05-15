#include "main.h"

// Gibt eine veränderte Matrix aus, für die gilt:
// Wenn m[zeile, spalte] > grenzwert, dann
//   m[zeile, spalte] -= (grenzwert-max(m))/2,
//   wobei max(m) das größte Matrixelement ist.
//
// Gibt die Anzahl der geänderten Elemente zurück.
int printMatrix(int dimension, double matrix[MATRIX_SIZE][MATRIX_SIZE], double grenzwert);
