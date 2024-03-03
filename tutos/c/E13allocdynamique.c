#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));

    int* memoireAllouee = NULL;

    memoireAllouee = malloc(sizeof(int));
    if (memoireAllouee == NULL) // Si l'allocation a échoué
    {
        exit(0); // On arrête immédiatement le programme
    }

    // On peut continuer le programme normalement sinon 
    // Utilisation de la mémoire
    do {
        printf("Ça va comment sur 10 ? ");
        scanf("%d", memoireAllouee);
    } while ((*memoireAllouee < -10) || (*memoireAllouee > 10));

    if (*memoireAllouee <= -5){
        printf("%d/10 ? miiiii\n", *memoireAllouee);
    } else if (*memoireAllouee >= 5){
        printf("%d/10 ? let's gooooo\n", *memoireAllouee);
    } else {
        printf("%d/10 ? mouai\n", *memoireAllouee);
    }
    
    free(memoireAllouee); // On n'a plus besoin de la mémoire, on la libère


    int nombreDAmis = 0, i = 0;
    int* ageAmis = NULL; // Ce pointeur va servir de tableau après l'appel du malloc

    // On demande le nombre d'amis à l'utilisateur
    printf("Combien d'amis avez-vous ? ");
    scanf("%d", &nombreDAmis);

    if (nombreDAmis > 0) // Il faut qu'il ait au moins un ami (je le plains un peu sinon :p)
    {
        ageAmis = malloc(nombreDAmis * sizeof(int)); // On alloue de la mémoire pour le tableau
        if (ageAmis == NULL) // On vérifie si l'allocation a marché ou non
        {
            exit(0); // On arrête tout
        }

        // On demande l'âge des amis un à un
        for (i = 0 ; i < nombreDAmis ; i++)
        {
            printf("Quel âge a l'ami numero %d ? ", i + 1);
            scanf("%d", &ageAmis[i]);
            // ageAmis[i] = 20 + i;
        }

        // On affiche les âges stockés un à un
        printf("\n\nVos amis ont les âges suivants :\n");
        for (i = 0 ; i < nombreDAmis ; i++)
        {
            printf("%d ans\n", ageAmis[i]);
        }

        // On libère la mémoire allouée avec malloc, on n'en a plus besoin
        free(ageAmis);
    }

    return 0;
}