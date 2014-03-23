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
	
public:
	//! Pole przechowujace informacje o ilosci danych w obiekcie.
	int IloscLiczb;
	//! Funkcja badajaca ilosc liczb w obiekcie.
	int ZbadajIloscLiczb( char napis[]);
	//! Funkcja wczytujaca dane z pliku i zapisujaca je do tablicy.
	void ZapiszLiczbyDoTablicy( char napis[], int tab[]);
	//! Funkcja mnozaca liczby tablicy przez liczbe.
	void PomnozLiczby(int liczba, int tab[], int Ilosc);
	//! Funkcja sprawdzajaca, czy dwie tablice sa sobie rowne.
	bool PorownajZgodnoscTablic(int tab1[], int tab2[], int Ilosc);
};
/*! Funkcja pomocnicza wyswietlajaca wyrazy tablicy w zaleznosci od ilosci jej elementow.
*/
void WyswietlTablice(int tab[], int Ilosc);



#endif