#include <iostream>
#include <limits>
using namespace std;

double calculMoyenne(int tableau[], int tailleTableau)
{
    double moyenne(0);
    for (int i = 0; i < tailleTableau; i++)
    {
        moyenne += tableau[i];
    }
    moyenne /= tailleTableau;
    return moyenne;
}

int main()
{
    int const taille(5);
    int tableauInts[taille];

    tableauInts[0] = 2364345;
    tableauInts[1] = 8945673;
    tableauInts[2] = 6749321;
    tableauInts[3] = 7634893;
    tableauInts[4] = 1048104;

    for (int i = 0; i < taille; i++)
    {
        cout << i << " : " << tableauInts[i] << endl;
    }

    int tableauDoubles[taille];
    tableauDoubles[0] = 12;
    tableauDoubles[1] = 8;
    tableauDoubles[2] = 6;
    tableauDoubles[3] = 18;
    tableauDoubles[4] = 14;
    cout << "Moyenne : " << calculMoyenne(tableauDoubles, taille) << endl;

    double moyenne(0);
    double note;

    for (int i = 0; i < taille; i++)
    {
        cout << "Entrez la note n°" << i << " : ";
        while (!(cin >> note)) {
            cout << "Invalide. Ré-entrez la note n°" << i << " : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        moyenne += note;
    }
    moyenne /= taille;
    cout << "Moyenne : " << moyenne << endl;
}