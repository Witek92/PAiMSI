#ifndef ZESTAW_H
#define ZESTAW_H

/*!
* \file
* \brief Definicja klasy Zestaw.
*
* Plik zawiera definicje klasy Zestaw, ktora jest klasa pochodna i jest ona specjalizacja
* klasy Karta.
*/
#include "karta.h"

/*!
* \brief Modeluje pojecie Zestaw.
*
* Klasa modeluje pojecie zestaw.
*/

class Zestaw
{
public:
/*!
* \brief Obiekt typu Karta zawierajacy zestaw 5 kart dla gracza.
*/
	Karta _Zestaw[5];
/*!
* \brief Metoda ktora zapisuje ile graczy bedzie bralo udzial w grze.
*/
	void ZapiszIloscGraczy(int ilosc);
/*!
* \brief Przeciazenie operatora = , potrzebne do przypisania jednego zestawu drugiemu.
*/
	Zestaw &operator = (Zestaw zestawik);



};

/*!
* \brief Przeciazenie operatora wyjscia.
*/
ostream &operator << (ostream &Ekran, Zestaw z);

#endif
