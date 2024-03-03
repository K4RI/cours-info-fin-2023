#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int nombreDeVies = 5, niveau = 1;

    printf("Vous avez %d vies et vous etes au niveau n° %d\n", nombreDeVies, niveau);
    nombreDeVies = 4; // Il vient de perdre une vie !
    printf("Il ne vous reste plus que %d vies !\n\n", nombreDeVies);

    const int nombreDeVie = 10; // constante, dont on ne peut changer la valeur
    
    /*
    int age;
    printf("Quel age avez-vous ? ");
    scanf("%d", &age); // On demande d'entrer l'âge avec scanf
    printf("Ah ! Vous avez donc %d ans !\n\n", age);
    */


    int a = 0, b = 0;
    printf("Premier nombre ? ");
    scanf("%d", &a); // On demande d'entrer l'âge avec scanf
    printf("Deuxième nombre ? ");
    scanf("%d", &b); // On demande d'entrer l'âge avec scanf

    printf("%d + %d = %d\n", a, b, a+b);


    return 0;
}