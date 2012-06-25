#include <stdio.h>
#include <iostream>

#include "berechnen1.h"
#include "berechnen2.h"

int main()
{
	// Feld deklarieren
	int feld[] = {1, 2, 3, 5, 0, 9, -3};
	int groesse = sizeof(feld)/sizeof(feld[0]);


	{
		// Variablen, um das Ergebnis zu speichern
		int max = 0, min = 0;

		// Mittels erster Methode berechnen
		std::cout << "Berechnung mittels Parametern:" << std::endl;
		berechnen1(groesse, feld, max, min);
		std::cout << "  min: " << min << std::endl;
		std::cout << "  max: " << max << std::endl;
	}

	{
		// Mittels struct berechnen
		std::cout << "Berechnung mittels struct:" << std::endl;
		minmax* m = berechnen2(groesse, feld);
		std::cout << "  min: " << m->min << std::endl;
		std::cout << "  max: " << m->max << std::endl;
	}

	system("pause");
	return 0;
}
