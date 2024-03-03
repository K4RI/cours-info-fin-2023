#include "Calculatrice.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(1);    
    vec.push_back(4);
    // vector<int> vec = {2, 7, 1, 4};

    int rayon = Calculatrice::somme(vec);
    cout << "Somme = " << rayon << endl;

    double peri = Calculatrice::perimetre(rayon);
    cout << "Périmètre = " << peri << endl;


}