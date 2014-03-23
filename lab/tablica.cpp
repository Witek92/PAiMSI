#include "tablica.h"
#include <iostream>
#include <fstream>
using namespace std;




	 /*!
	Argumenty i najwazniejsze pola funkcji
	- liczba - liczba, przez ktora jest mnozony kazdy wyraz tablicy
	- tab[] - tablica, na ktorej elementach bedzie wykonywane dzialanie
	- Ilosc - ilosc danych wczytanych z pliku
	
*/


	void tablica::PomnozLiczby(int liczba)
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
		void tablica::WyswietlTablice()
	{
	
		for (int i=0;i<IloscLiczb;i++)
		{
			cout<<TABLICA[i]<<endl;
		}

	}

		int tablica::partition(int p, int r)
		{
			int x = TABLICA[p]; 
			int i = p, j = r, w; 
			while (true) 
			{
				while (TABLICA[j] > x) 
				j--;
				while (TABLICA[i] < x) 
				i++;
				if (i < j) 
				{
					w = TABLICA[i];
					TABLICA[i] = TABLICA[j];
					TABLICA[j] = w;
					i++;
					j--;
				}
				else 
				return j;
			}
		}


	void tablica::quicksort(int p, int r) 
	{
		int q;
		if (p < r)
		{  
			q = partition(p,r); 
			quicksort(p,q); 
			quicksort(q+1,r); 
		}
	}

	void tablica::sortuj_babel()
	{
		int z;
		do
		{
			int schowek;
			z=0;
			for (int i=0; i<IloscLiczb-1; i++)
			{
				if (TABLICA[i]>TABLICA[i+1])
				{
					z=z+1; 

					schowek=TABLICA[i];
					TABLICA[i]=TABLICA[i+1];
					TABLICA[i+1]=schowek;
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

		void tablica::ZamienElementy(int i, int j)
		{
			int schowek1, schowek2;
			schowek1=TABLICA[i-1];
			schowek2=TABLICA[j-1];
			TABLICA[i-1]=schowek2;
			TABLICA[j-1]=schowek1;
		}

		void tablica::OdwrocKolejnosc()
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
			void tablica::DodajElement(int element)
			{
				IloscLiczb++;
				TABLICA[IloscLiczb]=element;	
			}

						 /*!


	Argumenty i najwazniejsze pola funkcji:
	
	- tab - tablica, ktora bedzie dodana do glownej tablicy
	- tabschow - tablica, do ktorej zostania zapisane dwie scalone tablice

	\return Adres pierwszego elementu Nowej tablicy z dodana druga tablica
	
*/
			

				int * tablica::operator + (tablica tab)
			{
					
					
				for (int i=0;i<IloscLiczb+tab.IloscLiczb;i++)
				{
					if (i>=IloscLiczb)
					{
						TABLICA[i]=tab.TABLICA[i];
					}
					
				}
				
				IloscLiczb=IloscLiczb+tab.IloscLiczb;
				
				
				return TABLICA;
					
			}
	
	
		/*!


	Argumenty i najwazniejsze pola konstruktora:
	
	- liczby - ilosc liczb, ile zawierac bedzie glowna tablica po utworzeniu
	
	
*/
			tablica::tablica(char nazwa[])
			{

				ifstream Wejscie;
				Wejscie.open(nazwa);
				
				Wejscie>>IloscLiczb;
				int *tablica=new int [IloscLiczb];
				TABLICA=tablica;
				for(int i=0;i<IloscLiczb;i++)
				{
					Wejscie>>TABLICA[i];
				}
		
				Wejscie.close();
				
			}


								 
 /*!
	Argumenty i najwazniejsze pola funkcji
	
	- tab - tablica wczytana jako pierwsza do porownania
	- prawda - pole logiczne, przechowujace informacje o spelnionym warunku
	

	\return prawda, jesli jest pelna zgodnosc; falsz, jesli wystapi blad w porownywaniu
	
*/

				bool tablica::operator == (int tab[])
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


		void tablica::operator = (tablica tabliczka)
					{
						if (tabliczka.IloscLiczb>IloscLiczb)
						{
							IloscLiczb=tabliczka.IloscLiczb;
						}

						for (int i=0; i<IloscLiczb;i++)
						{
							TABLICA[i]=tabliczka.TABLICA[i];
						}
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


	

	int tablica::ZwrocIloscLiczb()
	{
		return IloscLiczb;
	}

	
		void tablica::WypelnijStosTablica(Stos &stosek)
		{
			for (int i=0; i<IloscLiczb; i++)
			{
				stosek.push(TABLICA[i]);
			}

		}


void tablica::WypelnijKolejkeTablica(Kolejka &kolejeczka)
{
		for (int i=0; i<IloscLiczb; i++)
			{
				kolejeczka.enqueue(TABLICA[i]);
			}
}


void tablica::WypelnijStosLTablica(StosL &stosikL)
{
		for (int i=0; i<IloscLiczb; i++)
			{
				stosikL.push(TABLICA[i]);
			}
}
