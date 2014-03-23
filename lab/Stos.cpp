#include <iostream>
#include <fstream>
#include "Stos.h"

using namespace std;


/*!
		Parametry i najwazniejsze pola funkcji:

		tab2, tab3 - nowe tablice, do ktorych kopiowane sa 'stare' tablice, lecz odpowiednio powiekszone.

*/

void Stos::Powieksz()
{
	if (zmienna==0)
	{
		int *tab2 = new int [rozmiar + 1];		
 
		for(int i=0;i<rozmiar;i++)
			tab2[i] = tab[i];	
 
		delete []tab;	
 
		tab = tab2;		
 
		rozmiar++;		
	}

	else if (zmienna==1)
	{
		int *tab3 = new int [rozmiar*2];		
 
		for(int i=0;i<rozmiar;i++)
		tab3[i] = tab[i];	
 
		delete []tab;	
 
		tab = tab3;		
 
		rozmiar=rozmiar*2;		
	}

	else
	{
		cout<<"BLAD POWIEKSZENIA"<<endl;
	}


}

/*!
		Parametry i najwazniejsze pola funkcji:

		-element: liczba, ktora dodajemy na gore stosu

		Po dodaniu juz jednego elementu, parametry statyczny pusty przyjmuje wartosc falsz.


*/

void Stos::push(int element)
{

	if(wolny == rozmiar)	//jeœlo koñczy siê miejsce
	Powieksz();	//stos siê powiêksza
 
	tab[wolny++] = element;
	pusty=0;
}

/*!
		Gdy brak elementow w stosie, pusty rowny jest prawdzie.



*/
void Stos::pop()
{
	wolny--;
	rozmiar--;
	if (wolny==0)
	{
		pusty=1;
	}

}


int Stos::top()
{
	return tab[wolny-1];	
}

/*!
		Konstruktor domyslny tworzy pusty Stos, z rozmiarem domyslnym 1.



*/
Stos::Stos()
{
	wolny = 0;	//na pocz¹tku stos jest pusty
	rozmiar = 1;		//na starcie dajemy mo¿liwoœæ wrzucenia 1 elementu
 
	tab = new int[rozmiar];	//dyaniecznie przydzielana pamiêæ
 
	if(tab == NULL)		//coœ siê nie powiod³o przy alokacji pamiêci
	{
		cerr<< "B³¹d alokcacji pamiêci!";	
	}
}

/*!
		Parametry i najwazniejsze pola funkcji:
		-Ilosc: obiekt przyjmuje wybrany rozmiar.



*/

Stos::Stos(int Ilosc)
{
	wolny=0;	//na stosie pusto
	rozmiar=Ilosc;	//ustawiamy zgodnie z zyczeniem
 
	tab=new int[rozmiar];	
 
	if(tab == NULL)
	{
		cerr<<"B³¹d alokcacji pamiêci!";
	}
}
 

Stos::~Stos()
{
	delete []tab;	
}

void Stos::Wyswietl()
{
	if(pusty==0)
	{
		
		for (int i=rozmiar-1;i>=0;i--)
		{
			cout<<tab[i]<<endl;
		}

	}
	else
	{
		cout<<endl<<"NIE MA CO WYSWIETLAC!"<<endl;
	}

	
}

