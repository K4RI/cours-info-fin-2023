#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    int choixMenu = 0;
    printf("=== Menu ===\n");
    printf("1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\n");
    printf("Votre choix ? ");
    scanf("%d", &choixMenu);

    switch (choixMenu){
        case 1:
            printf("Tu as choisi le menu Royal Cheese\n");
            break;
        case 2:
            printf("Tu as choisi le menu Mc Deluxe\n");
            break;
        case 3:
            printf("Tu as choisi le menu Mc Bacon\n");
            break;
        case 4:
            printf("Tu as choisi le menu Big Mac\n");
            break;
        default:
            printf("???");
            break;
    }

     
    return 0;
}