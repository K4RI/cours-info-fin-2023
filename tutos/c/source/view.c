#include <stdio.h>
#include <stdlib.h>
#include "../headers/view.h"

int main(){
    printf("%d\n", incremente());
    printf("%d\n", incremente());
}

int incremente(){
    static int nombre = 0;
    nombre++;
    return nombre;
}