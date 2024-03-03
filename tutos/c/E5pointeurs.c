#include <stdio.h>
#include <stdlib.h>

int main(){
    int age = 10;

    printf("La valeur de la variable age est : %d\n", age);
    // en hexadécimal
    printf("L'adresse de la variable age est : %p\n", &age);
    // en décimal
    printf("L'adresse de la variable age est : %d\n\n", &age);

    int *pointeurSurAge = NULL;
    pointeurSurAge = &age;
    printf("La valeur du pointeur est : %d\n", pointeurSurAge);
    printf("La valeur pointée par le pointeur est : %d\n", *pointeurSurAge);

    return 0;
}