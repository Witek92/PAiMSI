#include <iostream>
#include "talia.h"
#include <ctime>


/*!
* \file
* \brief Definicja metody klasy Talia.
*
* Zawiera definicje metod klasy Talia..
*/

using namespace std;


void Talia::WypelnijTalie()
{
	int k=0;
	while (k<52)
	{

		for (int i=0; i<4; i++)
		{
			for (int j=0; j<13;j++)
			{
				talia[k].PrzypiszKarcieWartosc(i,j);
				k++;
			}

		}
	}

}

void Talia::Wyswietl()
{
	cout<<"TALIA ZAWIERA:"<<endl;
	for (int i=0; i<52; i++)
	{
		cout<<talia[i]<<endl;
	}
}


ostream &operator << (ostream & Ekran, Talia &t1)
{
	Ekran<<"TALIA ZAWIERA:"<<endl;
	for (int i=0; i<52; i++)
	{
		Ekran<<t1.talia[i]<<endl;
	}
	return Ekran;
}

Talia::Talia()
{
	talia=new Karta [ilosc];
	WypelnijTalie();
}


Talia::~Talia()
{
	delete [] talia;
}


void Talia::Potasuj()
{
	IloscZ=52;
	Karta *tablica=new Karta [IloscZ];
	Karta *tablica2=new Karta [IloscZ];
	tablica2=talia;
	Karta schowek;
	srand(time(NULL));
	int i;
	for(int j=0;j<52;j++)
	{
		IloscZ--;
		if (IloscZ>1)
		i=rand() % IloscZ;
		else
		i=0;
		tablica[j]=tablica2[i];

		schowek=tablica2[i];
		tablica2[i]=tablica2[IloscZ];
		tablica2[IloscZ]=schowek;
	}
	IloscZ=51;
	talia=tablica;
	tablica=NULL;
	delete [] tablica;
	delete []tablica2;


}




	void Talia::PobierzKarte(Karta &Karteczka)
	{

		Karteczka=talia[IloscZ];
		IloscZ--;

	}




