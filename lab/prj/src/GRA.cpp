#include "GRA.h"

/*!
* \file
* \brief Definicja metody klasy GRA
*
* Zawiera definicje metod klasy GRA.
*/
void GRA::Wymiana(Gracz &ziomek)
{

	char przycisk;
	int x,y,z,j,k,l;
	string wybor;
	bool sukces,sukces2;

		sukces=false;
		sukces2=false;
		bool clean=false;
		bool display=false;
		bool instru=false;

		while(sukces!=true || clean==true || display==true || instru==true)
		{
			cout<<endl<<"Czy gracz "<<ziomek.nazwa<<" bedzie wymienial karty? (y/n)";
			cin>>przycisk;
			switch (przycisk)
			{
			case 'y':
				{
					clean=false;
					display=false;
					instru=false;

					sukces=true;
					while (sukces2!=true)
					{
					sukces2=true;

					cout<<endl<<"Jakie karty chcesz wymienic ?"<<endl;
					cin>>wybor;
					if (wybor[0]=='c')
					{
						clean=true;
						display=false;
						instru=false;
						system( "cls" );
					}
					else if (wybor[0]=='d')
					{
						display=true;
						clean=false;
						instru=false;
						cout<<endl<<"Karty "<<ziomek.nazwa<<" : "<<ziomek.Z<<endl;


					}
					else if (wybor[0]=='i')
					{
						instru=true;
						clean=false;
						display=false;

						WyswietlInstrukcje();

					}

					else
					{
						switch(wybor.size())
						{
						case 1:
							{
									j=wybor[0]- '0';
									if(j==1 || j==2 || j==3 || j==4 || j==5)
									{

									}
									else
									{
										sukces2=false;
										break;
									}



								x = wybor[0] - '0';

								Wymien(ziomek.Z._Zestaw[x-1]);
								break;
							}
						case 2:
							{

								j=wybor[0]- '0';
								k=wybor[1]- '0';

									if(j==1 || j==2 || j==3 || j==4 || j==5)
									{

									}
									else
									{
										sukces2=false;
										break;
									}

									if(k==1 || k==2 || k==3 || k==4 || k==5)
									{

									}
									else
									{
										sukces2=false;
										break;
									}

								x = wybor[0] - '0';
								y = wybor[1] - '0';
								Wymien(ziomek.Z._Zestaw[x-1]);
								Wymien(ziomek.Z._Zestaw[y-1]);
								break;
							}
						case 3:
							{


								j=wybor[0]- '0';
								k=wybor[1]- '0';
								l=wybor[2]- '0';

								if(j==1 || j==2 || j==3 || j==4 || j==5)
									{

									}
								else
								{
									sukces2=false;
										break;
								}

								if(k==1 || k==2 || k==3 || k==4 || k==5)
									{

									}
								else
								{
									sukces2=false;
										break;
								}

								if(l==1 || l==2 || l==3 || l==4 || l==5)
									{

									}
								else
								{
									sukces2=false;
										break;
								}


								x = wybor[0] - '0';
								y = wybor[1] - '0';
								z = wybor[2] - '0';



								Wymien(ziomek.Z._Zestaw[x-1]);
								Wymien(ziomek.Z._Zestaw[y-1]);
								Wymien(ziomek.Z._Zestaw[z-1]);
								break;
							}
						default:
							{
								cout<<endl<<"BLAD!"<<endl;
								break;
							}



						}
					}
					if (sukces2==false)
						{
							cout<<endl<<"BLAD! NIC NIE ZOSTALO ZAMIENIONE! "<<endl<<"(Nalezy wpisac po kolei liczby porzadkowe wyswietlonych kart liczone od lewej strony (1,2,3,4 lub 5), ktore chcesz wymienic, bez przecinkow)"<<endl<<" MAKSYMALNIE MOZNA WYMIENIC 3 KARTY!";

						}


				}
					break;
				}
			case 'n':
				{
					sukces=true;
					break;
				}
			case 'c':
				{
					sukces=false;
					system( "cls" );
					break;
				}
			case 'd':
				{
					sukces=false;

							cout<<endl<<"Karty "<<ziomek.nazwa<<" : "<<ziomek.Z<<endl;

					break;
				}
			case 'i':
				{
					sukces=false;
						WyswietlInstrukcje();
				break;
				}



			default:
				{
					sukces=false;
					cout<<endl<<"Wpisales blednie Twoj wybor!! Wpisz y dla tak lub n dla nie! "<<endl;
					break;
				}


			}

		}


}


void GRA::Wymien(Karta &Karteczka)
{

	GLOWNA.PobierzKarte(Karteczka);

}


void GRA::WyswietlInstrukcje()
{
	cout<<endl<<"                 INSTRUKCJA OBSLUGI              "<<endl;
				cout<<"Po podaniu ilosci graczy (max 6) nalezy podac ich nazwy. Po obejrzeniu swojego zestawu kart, nalezy podjac decyzje, czy chcemy wymieniac karty (y - tak, lub n - nie)."<<endl;
				cout<<"Gdy odpowiedz jest pozytywna, nalezy podac liczby porzadkowe wybranych kart, liczac od lewej strony, po kolei, bez przecinkow. (Maksymalna dozwolona ilosc kart do wymienienia to 3)."<<endl;
				cout<<"Po wymianach, osoba z najlepszym zestawem kart (wg zasad Pokera) wygrywa. Milej zabawy!!"<<endl;
}


void GRA::PoliczUklady(Gracz &ziomek)
{
	ziomek.uklad=0;
	if (CzyJestPara(ziomek))
		{
			ziomek.uklad=1;
		}
		if (CzySaDwiePary(ziomek))
		{
			ziomek.uklad=2;
		}
		if (CzyJestTrojka(ziomek))
		{
			ziomek.uklad=3;
		}
		if (CzyJestKolor(ziomek))
		{
			ziomek.uklad=5;
		}
		if (CzyJestStrit(ziomek))
		{
			ziomek.uklad=4;
			if (CzyJestKolor(ziomek))
			{
				ziomek.uklad=8; //poker
			}

		}
		if (CzyJestFul(ziomek))
		{
			ziomek.uklad=6; //ful
		}
		if (CzyJestCzworka(ziomek))
		{
			ziomek.uklad=7;
		}



}



bool GRA::CzyJestPara(Gracz ziomek)
{
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i].CzyTaSamaFigura(ziomek.Z._Zestaw[j]) && i!=j)
			{
				return true;
			}

		}

	}
	return false;
}


bool GRA::CzySaDwiePary(Gracz ziomek)
{

	bool sukces=false;
	int iterator1, iterator2;
	int figura1,figura2;
	Karta schowek;
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i]._Figura==ziomek.Z._Zestaw[j]._Figura && i!=j)
			{
				sukces=true;
				iterator1=i;
				figura1=ziomek.Z._Zestaw[i]._Figura;
				iterator2=j;


			}

		}

	}
	if (sukces==true)
	{
		schowek=ziomek.Z._Zestaw[iterator1];
		ziomek.Z._Zestaw[iterator1]=ziomek.Z._Zestaw[3];
		ziomek.Z._Zestaw[3]=schowek;
		schowek=ziomek.Z._Zestaw[iterator2];
		ziomek.Z._Zestaw[iterator2]=ziomek.Z._Zestaw[4];
		ziomek.Z._Zestaw[4]=schowek;
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3;j++)
			{
				if(ziomek.Z._Zestaw[i]._Figura==ziomek.Z._Zestaw[j]._Figura && i!=j && ziomek.Z._Zestaw[i]._Figura!=figura1)
				{
					return true;
				}

			}

		}

	}

	return false;
}

bool GRA::CzyJestTrojka(Gracz ziomek)
{
	/*
	Karta schowek;
	bool sukces=false;
	Karta pomoc;
	int iterator1,iterator2;
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i].CzyTaSamaFigura(ziomek.Z._Zestaw[j]) && i!=j)
			{
				sukces=true;
				iterator1=i;
				iterator2=j;
				pomoc._Figura=ziomek.Z._Zestaw[i]._Figura;
			}


		}

	}
	if (sukces==true)
	{
		schowek=ziomek.Z._Zestaw[iterator1];
		ziomek.Z._Zestaw[iterator1]=ziomek.Z._Zestaw[3];
		ziomek.Z._Zestaw[3]=schowek;
		schowek=ziomek.Z._Zestaw[iterator2];
		ziomek.Z._Zestaw[iterator2]=ziomek.Z._Zestaw[4];
		ziomek.Z._Zestaw[4]=schowek;
		for (int i=0; i<3; i++)
		{
			if(ziomek.Z._Zestaw[i]._Figura==pomoc._Figura)
			{
				return true;
			}

		}

	}

	return false;
	*/


	bool sukces=false;
	int iterator1, iterator2;
	int figura1,figura2;
	Karta schowek;
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i]._Figura==ziomek.Z._Zestaw[j]._Figura && i!=j)
			{
				sukces=true;
				iterator1=i;
				figura1=ziomek.Z._Zestaw[i]._Figura;
				iterator2=j;


			}

		}

	}
	int j=0;
	if (sukces==true)
	{
		schowek=ziomek.Z._Zestaw[iterator1];
		ziomek.Z._Zestaw[iterator1]=ziomek.Z._Zestaw[3];
		ziomek.Z._Zestaw[3]=schowek;
		schowek=ziomek.Z._Zestaw[iterator2];
		ziomek.Z._Zestaw[iterator2]=ziomek.Z._Zestaw[4];
		ziomek.Z._Zestaw[4]=schowek;
		for (int i=0; i<3; i++)
		{

				if(ziomek.Z._Zestaw[i]._Figura==figura1)
				{
					j++;

				}



		}

	}
	if (j==1)
		return true;

	return false;
}

bool GRA::CzyJestStrit(Gracz ziomek)
{

		int z;
		do
		{
			Karta schowek;
			z=0;
			for (int i=0; i<4; i++)
			{
				if (ziomek.Z._Zestaw[i]._Figura>ziomek.Z._Zestaw[i+1]._Figura)
				{
					z=z+1;

					schowek=ziomek.Z._Zestaw[i];
					ziomek.Z._Zestaw[i]=ziomek.Z._Zestaw[i+1];
					ziomek.Z._Zestaw[i+1]=schowek;
				}
			}
		}
		while(z!=0);
		int k=0;
	for(int i=0;i<4;i++)
	{

		if ((ziomek.Z._Zestaw[i]._Figura)+1==ziomek.Z._Zestaw[i+1]._Figura)
		{
			k++;
		}


	}
	if (k==4)
	{
		return true;
	}
		return false;




}

bool GRA::CzyJestKolor(Gracz ziomek)
{

	int k=0;
	for(int i=0;i<1;i++)
	{
		for(int j=0; j<5;j++)
		{
			if (ziomek.Z._Zestaw[i]._Kolor==ziomek.Z._Zestaw[j]._Kolor && i!=j)
			{
				k++;
			}

		}
	}
	if (k==4)
	{
		return true;
	}

		return false;



}

bool GRA::CzyJestCzworka(Gracz ziomek)
{
	/*
	vector<int> pary;
		if (CzySaDwiePary(ziomek))
		{
			pary=ZnajdzPary(ziomek);

			if (pary[0]==pary[1])
			{
				return true; //kareta
			}
			else
			{
				return false;
			}




		}
		else
		{
			return false;
		}
		*/
	bool sukces=false;
	int iterator1, iterator2;
	int figura1,figura2;
	Karta schowek;
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i]._Figura==ziomek.Z._Zestaw[j]._Figura && i!=j)
			{
				sukces=true;
				iterator1=i;
				figura1=ziomek.Z._Zestaw[i]._Figura;
				iterator2=j;


			}

		}

	}
	int j=0;
	if (sukces==true)
	{
		schowek=ziomek.Z._Zestaw[iterator1];
		ziomek.Z._Zestaw[iterator1]=ziomek.Z._Zestaw[3];
		ziomek.Z._Zestaw[3]=schowek;
		schowek=ziomek.Z._Zestaw[iterator2];
		ziomek.Z._Zestaw[iterator2]=ziomek.Z._Zestaw[4];
		ziomek.Z._Zestaw[4]=schowek;
		for (int i=0; i<3; i++)
		{

				if(ziomek.Z._Zestaw[i]._Figura==figura1)
				{
					j++;

				}



		}

	}
	if (j==2)
		return true;

	return false;

}


bool GRA::CzyJestFul(Gracz ziomek)
{
	bool sukces=false;
	int iterator1, iterator2;
	int figura1,figura2;
	Karta schowek;
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i]._Figura==ziomek.Z._Zestaw[j]._Figura && i!=j)
			{
				sukces=true;
				iterator1=i;
				figura1=ziomek.Z._Zestaw[i]._Figura;
				iterator2=j;


			}

		}

	}
	int j=0;
	if (sukces==true)
	{
		schowek=ziomek.Z._Zestaw[iterator1];
		ziomek.Z._Zestaw[iterator1]=ziomek.Z._Zestaw[3];
		ziomek.Z._Zestaw[3]=schowek;
		schowek=ziomek.Z._Zestaw[iterator2];
		ziomek.Z._Zestaw[iterator2]=ziomek.Z._Zestaw[4];
		ziomek.Z._Zestaw[4]=schowek;
		for (int i=0; i<3; i++)
		{

				if(ziomek.Z._Zestaw[i]._Figura==figura1)
				{
					j++;

				}



		}

	}
	if (j==1)
	{
		for (int i=0; i<3 ;i++)
		{
			for (int s=0;s<3;s++)
			{
				if (ziomek.Z._Zestaw[i]._Figura==ziomek.Z._Zestaw[s]._Figura && i!=s && ziomek.Z._Zestaw[i]._Figura!=figura1)
				{
					return true;
				}

			}

		}
		return false;

	}
	return false;
}



		void GRA::PorownanieWPrzypadku0(Gracz &ziomek1, Gracz &ziomek2)
{
	int figura, figura2;
	figura=ZnajdzNajwyszaKarte(ziomek1);
	figura2=ZnajdzNajwyszaKarte(ziomek2);
				if (figura>figura2)
				{
					ziomek1.zwyciestwo=1;
					ziomek2.zwyciestwo=0;
				}
				if (figura<figura2)
				{
					ziomek1.zwyciestwo=0;
					ziomek2.zwyciestwo=1;
				}
				if (figura==figura2)
				{
					ziomek1.zwyciestwo=2;
					ziomek2.zwyciestwo=2;
				}
}


void GRA::PorownanieWPrzypadku1(Gracz &ziomek1, Gracz &ziomek2)
{
	int figura,figura2;
	figura=ZnajdzPare(ziomek1);
	figura2=ZnajdzPare(ziomek2);

					if (figura>figura2)
				{
					ziomek1.zwyciestwo=1;
					ziomek2.zwyciestwo=0;
				}
				if (figura<figura2)
				{
					ziomek1.zwyciestwo=0;
					ziomek2.zwyciestwo=1;
				}
				if (figura==figura2)
				{
					ziomek1.zwyciestwo=2;
					ziomek2.zwyciestwo=2;
				}
}

void GRA::PorownanieWPrzypadku2(Gracz &ziomek1, Gracz &ziomek2)
{
	vector<int> pary,pary2;
	pary=ZnajdzPary(ziomek1);
	pary2=ZnajdzPary(ziomek2);
	int najwyzsza, najwyzsza2;
	if (pary[0]>=pary[1])
	{
		najwyzsza=pary[0];
	}
	else
	{
		najwyzsza=pary[1];
	}

	if (pary2[0]>=pary2[1])
	{
		najwyzsza2=pary2[0];
	}
	else
	{
		najwyzsza2=pary2[1];
	}


	if (najwyzsza>najwyzsza2)
	{
		ziomek1.zwyciestwo=1;
		ziomek2.zwyciestwo=0;
	}
	if (najwyzsza<najwyzsza2)
	{
		ziomek1.zwyciestwo=0;
		ziomek2.zwyciestwo=1;
	}
	if (najwyzsza==najwyzsza2)
	{
		ziomek1.zwyciestwo=2;
		ziomek2.zwyciestwo=2;
	}



}

void GRA::PorownanieWPrzypadku3(Gracz &ziomek1, Gracz &ziomek2)
{
	int figura,figura2;
	figura=ZnajdzTrojke(ziomek1);
	figura2=ZnajdzTrojke(ziomek2);

			if (figura>figura2)
				{
					ziomek1.zwyciestwo=1;
					ziomek2.zwyciestwo=0;
				}
				if (figura<figura2)
				{
					ziomek1.zwyciestwo=0;
					ziomek2.zwyciestwo=1;
				}
				if (figura==figura2)
				{
					ziomek1.zwyciestwo=2;
					ziomek2.zwyciestwo=2;
				}

}

void GRA::PorownanieWPrzypadku4(Gracz &ziomek1, Gracz &ziomek2)
{
	int figura,figura2;
	figura=ZnajdzNajwyszaKarte(ziomek1);
	figura2=ZnajdzNajwyszaKarte(ziomek2);
	if (figura>figura2)
				{
					ziomek1.zwyciestwo=1;
					ziomek2.zwyciestwo=0;
				}
				if (figura<figura2)
				{
					ziomek1.zwyciestwo=0;
					ziomek2.zwyciestwo=1;
				}
				if (figura==figura2)
				{
					ziomek1.zwyciestwo=2;
					ziomek2.zwyciestwo=2;
				}
}


void GRA::PorownanieWPrzypadku5(Gracz &ziomek1, Gracz &ziomek2)
{
	PorownanieWPrzypadku4(ziomek1,ziomek2);
}

void GRA::PorownanieWPrzypadku6(Gracz &ziomek1, Gracz &ziomek2)
{

	cerr<<"BLAD! TA CZESC PROGRAMU JEST W BUDOWIE!";

}

void GRA::PorownanieWPrzypadku7(Gracz &ziomek1, Gracz &ziomek2)
{
	int figura,figura2;
	figura=ZnajdzPare(ziomek1);
	figura2=ZnajdzPare(ziomek2);
	if (figura>figura2)
				{
					ziomek1.zwyciestwo=1;
					ziomek2.zwyciestwo=0;
				}
				if (figura<figura2)
				{
					ziomek1.zwyciestwo=0;
					ziomek2.zwyciestwo=1;
				}
				if (figura==figura2)
				{
					ziomek1.zwyciestwo=2;
					ziomek2.zwyciestwo=2;
				}
}

void GRA::PorownanieWPrzypadku8(Gracz &ziomek1, Gracz &ziomek2)
{
	cerr<<"BLAD! TA CZESC PROGRAMU JEST W BUDOWIE!";
}



// Zwraca figure, ktora jest najwyzsza z kart.


int GRA::ZnajdzNajwyszaKarte(Gracz ziomek)
{
	int max;
	max=ziomek.Z._Zestaw[0]._Figura;

	for (int i=0; i<5;i++)
				{

						if(ziomek.Z._Zestaw[i]._Figura>=max)
						{
							max=ziomek.Z._Zestaw[i]._Figura;
						}

				}
	return max;
}


// Zwraca figure, ktora jest w parze.
int GRA::ZnajdzPare(Gracz ziomek)
{
		for (int i=0; i<5; i++)
		{
			for (int j=0; j<5;j++)
			{
				if(ziomek.Z._Zestaw[i].CzyTaSamaFigura(ziomek.Z._Zestaw[j]) && i!=j)
				{
					return ziomek.Z._Zestaw[i]._Figura;
				}

			}

		}
		cout<<"BLAD ZNALEZIENIA PARY!";
	return false;
}


// Zwraca wektor , ktory przechowuje figury, ktore sa w parach.
vector<int> GRA::ZnajdzPary(Gracz ziomek)
{
	vector<int> pary;
	int figura;
	figura=ZnajdzPare(ziomek);
	pary.push_back(figura);
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i].CzyTaSamaFigura(ziomek.Z._Zestaw[j]) && i!=j && ziomek.Z._Zestaw[i]._Figura!=figura)
			{
				pary.push_back(ziomek.Z._Zestaw[i]._Figura);
				return pary;
			}

		}

	}
		cerr<<"BLAD ZNALEZIENIA PAR!";
	return pary;
}

//Zwraca figure, ktora jest w trojce.
int GRA::ZnajdzTrojke(Gracz ziomek)
{
	Karta schowek;
	bool sukces=false;
	Karta pomoc;
	int iterator1,iterator2,figura;
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5;j++)
		{
			if(ziomek.Z._Zestaw[i].CzyTaSamaFigura(ziomek.Z._Zestaw[j]) && i!=j)
			{
				sukces=true;
				iterator1=i;
				iterator2=j;
				pomoc._Figura=ziomek.Z._Zestaw[i]._Figura;
			}


		}

	}

		schowek=ziomek.Z._Zestaw[iterator1];
		ziomek.Z._Zestaw[iterator1]=ziomek.Z._Zestaw[3];
		ziomek.Z._Zestaw[3]=schowek;
		schowek=ziomek.Z._Zestaw[iterator2];
		ziomek.Z._Zestaw[iterator2]=ziomek.Z._Zestaw[4];
		ziomek.Z._Zestaw[4]=schowek;
		for (int i=0; i<3; i++)
		{
			if(ziomek.Z._Zestaw[i]._Figura==pomoc._Figura)
			{
				figura=ziomek.Z._Zestaw[i]._Figura;
				return figura;
			}

		}
		return false;
}



/*

		zwyciestwo=0 - przegrana
		zwyciestwo=1 - wygrana
		zwyciestwo=2 - remis
		*/

void GRA::PorownajWyniki(Gracz &ziomek1, Gracz &ziomek2)
{
	PoliczUklady(ziomek1);
	PoliczUklady(ziomek2);

	if(ziomek1.uklad>ziomek2.uklad)
	{
		ziomek1.zwyciestwo=1;
		ziomek2.zwyciestwo=0;
	}
	if (ziomek1.uklad<ziomek2.uklad)
	{
		ziomek2.zwyciestwo=1;
		ziomek1.zwyciestwo=0;
	}
	if (ziomek1.uklad==ziomek2.uklad)
	{
		int co=ziomek1.uklad;
		switch (co)
		{
		case 0:
			{
				PorownanieWPrzypadku0(ziomek1,ziomek2);
				break;

			}
		case 1:
			{
				PorownanieWPrzypadku1(ziomek1, ziomek2);

				break;
			}
		case 2:
			{
				PorownanieWPrzypadku2(ziomek1,ziomek2);
				break;
			}
		case 3:
			{
				PorownanieWPrzypadku3(ziomek1,ziomek2);
				break;
			}
		case 4:
			{
				PorownanieWPrzypadku4(ziomek1,ziomek2);
				break;
			}
		case 5:
			{
				PorownanieWPrzypadku5(ziomek1,ziomek2);
				break;
			}
		case 6:
			{
				PorownanieWPrzypadku6(ziomek1,ziomek2); //UWAGA!!!!!! BRAK OBSLUGI FULA
				break;
			}
		case 7:
			{
				PorownanieWPrzypadku7(ziomek1,ziomek2);
				break;
			}
		case 8:
			{
				PorownanieWPrzypadku8(ziomek1,ziomek2);  //UWAGA!!!!!! BRAK OBSLUGI POKERA
				break;
			}
		default:
			{
				break;
			}


		}

	}


}




void GRA::Rozdaj(Gracz &gosc)
	{


			for (int i=0;i<5;i++)
			{

				GLOWNA.PobierzKarte(gosc.Z._Zestaw[i]);

			}




	}



void GRA::Potasuj()
{
	GLOWNA.Potasuj();
}


void GRA::RozdajKase(Gracz &ziomek, int ile)
{
	ziomek.hajs=ile;
}

void GRA::Decyzja(Gracz &ziomek)
{
	char wybor;
	cout<<endl<<"***** GRACZ "<<ziomek.nazwa<<" *****"<<endl;
	if(CzyJestPrzebicie==true)
	{
		cout<<endl<<"Stawka przebita o: "<<przebicie<<endl<<" $ Co robisz?";
	}
	cout<<endl<<"Aktualna stawka to: "<<AktualnaStawka<<" $";
	cout<<endl<<"Aktualna pula wynosi: "<<pula<< " $";
	cout<<endl<<"Podbijasz/czekasz (c), Przebijasz (p) czy pasujesz (X) ? ";
	cin>>wybor;
	switch (wybor)
	{
	case 'c':
		{
			if (AktualnaStawka>ziomek.hajs)
			{
				cout<<endl<<"Nie masz tyle pieniedzy! Grasz Va Banque!"<<endl;
				CzyJestPrzebicie=true;
				ziomek.obstawil=ziomek.hajs;
				ziomek.hajs=0;
				pula=pula+ziomek.obstawil;
			}
			else
			{
				CzyJestPrzebicie=true;
				ziomek.obstawil=AktualnaStawka;
				ziomek.hajs=ziomek.hajs-ziomek.obstawil;
				pula=pula+ziomek.obstawil;
			}
			ziomek.CzyPAS=false;
			cout<<endl<<"Gracz "<<ziomek.nazwa<<" stawia: "<<ziomek.obstawil<<" $"<<endl;
			break;
		}
	case 'p':
		{
			CzyJestPrzebicie=true;
			if (AktualnaStawka>ziomek.hajs)
			{
				cout<<endl<<"Nie masz tyle pieniedzy! Grasz Va Banque!"<<endl;
				CzyJestPrzebicie=false;
				ziomek.obstawil=ziomek.hajs;
				ziomek.hajs=0;
				pula=pula+ziomek.obstawil;
				AktualnaStawka=ziomek.obstawil;
			}
			else
			{
				cout<<endl<<"O ile przebijasz? ";
				cin>>przebicie;


				ziomek.obstawil=AktualnaStawka+przebicie;
 				pula=pula+ziomek.obstawil;
				ziomek.hajs=ziomek.hajs-ziomek.obstawil;
				AktualnaStawka=ziomek.obstawil;
			}
			cout<<endl<<"Gracz "<<ziomek.nazwa<<" stawia: "<<ziomek.obstawil<<" $"<<endl;
			ziomek.CzyPAS=false;
			break;

		}
	case 'X':
		{
			CzyJestPrzebicie=false;
			ziomek.CzyPAS=true;
			break;
		}
	default:
		{
			cout<<endl<<"ZLY PRZYCISK!"<<endl;
			break;
		}
	}


}
GRA::GRA()
{
	pula=0;
	przebicie=0;
	AktualnaStawka=0;
	CzyJestPrzebicie=false;

}

void GRA::DecyzjaZCzekaniem(Gracz &ziomek)
{
	char wybor;
	cout<<endl<<"***** GRACZ "<<ziomek.nazwa<<" *****"<<endl;
	if(CzyJestPrzebicie==true)
	{
		cout<<endl<<"Stawka przebita o: "<<przebicie<<endl<<" $ Co robisz?";
	}
	cout<<endl<<"Aktualna stawka to: "<<AktualnaStawka<<" $";
	cout<<endl<<"Aktualna pula wynosi: "<<pula<< " $";
	cout<<endl<<"Czekasz (c), Przebijasz (p) czy pasujesz (X) ? ";
	cin>>wybor;
	switch (wybor)
	{
	case 'c':
		{


				CzyJestPrzebicie=false;
				//ziomek.obstawil=0;
				//pula=pula+ziomek.obstawil;
				ziomek.obstawil=AktualnaStawka;
				//ziomek.hajs=ziomek.hajs-ziomek.obstawil;

			ziomek.CzyPAS=false;
			cout<<endl<<"Gracz "<<ziomek.nazwa<<" czeka! "<<endl;
			break;
		}
	case 'p':
		{
			CzyJestPrzebicie=true;
			if (AktualnaStawka>ziomek.hajs)
			{
				cout<<endl<<"Nie masz tyle pieniedzy! Grasz Va Banque!"<<endl;
				CzyJestPrzebicie=false;
				ziomek.obstawil=ziomek.hajs;
				ziomek.hajs=0;
				pula=pula+ziomek.obstawil;
				AktualnaStawka=ziomek.obstawil;
			}
			else
			{
				cout<<endl<<"O ile przebijasz? ";
				cin>>przebicie;


				ziomek.obstawil=AktualnaStawka+przebicie;
 				pula=pula+ziomek.obstawil;
				ziomek.hajs=ziomek.hajs-ziomek.obstawil;
				AktualnaStawka=ziomek.obstawil;
			}
			cout<<endl<<"Gracz "<<ziomek.nazwa<<" stawia: "<<ziomek.obstawil<<" $"<<endl;
			ziomek.CzyPAS=false;
			break;

		}
	case 'X':
		{
			CzyJestPrzebicie=false;
			ziomek.CzyPAS=true;
			break;
		}
	default:
		{
			cout<<endl<<"ZLY PRZYCISK!"<<endl;
			break;
		}
	}

}
