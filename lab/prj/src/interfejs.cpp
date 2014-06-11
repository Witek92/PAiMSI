#include <iostream>
#include <string>
#include "interfejs.h"


/*!
* \file
* \brief Definicja metody klasy Interfejs
*
* Zawiera definicje metod klasy Interfejs.
*/

void Interfejs::Dzialaj()
{
	int i;
	cout<<"         WITAMY W WITEK's POKER CHAMPIONSHIP!";
	char przycisk='a';
	while (przycisk!='q')
	{

		WyswietlIntro();
		cout<<endl<<"Co chcesz zrobic?"<<endl;
		cin>>przycisk;
		switch(przycisk)
		{
		case 'g':
			{
				NowaGra();
				break;
			}
		case 'i':
			{
				WyswietlInstrukcje();
				break;
			}
		case 'c':
			{
				system( "cls" );
				break;
			}
		case 'q':
			{
				cout<<"DO WIDZENIA!"<<endl<<endl;
				break;
			}
		default:
			{
				cout<<endl<<"Wybrana opcja nie istnieje, sprobuj jeszcze raz!";
			}



		}
	}
}



void Interfejs::NowaGra()
{
	string nazwagracza;


				//Wybor Ilosci graczy ludzi i komputerow + nadanie nazw

				cout<<endl<<"         Wybierz ilosc graczy (ludzi): ";
				cin>>IloscGraczy;
				while(IloscGraczy>6)
				{
					cout<<endl<<"PODALES ZA DUZA ILOSC,TYLE TO SIE PRZECIEZ PRZY STOLE NIE ZMIESCI...";
					cin>>IloscGraczy;
				}
				Gracze=new Gracz [IloscGraczy];


					cout<<endl<<"         Wybierz ilosc graczy CPU: ";
				cin>>IloscGraczyCPU;
				while(IloscGraczyCPU>6)
				{
					cout<<endl<<"PODALES ZA DUZA ILOSC,TYLE TO SIE PRZECIEZ PRZY STOLE NIE ZMIESCI...";
					cin>>IloscGraczyCPU;
				}
				Komputery=new CPU [IloscGraczyCPU];
				PobierzHajsPoczatkowy();

				//tasowanie talii.
				GIERKA.Potasuj();

				//Rozdanie kart graczom.
				int j=0;
				for (int i=0; i<IloscGraczy+IloscGraczyCPU;i++)
				{
					if(i<IloscGraczy)
					{
						cout<<endl<<"Podaj imie gracza nr "<<i+1<<endl;
						cin>>nazwagracza;
						Gracz g(nazwagracza);

						Gracze[i]=g;
						GIERKA.Rozdaj(Gracze[i]);
					}
					else
					{

						cout<<endl<<"Podaj imie gracza CPU nr "<<j+1<<endl;
						cin>>nazwagracza;
						CPU c(nazwagracza);


						Komputery[j]=c;
						GIERKA.Rozdaj(Komputery[j].Komputer);
						j++;
					}

				}

				int licznik=0;
				for(int i=0;i<IloscGraczy;i++)
				{
					GIERKA.RozdajKase(Gracze[i],hajspoczatkowy);

					PrzydzielPoczatkowePule(Gracze[i]);


					licznik++;
				}
				for (int i=0;i<IloscGraczyCPU;i++)
				{
					GIERKA.RozdajKase(Komputery[i].Komputer,hajspoczatkowy);
					PrzydzielPoczatkowePule(Komputery[i].Komputer);

					licznik++;
				}



				int zmienna=0;
				bool GlobalPrzebicie=false;
				/*
				while (GlobalPrzebicie==true || zmienna==0)
				{
					zmienna=1;
					/////
					for (int i=0; i<IloscGraczy;i++)
					{
						if (Gracze[i].CzyPAS==true)
						{
							UsunGracza(Gracze[i]);
						}
						if (i<=1)
						{
							cout<<endl<<"Gracz "<<Gracze[i].nazwa<<" stawia poczatkowa pule: "<<Gracze[i].obstawil<<" $"<<endl;
						}

						cout<<endl<<"***** GRACZ "<<Gracze[i].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[i].hajs<<" $"<<endl;
						cout<<endl<<"Karty "<<" : "<<Gracze[i].Z<<endl;
						if (Gracze[i].CzyPAS==true)
						{
							UsunGracza(Gracze[i]);
							i--;
						}
						else
						{
							if ((i>1 && GlobalPrzebicie==false) || GlobalPrzebicie==true)
							{
								cout<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[i].hajs<<" $"<<endl;
								cout<<endl<<"Karty "<<" : "<<Gracze[i].Z<<endl;
								GIERKA.Decyzja(Gracze[i]);
							}
							if (GIERKA.CzyJestPrzebicie)
								GlobalPrzebicie=true;
						}

					}
				}
				zmienna=0;
				GlobalPrzebicie=false;
				while (GlobalPrzebicie==true || zmienna==0)
				{
					zmienna=1;
					for(int i=0;i<IloscGraczy;i++)
					{
						if (Gracze[i].CzyPAS==true)
						{
							UsunGracza(Gracze[i]);
						}
						cout<<endl<<"***** GRACZ "<<Gracze[i].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[i].hajs<<" $"<<endl;
						cout<<endl<<"Karty "<<" : "<<Gracze[i].Z<<endl;
						GIERKA.Decyzja(Gracze[i]);
						if (Gracze[i].CzyPAS==true)
						{
							UsunGracza(Gracze[i]);
							i--;
						}
						else
						{
							cout<<endl<<"***** GRACZ "<<Gracze[i].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[i].hajs<<" $"<<endl;
							cout<<endl<<"Karty "<<" : "<<Gracze[i].Z<<endl;
							GIERKA.Wymiana(Gracze[i]);
							cout<<endl<<"Karty "<<Gracze[i].nazwa<<" po wymianie : "<<Gracze[i].Z<<endl<<endl<<endl<<endl;
						}

					}
				/////
				}

				while (GlobalPrzebicie==true)
				{
					for (int i=0; i<IloscGraczy; i++)
					{
						cout<<endl<<"***** GRACZ "<<Gracze[i].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[i].hajs<<" $"<<endl;
						cout<<endl<<"Karty "<<" : "<<Gracze[i].Z<<endl;
						GIERKA.Decyzja(Gracze[i]);
					}

				}
				*/
				/////// CPU
				zmienna=0;
				int it=0;
				int przebijanie=0;
				int stan=0;
				bool usuniecie=false;
				bool *usuniecieCPU=new bool [IloscGraczyCPU];
				bool wymiana=false;
				bool *wymianaCPU=new bool [IloscGraczyCPU];
				for (int i=0;i<IloscGraczyCPU;i++)
				{
					usuniecieCPU[i]=false;
				}
				for (int i=0;i<IloscGraczyCPU;i++)
				{
					wymianaCPU[i]=false;
				}

				for (int i=0; i<IloscGraczy;i++)
				{
					cout<<endl<<"* Gracz "<<Gracze[0].nazwa<<" stawia poczatkowa pule: "<<Gracze[0].obstawil<<" $"<<endl;
				}
				for (int i=0;i<IloscGraczyCPU;i++)
				{
					cout<<endl<<"* Gracz CPU "<<Komputery[i].Komputer.nazwa<<" stawia poczatkowa pule: "<<Komputery[i].Komputer.obstawil<<" $"<<endl;
				}


				while (stan<3)
				{
					if (Gracze[0].CzyPAS==true)
					{
						if (usuniecie==false)
						UsunGracza(Gracze[0]);
						if (IloscGraczyCPU==1)
						{
							stan=5;
							break;
							break;
						}

						usuniecie=true;
					}
					else
					{
							if (IloscGraczyCPU==0)
							{
								stan=5;
								break;
								break;
							}

							switch(stan)
							{
							case 0:
								{


									if(GIERKA.CzyJestPrzebicie)
									{
										przebijanie=0;
										GlobalPrzebicie=true;
									}
										cout<<endl<<endl<<"***** GRACZ "<<Gracze[0].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[0].hajs<<" $"<<endl;
										cout<<endl<<"Karty Gracza "<<Gracze[0].nazwa<<" : "<<endl<<Gracze[0].Z<<endl;
										if (GIERKA.AktualnaStawka!=Gracze[0].obstawil)
											GIERKA.Decyzja(Gracze[0]);
										else
											GIERKA.DecyzjaZCzekaniem(Gracze[0]);
										przebijanie++;


										if (przebijanie==IloscGraczy+IloscGraczyCPU)
										{
											stan++;
											przebijanie=0;
											GlobalPrzebicie=false;
										}




									break;
								}
							case 1:
								{

									if (wymiana==false)
									{
										wymiana=true;
										cout<<endl<<endl<<"***** GRACZ "<<Gracze[0].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[0].hajs<<" $"<<endl;
										cout<<endl<<"Karty Gracza "<<Gracze[0].nazwa<<" : "<<endl<<Gracze[0].Z<<endl;
										GIERKA.Wymiana(Gracze[0]);
										cout<<endl<<"Karty Gracza "<<Gracze[0].nazwa<<" po wymianie : "<<endl<<Gracze[0].Z<<endl<<endl;
										if (GIERKA.AktualnaStawka!=Gracze[0].obstawil)
											GIERKA.Decyzja(Gracze[0]);
										else
											GIERKA.DecyzjaZCzekaniem(Gracze[0]);
										przebijanie++;

										if (przebijanie==IloscGraczy+IloscGraczyCPU)
										{
											stan++;
											przebijanie=0;
											GlobalPrzebicie=false;
										}
									}
									else
									{
										cout<<endl<<endl<<"***** GRACZ "<<Gracze[0].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[0].hajs<<" $"<<endl;
										cout<<endl<<"Karty Gracza "<<Gracze[0].nazwa<<" : "<<endl<<Gracze[0].Z<<endl;
										if (GIERKA.AktualnaStawka!=Gracze[0].obstawil)
											GIERKA.Decyzja(Gracze[0]);
										else
											GIERKA.DecyzjaZCzekaniem(Gracze[0]);
										przebijanie++;
										if(przebijanie==IloscGraczy+IloscGraczyCPU)
										{
											stan++;
											przebijanie=0;
											GlobalPrzebicie=false;
										}
									}

									break;
								}
							case 2:
								{
										if(GIERKA.CzyJestPrzebicie)
										{
											przebijanie=0;
											GlobalPrzebicie=true;
										}
										if(GlobalPrzebicie==true)
										{
											cout<<endl<<endl<<"***** GRACZ "<<Gracze[0].nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Gracze[0].hajs<<" $"<<endl;
											cout<<endl<<"Karty Gracza "<<Gracze[0].nazwa<<" : "<<endl<<Gracze[0].Z<<endl;
											if (GIERKA.AktualnaStawka!=Gracze[0].obstawil)
												GIERKA.Decyzja(Gracze[0]);
											else
												GIERKA.DecyzjaZCzekaniem(Gracze[0]);
											przebijanie++;


											if (przebijanie==IloscGraczy+IloscGraczyCPU)
											{
												stan++;
												przebijanie=0;
												GlobalPrzebicie=false;
											}
										}
										else
											stan=5;
									break;
								}
							default:
								{
									break;
								}


							}




					}

					for (int i=0; i<IloscGraczyCPU;i++)
					{
						if (Komputery[i].Komputer.CzyPAS==true)
						{
							if(usuniecieCPU[i]==false)
							UsunGracza(Komputery[i]);
							if (IloscGraczyCPU==1 && IloscGraczy==0)
						{
							stan=5;
							break;
							break;
						}
							usuniecieCPU[i]=true;
							i--;
						}

						else
						{
							if (IloscGraczyCPU==1 && IloscGraczy==0)
							{
								stan=5;
								break;
								break;
							}
							switch(stan)
							{
							case 0:
								{



										if(GIERKA.CzyJestPrzebicie)
										{
											GlobalPrzebicie=true;
											przebijanie=0;
										}

										cout<<endl<<endl<<"***** GRACZ CPU "<<Komputery[i].Komputer.nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Komputery[i].Komputer.hajs<<" $"<<endl;
										cout<<endl<<"Karty gracza CPU "<<Komputery[i].Komputer.nazwa<<" : "<<endl<<Komputery[i].Komputer.Z<<endl;


											if (GIERKA.AktualnaStawka!=Komputery[i].Komputer.obstawil)
												Komputery[i].Decyzja(GIERKA);
											else
												Komputery[i].DecyzjaZCzekaniem(GIERKA);





										przebijanie++;

										if (przebijanie==IloscGraczy+IloscGraczyCPU)
										{
											stan++;
											przebijanie=0;
											GlobalPrzebicie=false;
										}

								break;
								}




							case 1:
								{


										if (wymianaCPU[i]==false)
										{
											wymianaCPU[i]=true;
											cout<<endl<<endl<<"***** GRACZ CPU "<<Komputery[i].Komputer.nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Komputery[i].Komputer.hajs<<" $"<<endl;
											cout<<endl<<"Karty gracza CPU "<<Komputery[i].Komputer.nazwa<<" : "<<endl<<Komputery[i].Komputer.Z<<endl;
											Komputery[i].Wymiana(GIERKA);
											cout<<endl<<"Karty gracza CPU "<<Komputery[i].Komputer.nazwa<<" po wymianie : "<<endl<<Komputery[i].Komputer.Z<<endl<<endl;
											if (GIERKA.AktualnaStawka!=Komputery[i].Komputer.obstawil)
												Komputery[i].Decyzja(GIERKA);
											else
												Komputery[i].DecyzjaZCzekaniem(GIERKA);
											przebijanie++;

											if (przebijanie==IloscGraczy+IloscGraczyCPU)
											{
												stan++;
												przebijanie=0;
												GlobalPrzebicie=false;
											}
										}
										else
										{
											cout<<endl<<endl<<"***** GRACZ CPU "<<Komputery[i].Komputer.nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Komputery[i].Komputer.hajs<<" $"<<endl;
											cout<<endl<<"Karty gracza CPU "<<Komputery[i].Komputer.nazwa<<" : "<<endl<<Komputery[i].Komputer.Z<<endl;
											if (GIERKA.AktualnaStawka!=Komputery[i].Komputer.obstawil)
												Komputery[i].Decyzja(GIERKA);
											else
												Komputery[i].DecyzjaZCzekaniem(GIERKA);
											przebijanie++;

											if (przebijanie==IloscGraczy+IloscGraczyCPU)
											{
												stan++;
												przebijanie=0;
												GlobalPrzebicie=false;
											}
										}

									break;
								}
							case 2:
								{
										if(GIERKA.CzyJestPrzebicie)
										{
											przebijanie=0;
											GlobalPrzebicie=true;
										}
										if (GlobalPrzebicie==true)
										{
											cout<<endl<<endl<<"***** GRACZ CPU "<<Komputery[i].Komputer.nazwa<<" *****"<<endl<<"Ilosc dostepnych pieniedzy: "<<Komputery[i].Komputer.hajs<<" $"<<endl;
											cout<<endl<<"Karty gracza CPU "<<Komputery[i].Komputer.nazwa<<" : "<<endl<<Komputery[i].Komputer.Z<<endl;
											if (GIERKA.AktualnaStawka!=Komputery[i].Komputer.obstawil)
												Komputery[i].Decyzja(GIERKA);
											else
												Komputery[i].DecyzjaZCzekaniem(GIERKA);
											przebijanie++;


											if (przebijanie==IloscGraczy+IloscGraczyCPU)
											{
												stan++;
												przebijanie=0;
											}
										}
										else
											stan=5;
									break;
								}
							default:
								{
									break;
								}

							}
						}
					}


				}














				Gracz wygrany;
				if ((IloscGraczy==1 && IloscGraczyCPU==0))
				{
					wygrany=Gracze[0];
					cout<<endl<<endl<<"WYGRAL: "<<wygrany.nazwa<<" z ukladem: "<<endl;
					WyswietlUklad(wygrany);
					cout<<endl;
					cout<<"          i zgarnia pule w wysokosci "<<GIERKA.pula<<" $ !!!"<<endl;
				}
				else if (IloscGraczyCPU==1 && IloscGraczy==0)
				{
					wygrany=Komputery[0].Komputer;
					cout<<endl<<endl<<"WYGRAL: "<<wygrany.nazwa<<" z ukladem: "<<endl;
					WyswietlUklad(wygrany);
					cout<<endl;
					cout<<"          i zgarnia pule w wysokosci "<<GIERKA.pula<<" $ !!!"<<endl;
				}
				else
				{
					wygrany=WskazWygranego();
					cout<<endl<<endl<<"WYGRAL: "<<wygrany.nazwa<<" z ukladem: "<<endl;
					WyswietlUklad(wygrany);
					cout<<endl;
					cout<<"          i zgarnia pule w wysokosci "<<GIERKA.pula<<" $ !!!"<<endl;
				}





				for (int i=0; i<IloscGraczy;i++)
				{
					cout<<endl<<"Gracz: "<<Gracze[i].nazwa<<" mial nastepujaca kombinacje: "<<endl;
					WyswietlUklad(Gracze[i]);
					cout<<endl;
				}
				for (int i=0; i<IloscGraczyCPU;i++)
				{
					cout<<endl<<"Gracz: "<<Komputery[i].Komputer.nazwa<<" mial nastepujaca kombinacje: "<<endl;
					WyswietlUklad(Komputery[i].Komputer);
					cout<<endl;
				}




}

Gracz Interfejs::WskazWygranego()
{

	Gracz wygrany("NIEWIADOMO");
	GIERKA.PoliczUklady(Gracze[0]);
				wygrany=Gracze[0];
				for (int i=1; i<IloscGraczy;i++)
				{


							GIERKA.PorownajWyniki(wygrany,Gracze[i]);

							if (wygrany.zwyciestwo!=1)
							{
								wygrany=Gracze[i];
							}




				}

				for (int i=0; i<IloscGraczyCPU;i++)
				{

							GIERKA.PorownajWyniki(wygrany,Komputery[i].Komputer);
						if (wygrany.zwyciestwo!=1)
							{
								wygrany=Komputery[i].Komputer;
							}

				}




	return wygrany;
	/*
	for(int i=0; i<IloscGraczy;i++)
	{
		if(Gracze[i].zwyciestwo==2)
		{
			cout<<endl<<"REMIS"<<endl;

			return Gracze[i].nazwa;
		}

	}
	for(int i=0; i<IloscGraczy;i++)
	{
		if(Komputery[i].Komputer.zwyciestwo==2)
		{
			cout<<endl<<"REMIS"<<endl;

			return Komputery[i].Komputer.nazwa;
		}

	}
	*/


}



















void Interfejs::WyswietlUklad(Gracz ziomek)
{
	switch (ziomek.uklad)
	{
	case 0:
		{
			cout<<endl<<"NAJWYZSZA KARTA!";
			break;

		}
	case 1:
		{
			cout<<endl<<"PARA!";
			break;

		}
	case 2:
		{
			cout<<endl<<"DWIE PARY!";
			break;

		}
	case 3:
		{
			cout<<endl<<"TROJKA!";
			break;

		}
	case 4:
		{
			cout<<endl<<"STRIT!";
			break;

		}
	case 5:
		{
			cout<<endl<<"KOLOR!";
			break;

		}
	case 6:
		{
			cout<<endl<<"FULL!";
			break;

		}
	case 7:
		{
			cout<<endl<<"KARETA!";
			break;

		}
	case 8:
		{
			cout<<endl<<"POKER!!!!!! BRAWO !!!";
			break;
		}
	default:
		{
			cout<<endl<<"NIE MASZ ZADNEGO UKLADU!!!";
			break;
		}


	}

}



void Interfejs::WyswietlIntro()
{
	cout<<endl<<" g - Aby rozpoczac nowa gre."<<endl;
		cout<<" i - Aby zapoznac sie z instrukcja gry. (W kazdym dowolnym momencie.)"<<endl;
		cout<<" c - Aby wyczyscic terminal. (W kazdym dowolnym momencie.) "<<endl;
		cout<<" d - (UWAGA tylko w czasie gry!) Aby wyswietlic swoje karty."<<endl;
		cout<<" q - Aby zakonczyc. "<<endl;
}



void Interfejs::WyswietlInstrukcje()
{
	cout<<endl<<"                 INSTRUKCJA OBSLUGI              "<<endl;
				cout<<"Po podaniu ilosci graczy (max 6) nalezy podac ich nazwy. Po obejrzeniu swojego zestawu kart, nalezy podjac decyzje, czy chcemy wymieniac karty (y - tak, lub n - nie)."<<endl;
				cout<<"Gdy odpowiedz jest pozytywna, nalezy podac liczby porzadkowe wybranych kart, liczac od lewej strony, po kolei, bez przecinkow. (Maksymalna dozwolona ilosc kart do wymienienia to 3)."<<endl;
				cout<<"Po wymianach, osoba z najlepszym zestawem kart (wg zasad Pokera) wygrywa. Milej zabawy!!"<<endl;
}


void Interfejs::PobierzHajsPoczatkowy()
{
	cout<<endl<<"Podaj poczatkowa stawke pieniedzy (min 500 - max 100 000 $): ";
	cin>>hajspoczatkowy;
}

void Interfejs::PrzydzielPoczatkowePule0(Gracz &ziomek)
{
	ziomek.obstawil=50;
	GIERKA.pula=GIERKA.pula+ziomek.obstawil;
	GIERKA.AktualnaStawka=50;
	ziomek.hajs=ziomek.hajs-50;
}
void Interfejs::PrzydzielPoczatkowePule1(Gracz &ziomek)
{
	ziomek.obstawil=100;
	GIERKA.pula=GIERKA.pula+ziomek.obstawil;
	GIERKA.AktualnaStawka=100;
	ziomek.hajs=ziomek.hajs-100;
}


void Interfejs::UsunGracza(Gracz &ziomek)
{
	int iterator;
	Gracz schowek;
	for(int i=0; i<IloscGraczy;i++)
	{
		if(ziomek.nazwa==Gracze[i].nazwa)
		{
			iterator=i;
		}

	}
	for (int i=iterator; i<IloscGraczy-1;i++)
	{
		schowek=Gracze[i];
		Gracze[i]=Gracze[i+1];
		Gracze[i+1]=schowek;
	}
	IloscGraczy--;

}



void Interfejs::UsunGracza(CPU &Komp)
{
	int iterator;
	Gracz schowek;
	for(int i=0; i<IloscGraczyCPU;i++)
	{
		if(Komp.Komputer.nazwa==Komputery[i].Komputer.nazwa)
		{
			iterator=i;
		}

	}
	for (int i=iterator; i<IloscGraczyCPU-1;i++)
	{
		schowek=Komputery[i].Komputer;
		Komputery[i].Komputer=Komputery[i+1].Komputer;
		Komputery[i+1].Komputer=schowek;
	}
	IloscGraczyCPU--;

}




void Interfejs::PrzydzielPoczatkowePule(Gracz &ziomek)
{
	ziomek.obstawil=100;
	GIERKA.pula=GIERKA.pula+ziomek.obstawil;
	GIERKA.AktualnaStawka=100;
	ziomek.hajs=ziomek.hajs-100;
}

