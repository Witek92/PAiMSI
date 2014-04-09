/*! \mainpage POPRAWA Dokumentacji zadania PAMSI lab 2
 *
 * \author Witold Zimnicki
 * \date 9.4.2014
 * 
 */

#include <iostream>
#include "operacja.h"
#include <fstream>
#include <ctime>



using namespace std;
/*! \brief Funkcja main wykonujaca zadane operacje na tablicy i liczaca sredni czas dzialania algorytmow.

W funkcji main wykonywane sa nastepujace operacje:

- Zostaje utworzona operacja (obiekt klasy Operacja) 
- Zostaje wczytany plik z danymi wejsciowymi, wczytujac je do tablicy "glownej" TABLICA[]
- Opcjonalnie wczytywana jest druga tablica pomocnicza (do wykonywania operacji np przypisania) i sprawdzony jest jej rozmiar (zapisany w j)


- Zostaje zatrzymany pomiar czasu oraz liczony jest dla kazdego wykonania algorytmu; liczona jest rowniez srednia czasu.

Pola funkcji:
-  *tablica 2: dynamicznie alokowana tablica pomocnicza, w ktorych przechowywane sa dane wczytane z plikow
*/

int main()
{
	Operacja Dzialanie("dane_wej.txt");
	Dzialanie.PobierzIloscPowtorzen();

	int *tablica2=new int [Dzialanie.IloscLiczb];
	
	Dzialanie.ZapiszLiczbyDoTablicy("dane_spr.txt", tablica2);

for (Dzialanie.LicznikPowtorzen=0;Dzialanie.LicznikPowtorzen<Dzialanie.Powtorzenia;Dzialanie.LicznikPowtorzen++)
{
	Dzialanie.ZmierzCzasStart();

	Dzialanie.OdwrocKolejnosc();
	Dzialanie.TABLICA=Dzialanie.DodajElement(9);
	Dzialanie=tablica2;
	Dzialanie.TABLICA=Dzialanie.DodajElement(6);
	Dzialanie.TABLICA=Dzialanie+tablica2;
	
	Dzialanie.ZmierzCzasKoniec();
}

Dzialanie.PodajSrednia();

delete [] tablica2;


	system("PAUSE");
	return 0;
}

