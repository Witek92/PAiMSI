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
 void Operacja::ZbadajIloscLiczb(char napis[])
{
	ifstream Wej;
	Wej.open(napis);
	Wej>>IloscLiczb;
	Wej.close();
	
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
			
				return false;
			
	
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



	void Operacja::ZmierzCzasStart()
	{
		
		start = clock();
	}
	void Operacja::ZmierzCzasKoniec()
	{
		int temp;
		if (LicznikPowtorzen==0)
		temp=0;
		temp=delta;
		koniec = clock(); // bie¿¹cy czas systemowy w ms
		delta=(long)(koniec - start);
		pomocsr=temp+delta;
		cout<<endl<<"Czas pomiaru dla algorytmu z "<<IloscLiczb<<" danymi nr: "<< LicznikPowtorzen+1<<" wynosi: "<<delta<<endl;
	}

	void Operacja::PobierzIloscPowtorzen()
	{
		cout<<endl<<"Podaj ilosc powtorzen algorytmu: ";
		cin>>Powtorzenia;
	}

	void Operacja::PodajSrednia()
	{
		srednia=pomocsr/Powtorzenia;
		cout<<endl<<"Srednia z "<<IloscLiczb<<" danymi dla: "<< Powtorzenia<<" powtorzen wynosi: "<<srednia<<endl<<endl;
	}
