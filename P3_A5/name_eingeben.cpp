#include <iostream>
#include "name_eingeben.h"

void name_eingeben(char* gesucht)
{
	std::cout << "Welcher Name soll gesucht werden?" << std::endl;
	std::cin >> gesucht;
}

std::string name_eingeben()
{
	std::cout << "Welcher Name soll gesucht werden?" << std::endl;
	std::string name;
	std::cin >> name;
	return name;
}
