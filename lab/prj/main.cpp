#include "NWP.h"
/*! \mainpage Dokumentacja zadania PAMSI lab 10
 *
 * \author Witold Zimnicki
 * \date 25.5.2014
 * 
 */
 

/*! \brief Funkcja main wykonujaca algorytm NWP.

W funkcji main wykonywane sa nastepujace operacje:

- Na wejscie standardowe podawany jest pierwszy ciag znakow.
- Na wejscie standardowe podadawany jest drugi ciag znakow do porownania.
- Tworzony jest obiekt klasy NWP.
- Liczona jest dlugosc najdluzszego wspolnego podciagu i wyswietlona zostaje macierz pracy.
- Wyswietlane sa wszystkie mozliwe najdluzsze wspolne podciagi.

*/
int main()
{
	string a,b;
	cout<<endl<<"PODAJ PIERWSZE SLOWO (w macierzy, znaki przy osi wierszy):"<<endl;
	cin>>a;
	cout<<endl<<"PODAJ DRUGIE SLOWO (w macierzy, znaki przy osi kolumn):"<<endl;
	cin>>b;
	cout<<endl;
	NWP podciag(a,b);
	int liczba=podciag.PoliczDlugoscPodciagu();
	cout<<endl<<"DLUGOSC NAJDLUZSZEGO WSPOLNEGO PODCIAGU: "<<endl<<liczba<<endl;
	cout<<endl;
	podciag.WyswietlNajdluzszyPodciag();

	system("PAUSE");
	return 0;
}


