#include <stdio.h>
#include <stdlib.h>

void triple(int nombre);
void triplePointeur(int *pointeurSurNombre);

int main(int argc, char *argv[])
{
    int nombre1 = 5;
    int nombre2 = 5;

    triple(nombre1);
    printf("%d\n", nombre1); // mais... ça marche pas.

    triplePointeur(&nombre2); // On envoie l'adresse de nombre à la fonction
    printf("%d", nombre2); // On affiche la variable nombre. La fonction a directement modifié la valeur de la variable car elle connaissait son adresse

    return 0;
}

void triple(int nombre)
{
    nombre *= 3; // On multiplie par 3 la valeur de nombre...
}

void triplePointeur(int *pointeurSurNombre)
{
    *pointeurSurNombre *= 3; // On multiplie par 3 la valeur de nombre
}