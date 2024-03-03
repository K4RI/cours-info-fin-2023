typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
    int nbElements;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
void insertionMilieu(Liste *liste, int nvNombre, Element *adresse);
void suppressionMilieu(Liste *liste, Element *adresse);
void destruction(Liste *liste);
int tailleListe(Liste *liste);