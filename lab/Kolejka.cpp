#include<iostream>
#include "Kolejka.h"

using namespace std;

/*!
	wskpocz po utworzeniu zmiennej klasy Kolejka pokazuje na poczatek tablicy.

	Parametry i najwazniejsza pola funkcji:
	-Ilosc: parametr okresla rozmiar stworzonej tablicy kolejki.

*/

Kolejka::Kolejka(int Ilosc)
{
  rozmiar = Ilosc;
  Q = new int[Ilosc];
  wskpocz = licznikel = 0;
}


Kolejka::~Kolejka()
{
  delete [] Q;
}
/*!
	\return prawde, jesli kolejka jest pusta; falsz, jesli kolejka posiada elementy


*/
bool Kolejka::empty()
{
  return !licznikel;
}
/*!
	\return ostatni element kolejki, gdy posiada elementy; falsz, gdy ich nie posiada.


*/

int Kolejka::front()
{
  if(licznikel) 
	 return Q[wskpocz];
  return 0;
}

/*!
	Parametry i najwazniejsza pola funkcji:
	-element: liczba typu int, ktora chcemy zakolejkowac.

	Gdy liczba elementow jest wieksza badz rowna rozmiarowi kolejki, nic sie nie dzieje.

*/

void Kolejka::enqueue(int element)
{
  int i;
  if(licznikel < rozmiar)
  {
    i = wskpocz + licznikel++;
    if(i >= rozmiar) 
		i -= rozmiar;
    Q[i] = element;
  }
}



void Kolejka::dequeue()
{
  if(licznikel)
  {
    licznikel--;
    wskpocz++;
    if(wskpocz == rozmiar) 
		wskpocz = 0;
  }
}

void Kolejka::Wyswietl()
{
	for (int i=0; i<rozmiar;i++)
	{
		cout<<Q[i]<<endl;
	}

}
