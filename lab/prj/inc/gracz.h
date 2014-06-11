#ifndef GRACZ_H
#define GRACZ_H
/*!
* \file
* \brief Definicja klasy Gracz.
*
* Plik zawiera definicje klasy Gracz, ktora jest klasa pochodna i jest ona specjalizacja
* klasy Zestaw.
*/
#include "zestaw.h"

/*!
* \brief Modeluje pojecie Gracz
*
* Klasa modeluje pojecie gracz.
*/
class Gracz
{

	public:
/*!
* \brief Zmienna oznaczajaca uklad kart:
* 0-nic, 1-para,2-dwie pary,3-trojka,4-strit,5-kolor,6-full,7-kareta
*/
		int uklad; //uklady kart: 0-nic, 1-para,2-dwie pary,3-trojka,4-strit,5-kolor,6-full,7-kareta
/*!
* \brief Zmienna oznaczajaca zwyciestwo.
*/
		int zwyciestwo;
/*!
* \brief Obiekt zawierajacy unikatowy zestaw gracza.
*/
		Zestaw Z; //unikatowy zestaw gracza
/*!
* \brief Zmienna typu string przechowujaca nazwe gracza.
*/
		string nazwa; //nazwa gracza
/*!
* \brief Inicjalizuje konstruktor.
*/
		Gracz();
/*!
* \brief Inicjalizuje konstruktor tworzacy gracza po nazwie.
*/
		Gracz(string n); //konstruktor tworzacy gracza po nazwie.
/*!
* \brief Przeciazenie operatora = potrzebne do przypisania jednemu graczowi grugiego.
*/
		Gracz &operator = (Gracz gosc); // przypisanie jednemu graczowi drugiego
/*!
* \brief Zmienna typu int przechowujaca
*/
		int hajs;
/*!
* \brief Zmienna typu int przechowujaca informacje o obstawieniu pieniedzy przez gracza.
*/
		int obstawil;
/*!
* \brief Metoda sprawdza czy uzytkownik rezygnuje z dlaszej gry.
* \return Zwraca true lub false.
*/
		bool CzyPAS;

};





#endif
