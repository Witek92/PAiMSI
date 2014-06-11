#ifndef KARTA_H
#define KARTA_H

/*!
* \file
* \brief Definicja klasy Karta.
*
* Plik zawiera definicje klasy Karta, ktora jest  klasa glowna i nie korzysta z zadnych innych klas.
*/

#include <iostream>
#include <string>



using namespace std;
/*!
* \brief Modeluje pojecie Karta.
*
* Klasa modeluje pojecie karta.
*/

class Karta
{


public:
/*!
* \brief Rodzaj koloru definiowany przez dana klase.
*/
	enum Kolor {Serce, Karo, Pik, Trefl};
/*!
* \brief Rodzaj figury definiowany przez dana klase.
*/
    enum Figura {dwa, trzy,cztery,piec,szesc,siedem,osiem,dziewiec,dziesiec,jopek,dama,krol,as};
/*!
* \brief Obiekt typu Kolor.
*/
	Kolor kol;
/*!
* \brief Obiekt typu Figura.
*/
	Figura fig;
/*!
* \brief Zmienna przechowujaca kolor karty.
*/
	int _Kolor;
/*!
* \brief Zmienna przechowujaca figure karty.
*/
	int _Figura;
/*!
* \brief Inicjalizuje konstruktor.
*/
	Karta(int kolor, int figura);

	Karta();



/*!
* \brief Metoda udostepnia kolor.
* \return Zwraca kolor karty.
*/
	int UdostepnijKolor();
/*!
* \brief Metoda udostepnia figure.
* \return Zwraca figure karty.
*/
	int UdostepnijFigure();
/*!
* \brief Metoda sprawdza czy tego samego koloru.
* \return Zwraca true lub false.
*/
	bool CzyTenSamKolor(Karta k1);
/*!
* \brief Metoda sprawdza czy ta sama figura.
* \return Zwraca true lub false.
*/
	bool CzyTaSamaFigura(Karta k1);
/*!
* \brief Metoda sprawdza czy ta sama karta.
* \return Zwraca true lub false.
*/
	bool CzyTaSamaKarta(Karta k1);
/*!
* \brief Przeciazenie operatora porownania ==.
*/
	bool operator == (Karta k1);
/*!
* \brief Przeciazenie operatora !=.
*/
	bool operator != (Karta k1);
/*!
* \brief Metoda przypisuje karcie wartosc.
*/
	void PrzypiszKarcieWartosc(int kolor, int figura);

/*!
* \brief Przeciazenie operatora =.
*/	Karta & operator = (Karta k1);




};
/*!
* \brief Przeciazenie operatora wyjscia.
*/
ostream &operator << (ostream &Ekran, Karta k);
/*!
* \brief Metoda przepisuje kolor i figure jednej z kart na druga.
*/
void Przepisz(Karta &k1, Karta k2);


#endif
