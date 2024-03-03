#include <iostream>
#include "Personnage.hpp" //Ne pas oublier
#include "Arme.hpp" //Ne pas oublier

using namespace std;

int main()
{
    Personnage goliath("Goliath");  // constructeur 1
    // Personnage david("David", "Epee aiguisee", 20); // constructeur 2
    // Personnage david("David", goliath); // constructeur 2
    Personnage david = goliath; // constructeur 2
    david = goliath;

    david.afficherEtat();
    goliath.afficherEtat();
    david.afficherPointeurArme();
    goliath.afficherPointeurArme();

    
    goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    david.afficherEtat();
    goliath.afficherEtat();
    david.afficherPointeurArme();
    goliath.afficherPointeurArme();

    david.afficherEtat();
    goliath.afficherEtat();
    
    goliath.attaquer(david); //goliath attaque david
    david.boirePotionDeVie(20); //david récupère 20 de vie en buvant une potion
    goliath.attaquer(david); //goliath attaque david
    david.attaquer(goliath); //david contre-attaque... c'est assez clair non ? 
    goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    goliath.attaquer(david);
    
    Personnage moise("Moise", david); // constructeur de copie
    
    moise.afficherEtat();
    moise.attaquer(goliath);

    //Et on consulte notre compteur
    cout << "Il y a actuellement " << Personnage::nombreInstances() << " personnages en jeu." << endl;
    
    return 0;
}
