// Prosta implementacja stosu z wykorzystaniem list jednokierunkowych   -  PODEJSCIE STRUKTURALNE.
// Programik prezentuje podstawowe operacje na stosie liczb calkowitych.

#include <iostream>
#include "StosL.h"

using namespace std;

/*!
	Konstruktor ustawia wskaznik nastepnego elementu na zero (poniewaz na poczatku nie ma zadnych elementow).


*/
 ElementStosu::ElementStosu()
 {
	 nastepny=0;

 }

 /*!
	Konstruktor ustawia wskaznik pierwszego elementu na zero (poniewaz na poczatku nie ma zadnych elementow).


*/
 StosL::StosL()
 {
	 pierwszy=0;
 }

 /*!
	Parametry i najwazniejsza pola funkcji:
	-element: liczba typu int, ktora chcemy dodac do listy.
	-nowy: utworzony nowy obiekt ElementStosu, ktory jest dodany na koniec listy stosu.
	-temp: utworzony przejsciowy wskaznik na obiekt ElementStosu sluzacy do znalezienia ostatniego elementu i dodaniu na jego koniec wybranego.

	Jesli jest pierwszym elementem listy, to staje sie poczatkiem listy. Jesli nie, po znalezieniu wskaznika na ostatni element, nowy element zastepuje ten ostatni.

*/

void StosL::push(int element)
{
	ElementStosu *nowy=new ElementStosu;
	nowy->wartosc=element;
	if (pierwszy==0) // sprawdzamy czy to pierwszy element listy
    {
        // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
        pierwszy = nowy;
    }

	else
    {
        // w przeciwnym wypadku wêdrujemy na koniec listy
        ElementStosu *temp = pierwszy;

        while (temp->nastepny)
        {
            // znajdujemy wskaŸnik na ostatni element
            temp = temp->nastepny;
        }

        temp->nastepny = nowy;  // ostatni element wskazuje na nasz nowy
        nowy->nastepny = 0;     // ostatni nie wskazuje na nic
    }
}

/*!
	Parametry i najwazniejsza pola funkcji:
	-temp: wskaznik na obiekt ElementStosu, ktory sluzy do znalezienia ostatniego elementu, ktory to bedzie usuniety (jego wartosc bedzie NULL).

	

*/
void StosL::pop()
{
	
	ElementStosu *temp=pierwszy;
	while (temp->nastepny)
        {
            temp = temp->nastepny;
        }
	temp->wartosc=NULL;
	

}	
void StosL::Wyswietl()
{
	ElementStosu *temp=pierwszy;

	while(temp->nastepny)
	{
		cout<<temp->wartosc<<endl;
		temp=temp->nastepny;
	}

}


int StosL::Top()
{
	ElementStosu *temp=pierwszy;
	while(temp)
	{
		temp=temp->nastepny;
	}
	return temp->wartosc;
}
