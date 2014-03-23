/*! \mainpage Dokumentacja zadania PAMSI lab 1 
 *
 * \author Witold Zimnicki
 * \date 1.3.2014
 * 
 */

#include <iostream>
#include "operacja.h"
#include <fstream>
#include <ctime>



using namespace std;
/*! \brief Funkcja main wykonujaca algorytm i prowadzaca statystyki na jej temat.

W funkcji main wykonywane sa nastepujace operacje:

- Zostaje utworzona operacja (obiekt klasy Operacja)
- Zostaje wczytany plik z danymi wejsciowymi
- Dane sa mnozone razy 2 (wlaczany jest pomiar czasu)
- Wczytywany jest plik z danymi sprawdzajacymi
- Wykonywanie jest sprawdzanie ich zgodnosci
- Zostaje zatrzymany pomiar czas oraz liczony jest dla kazdego wykonania algorytmu.

Pola funkcji:
- *tablica 1, * tablica 2: dynamicznie alokowane tablice, w ktorych przechowywane sa dane wczytane z plikow
- start, koniec - czasy: pocz¹tkowy oraz koñcowy pomiaru
- delta : roznica miedzy koncem, a poczatkiem; dlugosc trwania algorytmu
*/

int main()
{
	
	Operacja Mnozenie;
	int j;
	
	j=Mnozenie.ZbadajIloscLiczb("dane_wej.txt");

		
int *tablica1=new int [j];
int *tablica2=new int [j];

Mnozenie.ZapiszLiczbyDoTablicy("dane_wej.txt", tablica1);
Mnozenie.PomnozLiczby(2,tablica1,j);

clock_t start, koniec;
for (int k=0;k<20;k++)
{
start = clock(); // bie¿¹cy czas systemowy w ms

Mnozenie.ZapiszLiczbyDoTablicy("dane_spr.txt", tablica2);

if(Mnozenie.PorownajZgodnoscTablic(tablica1,tablica2,j))
{
	cout<<"Tablice sa zgodne!";
}
else
{
	cout<<"Tablice sa niezgodne!";
}

koniec = clock(); // bie¿¹cy czas systemowy w ms
long delta=(long)(koniec - start);
cout<<endl<<"Czas pomiaru dla algorytmu z "<<j<<" danymi nr: "<< k+1<<" wynosi: "<<delta<<endl<<endl;
}

delete [] tablica1;
delete [] tablica2;

	system("PAUSE");
	return 0;
}

