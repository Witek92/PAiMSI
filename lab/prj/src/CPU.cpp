#include "CPU.h"
#include <ctime>
/*!
* \file
* \brief Definicja metody klasy CPU.
*
* Zawiera definicje metod klasy CPU.
*/
bool CPU::CzyBedzieWymienial(GRA &Game)
{
	Game.PoliczUklady(Komputer);

	if (Komputer.uklad>=3)
	{
		return false;
	}
	else
	{
		return true;
	}



}


CPU::CPU(string nazwa)
{

	Gracz pomoc(nazwa);
	Komputer=pomoc;
	p1=false;
	p2=false;
	p3=false;
}

CPU::CPU()
{
	iter=1;
	p1=false;
	p2=false;
	p3=false;
}


void CPU::Wymiana(GRA &Game)
{
	if(CzyBedzieWymienial(Game))
	{
		CoBedzieWymienial(Game);
	}


}



void CPU::CoBedzieWymienial(GRA &Game)
{

	Game.PoliczUklady(Komputer);
	switch (Komputer.uklad)
	{
		case 0:
			{
				WymianaDla0(Game);
				break;

			}
		case 1:
			{
				WymianaDla1(Game);

				break;
			}
		case 2:
			{
				WymianaDla2(Game);
				break;
			}
		case 3:
			{
				WymianaDla3(Game);
				break;
			}
		case 4:
			{

				break;
			}
		case 5:
			{

				break;
			}
		case 6:
			{

				break;
			}
		case 7:
			{

				break;
			}
		case 8:
			{

				break;
			}
		default:
			{
				break;
			}
	}

}


void CPU::WymianaDla0(GRA &Game)
{

	vector<int> sla;
	WskazindeksySlabych(Komputer,sla);
	for (int i=0; i<sla.size() && i<3; i++)
	{
		Game.Wymien(Komputer.Z._Zestaw[sla[i]]);
	}



}

void CPU::WskazindeksySlabych(Gracz ziomek, vector<int> &slabe)
{
	for ( int i=0;i<5;i++)
	{
		if (ziomek.Z._Zestaw[i]._Figura<8)
		{

			slabe.push_back(i);
		}

	}

}

void CPU::WymianaDla1(GRA &Game)
{
	int figura;
	vector<int> slabe;
	figura=Game.ZnajdzPare(Komputer);
	for ( int i=0;i<5;i++)
	{
		if (Komputer.Z._Zestaw[i]._Figura<8 && Komputer.Z._Zestaw[i]._Figura!=figura)
		{

			slabe.push_back(i);
		}

	}
	for (int i=0; i<slabe.size() && i<3; i++)
	{
		Game.Wymien(Komputer.Z._Zestaw[slabe[i]]);
	}
}

void CPU::WymianaDla2(GRA &Game)
{
	vector<int> pary;
	pary=Game.ZnajdzPary(Komputer);
	for ( int i=0;i<5;i++)
	{
		if (!(Komputer.Z._Zestaw[i]._Figura==pary[0] || Komputer.Z._Zestaw[i]._Figura==pary[1]))
		{
			Game.Wymien(Komputer.Z._Zestaw[i]);
		}

	}
}

void CPU::WymianaDla3(GRA &Game)
{
	int figura=Game.ZnajdzTrojke(Komputer);
	for (int i=0; i<5;i++)
	{
		if (Komputer.Z._Zestaw[i]._Figura!=figura && Komputer.Z._Zestaw[i]._Figura<8)
		{
			Game.Wymien(Komputer.Z._Zestaw[i]);
		}

	}

}

void CPU::Decyzja(GRA &Game)
{
	char wybor;
	cout<<endl<<"***** GRACZ CPU "<<Komputer.nazwa<<" *****"<<endl;
	if(Game.CzyJestPrzebicie==true)
	{
		cout<<endl<<"Stawka przebita o: "<<Game.przebicie<<endl<<" $";
	}
	cout<<endl<<"Aktualna stawka to: "<<Game.AktualnaStawka<<" $";
	cout<<endl<<"Aktualna pula wynosi: "<<Game.pula<< " $";
	switch (CoObstawi(Game))
	{
	case 'c':
		{
			if (Game.AktualnaStawka>Komputer.hajs)
			{
				Game.CzyJestPrzebicie=true;
				Komputer.obstawil=Komputer.hajs;
				Komputer.hajs=0;
				Game.pula=Game.pula+Komputer.obstawil;
			}
			else
			{
				Game.CzyJestPrzebicie=true;
				Komputer.obstawil=Game.AktualnaStawka;
				Komputer.hajs=Komputer.hajs-Komputer.obstawil;
				Game.pula=Game.pula+Komputer.obstawil;
			}
			Komputer.CzyPAS=false;
			cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" stawia: "<<Komputer.obstawil<<" $"<<endl;
			break;
		}
	case 'p':
		{

			if (Game.AktualnaStawka>Komputer.hajs)
			{
				Game.CzyJestPrzebicie=false;
				Komputer.obstawil=Komputer.hajs;
				Komputer.hajs=0;
				Game.pula=Game.pula+Komputer.obstawil;
				Game.AktualnaStawka=Komputer.obstawil;
				cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" stawia: "<<Komputer.obstawil<<" $"<<endl;
			}
			else
			{
				int costam=rand() % Komputer.hajs-0.1*Komputer.hajs + 100;
				Game.przebicie=costam;


				Komputer.obstawil=Game.AktualnaStawka+Game.przebicie;
 				Game.pula=Game.pula+Komputer.obstawil;
				Komputer.hajs=Komputer.hajs-Komputer.obstawil;
				Game.AktualnaStawka=Komputer.obstawil;
				Game.CzyJestPrzebicie=true;
				cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" przebija stawke o "<<Game.przebicie<<" i ostatecznie stawia: "<<Komputer.obstawil<<" $"<<endl;
			}

			Komputer.CzyPAS=false;
			break;

		}
	case 'X':
		{
			Game.CzyJestPrzebicie=false;
			Komputer.CzyPAS=true;
			cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" PASUJE!"<<endl;
			break;
		}
	default:
		{

			break;
		}
	}
}


char CPU::CoObstawi(GRA &Game)
{
	srand(time(NULL));
	char wybor='X';
	Game.PoliczUklady(Komputer);
	vector<int> figurki;
	if (Komputer.uklad==2)
	{
		figurki=Game.ZnajdzPary(Komputer);
	}
	if (p2==false)
	{
		random=rand() % 3 + 1;
		p2=true;
	}

	if(Komputer.uklad<3 && Komputer.uklad>=0  )
	{
		wybor='c';
	}
	if ((Komputer.uklad>=3 || (Komputer.uklad==2 && (figurki[0]>8 || figurki[1]>8))) && iter<=random && iter<4)
	{
		wybor='p';
		iter++;

	}

	if ((Komputer.uklad==0 && Game.ZnajdzNajwyszaKarte(Komputer)<8) || (Game.AktualnaStawka>Komputer.hajs/2 && (Komputer.uklad==1 || Komputer.uklad==0)))
	{
		wybor='X';
	}


	return wybor;

}

void CPU::DecyzjaZCzekaniem(GRA &Game)
{
	char wybor;
	cout<<endl<<"***** GRACZ CPU "<<Komputer.nazwa<<" *****"<<endl;
	if(Game.CzyJestPrzebicie==true)
	{
		cout<<endl<<"Stawka przebita o: "<<Game.przebicie<<endl<<" $";
	}
	cout<<endl<<"Aktualna stawka to: "<<Game.AktualnaStawka<<" $";
	cout<<endl<<"Aktualna pula wynosi: "<<Game.pula<< " $";
	switch (CoObstawi(Game))
	{
	case 'c':
		{

				Game.CzyJestPrzebicie=false;


				//Komputer.obstawil=0;
				//Komputer.hajs=Komputer.hajs-Komputer.obstawil;
				//Game.pula=Game.pula+Komputer.obstawil;
				Komputer.obstawil=Game.AktualnaStawka;

			Komputer.CzyPAS=false;
			cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" CZEKA! "<<endl;
			break;
		}
	case 'p':
		{

			if (Game.AktualnaStawka>Komputer.hajs)
			{
				Game.CzyJestPrzebicie=false;
				Komputer.obstawil=Komputer.hajs;
				Komputer.hajs=0;
				Game.pula=Game.pula+Komputer.obstawil;
				Game.AktualnaStawka=Komputer.obstawil;
				cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" stawia: "<<Komputer.obstawil<<" $"<<endl;
			}
			else
			{
				int costam=rand() % Komputer.hajs-0.1*Komputer.hajs + 100;
				Game.przebicie=costam;


				Komputer.obstawil=Game.AktualnaStawka+Game.przebicie;
 				Game.pula=Game.pula+Komputer.obstawil;
				Komputer.hajs=Komputer.hajs-Komputer.obstawil;
				Game.AktualnaStawka=Komputer.obstawil;
				Game.CzyJestPrzebicie=true;
				cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" przebija stawke o "<<Game.przebicie<<" i ostatecznie stawia: "<<Komputer.obstawil<<" $"<<endl;
			}

			Komputer.CzyPAS=false;
			break;

		}
	case 'X':
		{
			Game.CzyJestPrzebicie=false;
			Komputer.CzyPAS=true;
			cout<<endl<<"Gracz CPU "<<Komputer.nazwa<<" PASUJE!"<<endl;
			break;
		}
	default:
		{

			break;
		}
	}
}
