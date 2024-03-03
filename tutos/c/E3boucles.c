
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int nombreEntre = 0;
    while (nombreEntre != 47)
    {
        printf("Tapez le nombre 47 ! ");
        scanf("%d", &nombreEntre);
    }

    int compteur1 = 0;
    while (compteur1 < 10)
    {
        printf("La variable compteur1 vaut %d\n", compteur1);
        compteur1++;
    }
    printf("\n");

    int compteur2 = 0;
    do
    {
        printf("La variable compteur2 vaut %d\n", compteur2);
        compteur2++;
    } while (compteur2 < 10);
    printf("\n");

    int compteur3;
    for (compteur3 = 0 ; compteur3 < 10 ; compteur3+=2){
        printf("La variable compteur3 vaut %d\n", compteur3);
    }


}