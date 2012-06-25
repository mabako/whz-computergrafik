#include <fstream>
#include <iostream>
#include <string>

#include "main.h"
#include "einlesen.h"
#include "name_eingeben.h"
#include "name_finden.h"

int main()
{
	{
		char namen[ANZAHL_NAMEN][LAENGE_NAMEN] = {0};
		einlesen(namen);

		char gesucht[LAENGE_NAMEN];
		name_eingeben(gesucht);

		int position = name_finden(namen, gesucht);
		if(position < 0)
			std::cout << "Name nicht gefunden" << std::endl;
		else
			std::cout << "Name steht an Position " << position << std::endl;
	}
	
	std::cout << "---------------------------" << std::endl;

	{
		std::string* namen = einlesen();
		std::string gesucht = name_eingeben();
		int position = name_finden(namen, gesucht);
		if(position < 0)
			std::cout << "Name nicht gefunden" << std::endl;
		else
			std::cout << "Name steht an Position " << position << std::endl;
	}

	system("pause");
}
