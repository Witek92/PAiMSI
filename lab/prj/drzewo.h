#ifndef DRZEWO_H
#define DRZEWO_H

#include "wezel.h"
#include<iostream>
using namespace std;


/*! \brief Klasa Drzewo przedstawia drzewo binarne.
	Sklada sie z wielu wezlow.
*/
class Drzewo
{
	//! Wskaznik na korzenie (wezly).
 Wezel * korzen;               
 //! Funkcja pomocnicza do wyswietlania drzewa od wskazanego miejsca.
 void pokolei(Wezel * ptr);   
 //! Pole przechowuje ilosc wezlow.
 int Ilosc;
 
 
 public:

//! Funkcja wyszukuje wartosc po kluczu.
int WyszukajWartosc(string kluczyk);
//! Konstruktor domyslny, zeruje korzen.
 Drzewo()                    
 {
   korzen=NULL;
 }
 
 //! Funkcja dodaje wybrana pare : klucz oraz wartosc.
 bool dodaj(int wartosc, string kluczyk);    
 
 //! Funkcja wyswietlajaca elementy po kolei.
void Wyswietlpokolei()       
{
     pokolei(korzen);
}

};

#endif