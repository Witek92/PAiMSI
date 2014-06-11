#ifndef INTERFEJS_H
#define INTERFEJS_H

/*!
* \file
* \brief Definicja klasy Interfejs.
*
* Plik zawiera definicje klasy Interfejs, ktora jest klasa pochodna i jest ona specjalizacja
* klasy talia, CPU , GRA.
*/
#include <iostream>
#include "talia.h"
#include "CPU.h"
#include "GRA.h"
#include <vector>




using namespace std;


/*!
* \brief Modeluje pojecie Interfejs.
*
* Klasa modeluje pojecie interfejs.
*/

class Interfejs
{

/*!
* \brief Metoda wyswietla ekran startowy programu.
*/

	void WyswietlIntro();
/*!
* \brief Metoda pozwala na wybor ilosci graczy ludzi i komputerow + nadanie nazw tym graczom
* rozdaje karty kazdemu z graczy,decyduje o wymianie kart,wyswietla wygranego oraz pokazuje kombinacje ukladow 4
* graczy bioracych udzial w grze.
*/
	void NowaGra();
/*!
* \brief Zmienna zawierajaca poczatkowa stawke pieniedzy.
*/
	int hajspoczatkowy;
/*!
* \brief Metoda po wybraniu przez gracza decyzji o pasowaniu usuwa go z listy graczy.
*/
	void UsunGracza(Gracz &ziomek);
/*!
* \brief Metoda po wybraniu przez komputer decyzji o pasowaniu usuwa go z listy graczy.
*/
	void UsunGracza(CPU &Komp);

	public:
/*!
* \brief Obiekt typu Gracz.
*/
		Gracz *Gracze;
/*!
* \brief Obiekt typu GRA.
*/
		GRA GIERKA;
/*!
* \brief Obiekt typu CPU.
*/
		CPU *Komputery;
/*!
* \brief Zmienna przechowuje ilosc graczy.
*/
		int IloscGraczy; // przechowuje ilosc graczy
/*!
* \brief Zmienna przechowuje ilosc graczy= komputerow.
*/
		int IloscGraczyCPU; // przechowuje ilosc graczy CPU
/*!
* \brief Metoda dzialaj w ktorej zawarte sa wszystkie kombinacje przyciskow z instrukcji oraz ich funkcje.
*/
		void Dzialaj();
/*!
* \brief Obiekt typu Gracz wskazuje wygranego.
*/
		Gracz WskazWygranego();
/*!
* \brief Metoda pomocnicza dla sprawdzenia poprawnosci dzialania programu.
*/
		void Proba();
    /*!
* \brief Metoda wyswietla uklad na koncu programu jaki uzyskal kazdy z graczy.
*/
		void WyswietlUklad(Gracz ziomek);
/*!
* \brief Metoda wyswietla instrukcje do programu.
*/
		void WyswietlInstrukcje();
/*!
* \brief Metoda ktora pobiera poczatkowa stawke pieniedzy wpisana przez uzytkownika.
*/
		void PobierzHajsPoczatkowy();
    /*!
* \brief Metoda przydziela poczatkowa  stawke rowna 50.
*/
		void PrzydzielPoczatkowePule0(Gracz &ziomek);
/*!
* \brief Metoda przydziela poczatkowa stawke rowna 100.
*/
		void PrzydzielPoczatkowePule1(Gracz &ziomek);
/*!
* \brief Metoda przydziela poczatkowa stawke wszystkim graczom rowna 100.
*/
        void PrzydzielPoczatkowePule(Gracz &ziomek);
};



#endif


