#include "Figure.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Figure*> listeFigures;

    listeFigures.push_back(new Triangle(3, 4));
    listeFigures.push_back(new Carre(5));
    listeFigures.push_back(new Rectangle(5, 2));
    listeFigures.push_back(new Cercle(3));

    for (int i(0); i < listeFigures.size(); i++)
    {
        listeFigures[i]->afficher();
        cout << "Aire : " << listeFigures[i]->aire() << endl;
        cout << "Périmètre : " << listeFigures[i]->perimetre() << endl;
    }


}