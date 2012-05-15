#include "main.h"
#include "generateMatrix.h"
#include "printMatrix.h"
#include "transMatrix.h"

int main()
{
	/* Eingabe der Matrix */
	int dimension = 0;
	do {
		wcout << "Dimension der Matrix (1-" << MATRIX_SIZE << ")? ";
		wcin >> dimension;
	} while(dimension <= 0 || dimension > MATRIX_SIZE);

	/* Matrix anlegen, mit 0-Werten initialisieren */
	double matrix[MATRIX_SIZE][MATRIX_SIZE] = {{0}};

	/** Matrix belegen und ausgeben */
	generateMatrix(dimension, matrix);
	wcout << "Originale Matrix:" << endl;
	if(printMatrix(dimension, matrix, DBL_MAX) != 0)
		wcout << "Fehler im Grenzwert" << endl;

	/* Matrix transponieren und Ausgeben */
	double transponierteMatrix[MATRIX_SIZE][MATRIX_SIZE] = {{0}};
	transMatrix(dimension, matrix, transponierteMatrix);
	wcout << "Transponierte Matrix:" << endl;
	if(printMatrix(dimension, transponierteMatrix, DBL_MAX) != 0)
		wcout << "Fehler im Grenzwert" << endl;

	/* mit Grenzwert Matrix korrigieren */
	double grenzwert;
	wcout << "Grenzwert? ";
	wcin >> grenzwert;
	int geaendert = printMatrix(dimension, transponierteMatrix, grenzwert);
	wcout << "Geaenderte Elemente: " << geaendert << endl;

	/* Auf weitere Eingabe warten, d.h. nicht sofort beenden. */
	system("pause");
	return 0;
}
