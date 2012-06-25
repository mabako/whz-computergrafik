#include "berechnen1.h"

// Über Parameter zurückgeben
void berechnen1(int groesse, int* feld, int& max, int& min)
{
	if(groesse == 0)
		return;

	max = feld[0];
	min = feld[0];

	for(int i = 1; i < groesse; ++ i)
	{
		int wert = feld[i];
		if(wert > max)
			max = wert;
		if(wert < min)
			min = wert;
	}
}