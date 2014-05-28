#include "NWP.h"


/*!
	Konstruktor pobiera rozmiary pobranych stringow i na ich podstawie tworzy adekwatna macierz.
*/
NWP::NWP(string x, string y)
{
	m=x.size();
	n=y.size();
	X=x;
	Y=y;
	C=new int*[m+1];
	for(int i=0;i<m+1;i++)
		C[i]=new int [n+1];

}

NWP::NWP()
{

}

/*!
	\return C[m][n] - czyli wartosc dlugosci wspolnego najdluzszego podciagu.( Zawsze ostatni element macierzy).
*/
int NWP::PoliczDlugoscPodciagu()
{
	
 
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         C[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         C[i][j] = C[i-1][j-1] + 1;
  
       else
         C[i][j] = max(C[i-1][j], C[i][j-1]);
     }
   }
    
   WyswietlC();
   return C[m][n];

}



int NWP::max(int a, int b)
{
    return (a > b)? a : b;
}


void NWP::WyswietlC()
{
	cout<<endl<<"*********************************************"<<endl<<endl<<"Macierz dla slow: "<<X<<" (pionowa os) oraz "<<Y<<" (pozioma os) :"<<endl;
	for (int i=0; i<=m; i++)
	{
		for ( int j=0; j<=n; j++)
		{
			cout<<" "<<C[i][j]<<" ";
		}
		cout<<endl;

	}

}

/*!
	Funkcja postepuje wedlug algorytmu, ktory idzie od ostatniej komorki [m][n] do zerowej dwoma sposobami:
	1. dopoki nie dojdzie do konca, jesli w danej komorce znaki sa takie same, znak dodany jest do NWP i nastepuje przejscie do sasiada na ukos. Jesli nie sa takie same, to jesli sasiad na gorze jest wiekszy od
	tego z lewej, algorytm idzie do gory, w przeciwnym razie idzie w lewo.
	2. dopoki nie dojdzie do konca, jesli w danej komorce znaki sa takie same, znak dodany jest do NWP i nastepuje przejscie do sasiada na ukos. Jesli nie sa takie same, to jesli sasiad na gorze jest mniejszy od
	tego z lewej, algorytm idzie w lewo, w przeciwnym razie idzie w gore.
*/
void NWP::WyswietlNajdluzszyPodciag()
{

   int k = C[m][n];
   char *nwp=new char [k+1];
   nwp[k] = '\0'; 
   int i = m, j = n;

   while (i > 0 && j > 0)
   {
     
      if (X[i-1] == Y[j-1])
      {
          nwp[k-1] = X[i-1]; 
          i--; j--; k--;     
      }
 
    
      else if (C[i-1][j] > C[i][j-1])
         i--;
      else
         j--;
   }
 
   k = C[m][n];
   char *nwp2=new char [k+1];
   nwp2[k] = '\0'; 
 
   i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          nwp2[k-1] = Y[j-1]; 
          i--; j--; k--;     
      }

      else if (C[i-1][j] < C[i][j-1])
         j--;
      else
         i--;
   }
 string g=nwp;
 string g2=nwp2;

   if (g!=g2)
   {
	   cout << "Najdluzszy wspolny podciag dla slow: " << X << " i " << Y << " to: " << nwp<<endl;
	   cout << "Druga mozliwosc najdluzszego wspolnego podciagu slow " << X << " i " << Y << " to: " << nwp2<<endl<<endl;
   }
   else if (g==g2 && !(g.empty() && g2.empty()))
	   cout << "Najdluzszy wspolny podciag dla slow: " << X << " i " << Y << " to: " << nwp<<endl<<endl;
   else
	   cout<<endl<<"BRAK WSPOLNEGO PODCIAGU"<<endl<<endl;
   
}
