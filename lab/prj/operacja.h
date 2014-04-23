#ifndef OPERACJA_H
#define OPERACJA_H


#include <iostream>
#include <fstream>
#include <ctime>
#include "hashm.h"
#include "drzewo.h"


/*! \brief Deklaracja klasy Operacja.

*	Klasa Operacja posiada pola oraz funkcje potrzebne do wykonywania dzialan na roznych strukturach danych.
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
	//! Pole przechowuje rozmiar problemu.
	int rozmiar;
	
	
	
public:
	//! Tablica haszujaca dla danej operacji.
	HashM haszujaca;
	//! Drzewo binarne dla danej operacji.
	Drzewo drzewko;
	//! Funkcja wyznaczajaca poczatek pomiaru czasu.
	void ZmierzCzasStart();
	//! Funkcja wyznaczajaca koniec pomiaru czasu dla zapelniania drzewa binarnego.
	void ZmierzCzasKoniecDrzewo();
	//! Funkcja wyznaczajaca koniec pomiaru czasu dla zapelniania tablicy haszujacej.
	void ZmierzCzasKoniecHasz();
	//! Funkcja pobierajaca ilosc powtorzen od uzytkownika.
	void PobierzIloscPowtorzen();
	//! Pole przechowujace informiacji o ilosci powtorzen dla danej operacji.
	int Powtorzenia;
	//! Funkcja wykonujaca zapelnianie drzewa binarnego.
	void PoliczOperacjeDrzewo();
	//! Funkcja wykonujaca zapelnianie tablicy haszujacej.
	void PoliczOperacjeHasz();
	//! Glowna Funkcja Operacji wykonujaca wszystkie potrzebne funkcje do uzyskania czasow.
	void Dzialaj();
	//! Konstruktor bezparametryczny.
	Operacja();
	
	

};





	

	


#endif