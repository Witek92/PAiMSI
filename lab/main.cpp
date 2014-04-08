/*! \mainpage POPRAWIONA Dokumentacja zadania PAMSI lab 1 
 *
 * \author Witold Zimnicki
 * \date 8.4.2014
 * 
 */

#include <iostream>
#include "operacja.h"
#include <fstream>
#include <ctime>



using namespace std;
/*! \brief Funkcja main wykonujaca algorytm i prowadzaca statystyki na jej temat.

W funkcji main wykonywane sa nastepujace operacje:

- Zostaje utworzona operacja (obiekt klasy Operacja)
- Zostaje wczytany plik z danymi wejsciowymi
- Dane sa mnozone razy 2 (wlaczany jest pomiar czasu)
- Mierzony jest czas wykonania algorytmu

Pola funkcji:
- *tablica 1, * tablica 2: dynamicznie alokowane tablice, w ktorych przechowywane sa dane wczytane z plikow

*/

int main()
{
	
	Operacja Mnozenie;
	
	Mnozenie.PobierzIloscPowtorzen();
	Mnozenie.ZbadajIloscLiczb("dane_wej.txt");
	
	int *tablica1=new int [Mnozenie.IloscLiczb];
	int *tablica2=new int [Mnozenie.IloscLiczb];

	Mnozenie.ZapiszLiczbyDoTablicy("dane_wej.txt", tablica1);
	Mnozenie.ZapiszLiczbyDoTablicy("dane_spr.txt", tablica2);
	
	for (Mnozenie.LicznikPowtorzen=0;Mnozenie.LicznikPowtorzen<Mnozenie.Powtorzenia;Mnozenie.LicznikPowtorzen++)
	{
		Mnozenie.ZmierzCzasStart();
		
		Mnozenie.PomnozLiczby(2,tablica1,Mnozenie.IloscLiczb);
		
		Mnozenie.ZmierzCzasKoniec();

	}

	Mnozenie.PodajSrednia();
	delete [] tablica1;
	delete [] tablica2;

	system("PAUSE");
	return 0;
}

