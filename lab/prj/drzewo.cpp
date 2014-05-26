#include <iostream>
#include "drzewo.h"
#include "wezel.h"

using namespace std;


/*! 
	Funkcja dodajaca element i klucz dziala nastepujaco: jezeli drzewo jest puste, to tworzy nowy wezel bedacy poczatkiem tego drzewa. Jezeli drzewo istnieje, po kolei sprawdzajac z lewej i prawej strony odpowiednie wartosci
	tworza sie nowe wezly.
Najwazniejsze pola i argumenty funkcji:
-tmp - wskaznik pomocniczny wskazujacy na korzen

\return true, jesli dodana zostala nowa wartosc; false, jesli dana para juz istnieje
	
*/



 bool Drzewo::dodaj(int wartosc, string kluczyk)    
 {
    if( korzen == NULL )     
    {                      
		Ilosc=0;
      Wezel *nowyWezel = new Wezel;
	  Ilosc++;
      nowyWezel->wartosc = wartosc;
	  nowyWezel->klucz=kluczyk;
      korzen = nowyWezel;
      return true;  
    }
    else                  
    {
       Wezel *tmp = korzen;   
       while(tmp!=NULL)   
       {
          if(wartosc<=tmp->wartosc)  
          {
              if( tmp->lewy != NULL ) 
              {
                tmp = tmp->lewy; 
              }
              else  
              {
                Wezel *nowyWezel = new Wezel;
				Ilosc++;
                nowyWezel->wartosc = wartosc;
				nowyWezel->klucz = kluczyk;
                tmp->lewy = nowyWezel;   
                return true;
              }
          }
          else if(wartosc>tmp->wartosc)
          {
             if( tmp->prawy != NULL ) 
             {
               tmp = tmp->prawy; 
             }
             else  
             {
                Wezel *nowyWezel = new Wezel;
				Ilosc++;
               nowyWezel->wartosc = wartosc;
			   nowyWezel->klucz = kluczyk;
               tmp->prawy = nowyWezel;  
               return true;
             }  
          }
          else 
          {
              return false;
          }
       }
    }
 }

 /*!
		\return wartosc szukanego klucza.
 */
 int Drzewo::WyszukajWartosc(string kluczyk)
 {
	 for (int i=0; i<Ilosc;i++)
	 {
		 if (korzen[i].klucz==kluczyk)
		 {
			 return korzen->wartosc;
			 
		 }

	 }
	 return -1;

 }


 void Drzewo::pokolei(Wezel * wezel)   
 {                          
    if(wezel!=NULL)                     
    {
      pokolei(wezel->lewy);
      cout<<wezel->wartosc<<" "<<wezel->klucz<<"\n";
      pokolei(wezel->prawy);
    }
 }

  /*!
		\return wartosc szukanego klucza.
 */
 int Drzewo::Szukaj(string klucz, Wezel *wezel)
 {
	
    if(wezel!=NULL)                     
    {
      Szukaj(klucz,wezel->lewy);
      if(wezel->klucz==klucz)
	  {
		  return wezel->wartosc;
		  wezel=NULL;
		  
	  }
      Szukaj(klucz,wezel->prawy);
	 
    }
	

 }
