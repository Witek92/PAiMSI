#ifndef STOS_H
#define STOS_H

#include <iostream>
#include <stack>

using namespace std;

/*! \brief pole typu enum definiujace zmienna powiekszanie, ktora decyduje o rodzaju powiekszania
	o_jeden - znaczy powiekszanie stosu o jeden, jesli braknie miejsca
	razy_dwa - znaczy podwajanie rozmiaru stosu, jesli braknie miejsca
*/

enum powiekszanie{o_jeden, razy_dwa};

	static powiekszanie zmienna=razy_dwa;
	//! Pole statyczne informujace, kiedy stos jest pusty.
	static int pusty=1;

	/*! \brief Definicja klasy Stos implementowanej tablicowo.
*/
class Stos
{
	//! Tablica glowna przechowujaca Stos.
	int *tab;
	//! Pole przechowujace rozmiar tablicy.
	int rozmiar;
	//! Pole z pierwszym wolnym elementem.
	int wolny;

public:
	//! Konstruktor domyslny klasy Stos.
	Stos();
	//! Destruktor klasy Stos usuwajacy dynamiczna tabilce tab.
	~Stos();
	//! Konstruktor tworzacy w zaleznosci od parametru Ilosc.
	Stos(int Ilosc);
	//! Funkcja powiekszajaca Stos w zaleznosci od statycznego parametru powiekszanie.
	void Powieksz();	
	//! Funkcja kladaca element na Stos.
	void push(int element);	
	//! Funkcja sciagajaca ostatni element ze stosu.
	void pop();			
	//! Funkcja zwracajaca ostatni element stosu.
	int top();			
	//! Funkcja wyswietlajaca caly stos.
	void Wyswietl();

	
};



#endif