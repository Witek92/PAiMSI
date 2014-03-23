#ifndef STOSL_H
#define STOSL_H

#include <iostream>


using namespace std;

/*!
	\brief Definicja klasy ElementStosu , opisujacej jeden z listowej implementacji klasy StosL.


*/
class ElementStosu
{
	
public:
	//! Pole przechowujace wartosc tego elementu.
	int wartosc;
	//! Wskaznik na nastepny element.
	ElementStosu *nastepny;
	//! Konstruktor klasy ElementStosu.
	ElementStosu();

};

/*!
	\brief Definicja klasy StosL dziedziczaca klase ElementStosu, majaca za zadanie dzialac na elementach stosu zaimplementowanego listowo.


*/
class StosL: public ElementStosu
{
	public:
		//! Wskaznik na pierwszy element stosu.
		ElementStosu *pierwszy;
		//! Funkcja dodajaca element do listy stosu.
		void push(int element);
		//! Funkcja usuwajaca ostatni element listy stosu.
		void pop();
		//! Funkcja wyswietla cala liste stosu.
		void Wyswietl();
		//! Konstrutktor klasy StosL.
		StosL();
		//! Funkcja zwracajaca ostatni element stosu.
		int Top();
};






#endif