#include <stdio.h>
#include <stdlib.h>
#include "E10def.h"

int main(){

    printf("\nNous sommes à la ligne %d du fichier %s\n\n", __LINE__, __FILE__);
    printf("Ce fichier a ete compile le %s a %s\n\n", __DATE__, __TIME__);

    COUCOU();
    return 0;
}