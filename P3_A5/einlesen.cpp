#include <iostream>
#include "einlesen.h"

void einlesen(char namen[ANZAHL_NAMEN][LAENGE_NAMEN])
{
	std::ifstream f(FILENAME, std::ios_base::in);
	if(!f.is_open())
	{
		std::cout << "Datei konnte nicht gelesen werden" << std::endl;
		return;
	}

	for(int i = 0; i < ANZAHL_NAMEN; ++ i)
	{
		if(!f.getline(namen[i], LAENGE_NAMEN))
			break;
		std::cout << namen[i] << std::endl;
	}

	f.close();
	std::cout << std::endl;
	return;
}

std::string* einlesen()
{
	std::ifstream f(FILENAME, std::ios_base::in);
	if(!f.is_open())
	{
		std::cout << "Datei konnte nicht gelesen werden" << std::endl;
		return 0;
	}

	std::string* namen = new std::string[ANZAHL_NAMEN];

	for(int i = 0; i < ANZAHL_NAMEN; ++ i)
	{
		std::string line;
		if(!std::getline(f, line))
			break;
		namen[i] = line;
		std::cout << line << std::endl;
	}
	return namen;
}
