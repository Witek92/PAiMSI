#include <iostream>
#include "operacja.h"
#include <fstream>
#include <ctime>
#include <string>

using namespace std;





	void Operacja::ZmierzCzasStart()
	{
		start = clock();
	}
	void Operacja::ZmierzCzasKoniecDrzewo()
	{
		
		koniec = clock(); 
		delta=(long)(koniec - start);
		
		cout<<endl<<"Czas wypelnienia drzewa z "<<Powtorzenia<<" powtorzeniami "<<" wynosi: "<<delta<<endl;
	}

	void Operacja::ZmierzCzasKoniecHasz()
	{
		
		koniec = clock(); 
		delta=(long)(koniec - start);
		
		cout<<endl<<"Czas wypelnienia tablicy mieszajacej z "<<Powtorzenia<<" powtorzeniami "<<" wynosi: "<<delta<<endl;
	}

	void Operacja::PobierzIloscPowtorzen()
	{
		cout<<endl<<"Podaj ilosc powtorzen algorytmu: ";
		cin>>Powtorzenia;
	}


	/*! 
		Konstruktor pobiera wybrana ilosc zestawow, ktore chcemy dodac do tablicy i drzewa.
	*/
	Operacja::Operacja()
	{
		PobierzIloscPowtorzen();
		haszujaca=HashM(Powtorzenia);
	}



	void Operacja::PoliczOperacjeDrzewo()
	{
	
		for (int i=0;i<Powtorzenia;i++)
		{
		
			drzewko.dodaj(i,"przlad");
	
		}
		
	}

	void Operacja::PoliczOperacjeHasz()
	{
		for (int i=0;i<Powtorzenia;i++)
		{
		
			haszujaca.Push("przklad",i);

		}
	}




	void Operacja::Dzialaj()
	{
		
			ZmierzCzasStart();
			PoliczOperacjeDrzewo();
			ZmierzCzasKoniecDrzewo();
			
			
			ZmierzCzasStart();
			PoliczOperacjeHasz();
			ZmierzCzasKoniecHasz();
			
		
		
		
	}

