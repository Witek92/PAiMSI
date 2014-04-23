#ifndef HASHM_H
#define HASHM_H

#include <iostream>
#include "hashen.h"

using namespace std;

/*! \brief Klasa HashM przechowuje w sobie elementy (klucze i wartosci) w tablicy mieszajacej.
*/

class HashM
{
	//! Glowna tablica zawierajaca klucz oraz wartosc.
	HashEn **tablica;
	//! Funkcja haszujaca.
	int hash(string klucz);
public:
	 //! Konstruktor parametryczny tworzacy obiekt HaszM o danym rozmiarze.
	 HashM(int r);
	 //! Funkcja znachodzi i zwraca wartosc po kluczu.
      int Znajdz(string klucz);
	 //! Funkcja dodajaca pare klucza oraz wartosci do tablicy.
      void Push(string key, int value);    

	   
	  //! Funkcja wypisuje elementy tablicy haszujacej.
	   void wypisz();
	   //! pole przechowuje rozmiar tablicy.
	   int rozmiar;
	   //! Konstruktor domyœlny.
	   HashM()
	   {

	   }

};

#endif