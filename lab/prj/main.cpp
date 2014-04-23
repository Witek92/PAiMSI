/*! \mainpage Dokumentacja zadania PAMSI lab 7
 *
 * \author Witold Zimnicki
 * \date 23.4.2014
 * 
 */


#include "operacja.h"
#include <ctime>
#include<iostream>

using namespace std;

/*! \brief Funkcja main wykonuje zapelnianie tablicy haszujacej oraz drzewa binarnego + mierzy czasy.

W funkcji main wykonywane sa nastepujace operacje:

- Tworzony jest obiekt klasy Operacja
- Uruchamiany jest interfejs i mozliwe jest wybranie ilosci zestawow, ktore chcemy dodac do struktur danych.

*/

int main()
{
	Operacja Zapelnianie;
	Zapelnianie.Dzialaj();


 system("PAUSE");
 return 0;
}