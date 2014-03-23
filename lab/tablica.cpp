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

			//////////////////////////////////QUICKSORT///////////////////////////////
/*! Funkcja ta jest niezbedna czescia funkcji quicksort. Wyznacza ona punkt podzia³u tablicy. 
W jednej czesci znajdowac sie beda liczby mniejsze od x (poczatkowego wyrazu TABLICA), a w 
drugiej wieksze lub rowne.

Najwazniejsze pola i argumenty funkcji:

- rozmiar: w tej funkcji oznacza on rozmiar tablicy, na ktorej bedzie wykonywane zamienianie wyrazow (w zaleznosci od punktu podzialu)
- poczatek: poczatek tablicy, w ktorej beda zamieniane elementy

\return j- czyli wartosc 'miejsca' podzialu tablicy po dokonanych operacjach zamiany elementow.




*/

int tablica::podziel(int poczatek, int rozmiar)
		{
			int x = TABLICA[poczatek]; 
			int i = poczatek, j = rozmiar, w; 
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

/*! Sortowanie typu quicksort wykonywane jest rekurencyjnie. Dopoki wartosc poczatku tablicy jest mniejsza niz poszczegolny rozmiar czesci tablicy, 
wykonuje sie 'funkcja w funkcji'. Najpierw pierwsza - od poczatku
do punktu podzialu. Pozniej sortowana jest druga czesc, ktora jako argumenty przyjmuje wartosc pierwszego elementu drugiej czesci tablicy oraz ponownie jej rozmiary.

Najwazniejsze pola i argumenty funkcji:

-punkt_podzialu: jw pole przechowujace wyliczane przez rekurencje punkty podzialu.
*/

	void tablica::quicksort(int poczatek, int rozmiar) 
	{
		int punkt_podzialu;
		if (poczatek < rozmiar)
		{  
			punkt_podzialu = podziel(poczatek,rozmiar); 
			quicksort(poczatek,punkt_podzialu); 
			quicksort(punkt_podzialu+1,rozmiar); 
		}
	}
	//////////////////////////////////////////////////////Sortowanie babelkowe/////////////////////////////////////////

	/* Prosta definicja sortowania babelkowego. Polega najpierw na sprawdzeniu, czy aby tablica nie jest juz posortowana. 
	Jesli nie, to kazdorazowo az do przekroczenia rozmiaru tablicy sprawdzane jest, czy wybrany element tablicy 
	jest wiekszy od kolejnego. Jesli tak, sa one zamieniane. Az
	*/
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

	//////////////////////////////////////////////////////Sortowanie przez scalanie///////////////////////////////////////////////
	/*! Funkcja merge pozwala na ponowne (po rozdrobnieniu tablicy na drobne 'paczki' elementow) scalenie ich w posortowanych kolejnosciach.

	Najwazniejsze pola i argumenty funkcji:

	-poczatek, srodek, rozmiar - jak nazwy wskazuja, sa to wskazniki na miejsca tablicy, w ktorych bedzie ona scalana.
	-tab - tablica pomocnicza o takiej samej wielkosci jak tablica::TABLICA, w ktorej przechowywane sa robocze wartosci sortowania/scalania.
	*/

	void tablica::merge(int poczatek, int srodek, int rozmiar)
{
    int h,i,j,k;
	int *tab=new int [IloscLiczb]; 
    h=poczatek;
    i=poczatek;
    j=srodek+1;
 
    while((h<=srodek)&&(j<=rozmiar))
    {
        if(TABLICA[h]<=TABLICA[j])
        {
            tab[i]=TABLICA[h];
            h++;
        }
        else
        {
            tab[i]=TABLICA[j];
            j++;
        }
        i++;
    }
    if(h>srodek)
    {
        for(k=j; k<=rozmiar; k++)
        {
            tab[i]=TABLICA[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=srodek; k++)
        {
            tab[i]=TABLICA[k];
            i++;
        }
    }
    for(k=poczatek; k<=rozmiar; k++) 
		TABLICA[k]=tab[k];
}
	
	/*! Mergesort rekurencyjnie sortuje elementy. Algorytm dziala nastepujaco: Tablica jest najpierw dzielona na pol. 
	Nastepnie na kolejne polowki, itd. W podzielonych malych paczkach elementy sa indywidualnie odwracane w posortowana kolejnosc (za pomoca merge() ).
	Na koncu paczki laczone sa w jedna calosc zapisana w TABLICA. Rekurencja dziala dwufazowo: 
	najpierw mergesort wykonywane jest na czesci od poczatku tablicy, do jej srodka; a ostatecznie na czesci od srodka do konca.

	Najwazniejsze pola i argumenty funkcji:

	-poczatek, rozmiar - poczatki i konce czesci tablic do scalenia.
	-srodek: srodek oznacza przy kazdym wywolaniu funkcji rozny srodek podzielonej na pol tablicy.
	
	*/
void tablica::mergesort(int poczatek, int rozmiar)
{
    int srodek;
    if(poczatek<rozmiar)
    {
        srodek=(poczatek+rozmiar)/2;
        mergesort(poczatek,srodek);
        mergesort(srodek+1,rozmiar);
        merge(poczatek,srodek,rozmiar);
    }
	
}

//////////////////////////////////////////Heapsort///////////////////////////////////////

/*!	Sortowanie przez kopcowanie wykonywane jest dzieki stworzeniu kopca binarnego. Pierwszym etapem wiec jest stworzenie takiego kopca. Mniejsze elementy od szczytowego elementu
sa spuszczane w dol kopca, a przy okazji zamieniane sa z wiekszymi, ktore to pna sie do gory. Gdy kopiec jest wypelniony zaczyna sie jego sortowanie. Najwiekszy z gory jest dodawany na koniec TABLICA. 
Na jego miejsce trafia element najmniejszy wsrod calkiem dolnych galezi. Nastepnie spada on wedlug tej samej zasady na dol, przy czym na szczyt trafiaja kolejne wieksze wartosci, ktore finalnie w TABLICA tworza posortowane wartosci.

Najwazniejsze argumenty i pola funkcji:

-rozmiar: bada rozmiar calego kopca, ewentualnie zmniejsza jego rozmiar, jesli element zostanie ze sczytu zdjety i dodany do TABLICA
- szczyt, galaz - indeksy szczytu, oraz galezi
- wskaznik - przechowuje indeks elementu, na ktorym jest wykonywana operacja np przenoszania na szczyt
- schowek - pole przechowujace wartosc w celu np spuszczenia ja na dol kopca

*/

void tablica::heapsort() 
{
    int schowek;
    int rozmiar = IloscLiczb, szczyt =IloscLiczb/2, wskaznik, galaz; 
    
    while (1) 
	{ 
        if (szczyt > 0) 
		{     
            schowek = TABLICA[--szczyt]; 
        } 
		else 
		{ 
            rozmiar--;               
            if (rozmiar == 0) 
			{
                return; 
            }
            schowek = TABLICA[rozmiar];         
            TABLICA[rozmiar] = TABLICA[0];    
        }   
        wskaznik = szczyt; 
        galaz = wskaznik * 2 + 1; 
        while (galaz < rozmiar) 
		{
            
            if (galaz + 1 < rozmiar  &&  TABLICA[galaz + 1] > TABLICA[galaz]) 
			{
                galaz++;
            }
            
            if (TABLICA[galaz] > schowek) 
			{
                TABLICA[wskaznik] = TABLICA[galaz]; 
                wskaznik = galaz; 
                galaz = wskaznik * 2 + 1; 
            } 
			else 
			{
                break; 
            }
        }
        TABLICA[wskaznik] = schowek; 
    }
}
