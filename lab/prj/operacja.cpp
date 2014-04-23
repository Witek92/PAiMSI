#include <iostream>
#include "operacja.h"
#include "tablica.h"
#include <fstream>
#include <ctime>
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
		koniec = clock(); // bie¿¹cy czas systemowy w ms
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

	
	Operacja::Operacja(char nazwa[])
	{
	
		tabliczka2= tablica(nazwa);

	}

	Operacja::Operacja()
	{

	}



	void Operacja::WyborOperacji()
	{
		bool sukces=false;

		cout<<endl<<"WYBIERZ ZADANA OPERACJE: "<<endl;
		cout<<"* - Mnozenie tablicy przez liczbe"<<endl;
		cout<<"z - Zamien Elementy tablicy"<<endl;
		cout<<"b - Sortowanie babelkowe tablicy"<<endl;
		cout<<"q - quicksort przypadek przecietny"<<endl;
		cout<<"p - quicksort przypadek pesymistyczny"<<endl;
		cout<<"o - quicksort przypadek optymistyczny"<<endl;
		cout<<"m - sortowanie mergesort tablicy"<<endl;
		cout<<"h - sortowanie heapsort tablicy"<<endl;
		cout<<"r - Odwroc Kolejnosc tablicy"<<endl;
		cout<<"d - Dodaj Element do tablicy "<<endl;
		cout<<"s - zapelnij stos tablicowy"<<endl;
		cout<<"l - zapelnij stos listowy"<<endl;
		cout<<"k - zapelnij kolejke tablicowa"<<endl;
		cout<<"Co chcesz zrobic?"<<endl;
		cin>>wyborco;
		PobierzRozmiarProblemu();
		Kolejeczka.UstalRozmiar(rozmiar);
		cout<<"Jak wiele powtorzen chcesz dla wykonania sie tego algorytmu ?"<<endl;
		PobierzIloscPowtorzen();
		while (sukces!=true)
		{
		switch (rozmiar)
			{
			case 10:
				{
					tabliczka2=tablica("sort_10.txt");
					sukces=true;
					break;
				}
			case 100:
				{
					tabliczka2=tablica("sort_100.txt");
					sukces=true;
					break;
				}
			case 1000:
				{
					tabliczka2=tablica("sort_1000.txt");
					sukces=true;
					break;
				}
			case 5000:
				{
					tabliczka2=tablica("sort_5000.txt");
					sukces=true;
					break;
				}
			case 10000:
				{
					
					tabliczka2=tablica("sort_10000.txt");
					sukces=true;
					break;
				}
			case 50000:
				{
					tabliczka2=tablica("sort_50000.txt");
					sukces=true;
					break;
				}
			case 100000:
				{
					tabliczka2=tablica("sort_100000.txt");
					sukces=true;
					break;
				}
			case 500000:
				{
					tabliczka2=tablica("sort_500000.txt");
					sukces=true;
					break;
				}
			case 1000000:
				{
					tabliczka2=tablica("sort_1000000.txt");
					sukces=true;
					break;
				}
			case 2000000:
				{
					tabliczka2=tablica("sort_2000000.txt");
					sukces=true;
					break;
				}
			case 5000000:
				{
					tabliczka2=tablica("sort_5000000.txt");
					sukces=true;
					break;
				}


			default:
				{
					cout<<"NIEPOPRAWNA ILOSC!!!"<<endl;
					sukces=false;

				}

			}
		}

		switch(wyborco)
			{
			case '*':
				{
					
					cout<<endl<<"Razy ile chcesz pomnozyc elementy?"<<endl;
					cin>>liczba1;
					break;
				}
			case 'z':
				{
					
					cout<<endl<<"Ktore elementy chcesz zamienic?"<<endl<<"Element pierwszy: ";
					cin>>liczba2;
					cout<<"Element drugi: ";
					cin>>liczba3;
					break;

				}
		
			
			
			case 'd':
				{
					
					cout<<endl<<"Jaki element chcesz dodac?"<<endl;
					cin>>element;
					tabliczka2.DodajElement(element);
					
					break;
				}
			case 's':
				{
					cout<<endl<<"Jak chcesz powiekszac stos? (0 - o jeden, 1 - razy dwa)"<<endl;
					cin>>jakstos;
					
				}


	
			default:
				{
				
					break;

					
				}

			}
		
		
	}



	void Operacja::PoliczOperacje()
	{
	
	
		switch(wyborco)
			{
			case '*':
				{
				
					tabliczka2.PomnozLiczby(liczba1);
					break;
				}
			case 'z':
				{

					tabliczka2.ZamienElementy(liczba2,liczba3);
					
					break;

				}
			case 'b':
				{
					tabliczka2.sortuj_babel();
					break;
				}
			case 'q':
				{
					tabliczka2.quicksort_przecietny(0,tabliczka2.ZwrocIloscLiczb()-1);
					
					break;
				}
			case 'o':
				{
					tabliczka2.quicksort_opt(0,tabliczka2.ZwrocIloscLiczb()-1);
					break;
				}
			case 'p':
				{
					tabliczka2.quicksort_pes(0, tabliczka2.ZwrocIloscLiczb()-1);
					break;
				}


			case 'r':
				{
					tabliczka2.OdwrocKolejnosc();
					break;
				}
			case 'd':
				{
					
					tabliczka2.DodajElement(element);
				
					break;
				}
			case 's':
				{
					
					stosik.OkreslZmienna(jakstos);
					tabliczka2.WypelnijStosTablica(stosik);
					break;
				}
			case 'l':
				{
					
					tabliczka2.WypelnijStosLTablica(stosikL);
					
					break;
				}
			case 'k':
				{
					
					tabliczka2.WypelnijKolejkeTablica(Kolejeczka);
					
					break;
				}
			case 'm':
				{
					tabliczka2.mergesort(0,tabliczka2.ZwrocIloscLiczb()-1);
					break;
				}
			case 'h':
				{
					tabliczka2.heapsort();
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
		cout<<"Jak duzy problem wybierasz? (10, 100, 1000, 5000, 10000, 50000, 100000, 500 000, 1 000 000, 2 000 000, 5 000 000):"<<endl;
		cin>>rozmiar;
	}
