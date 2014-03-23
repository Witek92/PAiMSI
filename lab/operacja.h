#ifndef OPERACJA_H
#define OPERACJA_H


#include <iostream>
#include <fstream>
#include <ctime>

/*! \brief Deklaracja klasy Operacja.

*	Klasa Operacja posiada pola oraz funkcje potrzebne do wykonywania dzialan na tablicach typu int.
*/

class Operacja
{
	/*! Funkcja pomocnicza (dzielaca tablice na dwie czesci) do wykonania algorytmu quicksort.
	*/
	int partition (int p, int r);
	
public:

	//! Pole przechowujace informacje o ilosci danych w tablicy g³ównej.
	int IloscLiczb;
	//! Pole przechowujace informacje o ilosci danych w tablicy drugiej (stworzonej w zaleznosci od potrzeb w funkcji main).
	int IloscLiczb2;
	
	//! Funkcja wczytujaca dane z pliku i zapisujaca je do tablicy.
	void ZapiszLiczbyDoTablicy( char napis[]);
	//! Funkcja mnozaca liczby tablicy przez liczbe.
	void PomnozLiczby(int liczba);

	/*! Funkcja wyswietlajaca wyrazy tablicy klasy Operacja.
	*/
	void WyswietlTablice();

	/*! Pole przechowujace glowna tablice klasy Operacja.
	*/
	int *TABLICA;
	/*! Konstruktor klasy Operacja tworzacy obiekt z tablica o okreslonej liczbie elementow.
	*/
	Operacja( int liczby);

	/*! Funkcja wykonujaca algorytm quicksort.
	*/
	void quicksort(int p, int r);
	/*! Funkcja wykonujaca algorytm 'sortowania babelkowego'.
	*/
	void sortuj_babel();
	/*! Funkcja zamieniajaca miejscami wybrane elementy tablicy.
	*/
	void ZamienElementy(int i, int j);
	/*! Funkcja odwracajaca kolejnosc tablicy.
	*/
	void OdwrocKolejnosc();
	/*! Funkcja dodajaca wybrany element typu int do tablicy.
	*/
	int * DodajElement(int element);

		/*! Przeciazenie operatora porownywania tablicy z tablic¹.
	*/		
	bool operator == (int tab[]);
	/*! Przeciazenie operatora dodawania (sklejania) dwoch tablic.
	*/
	int * operator + (int tab[]);
	/*! Przeciazenie operatora przypisywania tablicy glownej innej tablicy.
	*/
	void operator = (int tab[]);

	

};



//! Funkcja badajaca ilosc liczb w obiekcie.
	int ZbadajIloscLiczb( char napis[]);

	//! Funkcja zapisujaca liczby z wybranego pliku do wybranej tablicy.
	void ZapiszLiczbyDoTablicy( char napis[], int tab[], int Ilosc);

	/*! Funkcja pomocnicza wyswietlajaca wyrazy dowolnej tablicy w zaleznosci od ilosci jej elementow.
	*/
	void WyswietlTablice(int tab[], int Ilosc);

	 


#endif