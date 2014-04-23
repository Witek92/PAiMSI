#ifndef OPERACJA_H
#define OPERACJA_H


#include <iostream>
#include <fstream>
#include <ctime>
#include "tablica.h"
#include "Stos.h"
#include "StosL.h"
#include "Kolejka.h"

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
	//! Pole przechowuje wybor operacji przez uzytkownika.
	char wyborco;
	//! Pole przechowuje rozmiar problemu.
	int rozmiar;
	//! liczby pomocnicze przy operacjach na tablicy.
	int liczba1, liczba2, liczba3,element,jakstos;

		//! Stos na ktorym wykonywana jest operacja
		Stos stosik;
		//! Stos jako lista, na ktorym wykonywana jest operacja.
		StosL stosikL;
		//! Kolejka, na ktorej wykonywana jest operacja
		Kolejka Kolejeczka;
	
	
public:
	//! Tablica, na ktorej wykonywane sa operacje.
	tablica tabliczka2;
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
	//! Funkcja pozwalajaca na wybor algorytmu, rozmiaru problemu i ilosc powtorzen.
	void WyborOperacji();
	//! Funkcja liczaca wybrany algorytm
	void PoliczOperacje();
	//! Glowna Funkcja Operacji wykonujaca pomiary czasu itp.
	void Dzialaj();
	//! Funkcja wczytujaca rozmiar problemu z klawiatury.
	void PobierzRozmiarProblemu();
	Operacja(char nazwa[]);
	Operacja();
	
	

};





	

	


#endif