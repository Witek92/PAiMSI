#ifndef CPU_H
#define CPU_H

/*!
* \file
* \brief Definicja klasy CPU
*
* Plik zawiera definicjê klasy CPU, ktora jest klasa pochodna i jest ona specjalizacja
* klasy GRA.
*/
#include "GRA.h"

/*!
* \brief Modeluje pojecie CPU
*
* Klasa modeluje pojecie cpu czyli gracza komputerowego.
*/
class CPU
{
/*!
* \brief Sprawdza czy komputer chce wymienic karty ze swojego zestawu.
* \return Zwraca true lub false.

*/
	bool CzyBedzieWymienial(GRA &Game);
/*!
* \brief Metoda wymiany kart dla komputera z ukladem 0 ( nie ma par ,trojek ,fulla, strita itd.)
*/
	void WymianaDla0(GRA &Game);
/*!
* \brief Metoda wymiany kart dla komputera z ukladem 1(czyli dla jednej pary)
*/

	void WymianaDla1(GRA &Game);
/*!
* \brief Metoda wymiany kart dla komputera z ukladem 2 (czyli dla dwóch par)
*/
	void WymianaDla2(GRA &Game);
/*!
* \brief Metoda wymiany kart dla komputera z ukladem 3(czyli dla trojki)
*/
	void WymianaDla3(GRA &Game);
/*!
* \brief Metoda wskazuje indeksy slabych kart.
*/
	void  WskazindeksySlabych(Gracz ziomek, vector<int> &slabe);
/*!
* \brief Zmienna pomocnicza typu int.
*/
	int random;
/*!
* \brief Zmienna pomocnicza typu int.
*/

	int iter;
/*!
* \brief Zmienne pomocnicze
* \return Zwracaja false lub true.
*/
    bool p1,p2,p3;
public:
/*!
* \brief Metoda wymiany kart dla komputera.Jesli bd wymienial to co bd wymienial.
*/
	void Wymiana(GRA &Game);
/*!
* \brief Inicjalizuje konstruktor.
*/
	CPU();
/*!
* \brief Metoda nadaje nazwe graczowi z komputera.
*/
	CPU(string nazwa);
/*!
* \brief Tworzy obiekt typu Gracz.
*/
	Gracz Komputer;
/*!
* \brief Tworzy obiekt typu GRA.
*/
	GRA Gierka;
/*!
* \brief Metoda liczy uklad kart komputera i wywoluje odpowiednie funckje wymiany w zaleznosci od ukladu kart.
*/
	void CoBedzieWymienial(GRA &Game);
/*!
* \brief Metoda odpowiadajaca za decyzje gracza :
* -podbija/czeka
* -przebija
* -pasuje
*/
	void Decyzja(GRA &Game);
/*!
* \brief Metoda odpowiadajaca za decyzje gracza z czekaniem.
*/
	void DecyzjaZCzekaniem(GRA &Game);
/*!
* \brief Metoda liczy uklad kart komputera i decyduje czy komputer bd pasowal,czekal czy podbijal.
*/
    char CoObstawi(GRA &Game);
};





#endif
