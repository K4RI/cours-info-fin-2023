#ifndef E10def // Si la constante n'a pas été définie le fichier n'a jamais été inclus

    #define E10def // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

    /* Contenu de votre fichier .h (autres include, prototypes, define...) */

    #define TAILLE_MAX       1000
    #define LARGEUR_FENETRE  800
    #define HAUTEUR_FENETRE  600
    #define NOMBRE_PIXELS    (LARGEUR_FENETRE * HAUTEUR_FENETRE)
    #define COUCOU() printf("Coucou\n");

#endif