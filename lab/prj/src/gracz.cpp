#include <iostream>
#include "gracz.h"

using namespace std;
/*!
* \file
* \brief Definicja metody klasy Gracz.
*
* Zawiera definicjê metod klasy Gracz.
*/


Gracz::Gracz(string n)
{
	nazwa=n;
	obstawil=0;
	CzyPAS=false;
}


Gracz::Gracz()
{
	nazwa="niedobrana";
	obstawil=0;
	CzyPAS=false;
}



Gracz &Gracz::operator = (Gracz gosc)
{
	nazwa=gosc.nazwa;
	Z=gosc.Z;
	uklad=gosc.uklad;
	hajs=gosc.hajs;
	obstawil=gosc.obstawil;
	CzyPAS=gosc.CzyPAS;
	return *this;
}
