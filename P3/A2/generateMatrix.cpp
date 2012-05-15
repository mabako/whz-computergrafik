#include "main.h"

// Generiert eine Matrix nach Aufgabenstellung,
// Elemente der Hauptdiagonale = -a, -a+100, -a+200, ..., a-200, a-100, a
// Oberes Dreieck = (Zeilenindex + Spaltenindex) * a/10
// Unteres Dreieck = (Zeilenindex - Spaltenindex) * a/10
void generateMatrix(int dimension, double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	int a = (dimension-1) * 50;
	for(int zeile = 0; zeile < dimension; ++ zeile)
	{
		for(int spalte = 0; spalte < dimension; ++ spalte)
		{
			if(zeile < spalte)
				// Oberes Dreieck
				matrix[zeile][spalte] = (zeile+spalte) * a/10;
			else if(zeile == spalte)
				// Hauptdiagonale
				matrix[zeile][spalte] = -a+(zeile*100);
			else
				// Unteres Dreieck
				matrix[zeile][spalte] = (zeile - spalte) * a/10;
		}
	}
}
