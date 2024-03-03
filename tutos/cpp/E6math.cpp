#include "E6math.hpp"
#include <iostream>

int ajouteDeux(int nombreRecu)
{
    int valeur(nombreRecu + 2);
    return valeur;
}

void afficherMessage(std::string message)
{
    std::cout << "Le message est : \"" << message << "\"." << std::endl;
}

// Définition de la fonction
int nombreDeSecondes(int heures, int minutes, int secondes)
{
    int total = 0;

    total = heures * 60 * 60;
    total += minutes * 60;
    total += secondes;

    return total;
}