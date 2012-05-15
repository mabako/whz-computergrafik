#include "main.h"

int main(int argc, char* argv[])
{
	/* 1. Parameter ist der Name des Programms selber */
	if(argc > 1)
	{
		wcout << "Es wurden " << argc-1 << " Summanden angegeben" << endl;

		/* Summe bilden */
		double summe = 0;
		for(int summand = 1; summand < argc; ++ summand)
		{
			double wert = atof(argv[summand]);
			wcout << setw(3) << summand << ". Summand: " << setw(10) << wert << endl;
			
			summe += wert;
		}
		wcout << "----------------------------" << endl;
		wcout << "  Summe: " << setw(15) << summe << endl;

	}
	else
		wcout << "Keine Parameter angegeben." << endl;
	/* Auf weitere Eingabe warten, d.h. nicht sofort beenden. */
	system("pause");
	return 0;
}