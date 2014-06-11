#ifndef GRA_H
#define GRA_H

/*!
* \file
* \brief Definicja klasy GRA
*
* Plik zawiera definicjê klasy GRA, ktora jest klasa glowna programu.
*/
#include "gracz.h"
#include "talia.h"
#include <vector>

/*!
* \brief Modeluje pojecie GRA
*
* Klasa modeluje pojecie GRA.
* Jej atrybutem jest pole zawierajace talie.
*/

class GRA
{
  /*!
* \brief Talia kart.
*/
	Talia GLOWNA;
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy zaden z nich nie ma zadnego ukladu.
*/
	void PorownanieWPrzypadku0(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma pare w swoim zestawie kart.
*/
	void PorownanieWPrzypadku1(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma po dwie pary w swoim zestawie kart.
*/
	void PorownanieWPrzypadku2(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma trojke w swoim zestawie kart.
*/
	void PorownanieWPrzypadku3(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma po dwie pary w swoim zestawie kart.
*/
	void PorownanieWPrzypadku4(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma po dwie pary w swoim zestawie kart.
*/
	void PorownanieWPrzypadku5(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma po fullu.
*/
	void PorownanieWPrzypadku6(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma po dwie pary w swoim zestawie kart.
*/
	void PorownanieWPrzypadku7(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda porownuje zestawy graczy w przypadku gdy kazdy z nich ma pokera.
*/
	void PorownanieWPrzypadku8(Gracz &ziomek1, Gracz &ziomek2);




public:
/*!
* \brief Inicjalizuje konstruktor.
*/
	GRA();
/*!
* \brief Metoda szuka pary w zestawie kart gracza
* \return Zwraca figure ktora jest w parze.
*/
	int ZnajdzPare(Gracz ziomek);
/*!
* \brief Metoda szuka pary w zestawie kart gracza
* \return Zwraca wektor , ktory przechowuje figury, ktore sa w parach.
*/
	vector<int> ZnajdzPary(Gracz ziomek);
/*!
* \brief Metoda znajduje trojke w zestawie kart gracza.
* \return Zwraca figure ktora jest w trojce.
*/
	int ZnajdzTrojke(Gracz ziomek);
/*!
* \brief Metoda sprawdza czy jest para w zestawie kart gracza.
* \return Zwraca false lub true.
*/
	bool CzyJestPara(Gracz ziomek);
/*!
* \brief Metoda sprawdza czy sa dwie pary w zestawie kart gracza.
* \return Zwraca false lub true.
*/
	bool CzySaDwiePary(Gracz ziomek);
/*!
* \brief Metoda sprawdza czy jest trojka w zestawie kart gracza.
* \return Zwraca false lub true.
*/
	bool CzyJestTrojka(Gracz ziomek);
/*!
* \brief Metoda sprawdza czy jest strit w zestawie kart gracza.
* \return Zwraca false lub true.
*/
	bool CzyJestStrit(Gracz ziomek);
/*!
* \brief Metoda sprawdza czy jest kolor w zestawie kart gracza (piec kart w jednym kolorze).
* \return Zwraca false lub true.
*/
	bool CzyJestKolor(Gracz ziomek);
/*!
* \brief Metoda sprawdza czy jest czworka w zestawie kart gracza.
* \return Zwraca false lub true.
*/
	bool CzyJestCzworka(Gracz ziomek);
/*!
* \brief Metoda sprawdza czy jest ful w zestawie kart gracza.
* \return Zwraca false lub true.
*/
	bool CzyJestFul(Gracz ziomek);
/*!
* \brief Metoda sluzaca do wymiany kart gracza.Gracz zostaje spytany czy chce wymienic karty
* a potem ma mozliwosc wybrania ktore karty chce wymienic.
*/
	void Wymiana(Gracz &ziomek);
/*!
* \brief Metoda pobiera nowa karte z talii 52 kart.
*/
	void Wymien(Karta &Karteczka);
/*!
* \brief Metoda szuka najwyzszej karty w zestawie kart gracza.
* \return Zwraca figure ktora jest najwyzsza w kartach gracza.
*/
	int ZnajdzNajwyszaKarte(Gracz ziomek);
/*!
* \brief Metoda liczy uklady kart graczy i decyduje o zwyciestwie gracza:
*  zwyciestwo=0 - przegrana
*  zwyciestwo=1 - wygrana
*  zwyciestwo=2 - remis
*/
	void PorownajWyniki(Gracz &ziomek1, Gracz &ziomek2);
/*!
* \brief Metoda rozdaje karty z talii dla wszystkich graczy.
*/
	void Rozdaj(Gracz &gosc);

/*!
* \brief Metoda tasuje karty z talii.
*/
	void Potasuj();
/*!
* \brief Metoda wyswietla instrukcje.
*/
	void WyswietlInstrukcje();

/*!
* \brief Metoda liczy uklady, czyli graczowi przyporzadkowuje uklad w zaleznosci co ma.
*/
	void PoliczUklady(Gracz &ziomek);
/*!
* \brief Metoda rozdaje pieniadze dla kazdego z graczy.
*/
	void RozdajKase(Gracz &ziomek, int ile);
/*!
* \brief Metoda odpowiadajaca za decyzje gracza :
* -podbija/czeka
* -przebija
* -pasuje
*/
	void Decyzja(Gracz &ziomek);
/*!
* \brief Metoda odpowiadajaca za decyzje gracza z czekaniem.
*/
	void DecyzjaZCzekaniem(Gracz &ziomek);
/*!
* \brief Zmienna przechowujaca aktualna stawke znajdujaca sie w puli.
*/
	int AktualnaStawka;
/*!
* \brief Zmienna przechowujaca pule pieniedzy.
*/
	int pula;
/*!
* \brief Zmienna przechowujaca i ile gracz chce przebic stawke.
*/
	int przebicie;
/*!
* \brief Metoda sprawdza czy jest przebicie.
* \return Zwraca false lub true.
*/
	bool CzyJestPrzebicie;

};



#endif
