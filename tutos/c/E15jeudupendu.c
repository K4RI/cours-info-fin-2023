#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "E15jeudupendu.h"

int main(int argc, char* argv[])
{
    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[] = "ROUGE"; // C'est le mot à trouver
    int coupsRestants = 10; // Compteur de coups restants (0 = mort)

    int nombreLettres = tailleMot(motSecret);
    int *lettreTrouvee = NULL;
    lettreTrouvee = malloc(nombreLettres * sizeof(int));
    initTableau(lettreTrouvee, nombreLettres);
    for (int i = 0; i<nombreLettres; i++){
        printf("%i, ", lettreTrouvee[i]);
    }

    while(coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres)){
        printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for (int i = 0; i < nombreLettres; i++){
            if (lettreTrouvee[i]){
                printf("%c", motSecret[i]);
            }
            else
            {
                printf("*");
            }
        }
        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        // Si ce n'était PAS la bonne lettre
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--; // On enlève un coup au joueur
        }
    }
    if (gagne(lettreTrouvee, nombreLettres))
    {
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    }    
    else {
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);
    }
    free(lettreTrouvee);
    return 0;
}

int tailleMot(char motSecret[])
{
    int nombreLettres = 0;
    for(int i = 0; motSecret[i] != '\0'; i++)
    {
        nombreLettres++;
    }
    return nombreLettres;
}

void initTableau(int* lettreTrouvee, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        lettreTrouvee[i] = 0;
    }
}

int gagne(int *lettreTrouvee, int nombreLettres){
    int i = 0;
    int joueurGagne = 1;
    for (i = 0; i < nombreLettres; i++){
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }
    return joueurGagne;
}

char lireCaractere()
{
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);
    while (getchar() != '\n');
    return caractere;
}

int rechercheLettre(char lettre, char motSecret[], int * lettreTrouvee){
    int i = 0, bonneLettre = 0;
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonneLettre;
}