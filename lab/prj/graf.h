#ifndef GRAF_H
#define GRAF_H

#include "tablicaA.h"

/*! \brief Deklaracja klasy graf, zawierajaca jej podstawowe funkcje i pola.
*/
class Graf
{
public:
	/*! Konstruktor ustawiajacy odpowiednie parametry obiektom tworzacym podstawowe funkcje grafu.

	\param[in] ile - parametr okreslajacy ilosc wierzcholkow w grafie.
	*/
    Graf(int ile) 
	{
		ilosc=ile;
		GRAF=new int*[ilosc] ;
		for (int i=0;i<ilosc;i++)
		{
			GRAF[i]=new int [ilosc];
		}
		

		
		Q=new int[ilosc];
		iter=0;
		for (int i=0;i<ilosc;i++)
		{
			Q[i]=0;
		}
		apomoc=0;
		WyzerujGRAF();
		pomoc=0;
		
	}

	/*! Funkcja dodaje krawedz laczaca dwa wierzcholki w1 i w2.
		Wierzcholki sa przechowywane w macierzy sasiedztwa. Kazda wartosc w macierzy wieksza od 0 oznacza:
		- istnienie polaczenia miedzy wierzcholkami
		- okresla wartosc wagi miedzy nimi
		Dodatkowo do wczesniej zaimplementowanych tablic asocjacyjnych dodawane sa nazwy wierzcholkow z ich numerami porzadkowymi, oraz ich wagami.

		\param[in] w1, w2 - nazwy wierzcholkow, ktore beda dodane
		\param[in] waga - wartosc wagi polaczenia miedzy dwoma wierzcholkami
	*/
    void dodajKrawedz(string w1, string w2, int waga)
    {
		
		bool gotowe=false;
		if(pomoc==0)
		{
		if(!tabliczka.CzyIstnieje(w2,waga) && !tabliczka.CzyIstnieje(w1,waga))
		{

			tabliczka.dodaj(w1,waga);
			IteratorWierzcholkow=0;
			numery.dodaj(w1,IteratorWierzcholkow);
			GRAF[0][1]=waga;
			tabliczka.dodaj(w2,waga);
			IteratorWierzcholkow++;
			numery.dodaj(w2,IteratorWierzcholkow);
			GRAF[1][0]=waga;
		
			
			gotowe=true;
			pomoc++;
			
		}
		}
		if (gotowe==false)
		{
		if(numery.CzyIstnieje(w1,numery.pobierz(w1)) && !CzyIstnieje(w2) )
		{
			IteratorWierzcholkow++;
			tabliczka.dodaj(w2,waga);
			tabliczka.dodaj(w1,waga);
			numery.dodaj(w2,IteratorWierzcholkow);
			GRAF[numery.pobierz(w1)][IteratorWierzcholkow]=waga;
			GRAF[IteratorWierzcholkow][numery.pobierz(w1)]=waga;
			
			
			gotowe=true;

		}
		}
		if(gotowe==false)
		{
		if (numery.CzyIstnieje(w2,numery.pobierz(w2)) && !CzyIstnieje(w1) )
		{
			IteratorWierzcholkow++;
			tabliczka.dodaj(w1,waga);
			tabliczka.dodaj(w2,waga);
			numery.dodaj(w1,IteratorWierzcholkow);
			GRAF[numery.pobierz(w2)][IteratorWierzcholkow]=waga;
			GRAF[IteratorWierzcholkow][numery.pobierz(w2)]=waga;
			
			
			gotowe=true;
			
		}
		}
		if (gotowe==false)
		{
		if (numery.CzyIstnieje(w2,numery.pobierz(w2)) && numery.CzyIstnieje(w1,numery.pobierz(w1)))
		{
			
			tabliczka.dodaj(w1,waga);
			tabliczka.dodaj(w2,waga);
			
			GRAF[numery.pobierz(w2)][numery.pobierz(w1)]=waga;
			GRAF[numery.pobierz(w1)][numery.pobierz(w2)]=waga;
			
			
			gotowe=true;
			
			
		}
		}
		
		

		
    }

	/*! Funkcja sprawdza, czy w tablicy asocjacyjnej istnieje juz wierzcholek o zadanej nazwie.
	\param[in] - w : nazwa wierzcholka, ktora bedzie sprawdzona

	\return prawda, jesli istnieje; falsz, jesli nie istnieje.
	*/

	bool CzyIstnieje(string w)
	{
		for (int i=0; i<tabliczka.klucz.size();i++)
		{
			if (tabliczka.klucz[i]==w)
			{
				return true;
			}

		}
		return false;
	}

	//! Funkcja wyswietla caly graf, poprzez poszczegolne wyswietlanie po kolei sasiedztw kazdego z wierzcholkow.
	void WyswietlGraf()
	{
		for (int i=0; i<ilosc;i++)
		{
			WyswietlSasiedztwo(i);

		}

	}

	/*! Funkcja liczaca bezposrednich polaczen z danego indeksu wierzcholka.
	\param[in] - jaki: indeks wybranego wierzcholka.
	\return - ilosc bezposrednich polaczen z danego wierzcholka.
	*/
	int IlePolaczenBezposrednich(int jaki)
	{
		int j=0;
		for (int i=0;i<ilosc;i++)
		{
			if (GRAF[jaki][i]>0)
			{
				j++;
			}

		}
		
		return j;
	}


	/*! Funkcja wyswietla sasiedztwo zadanego wierzcholka
	\param[in] - jaki : indeks wierzcholka, ktorego sasiedztwo bedzie wyswietlone.
	*/
	void WyswietlSasiedztwo(int jaki)
	{
		cout<<endl<<"SASIEDZTWO "<<numery.pobierz(jaki)<<" :"<<endl;
		for (int i=0; i<ilosc;i++)
		{
			if (GRAF[jaki][i]>0)
			{
				cout<<numery.pobierz(i)<<" - "<<GRAF[jaki][i]<<endl;
			}

		}

	}
	
	/*! Funkcja sprawdzajaca, czy (wykorzystywane podczas szukania drogi) pobrany wierzcholek jest na liscie przejrzanych, zakazanych wierzcholkow.
	\param[in] - w: nazwa wierzcholka, ktory chcemy sprawdzic.
	\return prawda, jesli juz istnieje w tym wektorze; falsz, jesli nie istnieje.
	*/
	bool CzyJestZakazane(string w)
	{
		for (int i=0;i<zakazane.size();i++)
		{
			if(zakazane[i]==w)
			{
				return true;
			}
		}
		return false;
	}

	/*! \Branch and Bound
	Funkcja liczaca droge z zadanego do wierzcholka, do celowego. 
		Algorytm dziala na zasadzie rekurencji, sprawdzajac czy poprzez wierzcholek, przy ktorym sie znajduje, jest w stanie dojsc do celu.
		Jesli nie, to cofa sie do tylu i sprawdza w innych. Tak, az do skutku.
		\param[in] - akcj, cel - nazwy wierzcholkow: wierzcholek skad wyruszamy, wierzcholek celowy.
		Dla informacji wyswietla sie zliczona waga sumaryczna wybranej drogi.
	*/
	void PoliczDroge(string akcj,string cel)
	{
		if(iter<ilosc-1)
		iter++;
		else
		{
			apomoc++;
			if (apomoc==ilosc)
				apomoc=1;
			iter=apomoc;
			
		}
		if(iter==1)
		{
			poczatkowy=akcj;
			b=0,c=0,suma=0;
			zakazane.erase(zakazane.begin(),zakazane.begin()+zakazane.size());
			zakazane.push_back(numery.pobierz(numery.pobierz(akcj)));
			akcj=poczatkowy;
			
		}

		
		for (int j=Q[iter];j<ilosc; j++, Q[iter]=j)
		{
			

						pomocs=akcj;
						if (pomocs==poczatkowy)
						{
							b=0,c=0,suma=0;
							
						}
					

						akcja2=numery.pobierz(j);
					
						if (GRAF[numery.pobierz(pomocs)][j]>0 && !CzyJestZakazane(akcja2)  )
						{
							akcja=akcja2;
							zakazane.push_back(akcja);
							
							c=GRAF[numery.pobierz(pomocs)][j];
							b=b+c;
								if (akcja==cel)
								{
									suma=b;
									j=ilosc+1;
									Q[iter]=j;
									cout<<endl<<"Odleglosc: "<<suma<<endl;
									apomoc=ilosc-1;
									for(int x=0;x<ilosc-1;x++)
									break;
									
								}
								poczatkowy2=akcja;
								if(apomoc!=ilosc-1)
								PoliczDroge(akcja,cel);
						}
		}
	
	}


	/*! Funkcja sprawdzajaca, czy polaczone sa dwa wierzcholki. Wykonywane jest to przez macierz sasiedztwa.
	\param[in] - w1, w2: nazwy wierzcholka, ktore chcemy sprawdzic.
	\return prawda, jesli sa polaczone; falsz, jesli nie sa.
	*/
	bool CzyPolaczone(string w1, string w2)
	{
		if (GRAF[numery.pobierz(w1)][numery.pobierz(w2)]!=0)
		{
			return true;
		}
		return false;

	}
	/*! Funkcja zwraca wage, pomiedzy dwoma bezposrednio polaczonymi wierzcholkami w1, w2
	\return waga (int) miedzy dwoma wierzcholkami; -1, jesli nie sa polaczone.
	*/
	int ZwrocWage(string w1, string w2)
	{
		if (CzyPolaczone(w1,w2))
		{
			return GRAF[numery.pobierz(w1)][numery.pobierz(w2)];
		}
		cout<<endl<<"TE WIERZCHOLKI NIE MAJA WAGI, NIE SA POLACZONE!";
		return -1;
	}


private:
	//! Tablica dwuwymiarowa odgrywajaca role macierzy sasiedztwa.
  int **GRAF;
  //! Tablica przechowujaca indeks wykonywanej petli for (funkcja PoliczDroge)
  int *Q;
  //! iterator zliczajacy ilosc petli for (funkcja PoliczDroge)
	int iter;
	//! Pola typu string pomocnicze dla funkcji Branch & Bound
  	string poczatkowy,poczatkowy2,akcja,akcja2,pomocs;
	//! Pola typu int pomocnicze dla funkcji Branch & Bound
	int apomoc,b,c,suma;
	//! Pola typu int pomocnicze dla funkcji dodawania krawedzi.
	int pomoc, IteratorWierzcholkow;
	//! Pole przechowujace zadana ilosc wierzcholkow.
	 int ilosc;
	 //! Wektor z odwiedzonymi wierzcholkami.
	 vector<string> zakazane;
	 //! Tablica asocjacyjna wykorzystywana do przechowywania pary informacji, nazwy wierzcholka i wagi jego krawedzi.
	 TablicaA<int> tabliczka;
	 //! Tablica asocjacyjna wykorzystywana do przechowywania pary informacji, nazwy wierzcholka i jego indeksu typu int.
	 TablicaA<int> numery;

	 /*! Funkcja podajaca najkrotsza krawedz dookola wybranego wierzcholka.
		 \param[in] - w : wybrany wierzcholek, ktory chcemy sprawdzic.
		 \return waga najkrotszej krawedzi w sasiedztwie.
	 */
   int NajkrotszaKrawedz(string w)
	{
		int j;
		j=GRAF[numery.pobierz(w)][0];
		for (int i=0;i<ilosc;i++)
		{
			if (j<GRAF[numery.pobierz(w)][i])
			{
				j=GRAF[numery.pobierz(w)][i];
			}

		}
		return j;
	}
   //! Funkcja przypisujaca tablicy dwuwymiarowej 0.
   void WyzerujGRAF()
   {
	 
	   for(int i=0; i<ilosc;i++)
	   {
		   for (int j=0;j<ilosc;j++)
		   {
			   GRAF[i][j]=0;
		   }

	   }

   }


};


#endif