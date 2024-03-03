#include <iostream>
#include "Personnage.hpp"
#include "Guerrier.hpp"
#include "Magicien.hpp"

using namespace std;

int main()
{
    Personnage goliath();

    Personnage monPersonnage("Pierre");
    Guerrier monGuerrier("Ougl");
 
    monPersonnage.coupDePoing(monGuerrier);
    monGuerrier.frapperAvecUnMarteau(monPersonnage);

    monPersonnage.sePresenter();
    monGuerrier.sePresenter();

    // monPersonnage = monGuerrier; // marche
    // monGuerrier = monPersonnage; //marche pas

    Magicien monMagicien("Gandalf");
    monMagicien.bouleDeFeu(monGuerrier);
    
    return 0;
}