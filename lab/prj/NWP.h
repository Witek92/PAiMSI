#ifndef NWP_H
#define NWP_H
#include <iostream>
#include <string>

/*! \brief Klasa prezentujaca algorytm Najdluzszego Wspolnego Podciagu.
*/
using namespace std;

class NWP
{
	//! Tablica dwuwymiarowa przechowujaca informacje dotyczace dwoch ciagow znakow.
	int **C;
	//! Funkcja wyswietlajaca kontrolnie macierz C.
	void WyswietlC();
	//! Pola przechowujace wymiary zadanych ciagow.
	int m,n;
	//! Ciagi znakow zadane przez uzytkownika.
	string X,Y;
	//! Funkcja zwracajaca wieksza wartosc z dwoch.
	int max(int a, int b);
public:
	//! Konstruktor parametryczny, tworzacy macierz w zaleznosci od zadanych dwoch ciagow znakow x oraz y.
	NWP(string x, string y);
	//! Konstruktor domyslny.
	NWP();
	//! Funkcja liczaca maksymalna dlugosc podciagu.
	int PoliczDlugoscPodciagu();
	//! Funkcja znachodzi i wyswietla NWP.
	void WyswietlNajdluzszyPodciag();
	

};

#endif