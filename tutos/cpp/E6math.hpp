#ifndef E6MATH_HPP_INCLUDED
#define E6MATH_HPP_INCLUDED

#include <string>

/*
 * Fonction qui ajoute 2 au nombre reçu en argument
 * - nombreRecu : Le nombre auquel la fonction ajoute 2
 * Valeur retournée : nombreRecu + 2
 */
int ajouteDeux(int nombreRecu);

/*
 * Fonction qui affiche un message
 * - message : Le message à afficher
 */
void afficherMessage(std::string message);

// Prototype de la fonction
int nombreDeSecondes(int heures, int minutes = 0, int secondes = 0);

#endif // E6MATH_HPP_INCLUDED