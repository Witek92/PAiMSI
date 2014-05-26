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

	void Operacja::dodaj(string &tekst, int ktory)
	{
		string pomoc;
		pomoc=tekst;
		for (int i=0;i<ktory;i++)
		{
			tekst+=pomoc;
		}

	}

	Operacja::Operacja()
	{
		PobierzRozmiarProblemu();
		HashM jakas(rozmiar);
		haszujaca=jakas;
		nazwys=new string [rozmiar];
		int j=97,k=0,l=0;
					for (int i=1;l<rozmiar;i++,l++)
					{

					nazwys[l]=j;
					j++;
						if(i%26==0)
						{
							j=97;
						}
							
						
						
						dodaj(nazwys[l],k);
						if(i%26==0)
						{
							k++;
						}

					}
					

	}

	



	void Operacja::WyborOperacji()
	{
		
	int losowa, losowa2;
		cout<<endl<<"WYBIERZ ZADANA OPERACJE: "<<endl;
		cout<<"a -  asocjacyjna"<<endl;
		cout<<"d -  drzewo"<<endl;
		cout<<"h -  haszujaca"<<endl;
		
		cout<<"Co chcesz zrobic?"<<endl;
		cin>>wyborco;
		cout<<"Jak wiele powtorzen chcesz dla wykonania sie tego algorytmu ?"<<endl;
		PobierzIloscPowtorzen();
		srand(time(NULL));
		switch(wyborco)
		{
		case 'a':
			{
				
				for(int i=0; i<rozmiar;i++)
					{
							
						
						tabliczka.dodaj(nazwys[i],i);
						
						
					}
				break;
			}
		case 'd':
			{
					for(int i=0;i<rozmiar;i++)
					{
						
						drzewko.dodaj(i,nazwys[i]);
					}
		
				break;
			}
		case 'h':
			{
					for(int i=0;i<rozmiar;i++)
					{
						haszujaca.Push(nazwys[i],i);
					}
				break;
			}



		}
		
					
		

	}
	

	void Operacja::PoliczOperacje()
	{
	int losowa,losowa2, a;
	
		switch(wyborco)
			{
		
			case 'a':
				{
					
					a=rand() % (rozmiar-1);
					a=tabliczka.pobierz(nazwys[a]);
					cout<<endl<<a;

					
					break;
				}
			case 'd':
				{

					a=rand() % (rozmiar-1);
					a=drzewko.SzukajPoKolei(nazwys[a]);
					cout<<endl<<a;
					
					
					
					break;
				}
			case 'h':
				{
					a=rand() % (rozmiar-1);
					a=haszujaca.Znajdz(nazwys[a]);
					cout<<endl<<a;
					
					
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
		cout<<"Jak duzy problem wybierasz? :"<<endl;
		cin>>rozmiar;
	}
