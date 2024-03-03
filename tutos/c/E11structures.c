#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E11structures.h"

int main(int argc, char *argv[])
{
    Coordonnees point;    
    point.x = 10;
    point.y = 20;
    Coordonnees pointt = {0, 0}; // valeur directement initialisées
    
    Personne utilisateur;
    printf("Quel est votre nom ? ");
    scanf("%s", utilisateur.nom);
    printf("Votre prénom ? ");
    scanf("%s", utilisateur.prenom);
    printf("Vous vous appelez %s %s\n", utilisateur.prenom, utilisateur.nom);
    
    Personne joueurs[2]; // tableau de joueurs
    strcpy(joueurs[0].nom, "Koko");
    printf("%s\n", joueurs[0].nom);

    Personne joueur0 = {"Pierre", "Dupont", "1 rue du Lol", 23, 0};
    Personne joueur1 = {"Nicolas", "Fernandel", "5 bd de la Gariguette", 45, 1};
    Personne joueurss[2] = {joueur0, joueur1}; // tableau de joueurs
    printf("%i\n", joueurss[0].age);
    printf("%s\n", joueurss[0].adresse);

    Coordonnees point1;
    initialiserCoordonnees(&point1);

    Volume musique = MOYEN;
    if (musique == MOYEN){
        printf("On joue à volume moyen.");
    }

    return 0;
}

void initialiserCoordonnees(Coordonnees* point)
{
    /*
    (*point).x = 0;
    (*point).y = 0;
    */
    point->x = 0;
    point->y = 0;
}