/*! \mainpage POPRAWIONA Dokumentacja zadania PAMSI lab 5
 *
 * \author Witold Zimnicki
 * \date 23.4.2014
 * 
 */

#include <iostream>
#include "operacja.h"



using namespace std;
/*! \brief Funkcja main wykonujaca wybrana operacje i liczaca czasy.

W funkcji main wykonywane sa nastepujace operacje:

- Tworzony jest obiekt klasy Operacja
- Uruchamiany jest interfejs i mozliwe jest wybranie algorytmu, ktory chcemy obserwowac.

*/

int main()
{
	
	Operacja jakas;
	jakas.Dzialaj();
	
	system("PAUSE");
	return 0;
}

