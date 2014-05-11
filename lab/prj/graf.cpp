#include "graf.h"


Graf::Graf(int rozmiar)
{
    this->IloscWierzcholkow = rozmiar;
    Q = new list<int>[rozmiar];
}
 /*! W ponizszej funkcji do listy opartej na tablicy Q (z indeksem wierzcholka 1.) zostaje dodany wierzcholek 2. (tworzy sie krawedz).
 */
void Graf::DodajKrawedz(int w1, int w2)
{
    Q[w1].push_back(w2); 
}
 /*! Zaimplementowany algorytm Bredth First Search dziala nastepujaco:
		- Wszystkie wierzcholki sa zaznaczone jako odwiedzone,
		- Tworzona jest kolejka dla wykonania algorytmu BFS
		- wybrane miejsce, od ktorego chcemy wykonac algorytm, jest zaznaczone jako odwiedzone i dodane do kolejki.
		- dopoki w kolejsce cos jest, z kolejki jest usuwany i wyswietlany kolejny wierzcholek
		- wszystkie graniczne wierzcholki wybranego wierzcholka zostaja zdekolejkowane
		- jesli jakis graniczny wierzcholek nie zostal odwiedzony, zaznaczony jest jako odwiedzony i dodany do kolejki.

		iterator i - uzywany do wyluskania wszystkich granicznych wierzcholkow
 */
void Graf::BFS(int odkad)
{
    bool *odwiedzony = new bool[IloscWierzcholkow];
    for(int i = 0; i < IloscWierzcholkow; i++)
        odwiedzony[i] = false;
    list<int> kolejka;
    odwiedzony[odkad] = true;
    kolejka.push_back(odkad);
    list<int>::iterator i;
    while(!kolejka.empty())
    {
        odkad = kolejka.front();
        cout << odkad << " ";
        kolejka.pop_front();
        for(i = Q[odkad].begin(); i != Q[odkad].end(); ++i)
        {
            if(!odwiedzony[*i])
            {
                odwiedzony[*i] = true;
                kolejka.push_back(*i);
            }
        }
    }
}

/*! Pomocnicza funkcja DFS sluzy do stworzenia rekurencji dla wszystkich wierzcholkow graniczacych wybranemu wierzcholkowi i zaznaczanie ich jako odwiedzonych.
*/

void Graf::DFS_pomoc(int w, bool odwiedzony[])
{
    odwiedzony[w] = true;
    cout << w << " ";
    list<int>::iterator i;
    for(i = Q[w].begin(); i != Q[w].end(); ++i)
        if(!odwiedzony[*i])
            DFS_pomoc(*i, odwiedzony);
}
 
/*! Aby przeprowadzic algorytm Depth First Search, najpierw wszystkie wierzcholki zaznaczone sa jako NIE odwiedzone. Nastepnie pomocnicza rekurencyjna funkcja jest wywolywana,
by wyswietlic przeszukiwanie w glab zaczynajac od kazdego wierzcholka jeden po jednym.
*/

void Graf::DFS()
{
    bool *odwiedzony = new bool[IloscWierzcholkow];
    for(int i = 0; i < IloscWierzcholkow; i++)
        odwiedzony[i] = false;
    for(int i = 0; i < IloscWierzcholkow; i++)
        if(odwiedzony[i] == false)
            DFS_pomoc(i, odwiedzony);
}

/*! Funkcja ponizej rozni sie od powyzszej tylko tym, ze przeszukiwane nie jest dla wszystkich wierzcholkow, lecz tylko dla wybranego "odkad".
*/
void Graf::DFS(int odkad)
{
    bool *odwiedzony = new bool[IloscWierzcholkow];
    for(int i = 0; i < IloscWierzcholkow; i++)
        odwiedzony[i] = false;
    DFS_pomoc(odkad, odwiedzony);
}