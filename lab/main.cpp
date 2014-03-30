/*! \mainpage Dokumentacja zadania PAMSI lab 4
 *
 * \author Witold Zimnicki
 * \date 23.3.2014
 * 
 */

#include <iostream>
#include <ctime>
#include "tablica.h"
#include "Stos.h"
#include "Kolejka.h"
#include "StosL.h"



using namespace std;
/*! \brief Funkcja main wykonujaca zadane operacje na tablicy, stosie i kolejce, oraz liczaca sredni czas dzialania algorytmow.

W funkcji main wykonywane sa nastepujace operacje:

- Utworzona zostaje tablica z danymi z wybranego pliku wejsciowego (o roznych rozmiarach problemu).
- Opcjonalnie Utworzone zostaja wybrane obiekty innych wybranych klas.
- 50 razy wykonana jest petla z pomiarem czasu dla wykonywania sie wybranego sortowania.
- Zostaje zatrzymany pomiar czasu oraz liczony jest dla kazdego wykonania algorytmu; liczona jest rowniez srednia czasu.

Pola funkcji:
- start, koniec - czasy: pocz¹tkowy oraz koñcowy pomiaru
- delta : roznica miedzy koncem, a poczatkiem; dlugosc trwania algorytmu
-sredni: czas sredni wykonywania sie algorytmu
-nr: numer powtorzenia algorytmu
*/

int main()
{
	
	tablica tabliczka("sort_10000.txt");
	
	
	int temp=0,sredni,delta,nr,j;
	j=tabliczka.ZwrocIloscLiczb();
	clock_t start, koniec;	
	srand(time(NULL));

	for (nr=0;nr<50;nr++)
	{

		start = clock(); // bie¿¹cy czas systemowy w ms
		
		tabliczka.quicksort_opt(0,j-1);
		koniec = clock(); // bie¿¹cy czas systemowy w ms
		
		delta=(koniec - start);
		cout<<endl<<"Czas pomiaru z "<<j<<" danymi dla powtorzenia nr: "<< nr+1<<" wynosi: "<<delta<<endl<<endl;
		delta=temp+delta;
		temp=delta;
	}
	sredni=delta/nr;
	cout<<endl<<"SREDNI CZAS TO: "<<sredni<<endl;
	
	system("PAUSE");
	return 0;
}

