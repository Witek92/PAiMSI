#include <iostream>
#include "karta.h"

/*!
* \file
* \brief Definicja metody klasy Karta.
*
* Zawiera definicje metod klasy Karta.
*/


using namespace std;

int Karta::UdostepnijKolor()
{
	return _Kolor;
}

int Karta::UdostepnijFigure()
{
	return _Figura;
}

bool Karta::CzyTenSamKolor(Karta k1)
{
	if (k1._Kolor==_Kolor)
	{
		return true;
	}
	return false;


}

bool Karta::CzyTaSamaFigura(Karta k1)
{
	if (k1._Figura==_Figura)
	{
		return true;
	}
		return false;

}


ostream &operator << (ostream &Ekran, Karta k)
{
	char kar;
	switch (k._Figura)
	{
	case 0:
		{
			Ekran<<" 2 ";
			break;
		}
	case 1:
		{
			Ekran<<" 3 ";
			break;
		}
	case 2:
		{
			Ekran<<" 4 ";
			break;
		}
	case 3:
		{
			Ekran<<" 5 ";
			break;
		}
	case 4:
		{
			Ekran<<" 6 ";
			break;
		}
	case 5:
		{
			Ekran<<" 7 ";
			break;
		}
	case 6:
		{
			Ekran<<" 8 ";
			break;
		}
	case 7:
		{
			Ekran<<" 9 ";
			break;
		}
	case 8:
		{
			Ekran<<" 10 ";
			break;
		}
	case 9:
		{
			Ekran<<" JOPEK ";
			break;
		}
	case 10:
		{
			Ekran<<" DAMA ";
			break;
		}
	case 11:
		{
			Ekran<<" KROL ";
			break;
		}
	case 12:
		{
			Ekran<<" AS ";
			break;
		}
	default:
		{
			cout<<endl<<"Nieznana figura!!!"<<endl;
		}
	}

	switch (k._Kolor)
	{
	case 0:
		{
			kar=3;
			Ekran<<" "<<kar<<" ";
			break;
		}
	case 1:
		{
			kar=4;
			Ekran<<" "<<kar<<" ";
			break;
		}
	case 2:
		{
			kar=6;
			Ekran<<" "<<kar<<" ";
			break;
		}
	case 3:
		{
			kar=5;
			Ekran<<" "<<kar<<" ";
			break;
		}
	default:
		{
			cout<<endl<<"Brak takiego koloru!!!"<<endl;
		}
	}

	return Ekran;
}



bool Karta::CzyTaSamaKarta(Karta k1)
{
	if (CzyTaSamaFigura(k1) && CzyTenSamKolor(k1))
	{
		return true;
	}

		return false;


}



Karta::Karta(int kolor, int figura)
	{


		_Kolor=kolor;
		_Figura=figura;



		switch(kolor)
		{
		case 0:
			{
				kol=Serce;
				break;
			}
		case 1:
			{
				kol=Karo;
				break;
			}
		case 2:
			{
				kol=Pik;
				break;
			}
		case 3:
			{
				kol=Trefl;
				break;
			}
		default:
			{
				cout<<endl<<"BLAD konstruktora karty!!!"<<endl;
				break;
			}
		}
		switch (figura)
		{
		case 0:
			{
				fig=dwa;
				break;
			}
		case 1:
			{
				fig=trzy;
				break;
			}
		case 2:
			{
				fig=cztery;
				break;
			}
		case 3:
			{
				fig=piec;
				break;
			}
		case 4:
			{
				fig=szesc;
				break;
			}
		case 5:
			{
				fig=siedem;
				break;
			}
		case 6:
			{
				fig=osiem;
				break;
			}
		case 7:
			{
				fig=dziewiec;
				break;
			}
		case 8:
			{
				fig=dziesiec;
				break;
			}
		case 9:
			{
				fig=jopek;
				break;
			}
		case 10:
			{
				fig=dama;
				break;
			}
		case 11:
			{
				fig=krol;
				break;
			}
		case 12:
			{
				fig=as;
				break;
			}
		default:
			{
				cout<<endl<<"BLAD konstruktora figury karty!!!"<<endl;
				break;
			}
		}


	}

	Karta::Karta()
	{
		_Figura=0;
		_Kolor=0;
		fig=dwa;
		kol=Serce;


	}


	bool Karta::operator == (Karta k1)
	{
		if (CzyTaSamaKarta(k1))
		{
			return true;
		}

			return false;



	}

	bool Karta::operator != (Karta k1)
	{
		if (CzyTaSamaKarta(k1))
		{
			return false;
		}

			return true;


	}


		Karta &Karta::operator = (Karta k1)
		{

			_Kolor=k1._Kolor;
			_Figura=k1._Figura;

			return *this;
		}




		void Przepisz(Karta &k1, Karta k2)
		{
			//Kolor kolorek;
			//Figura figurka;
			//kolorek=k2._Kolor;
			//figurka=k2._Figura;
			k1._Kolor=k2._Kolor;
			k1._Figura=k2._Figura;
		}



	void Karta::PrzypiszKarcieWartosc(int kolor, int figura)
	{
			_Kolor=kolor;
			_Figura=figura;


		switch(kolor)
		{
		case 0:
			{
				kol=Serce;
				break;
			}
		case 1:
			{
				kol=Karo;
				break;
			}
		case 2:
			{
				kol=Pik;
				break;
			}
		case 3:
			{
				kol=Trefl;
				break;
			}
		default:
			{
				cout<<endl<<"BLAD konstruktora karty!!!"<<endl;
				break;
			}
		}
		switch (figura)
		{
		case 0:
			{
				fig=dwa;
				break;
			}
		case 1:
			{
				fig=trzy;
				break;
			}
		case 2:
			{
				fig=cztery;
				break;
			}
		case 3:
			{
				fig=piec;
				break;
			}
		case 4:
			{
				fig=szesc;
				break;
			}
		case 5:
			{
				fig=siedem;
				break;
			}
		case 6:
			{
				fig=osiem;
				break;
			}
		case 7:
			{
				fig=dziewiec;
				break;
			}
		case 8:
			{
				fig=dziesiec;
				break;
			}
		case 9:
			{
				fig=jopek;
				break;
			}
		case 10:
			{
				fig=dama;
				break;
			}
		case 11:
			{
				fig=krol;
				break;
			}
		case 12:
			{
				fig=as;
				break;
			}
		default:
			{
				cout<<endl<<"BLAD konstruktora figury karty!!!"<<endl;
				break;
			}
		}

	}

