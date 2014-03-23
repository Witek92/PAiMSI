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
/*! \brief Funkcja main wykonujaca zadane operacje na tablicy i liczaca sredni czas dzialania algorytmow.

W funkcji main wykonywane sa nastepujace operacje:

- Zostaje utworzona operacja (obiekt klasy Operacja) 
- Zostaje wczytany plik z danymi wejsciowymi, wczytujac je do tablicy "glownej" TABLICA[]
- Opcjonalnie wczytywana jest druga tablica pomocnicza (do wykonywania operacji np przypisania) i sprawdzony jest jej rozmiar (zapisany w j)
- Wczytywany jest plik z danymi sprawdzajacymi
- Wykonywanie jest sprawdzanie ich zgodnosci
- Zostaje zatrzymany pomiar czasu oraz liczony jest dla kazdego wykonania algorytmu; liczona jest rowniez srednia czasu.

Pola funkcji:
-  *tablica 2: dynamicznie alokowana tablica pomocnicza, w ktorych przechowywane sa dane wczytane z plikow
- start, koniec - czasy: pocz¹tkowy oraz koñcowy pomiaru
- delta : roznica miedzy koncem, a poczatkiem; dlugosc trwania algorytmu
-sredni: czas sredni wykonywania sie algorytmu
-nr: numer powtorzenia algorytmu
*/

int main()
{
	Operacja Dzialanie(ZbadajIloscLiczb("dane_wej.txt"));
	int temp=0,sredni,delta,nr;
	clock_t start, koniec;	

	int &j=Dzialanie.IloscLiczb2;
	j=ZbadajIloscLiczb("dane_spr.txt");
	int *tablica2=new int [j];
	
	
	ZapiszLiczbyDoTablicy("dane_spr.txt", tablica2,j);
	Dzialanie.ZapiszLiczbyDoTablicy("dane_wej.txt");
	
	Dzialanie.OdwrocKolejnosc();
	Dzialanie.TABLICA=Dzialanie.DodajElement(9);
	Dzialanie=tablica2;
	Dzialanie.TABLICA=Dzialanie.DodajElement(6);
	Dzialanie.TABLICA=Dzialanie+tablica2;
	
	Dzialanie.WyswietlTablice();

	
for (nr=0;nr<20;nr++)
{

	start = clock(); // bie¿¹cy czas systemowy w ms

	if (Dzialanie==tablica2)
		{
			cout<<"Tablice sa zgodne!";
		}	
	else
		{
			cout<<"Tablice sa niezgodne!";
		}

	koniec = clock(); // bie¿¹cy czas systemowy w ms
	delta=(koniec - start);
	cout<<endl<<"Czas pomiaru z "<<j<<" danymi dla powtorzenia nr: "<< nr+1<<" wynosi: "<<delta<<endl<<endl;
	delta=temp+delta;
	temp=delta;
}
sredni=delta/nr;
cout<<endl<<"SREDNI CZAS TO: "<<sredni<<endl;
delete [] tablica2;


	system("PAUSE");
	return 0;
}

