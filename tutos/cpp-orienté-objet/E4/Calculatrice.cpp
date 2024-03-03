#include "Calculatrice.hpp"
#include <cmath>

#define PI atan(1)*4

int Calculatrice::somme(std::vector<int> vecteur)
{
    int sum = 0;
    for (int i(0); i < vecteur.size(); i++)
    {
        sum += vecteur[i];
    }
    return sum;
}



double Calculatrice::perimetre(double rayon)
{
    return 2 * PI * rayon;
}