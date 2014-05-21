#ifndef TABLICAA_H
#define TABLICAA_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//! \brief Klasa TablicaA reprezentuje tablice asocjacyjna, ktora przechowuje pary wartosci (klucz+wartosc) oraz dodatkowo wykonuje na nich operacje.

template<typename TYP> class TablicaA
{
	private:
		
		
	public:

		//!Pole przechowujace kluczy tablicy asocjacyjnej, ktore sa typu string. 
		vector<string> klucz;
		//!Pole przechowujace wartosci tablicy asocjacyjnej, ktore sa wybranego typu.
		vector<TYP> wartosc;
		//! Funkcja dodaj¹ca do tablicy asocjacyjnej pozycje.
		void dodaj(string k,TYP v);
		//! Funkcja usuwajaca z tablicy asocjacyjnej wybrana pozycje.
		void usun(string k,TYP v);
		//! Funkcja zwracajaca wartosc zadanego klucza.
		TYP pobierz(string k);
		//! Funkcja zwracajaca klucz zadanej wartosci.
		string pobierz(TYP v);
		//! Funkcja zwracajaca ilosc elementow tablicy asocjacyjnej.
		int IleElementow();
		//! Funkcja sprawdzajaca, czy tablica asocjacyjna jest pusta.
		bool CzyPusta();
		//! Funkcja sprawdzajaca, czy istnieje wybrana pozycja (klucz+wartosc).
		bool CzyIstnieje(string k, TYP v);
		//! Przeciazenie operatora wyswietlania tablicy asocjacyjnej.
		template <typename TYP>
		friend ostream &operator << (ostream &ekran, TablicaA<TYP> &tabliczka);
		
};
/*!	Argumenty i najwa¿niejsze pola funkcji:
	-k: element typu string, ktory bedzie kluczem dodawanej pozycji.
	-v: element dowolnego typu, ktory bedzie wartoscia dla wybranego klucza.
*/
template<typename TYP>
void TablicaA<TYP>::dodaj(string k, TYP v)
{
	
	klucz.push_back(k);
	wartosc.push_back(v);

}

/*!	Argumenty i najwa¿niejsze pola funkcji:
	-k: klucz, ktorego istnienie jest kwestionowane.
	-v: wartosc klucza, jw.
	\return Prawda, jesli taka para istnieje (klucz+wartosc); Falsz, jesli tak nie jest.
*/
template <typename TYP>
bool TablicaA<TYP>::CzyIstnieje(string k, TYP v)
{
	for (int i=0; i<klucz.size();i++)
	{
		if (klucz[i]==k && wartosc[i]==v)
		{
			return true;
		}

	}
	return false;

}
/*!	Argumenty i najwa¿niejsze pola funkcji:
	-k: klucz, ktorego element bedzie usuwany.
	-v: wartosc klucza, ktora bedzie usuwana.
	
*/

template <typename TYP>
void TablicaA<TYP>::usun(string k, TYP v)
{
	if(!CzyIstnieje(k,v))
	{
		cerr<<endl<<"BLAD USUWANIA! Nie istnieje taka pozycja w mapie!"<<endl;
	}
	else
	{
		for (int i=0; i<klucz.size();i++)
		{
			if (klucz[i]==k && wartosc[i]==v)
			{
				klucz.erase(klucz.begin()+i);
				wartosc.erase(wartosc.begin()+i);
			}

		}
	}
}
/*!	Argumenty i najwa¿niejsze pola funkcji:
	
	\return Prawda, jesli tablica jest pusta; Falsz, jesli zawiera choc jeden element.
*/
template <typename TYP>
bool TablicaA<TYP>::CzyPusta()
{
	if (klucz.empty())
	{
		return true;
	}
	return false;
}




template <typename TYP>

ostream &operator << (ostream &ekran, TablicaA<TYP> &tabliczka)
{
	if(tabliczka.CzyPusta())
	{
		ekran<<endl<<"Nie ma co wyswietlac, mapa jest pusta!"<<endl;
		return ekran;
	}
	else
	{
		for (int i=0; i<tabliczka.klucz.size();i++)
		{
			ekran<<endl<<"Klucz: "<<tabliczka.klucz[i]<<"   Wartosc: " <<tabliczka.wartosc[i]<<endl;
		}
		return ekran;
	}
}

/*!	Argumenty i najwa¿niejsze pola funkcji:
	-k: klucz, ktorego wartosc jest szukana.
	
	\return Wartosc szukanego po kluczu elementu.
*/
template <typename TYP>
TYP TablicaA<TYP>::pobierz(string k)
{
	
	for (int i=0; i<klucz.size();i++)
	{
		if (klucz[i]==k)
		{
			return wartosc[i];
		}
	}
	cout<<endl<<"BRAK ELEMENTU Z TAKIM KLUCZEM!"<<endl;
	return NULL;
}

template <typename TYP>
string TablicaA<TYP>::pobierz(TYP v)
{
	for (int i=0; i<klucz.size();i++)
	{
		if (wartosc[i]==v)
		{
			return klucz[i];
		}
	}
	cout<<endl<<"BRAK ELEMENTU Z TAKA WARTOSCIA!"<<endl;
	return NULL;
}



/*!	Argumenty i najwa¿niejsze pola funkcji:
	
	\return Ilosc pozycji w tablicy asocjacyjnej.
*/
template <typename TYP>
int TablicaA<TYP>::IleElementow()
{
	return klucz.size();
}


#endif