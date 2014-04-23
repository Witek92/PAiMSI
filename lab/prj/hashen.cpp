#include <iostream>
#include "hashen.h"

using namespace std;




HashEn::HashEn(string klucz, int wartosc) 
	  {
            this->klucz = klucz;
            this->wartosc = wartosc;
      }
 
      string HashEn::PobierzKlucz() 
	  {
            return klucz;
      }
 
      int HashEn::PobierzWartosc() 
	  {
            return wartosc;
      }