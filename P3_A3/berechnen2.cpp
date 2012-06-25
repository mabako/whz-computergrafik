#include "berechnen2.h"

minmax* berechnen2(int groesse, int* feld)
{
	if(groesse == 0)
		return 0;

	minmax* m = new minmax();
	m->max = feld[0];
	m->min = feld[0];
	
	for(int i = 1; i < groesse; ++ i)
	{
		int wert = feld[i];
		if(wert > m->max)
			m->max = wert;
		if(wert < m->min)
			m->min = wert;
	}

	return m;
}
