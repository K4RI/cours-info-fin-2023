#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 100, MIN = 1;

int main(){
    srand(time(NULL));

    int nombreMystere = 0;
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    int nombreEntre = 0;

    do {
        printf("Nombre mystère ? ");
        scanf("%d", &nombreEntre);

        if (nombreMystere > nombreEntre){
            printf("C'est plus !\n\n");
        } else if (nombreMystere < nombreEntre){
            printf("C'est moins !\n\n");
        } else {
            printf ("Bravo, vous avez trouve le nombre mystere !!!\n\n");
        }
    } while(nombreEntre != nombreMystere);
    return 0;
}