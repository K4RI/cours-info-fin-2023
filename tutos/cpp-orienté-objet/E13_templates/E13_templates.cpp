#include <iostream>
#include <vector>
#include "E13_templates.hpp"
using namespace std;

int main()
{
    double pi(3.14);
    double e(2.71);
    cout << maximum<double>(pi,e) << endl; //Utilise la "version double"de la fonction

    int cave(-1);
    int dernierEtage(12);
    cout << maximum<int>(cave,dernierEtage) << endl; //Utilise la "version int" de la fonction

    unsigned int a(43);
    unsigned int b(87);
    cout << maximum<unsigned int>(a,b) << endl; //Utilise la "version unsigned int" de la fonction.

    int tab[] = {10, 7, 4, 3, 22};
    vector<int> vec = {10, 7, 4, 3, 22};
    double moyt = moyenne<int, double>(tab, 5);
    double moyv = moyenne<int, double>(vec);
    cout << "Moyenne tableau = " << moyt << endl;
    cout << "Moyenne vecteur = " << moyv << endl;

    // on a spécialisé le template "maximum" sur le string
        // au lieu de l'ordre lexicographique, c'est mtn l'ordre de taille
    cout << "Le plus grand est: " << maximum<string>("elephant","souris") << endl;

     return 0;
}