#include <iostream>
#include <vector> //Ne pas oublier !
#include <string>
#include "E8tableauxdynamiques.hpp"
using namespace std;

int main()
{
    vector<int> tableauInt(5, 3); // contient 5 fois le nombre 3
    vector<string> tableauString(4, "Sans nom"); // contient 4 fois la chaîne "Sans nom"
    tableauInt[0] = 2364345;
    tableauInt[1] = 8945673;
    tableauInt[2] = 6749321;
    tableauInt[3] = 7634893;
    tableauInt[4] = 1048104;
    tableauInt.push_back(1111111); // ajoute une case
    tableauInt.push_back(2222222);
    tableauInt.pop_back(); // retire une case

    int const taille(tableauInt.size()); // la taille du tableau

    cout << "Moyenne du tableau : " << moyenneVecteur(tableauInt) << endl;

    int const tailleX(5);
    int const tailleY(4);
    int tableau[tailleX][tailleY]; // tableau de 5 elts de 4 elts
    
    vector<vector<int> > grille;
    
    grille.push_back(vector<int>(5));   //On ajoute une ligne de 5 cases à notre grille
    grille.push_back(vector<int>(3,4)); //On ajoute une ligne de 3 cases contenant chacune le nombre 4 à notre grille
    grille[0].push_back(8);     //Ajoute une case contenant 8 à la première ligne du tableau
    grille[1][2] = 9;     //Change la valeur de la cellule (1,2) de la grille
    
    string nom = "Julien";
    nom[0] = 'L';
    nom[3] = 'u';
    cout << "Le nom modifié est : " << nom << endl;

    return 0;
}

double moyenneVecteur(vector<int> const& tableau)
{
    double moyenne(0);
    for (int i(0); i < tableau.size(); i++)
    {
        moyenne += tableau[i];
    }
    moyenne /= tableau.size();
    return moyenne;
}