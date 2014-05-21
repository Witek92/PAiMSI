#include "operacja.h"
#include <string>

using namespace std;





	void Operacja::ZmierzCzasStart()
	{
		
		start = clock();
	}
	void Operacja::ZmierzCzasKoniec()
	{
		if (LicznikPowtorzen==0)
		{
		pomocsr=0;
		}
		koniec = clock(); 
		delta=(long)(koniec - start);
		pomocsr=delta+pomocsr;
		cout<<endl<<"Czas pomiaru dla algorytmu z "<<rozmiar<<" danymi nr: "<< LicznikPowtorzen+1<<" wynosi: "<<delta<<endl;
	}

	void Operacja::PobierzIloscPowtorzen()
	{
		cout<<endl<<"Podaj ilosc powtorzen algorytmu: ";
		cin>>Powtorzenia;
	}

	void Operacja::PodajSrednia()
	{
		srednia=pomocsr/Powtorzenia;
		cout<<endl<<"Srednia z "<<rozmiar<<" danymi dla: "<< Powtorzenia<<" powtorzen wynosi: "<<srednia<<endl<<endl;
	}

	
	



	void Operacja::WyborOperacji()
	{
	
		cout<<endl<<"WYBIERZ ZADANA OPERACJE: "<<endl;
		cout<<"a -  Branch and Bound"<<endl;
		cout<<"Co chcesz zrobic?"<<endl;
		cin>>wyborco;
		PobierzRozmiarProblemu();
		cout<<"Jak wiele powtorzen chcesz dla wykonania sie tego algorytmu ?"<<endl;
		PobierzIloscPowtorzen();
		

	}
	

	void Operacja::PoliczOperacje()
	{
	int x,y,a,glowny=1,glowny2=0;
	string pierwszy;
	srand(time(NULL));
		switch(wyborco)
			{
		
			case 'a':
				{
					nazwy=new int [rozmiar];
					for (int i=0; i<rozmiar;i++)
					{
						nazwy[i]=i;
					}
					nazwys=new string [rozmiar];
					for (int i=0;i<rozmiar;i++)
					{
						nazwys[i]=nazwy[i];
					}
					Graf g(rozmiar);
					for (int i=glowny2;i<glowny2+3 && glowny<rozmiar;i++,glowny2++)
					{
						
						for (int j=glowny;j<glowny+3 && glowny<rozmiar;j++,glowny++)
						{
							a=rand() % 20 + 1;
							g.dodajKrawedz(nazwys[i],nazwys[j],a);
						}

						
						
						
					}
					g.PoliczDroge(nazwys[0],nazwys[rozmiar-1]);
					
				}
				

			default:
				{
			
					break;

					
				}

			}
		}
	



	void Operacja::Dzialaj()
	{
		WyborOperacji();
		
		
		for (LicznikPowtorzen=0;LicznikPowtorzen<Powtorzenia;LicznikPowtorzen++)
		{
			
			ZmierzCzasStart();
			PoliczOperacje();
			ZmierzCzasKoniec();
			
			
			
	
		}
		
		PodajSrednia();
		
	}


	void Operacja::PobierzRozmiarProblemu()
	{
		cout<<"Jak duzy problem grafu wybierasz? :"<<endl;
		cin>>rozmiar;
	}
