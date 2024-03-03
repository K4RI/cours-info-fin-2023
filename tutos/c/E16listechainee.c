#include <stdio.h>
#include <stdlib.h>
#include "E16listechainee.h"

int main()
{
    Liste *maListe = initialisation();

    insertion(maListe, 4);
    Element *adresseSuppr = maListe->premier;
    insertion(maListe, 8);
    Element *adresseAdd = maListe->premier;
    insertion(maListe, 15);
    suppression(maListe);

    afficherListe(maListe);

    insertionMilieu(maListe, 6, adresseAdd);
    afficherListe(maListe);
    printf("Taille = %d\n", tailleListe(maListe));

    suppressionMilieu(maListe, adresseSuppr);
    afficherListe(maListe);

    destruction(maListe);
    insertion(maListe, 1);
    afficherListe(maListe);
    printf("Taille = %d\n", tailleListe(maListe));
    
    return 0;
}

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;
    liste->nbElements = 1;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    liste->nbElements++;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
        liste->nbElements--;
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}


// à partir de là c'est moi
void insertionMilieu(Liste *liste, int nvNombre, Element *adresse)
{
    if (liste == NULL || adresse == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
    while (actuel != adresse && actuel != NULL)
    {
        actuel = actuel->suivant;
    }

    if (actuel == NULL)
    {
        printf("Adresse non-trouvée\n");
    }
    else
    {        
        Element *nouveau = malloc(sizeof(*nouveau));
        nouveau->nombre = nvNombre;
        nouveau->suivant = actuel->suivant;
        actuel->suivant = nouveau;
        liste->nbElements++;
    }
}

void suppressionMilieu(Liste *liste, Element *adresse)
{
    if (liste == NULL || adresse == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
    if (actuel == adresse)
    {
        liste->premier = actuel->suivant;
        free(adresse);
        liste->nbElements--;
    }
    else
    {
        while (actuel->suivant != adresse && actuel != NULL)
        {
            actuel = actuel->suivant;
        }

        if (actuel == NULL)
        {
            printf("Adresse non-trouvée\n");
        }
        else
        {
            actuel->suivant = actuel->suivant->suivant;
            free(adresse);
            liste->nbElements--;
        }
    }    
}

void destruction(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /*
    Element *actuel = liste->premier;
    while (actuel != NULL){
        liste->premier = actuel->suivant;
        free(actuel);
        actuel = liste->premier;
    }
    */

    while (liste->premier != NULL)
    {
        suppression(liste);
    }    
    liste->nbElements = 0;
}

int tailleListe(Liste *liste)
{
    return liste->nbElements;
}