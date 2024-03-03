#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000

int main(int argc, char *argv[])
{
    FILE* fichierw = NULL;

    fichierw = fopen("E12.txt", "r+");

    if (fichierw != NULL)
    {
        fputc('A', fichierw); // Écriture du caractère A
        fputc('\n', fichierw);
        fputs("hello\n", fichierw);
        int num;
        printf("Quelle est votre carte ? ");
        scanf("%d", &num);
        fprintf(fichierw, "Votre carte est le %d de trèfle\n", num);

        int c = fclose(fichierw); // on libère la mémoire
        if (c == 0)
        {
            printf("Fichier correctement modifié et libéré\n");
        }
    }
    else
    {
        // le fichier n'existe pas
        printf("Impossible d'ouvrir le fichier test.txt");
    }



    FILE* fichierr = NULL;
    int caractereActuel = 0; 
    fichierr = fopen("E12.txt", "r"); 
    if (fichierr != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichierr); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        fclose(fichierr);
    }

    char chaine[TAILLE_MAX] = "";
    rewind(fichierr);
    if (fichierr != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichierr) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }
        fclose(fichierr);
    }

    rewind(fichierr);
    int score;
    fgets(chaine, TAILLE_MAX, fichierr);
    fgets(chaine, TAILLE_MAX, fichierr);
    fscanf(fichierr, "Votre carte est le %i de trèfle", &score);
    printf("La carte était le %i de trèfle\n", score);



    return 0;
}