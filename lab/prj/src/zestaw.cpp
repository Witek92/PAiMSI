#include <iostream>
#include "zestaw.h"


/*!
* \file
* \brief Definicja metody klasy Zestaw.
*
* Zawiera definicje metod klasy Zestaw.
*/


using namespace std;



ostream &operator << (ostream &Ekran, Zestaw z)
{
	for (int i=0; i<5;i++)
	{
		Ekran<<"|  "<<z._Zestaw[i]<<"  |";
	}
	Ekran<<endl;
	return Ekran;
}




		Zestaw &Zestaw::operator = (Zestaw zestawik)
		{
			for (int i=0;i<5;i++)
			{
				_Zestaw[i]=zestawik._Zestaw[i];
			}
			return *this;
		}

