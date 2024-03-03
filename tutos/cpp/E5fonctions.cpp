#include <iostream>

using namespace std;

double carre(double x)
{
    double nombre;
    nombre = x*x;
    return nombre;
}

void direBonjour()
{
    cout << "Bonjour !" << endl;
}

void dessineRectangle(int l, int h, char symb)
{
    if (l < 0 || h < 0)
    {
        cout << "Erreur, valeur négative !" << endl;
    }
    else
    {
        for(int ligne(0); ligne < h; ligne++)
        {
            for(int colonne(0); colonne < l; colonne++)
            {
                cout << symb;
            }
            cout << endl;
        }
    }

}

int main()
{
    direBonjour();

    int longueur(0), largeur(0);
    char symbole('*');
    cout << "Longueur ? ";
    cin >> longueur;
    cout << "Largeur ? ";
    cin >> largeur;
    cout << "Symbole ? ";
    cin >> symbole;
    dessineRectangle(longueur, largeur, symbole);
}

