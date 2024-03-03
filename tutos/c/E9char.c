#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen2(const char* chaine);
int strcpy2(char* copie, const char* chaine);
char* strcat2(char* chaine1, const char* chaine2);
int strcmp2(const char* chaine1, const char* chaine2);
char* strchr2(const char* chaine, int caractereARechercher);
char* strrchr2(const char* chaine, int caractereARechercher);
char* strpbrk2(const char* chaine, const char* lettresARechercher);
char* strstr2(const char* chaine, const char* chaineARechercher);


int main(){
    char c = 'A';
    printf("%d\n", c);

    char ch = 65;
    printf("%c\n", ch);

    char chaine[6]; // Tableau de 6 char pour stocker S-a-l-u-t + le \0    
    chaine[0] = 'S';
    chaine[1] = 'a';
    chaine[2] = 'l';
    chaine[3] = 'u';
    chaine[4] = 't';
    chaine[5] = '\0';
    printf("%s\n", chaine);

    char chainee[] = "Salut";
    printf("%s\n", chainee);

    char prenom[100] = "Jej";
    printf("Entrez un prénom : ");
    // scanf("%s", &prenom);
    printf("Coucou %s !\n", prenom);

    printf("taille du prénom = %d\n", strlen(prenom));
    printf("taille du prénom2 = %d\n", strlen2(prenom));

    char copie[100] = "", copie2[100] = "";
    // copier un str dans un autre
    strcpy(copie, prenom);
    strcpy2(copie2, prenom);
    printf("Encore coucou %s !\n", copie);
    printf("Encore coucou %s !\n", copie2);

    char doubler[100] = "", doubler2[100] = "";
    // concaténer un str à un autre
    strcat(doubler, prenom);
    strcat(doubler, prenom);
    strcat2(doubler2, prenom);
    strcat2(doubler2, prenom);
    printf("Attention dédoublement : %s\n", doubler);
    printf("Attention dédoublement : %s\n", doubler2);

    // comparer un str à un autre
    printf("Comparaison : %d\n", strcmp2("Jej", "Joj"));
    printf("Comparaison : %d\n", strcmp2("Jej", "Jejj"));
    printf("Comparaison : %d\n", strcmp2("Jejj", "Jej"));
    
    // rechercher la première occurrence d'un char dans un str
    printf("Recherche : %s\n", strchr("Jejjej", 'e'));
    printf("Recherche : %s\n", strchr2("Jejjej", 'e'));
    printf("Recherche : %s\n", strchr2("Jejjej", 'o'));
    printf("Recherche : %s\n", strrchr("Jejjej", 'e'));
    printf("Recherche : %s\n", strrchr2("Jejjej", 'e'));

    // rechercher la première occurrence d'un des chars dans un str
    printf("Recherchel : %s\n", strpbrk("lrdksdp", "xek"));
    printf("Recherchel : %s\n", strpbrk2("lrdksdp", "xek"));

    // rechercher la première occurrence d'un str dans un str
    printf("Recherches : %s\n", strstr("Jejjej", "jj"));
    printf("Recherches : %s\n", strstr2("Jejjej", "jj"));

    return 0;
}


int strlen2(const char* chaine){
    int i = 0;
    while(*(chaine+i) != '\0'){
        i++;
    }
    return i;
}

int strcpy2(char* copie, const char* chaine){
    int i = 0;
    while(*(chaine+i) != '\0'){
        *(copie+i) = *(chaine+i);
        i++;
    }
}

char* strcat2(char* chaine1, const char* chaine2){
    int i = 0;
    int initlen = strlen(chaine1);
    while(*(chaine2+i) != '\0'){
        *(chaine1 + initlen + i) = *(chaine2+i);
        i++;
    }
    *(chaine1 + initlen + strlen(chaine2)) = '\0';
}

int strcmp2annex(const char* chaine1, const char* chaine2){
    int somme = 0, diff = 0;
        
    for (int i=0; i<strlen(chaine1); i++){
        diff = ((int) chaine1[i]) - ((int) chaine2[i]);
        if (diff > 0) {
            somme += diff;
        } else {
            somme -= diff;
        }
    }
    for (int i=strlen(chaine1); i<strlen(chaine2); i++){
        somme += (int) chaine2[i];
    }
    return somme;
}

int strcmp2(const char* chaine1, const char* chaine2){
    if (strlen(chaine1) < strlen(chaine2)){
        return strcmp2annex(chaine1, chaine2);
    } else {
        return strcmp2annex(chaine2, chaine1);
    }
}

int strcmp3(const char* chaine1, const char* chaine2){ // la vraie
    while (*chaine1 != '\0' && (*chaine1 == *chaine2)){
        chaine1++;
        chaine2++;
    }
    return (*chaine1 == *chaine2) ? 0 : (*(unsigned char *) chaine1 - *(unsigned char *) chaine2);
}

char* strchr2(const char* chaine, int caractereARechercher){
    for (int i=0; i<strlen(chaine); i++){
        if (chaine[i]==caractereARechercher){
            return (char *) chaine+i;
        }
    }
    return NULL;
}

char* strrchr2(const char* chaine, int caractereARechercher){
    for (int i=strlen(chaine)-1; i>=0; i--){
        if (chaine[i]==caractereARechercher){
            return (char *) chaine+i;
        }
    }
    return NULL;
}

char* strpbrk2(const char* chaine, const char* lettresARechercher){
    for (int i=0; i<strlen(chaine); i++){
        for (int j=0; j<strlen(lettresARechercher); j++){
            if (chaine[i]==lettresARechercher[j]){
                return (char *) chaine+i;
            }
        }
    }
    return NULL;
}

int strstr2annex(const char* chaine, const char* chaineARechercher){
    for (int k=0; k<strlen(chaineARechercher); k++){
        if (chaine[k]!=chaineARechercher[k]){
            return 0;
        }
    }
    return 1;
}

char* strstr2(const char* chaine, const char* chaineARechercher){
    for (int i=0; i<strlen(chaine); i++){
        char * chainesliced = (char*) chaine + i;
        if (strstr2annex(chainesliced, chaineARechercher) == 1){
            return (char *) chaine+i;
        }
    }
    return NULL;
}