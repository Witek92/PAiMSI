#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <list>


using namespace std;

/*!	\brief Klasa opisujaca graf nieskierowany.
*/
class Graf
{
    //! Pole klasy przechowujace ilosc wierzcholkow w grafie.
    int IloscWierzcholkow;   
	//! Wskaznik na tablice zawierajaca listy ze soba graniczace.
    list<int> *Q;   
	//! Funkcja pomocnicza dla algorytmu Depth First Search.
	void DFS_pomoc(int w, bool odwiedzony[]); 
public:
	//! Konstruktor tworzacy graf wedlug podanej ilosci wierzcholkow.
    Graf(int rozmiar);  
	//! Funkcja dodaje krawedz miedzy dwa wierzcholki.
    void DodajKrawedz(int w1, int w2); 
	//! Wyswietla wynik przeszukiwania wszerz od zadanego miejsca.
    void BFS(int odkad);  
	//! Wyswietla wynik przeszukiwania w glab.
	void DFS();    
	//! Wyswietla wynik przeszukiwania w glab od zadanego wierzcholka.
	void DFS(int odkad);    
};
#endif


