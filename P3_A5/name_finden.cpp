#include "name_finden.h"

int name_finden(char namen[ANZAHL_NAMEN][LAENGE_NAMEN], char gesucht[LAENGE_NAMEN])
{
	for(int i = 0; i < ANZAHL_NAMEN; ++i)
	{
		if(strlen(namen[i]) > 0)
			if(strcmp(namen[i], gesucht) == 0)
				return i;
	}
	return -1;
}

int name_finden(std::string* namen, std::string gesucht)
{
	for(int i = 0; i < ANZAHL_NAMEN; ++ i)
		if(gesucht == namen[i])
			return i;
	return -1;
}