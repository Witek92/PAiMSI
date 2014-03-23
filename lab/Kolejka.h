#ifndef KOLEJKA_H
#define KOLEJKA_H

#include <iostream>

using namespace std;

/*! \brief Definicja klasy Kolejka
	
	Ta struktura danych pozwala na zapisywanie danych do kolejki zaimplementowej tablicowo.


*/

class Kolejka
{

  private:
	//! Pole przechowujace rozmiar tablicy.
    int rozmiar;   
	//! Pole wskazujace na poczatek kolejki
    int wskpocz;   
	//! Pole odpowiedzialne za zliczanie elementow tablicy kolejki.
    int licznikel;  
	//! Tablica glowna przechowujaca kolejke.
    int *Q;   

  public:
	//! Konstruktor domyslny klasy Kolejka.
	Kolejka();
	//! Konstruktor pobierajacy parametr ilosci elementow tablicy.
    Kolejka(int Ilosc);
	//! Destruktor usuwajacy tablice dynamiczna Q.
    ~Kolejka();     
	//! Funkcja sprawdzajaca, czy tablica jest pusta.
    bool empty();
	//! Funkcja zwraca element na koncu kolejki.
    int  front();
	//! Funkcja kolejkuje wybrany element.
    void enqueue(int element);
	//! Funkcja usuwa ostatni element kolejki.
    void dequeue();
	//! Funkcja wyswietla cala kolejke.
	void Wyswietl();
};






#endif