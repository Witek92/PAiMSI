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
		cout<<"d - Depth First Search zwykle "<<endl;
		cout<<"p - Depth First Search z wyborem wierzcholka"<<endl;
		cout<<"b - Breadth First Search z wyborem elementu"<<endl;
		cout<<"Co chcesz zrobic?"<<endl;
		cin>>wyborco;
		PobierzRozmiarProblemu();
		cout<<"Jak wiele powtorzen chcesz dla wykonania sie tego algorytmu ?"<<endl;
		PobierzIloscPowtorzen();
		

	}



	void Operacja::PoliczOperacje()
	{
	int x,y;
	srand(time(NULL));
		switch(wyborco)
			{
		
			case 'b':
				{
					Graf g(rozmiar);
					
					for (int i=0;i<rozmiar;i++)
					{
						x=rand() % rozmiar;
						y=rand() % rozmiar;
						g.DodajKrawedz(x,y);
					}
					g.BFS(x);
					break;
				}
			
			case 'p':
				{
					Graf g(rozmiar);
					
					for (int i=0;i<rozmiar;i++)
					{
						x=rand() % rozmiar;
						y=rand() % rozmiar;
						g.DodajKrawedz(x,y);
					}
					g.DFS(x);
					
					break;
				}


			
			case 'd':
				{
					
					Graf g(rozmiar);
				
					
					for (int i=0;i<rozmiar;i++)
					{
						x=rand() % rozmiar;
						y=rand() % rozmiar;
						g.DodajKrawedz(x,y);
					}
					g.DFS();
					
					break;
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
