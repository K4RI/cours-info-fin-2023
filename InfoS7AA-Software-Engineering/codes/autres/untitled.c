// https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19733-stockez-les-donnees-avec-les-listes-chainees

#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

Element *insertion(Element *element, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (element == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;
    nouveau->suivant = element;
    return nouveau;
}

void afficherListe(Element *element)
{
    if (element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = element;
    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

int main()
{
    Element *element = malloc(sizeof(*element));
    element->nombre = 0; // demande toujours un zéro...
    element->suivant = NULL;
    element = insertion(element, 4);
    element = insertion(element, 8);
    element = insertion(element, 0);
    element = insertion(element, 15);

    afficherListe(element);

    return 0;
}