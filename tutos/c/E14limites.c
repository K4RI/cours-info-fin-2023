#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E14limites.h"

int main(){
    char nom[6] = {0};
    printf("Ton nom ? ");
    // scanf("%s", &nom); // il peut y avoir un dépassement
    // fgets(nom, 6, stdin); // ici on s'arrête à 5
    lire(nom, 6);
    printf("Hello %s !\n", nom);

    long i;
    printf("Alors ? ");
    i = lireLong();
    printf("Le nombre est %d\n", i);

    double d;
    printf("Alors ?? ");
    d = lireDouble();
    printf("L'autre nombre est %lf\n", d);

    return 0;
}

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

int lire(char* chaine, int longueur){
    char* entree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL){
        entree = strchr(chaine, '\n');
        if (entree != NULL){
            *entree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        return 0;
    }    
}

long lireLong()
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire
 
    if (lire(nombreTexte, 100))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}

double lireDouble()
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire
 
    if (lire(nombreTexte, 100))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtod(nombreTexte, NULL);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}