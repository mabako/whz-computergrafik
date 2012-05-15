#include "main.h"

// Generiert eine Matrix nach Aufgabenstellung,
// Elemente der Hauptdiagonale = -a, -a+100, -a+200, ..., a-200, a-100, a
// Oberes Dreieck = (Zeilenindex + Spaltenindex) * a/10
// Unteres Dreieck = (Zeilenindex - Spaltenindex) * a/10
void generateMatrix(int dimension, double matrix[MATRIX_SIZE][MATRIX_SIZE]);
