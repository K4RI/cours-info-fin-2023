#include "Magicien.hpp"
 
using namespace std;

Magicien::Magicien() : Personnage(), m_mana(100)
{
 
}

Magicien::Magicien(string nom) : Personnage(nom), m_mana(100)
{
    
}

void Magicien::bouleDeFeu(Personnage &cible)
{
    cout << "FOUCH" << endl;
    cible.recevoirDegats(25);
    m_mana -= 15;
}

void Magicien::bouleDeGlace(Personnage &cible)
{
    cout << "AGLAGLA" << endl;
    cible.recevoirDegats(20);
    m_mana -= 10;
}