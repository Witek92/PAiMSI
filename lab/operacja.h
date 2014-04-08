#ifndef OPERACJA_H
#define OPERACJA_H


#include <iostream>
#include <fstream>
#include <ctime>

/*! \brief Deklaracja klasy Operacja.

*	Klasa Operacja wykonuje wszystkie potrzebne funkcje do analizowania wykonywania siê algorytmow.
*/

class Operacja
{
	//! Zmienne czasowe podajace wartosci czasu w ms.
	clock_t start, koniec;
	//! Zmierzony czas dla wykonania danego powtorzenia
	long delta;
	//! Zmienna pomocna do liczenia sredniej czasu.
	int pomocsr;
	//! Zmienna przechowujaca wartosc sredniej dla danej operacji.
	int srednia;
	
	
public:
	//! Pole przechowujace informacje o ilosci danych w obiekcie.
	int IloscLiczb;
	//! Funkcja badajaca ilosc liczb w obiekcie.
	void ZbadajIloscLiczb( char napis[]);
	//! Funkcja wczytujaca dane z pliku i zapisujaca je do tablicy.
	void ZapiszLiczbyDoTablicy( char napis[], int tab[]);
	//! Funkcja mnozaca liczby tablicy przez liczbe.
	void PomnozLiczby(int liczba, int tab[], int Ilosc);
	//! Funkcja sprawdzajaca, czy dwie tablice sa sobie rowne.
	bool PorownajZgodnoscTablic(int tab1[], int tab2[], int Ilosc);
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
};

/*! Funkcja pomocnicza wyswietlajaca wyrazy tablicy w zaleznosci od ilosci jej elementow.
*/
void WyswietlTablice(int tab[], int Ilosc);



#endif