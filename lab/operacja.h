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
	//! Zmienne czasowe podajace wartosci czasu w ms.
	clock_t start, koniec;
	//! Zmierzony czas dla wykonania danego powtorzenia
	long delta;
	//! Zmienna pomocna do liczenia sredniej czasu.
	int pomocsr;
	//! Zmienna przechowujaca wartosc sredniej dla danej operacji.
	int srednia;
	
	
	
public:

	//! Pole przechowujace informacje o ilosci danych w tablicy g³ównej.
	int IloscLiczb;
	//! Pole przechowujace informacje o ilosci danych w tablicy drugiej (stworzonej w zaleznosci od potrzeb w funkcji main).
	int IloscLiczb2;
	
	//! Funkcja mnozaca liczby tablicy przez liczbe.
	void PomnozLiczby(int liczba);

	/*! Funkcja wyswietlajaca wyrazy tablicy klasy Operacja.
	*/
	void WyswietlTablice();

	/*! Pole przechowujace glowna tablice klasy Operacja.
	*/
	int *TABLICA;
	/*! Konstruktor klasy Operacja tworzacy obiekt z danymi wczytanymi z pliku.
	*/
	Operacja( char nazwa[]);
	//! destuktor zwalniajacy pamiec podreczna TABLICA.
	~Operacja();

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
	//! Funkcja wyznaczajaca poczatek pomiaru czasu.
	void ZmierzCzasStart();
	//! Funkcja wyznaczajaca koniec pomiaru czasu.
	void ZmierzCzasKoniec();
	//! Funkcja pobierajaca ilosc powtorzen od uzytkownika.
	void PobierzIloscPowtorzen();
	//! Funkcja wyswietlajca i liczaca srednia dla danej operacji.
	void PodajSrednia();
	//! Pole przechowujace informiacji o ilosci powtorzen dla danej operacji.
	int Powtorzenia;
	//! Pole pomagajace w liczeniu ilosci powtorzen.
	int LicznikPowtorzen;
	//! Funkcja badajaca ilosc liczb w obiekcie.
	void ZbadajIloscLiczb( char napis[]);
	//! Funkcja zapisujaca liczby z wybranego pliku do wybranej tablicy.
	void ZapiszLiczbyDoTablicy( char napis[], int tab[]);
	

};





	

	/*! Funkcja pomocnicza wyswietlajaca wyrazy dowolnej tablicy w zaleznosci od ilosci jej elementow.
	*/
	void WyswietlTablice(int tab[], int Ilosc);

	 


#endif