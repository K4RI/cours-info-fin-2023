typedef struct Coordonnees Coordonnees;
// on peut déclarer "Coordonnees c" au lieu de "struct Coordonnees c"
struct Coordonnees
{
    int x; // Abscisses
    int y; // Ordonnées
};

typedef struct Personne Personne;
struct Personne
{
    char nom[100];
    char prenom[100];
    char adresse[1000];
    
    int age;
    int etudiant; // Booléen : 1 = etudiant, 0 = non etudiant
};

void initialiserCoordonnees(Coordonnees* point);

typedef enum Volume Volume;
enum Volume
{
    FAIBLE = 10, MOYEN = 50, FORT
};