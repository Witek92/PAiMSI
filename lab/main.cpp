/*! \mainpage Dokumentacja zadania PAMSI lab 6
 *
 * \author Witold Zimnicki
 * \date 5.4.2014
 * 
 */


#include <iostream>
#include "tablicaA.h"
#include <string>

using namespace std;

/*! \brief Glowna funkcja programu.
	W funkcji main przedstawione jest przykladowe wykorzystanie funkcji klasy TablicaA , w celu zademonstrowania sposobu ich dzialania na utworzonej tablicy asocjacyjnej.
	Skrocony przebieg przykladowego programu:
	-Tworzona jest tablica asocjacyjna tabliczka
	-Parami (litera alfabetu - liczba) dodawane sa pozycje do tablicy.
	- Przykladowo usunieta jest jedna pozycja
	- Wyswietlona jest tablica po powyzszych operacjach.
	- Przykladowo zwrocona jest wartosc wybranego klucza.
	- Zwrocona jest ilosc pozycji w tablicy asocjacyjnej.
*/

int main()
{
	TablicaA<int> tabliczka;
	string klucz;
	int wartosc;
	char k='a';
	for (int i=1 ;i<=26;i++,k++)
	{
		klucz=k;
		wartosc=i;
		tabliczka.dodaj(klucz,wartosc);
	}

	tabliczka.usun("e", 5);

	cout<<"Tak wyglada tablica asocjacyjna po operacjach: "<<endl<<tabliczka;

	klucz="j";
	wartosc=tabliczka.pobierz(klucz);

	cout<<endl<<"Tablica asocjacyjna zawiera: "<<tabliczka.IleElementow()<<" elementow!"<<endl;
	cout<<"Pobrana wartosc klucza: "<<klucz<<" to: "<<wartosc<<endl;

	system("PAUSE");
	return 0;
}
