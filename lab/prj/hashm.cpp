#include <iostream>
#include "hashm.h"


using namespace std;


/*!
	Konstruktor alokuje pamiec o zadanej ilosci dla tablicy haszujacej.
*/

	 HashM::HashM(int r) 
	 {
			rozmiar=r;
			tablica = new HashEn*[rozmiar];
			for (int i = 0; i < rozmiar; i++)
			tablica[i] = NULL;
	 }
 
	 /*!
		\return Wartosc dla wybranego klucza, lub -1, jesli tablica jest pusta.
	 */
      int HashM::Znajdz(string klucz) 
	  {
            int h = (hash(klucz) % rozmiar);
            while (tablica[h] != NULL && tablica[h]->PobierzKlucz() != klucz)
                  h = (h + 1) % rozmiar;
            if (tablica[h] == NULL)
                  return -1;
            else
                  return tablica[h]->PobierzWartosc();
      }
 
	
      void HashM::Push(string klucz, int wartosc) 
	  {
            int h = (hash(klucz) % rozmiar);
            while (tablica[h] != NULL && tablica[h]->PobierzKlucz() != klucz)
                  h = (h + 1) % rozmiar;
            if (tablica[h] != NULL)
                  delete tablica[h];
            tablica[h] = new HashEn(klucz, wartosc);
      }     
 
	
	  int HashM::hash(string klucz)
	  {
		long h = 0;
		for(unsigned int i = 0; i<klucz.length(); i++){
			h = abs(h*101 + abs(klucz[i]));	
		}
		return h;
	  }

	  void HashM::wypisz()
	  {
		  
		for(int i = 0; i<rozmiar; i++)
		{
			cout<<endl;
			cout<<tablica[i]->PobierzKlucz()<<" --- "<<tablica[i]->PobierzWartosc()<<endl;
			
		}
	  }