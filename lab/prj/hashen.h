#ifndef HASHEN_H
#define HASHEN_H

#include <iostream>
#include <string>

using namespace std;

/*! \brief Klasa HashEn przedstawia element mapy tablicy haszujacej.
*/
class HashEn
{
	string klucz;
	int wartosc;

public:

	HashEn(string klucz, int wartosc); 
	 
    string PobierzKlucz();
    int PobierzWartosc(); 
	 
};



#endif