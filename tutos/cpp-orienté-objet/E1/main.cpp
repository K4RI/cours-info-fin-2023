#include <iostream>
#include "Personnage.hpp" //Ne pas oublier
#include "Arme.hpp" //Ne pas oublier

using namespace std;

int main()
{
    Personnage goliath("Goliath");  // constructeur 1
    Personnage david("David", "Epee aiguisee", 20); // constructeur 2

    david.afficherEtat();
    goliath.afficherEtat();

    /*
    david.afficherEtat();
    goliath.afficherEtat();
    */

    goliath.attaquer(david); //goliath attaque david
    david.boirePotionDeVie(20); //david récupère 20 de vie en buvant une potion
    goliath.attaquer(david); //goliath attaque david
    david.attaquer(goliath); //david contre-attaque... c'est assez clair non ? 
    goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    goliath.attaquer(david);
    
    Personnage moise("Moise", david); // constructeur de copie
    
    moise.afficherEtat();
    moise.attaquer(goliath);
    
    return 0;
}