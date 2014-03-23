#include <iostream>
#include "operacja.h"
#include <fstream>
#include <ctime>

using namespace std;
/*!
*	Argument funkcji:
	- napis[] - tablica znakow bedaca nazwa wczytywanego pliku
	Pola funkcji:
	- Wej -bufor, do ktorego wczytany zostaje plik
	\return IloscLiczb - Ilosc liczb, ktora zawiera plik z danymi	
*/
 int Operacja::ZbadajIloscLiczb(char napis[])
{
	ifstream Wej;
	Wej.open(napis);
	Wej>>IloscLiczb;
	Wej.close();
	return IloscLiczb;
}
 /*!
*	Argumenty funkcji:
	- napis[] - tablica znakow bedaca nazwa wczytywanego pliku
	- tab[] - tablica, do ktorej sa wczytywane dane z pliku
	Pola funkcji:
	- Wej -bufor, do ktorego wczytany zostaje plik
*/

	void Operacja::ZapiszLiczbyDoTablicy (char napis[], int tab[])
	{
		int i;
		ifstream Wej;
		Wej.open(napis);
		Wej.ignore(3);
		for(i=0;i<IloscLiczb;i++)
		{
			Wej>>tab[i];
		}
		Wej.close();

	}
	 /*!
	Argumenty funkcji:
	- liczba - liczba, przez ktora jest mnozony kazdy wyraz tablicy
	- tab[] - tablica, na ktorej elementach bedzie wykonywane dzialanie
	- Ilosc - ilosc danych wczytanych z pliku
	
*/


	void Operacja::PomnozLiczby(int liczba, int tab[], int Ilosc)
	{
		for (int i=0;i<Ilosc;i++)
		{
			tab[i]=tab[i]*liczba;
		}

	}
		 /*!
	Argumenty funkcji:
	
	- tab1[] - tablica wczytana jako pierwsza do porownania
	- tab2[] - tablica wczytana jako druga do porownania
	- Ilosc - ilosc danych wczytanych z pliku

	\return prawda, jesli jest pelna zgodnosc; blad, jesli wystapi blad w porownywaniu
	
*/


	bool Operacja::PorownajZgodnoscTablic(int tab1[], int tab2[], int Ilosc)
	{
		for (int i=0;i<Ilosc;i++)
		{
			if (tab1[i]==tab2[i])
			{
				return true;
			}
			else
			{
				return false;
			}
	
		}
	}

	 /*!
	Argumenty funkcji:
	
	- tab[] - tablica, ktora jest wyswietlana
	- Ilosc - ilosc danych do wyswietlenia
	
*/
		void WyswietlTablice(int tab[], int Ilosc)
	{
		for (int i=0;i<Ilosc;i++)
		{
			cout<<tab[i]<<endl;
		}

	}