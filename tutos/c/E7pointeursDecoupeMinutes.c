#include <stdio.h>
#include <stdlib.h>

void decoupeMinutes(int *heures, int *minutes);

int main(int argc, char *argv[])
{
    int heures = 0, minutes = 90;

    /* On a une variable minutes qui vaut 90.
    Après appel de la fonction, je veux que ma variable
    "heures" vaille 1 et que ma variable "minutes" vaille 30 */

    decoupeMinutes(&heures, &minutes);

    printf("%d heures et %d minutes", heures, minutes);

    return 0;
}

void decoupeMinutes(int *pheures, int *pminutes)
{
    *pheures = *pminutes / 60;  // 90 / 60 = 1
    *pminutes = *pminutes % 60; // 90 % 60 = 30
}