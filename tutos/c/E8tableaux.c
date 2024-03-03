#include <stdio.h>
#include <stdlib.h>

void affiche (int tableau[], int tailleTableau);
int sommeTableau(int tableau[], int tailleTableau);
double moyenneTableau(int tableau[], int tailleTableau);

int main(){
    /*
    int tableau[4];
    tableau[0] = 10;
    tableau[1] = 15;
    tableau[2] = 20;
    tableau[3] = 25;
    printf("%d\n", *(tableau+2));
    */

    int tableau[4] = {10, 15, 20, 25};
    for (int i=0; i<4; i++){
        tableau[i] = i*3 + 1;
    }
    affiche(tableau, 4);
    printf("somme = %d\n", sommeTableau(tableau, 4));
    printf("moyenne = %f\n", moyenneTableau(tableau, 4));

    return 0;
}


void affiche (int tableau[], int tailleTableau){
    for (int i=0; i<tailleTableau; i++){
        printf("%d\n", tableau[i]);
    } 
}

int sommeTableau(int tableau[], int tailleTableau){
    int somme = 0;
    for (int i=0; i<tailleTableau; i++){
        somme += tableau[i];
    }
    return somme;
}

double moyenneTableau(int tableau[], int tailleTableau){
    return (double)sommeTableau(tableau, tailleTableau) / (double)tailleTableau;
}