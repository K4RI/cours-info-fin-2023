#include "Guerrier.hpp"
 
using namespace std;

Guerrier::Guerrier(string nom): Personnage(nom)
{

}

void Guerrier::frapperAvecUnMarteau(Personnage &cible) const
{
    cout << "BOUM" << endl;
    cible.recevoirDegats(20);

}

void Guerrier::sePresenter() const
{
    Personnage::sePresenter();
    cout << "Je suis un Guerrier redoutable." << endl;
}