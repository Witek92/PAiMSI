#ifndef WEZEL_H
#define WEZEL_H
#include<iostream>
#include <string>
using namespace std;

/*! \brief Klasa Wezel opisuje obiekt bedacy elementem wiekszej klasy Drzewo - drzewa binarnego.
	Posiada on swoj klucz - string, oraz wartosc - int.
*/
class Wezel
{
public:
  //! klucz wezla.
 string klucz;
  //! wartosc wezla.
 int wartosc;        
 //! wska�nik na lewego potomka.
 Wezel * lewy;   
 //! wska�nik na prawego potomka.
 Wezel * prawy; 
 //! konstruktor domyslny - zeruje pola.
 Wezel()          
 {
   wartosc=0;
   lewy=NULL;
   prawy=NULL;
 }
};
#endif