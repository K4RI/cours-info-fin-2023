#include <stdio.h>
#include <stdlib.h>
#include "E17files.h"


int main(){

    File *maFile = initialiser();
    enfiler(maFile, 4);
    enfiler(maFile, 8);
    enfiler(maFile, 15);
    enfiler(maFile, 16);
    enfiler(maFile, 23);    
    enfiler(maFile, 42);
    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    printf("Je défile %d\n", defiler(maFile));
    printf("Je défile %d\n", defiler(maFile));
    
    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    return 0;
}

File *initialiser()
{    
    File *file = malloc(sizeof(*file));

    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    file->premier = NULL;
    return file;
}

void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}

int defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return nombreDefile;
}

void afficherFile(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = file->premier;

    while (actuel != NULL)
    {
        printf("%d ", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n\n");
}