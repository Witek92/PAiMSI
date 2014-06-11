#ifndef TALIA_H
#define TALIA_H

/*!
* \file
* \brief Definicja klasy Talia.
*
* Plik zawiera definicje klasy Talia ktora jest  klasa specjalistyczna i korzysta z klasy Karta.
*/
#include "karta.h"

/*!
* \brief Modeluje pojecie Talia.
*
* Klasa modeluje pojecie talia.
*/


class Talia
{
/*!
* \brief Zmienna stala statyczna typu int okreslajaca ilosc kart w talii(52).
*/
	static const int ilosc=52;
/*!
* \brief Metoda wypelnia talie dla czterech rodzai kolorow i trzynastu figur.
*/
	void WypelnijTalie();

public:
/*!
* \brief Obiekt typu int przechowujacy ilosc kart w talii.
*/
	int IloscZ;
/*!
* \brief Obiekt typu Karta.
*/
	Karta *talia;
/*!
* \brief Metoda sluzaca do wyswietlania wszystkich kart z talii.
*/
	void Wyswietl();
/*!
* \brief Inicjalizuje konstruktor.
*/
	Talia();
/*!
* \brief Inicjalizuje destruktor.
*/
	~Talia();
/*!
* \brief Metoda ktora losowo tasuje talie.
*/
	void Potasuj();
/*!
* \brief Przeciazenie operatora wyjscia.
*/
	friend ostream & operator << (ostream & Ekran, Talia &_Talia);
/*!
* \brief Metoda pobiera karte z talii.
*/
	void PobierzKarte(Karta &Karteczka);


};





#endif
