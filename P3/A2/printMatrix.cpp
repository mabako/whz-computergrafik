#include "main.h"

// Gibt eine Matrix aus
void printMatrix(int dimension, double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for(int zeile = 0; zeile < dimension; ++ zeile)
	{
		for(int spalte = 0; spalte < dimension; ++ spalte)
		{
			wcout << matrix[zeile][spalte] << "\t";
	}
		wcout << endl;
	}
	wcout << endl;
}

// Liefert das größte Element der Matrix zurück.
double max(int dimension, double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	double wert = matrix[0][0];
	for(int zeile = 0; zeile < dimension; ++ zeile)
	{
		for(int spalte = 0; spalte < dimension; ++ spalte)
		{
			wert = max(wert, matrix[zeile][spalte]);
		}
	}
	return wert;
}

// Gibt eine veränderte Matrix aus, für die gilt:
// Wenn m[zeile, spalte] > grenzwert, dann
//   m[zeile, spalte] -= (grenzwert-max(m))/2,
//   wobei max(m) das größte Matrixelement ist.
//
// Gibt die Anzahl der geänderten Elemente zurück.
int printMatrix(int dimension, double matrix[MATRIX_SIZE][MATRIX_SIZE], double grenzwert)
{
	double differenz = max(grenzwert, ::max(dimension, matrix)) - grenzwert;
	int geaendert = 0;

	for(int zeile = 0; zeile < dimension; ++ zeile)
	{
		for(int spalte = 0; spalte < dimension; ++ spalte)
		{
			double wert = matrix[zeile][spalte];
			if(wert > grenzwert)
			{
				wert -= differenz / 2;
				++ geaendert;
			}
			wcout << wert << "\t";
		}
		wcout << endl;
	}
	wcout << endl;
	return geaendert;
}
