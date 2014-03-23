#include <iostream>
#include "operacja.h"
#include <fstream>
#include <ctime>

using namespace std;


/*!
*	Argumenty i najwazniejsze pola funkcji
	- napis[] - tablica znakow bedaca nazwa wczytywanego pliku
	Pola funkcji:
	- Wej -bufor, do ktorego wczytany zostaje plik
	\return IloscLiczb - Ilosc liczb, ktora zawiera plik z danymi	
*/
 int ZbadajIloscLiczb(char napis[])
{
	int Ilosc;
	ifstream Wej;
	Wej.open(napis);
	Wej>>Ilosc;
	Wej.close();
	return Ilosc;
}


 /*!
*	Argumenty i najwazniejsze pola funkcji
	- napis[] - tablica znakow bedaca nazwa wczytywanego pliku
	Pola funkcji:
	- Wej -bufor, do ktorego wczytany zostaje plik
*/

	void Operacja::ZapiszLiczbyDoTablicy (char napis[])
	{
		int i;
		ifstream Wej;
		Wej.open(napis);
		Wej.ignore(3);
		for(i=0;i<IloscLiczb;i++)
		{
			Wej>>TABLICA[i];
		}
		Wej>>i;
		Wej.close();

	}
	 /*!
	Argumenty i najwazniejsze pola funkcji
	- liczba - liczba, przez ktora jest mnozony kazdy wyraz tablicy
	- tab[] - tablica, na ktorej elementach bedzie wykonywane dzialanie
	- Ilosc - ilosc danych wczytanych z pliku
	
*/


	void Operacja::PomnozLiczby(int liczba)
	{
		for (int i=0;i<IloscLiczb;i++)
		{
			TABLICA[i]=TABLICA[i]*liczba;
		}

	}
		
	 /*!
	Funkcja wyswietla wszystkie elementy tablicy glownej w zaleznosci od przechowywanej w polu
	IloscLiczb informacji o liczbie jej elementow.
	
*/
		void Operacja::WyswietlTablice()
	{
		
		for (int i=0;i<IloscLiczb;i++)
		{
			cout<<TABLICA[i]<<endl;
		}

	}

		int Operacja::partition(int p, int r)
		{
			int x = TABLICA[p]; 
			int i = p, j = r, w; // i, j - indeksy w tabeli
			while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
			{
				while (TABLICA[j] > x) // dopoki elementy sa wieksze od x
				j--;
				while (TABLICA[i] < x) // dopoki elementy sa mniejsze od x
				i++;
				if (i < j) // zamieniamy miejscami gdy i < j
				{
					w = TABLICA[i];
					TABLICA[i] = TABLICA[j];
					TABLICA[j] = w;
					i++;
					j--;
				}
				else // gdy i >= j zwracamy j jako punkt podzialu tablicy
				return j;
			}
		}


	void Operacja::quicksort(int p, int r) // sortowanie szybkie
	{
		int q;
		if (p < r)
		{  
			q = partition(p,r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
			quicksort(p,q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
			quicksort(q+1,r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
		}
	}

	void Operacja::sortuj_babel()
	{
		int z;
		do
		{
			int schowek;//przed ka¿dym "przejazdem" pêtli for zmienna zamiana jest zerowana
			z=0;
			for (int i=0; i<IloscLiczb-1; i++)
			{
				if (TABLICA[i]>TABLICA[i+1])// jeœli element tablicy jest wiêkszy od nastêpnego elementu
				{
					z=z+1; //jeœli jest jakaœ zmiana, to zmienne z powiêksza swoj¹ wartoœæ

					schowek=TABLICA[i];//wartoœæ t[i] jest kopiowana do schowka
					TABLICA[i]=TABLICA[i+1];//t[i] przyjmuje wartoœæ nastêpnego elementu, gdy¿ jest on mniejszy
					TABLICA[i+1]=schowek;//kolejny element tablicy przejmuje wczeœniejsz¹ wartoœæ poprzedniego elementu, gdy¿ jest on wiêkszy
				}
			}
		}
		while(z!=0);//jeœli zmienna zamiana mia³aby wartoœæ 0, oznacza³oby to ¿e nie dokonano ¿adnych zmian, a wiêc nie ma potrzeby dalszego sortowania
	}

			 /*!
	Argumenty i najwazniejsze pola funkcji:
	
	- i - wybrany element pierwszej tablicy
	- j - wybrany element drugiej tablicy
	
	
*/

		void Operacja::ZamienElementy(int i, int j)
		{
			int schowek1, schowek2;
			schowek1=TABLICA[i-1];
			schowek2=TABLICA[j-1];
			TABLICA[i-1]=schowek2;
			TABLICA[j-1]=schowek1;
		}

		void Operacja::OdwrocKolejnosc()
		{
			int schowek;
			for (int i=0, j=IloscLiczb-1;i<IloscLiczb/2;i++,j--)
			{
				schowek=TABLICA[i];
				TABLICA[i]=TABLICA[j];
				TABLICA[j]=schowek;
			}

		}

				 /*!
	Argumenty i najwazniejsze pola funkcji:
	
	- element - wybrany element typu int, ktory chcemy dodac do tablicy
	- tabschow - tablica, do ktorej zostanie zapisana nowa tablica z nowym elementem

	\return Nowa tablica z dodanym elementem
	
*/
			int * Operacja::DodajElement(int element)
			{
				
				int *tabschow=new int [IloscLiczb+1];
				for (int i=0;i<IloscLiczb;i++)
				{
					tabschow[i]=TABLICA[i];
				}

				tabschow[IloscLiczb]=element;
				IloscLiczb++;
				return tabschow;
				delete [] tabschow;

			}

						 /*!


	Argumenty i najwazniejsze pola funkcji:
	
	- tab - tablica, ktora bedzie dodana do glownej tablicy
	- tabschow - tablica, do ktorej zostania zapisane dwie scalone tablice

	\return Adres pierwszego elementu Nowej tablicy z dodana druga tablica
	
*/
			

				int * Operacja::operator + (int tab[])
			{
					int *tabschow=new int [IloscLiczb+IloscLiczb2];
				for (int i=0,j=0;i<IloscLiczb+IloscLiczb2;i++)
				{
					if (i<IloscLiczb)
					tabschow[i]=TABLICA[i];
					else
					{
					tabschow[i]=tab[j];
					j++;
					}
				}

				
				IloscLiczb=IloscLiczb+IloscLiczb2;
				return tabschow;
				delete [] tabschow;
					
			}
	
	
									 /*!


	Argumenty i najwazniejsze pola konstruktora:
	
	- liczby - ilosc liczb, ile zawierac bedzie glowna tablica po utworzeniu
	
	
*/
			Operacja::Operacja( int liczby)
			{
				IloscLiczb=liczby;
				int *tablica=new int [IloscLiczb];
				TABLICA=tablica;
			}

								 /*!


	Argumenty i najwazniejsze pola funkcji:

	- napis - tablica znakow z nazwa wybranego pliku 
	- tab - tablica, do ktorej dane z wczytanego pliku beda wpisane
	- Ilosc - Ilosc elementow wczytanych z pliku

	
*/

				void ZapiszLiczbyDoTablicy( char napis[], int tab[], int Ilosc)
				{
					int i;
					ifstream Wej;
					Wej.open(napis);
					Wej.ignore(3);
					for(i=0;i<Ilosc;i++)
					{
						Wej>>tab[i];
					}
					Wej>>i;
					Wej.close();
				}
	
 /*!
	Argumenty i najwazniejsze pola funkcji
	
	- tab - tablica wczytana jako pierwsza do porownania
	- prawda - pole logiczne, przechowujace informacje o spelnionym warunku
	

	\return prawda, jesli jest pelna zgodnosc; falsz, jesli wystapi blad w porownywaniu
	
*/

				bool Operacja::operator == (int tab[])
				{
					int prawda=0;
					for (int i=0;i<IloscLiczb;i++)
					{
						if (TABLICA[i]==tab[i])
						{
							prawda=1;
						}
						else
						{
							prawda=0;
							
							return false;
						}

					}
					if (prawda==1)
					{
						
						return true;
					}
					return false;
				}

			/*!
			Przeciazenie to powoduje nadpisanie glownej tablicy wybrana tablica, zarazem zrownujac liczby elementow obu tablic.
	Argumenty i najwazniejsze pola funkcji:
	
	- tab - tablica, ktora nadpisze tablice glowna
	
*/


		void Operacja::operator = (int tab[])
					{
						
						for (int i=0; i<IloscLiczb2;i++)
						{
							TABLICA[i]=tab[i];
						}
						IloscLiczb=IloscLiczb2;
					}
			

 /*!
 Funkcja wyswietlajaca nie tylko tablice z klasy Operacja, lecz kazda inna o zadanej ilosci elementow
	Argumenty i najwazniejsze pola funkcji
	
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



	
	

