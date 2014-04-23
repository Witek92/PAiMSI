#ifndef TABLICA_H
#define TABLICA_H


#include <iostream>
#include "Stos.h"
#include "Kolejka.h"
#include "StosL.h"

using namespace std;

/*! \brief Deklaracja klasy tablica.

*	Klasa tablica posiada pola oraz funkcje potrzebne do wykonywania dzialan na tablicach typu int.
*/

class tablica
{
	/*! Funkcja pomocnicza (dzielaca tablice na dwie czesci) do wykonania algorytmu quicksort.
	*/
	int podziel_pes (int poczatek, int rozmiar);
	int podziel_opt(int poczatek, int rozmiar);

	void merge( int low, int pivot, int high);
	//! Pole przechowujace informacje o ilosci danych w tablicy g³ównej.
	int IloscLiczb;
	
	char nazwa_pliku;
	

	
	
public:

	/*! Pole przechowujace glowna tablice klasy Operacja.
	*/
	int *TABLICA;
	//! Funkcja zwracajaca ilosc liczb tablicy.
	int ZwrocIloscLiczb();
	
	//! Funkcja mnozaca liczby tablicy przez liczbe.
	void PomnozLiczby(int liczba);

	/*! Funkcja wyswietlajaca wyrazy tablicy klasy Operacja.
	*/
	void WyswietlTablice();
	
	/*! Konstruktor klasy Operacja tworzacy obiekt z tablica o okreslonej liczbie elementow.
	*/
	tablica(char nazwa[]);
	tablica()
	{

	}

	/*! Funkcja wykonujaca algorytm quicksort.
	*/
	void quicksort_pes(int poczatek, int rozmiar);
	void quicksort_przecietny(int poczatek, int rozmiar);
	void quicksort_opt(int poczatek, int rozmiar);
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
	void DodajElement(int element);

		/*! Przeciazenie operatora porownywania tablicy z tablic¹.
	*/		
	bool operator == (int tab[]);
	/*! Przeciazenie operatora dodawania (sklejania) dwoch tablic.
	*/
	int * operator + (tablica tab);
	/*! Przeciazenie operatora przypisywania tablicy glownej innej tablicy.
	*/
	void operator = (tablica &tabliczka);
	//! Funkcja, ktora po wczytaniu tablicy, kopiuje jej zawartosc do obiektu klasy Stos.
	void WypelnijStosTablica(Stos &stosek);
	//! Funkcja, ktora po wczytaniu tablicy, kopiuje jej zawartosc do obiektu klasy Kolejka.
	void WypelnijKolejkeTablica(Kolejka &kolejeczka);
	//! Funkcja, ktora po wczytaniu tablicy, kopiuje jej zawartosc do obiektu klasy StosL.
	void WypelnijStosLTablica(StosL &stosikL);

	
	void mergesort( int low, int high);
	void heapsort();
};


	/*! Funkcja pomocnicza wyswietlajaca wyrazy dowolnej tablicy w zaleznosci od ilosci jej elementow.
	*/
	void WyswietlTablice(int tab[], int Ilosc);

	 


#endif