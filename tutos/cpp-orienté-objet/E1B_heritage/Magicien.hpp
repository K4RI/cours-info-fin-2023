#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN
 
#include <iostream>
#include <string>
#include "Personnage.hpp"
 
class Magicien : public Personnage
{
    public:
        Magicien();
        Magicien(std::string nom);
        void bouleDeFeu(Personnage &cible);
        void bouleDeGlace(Personnage &cible);
 
    private:
        int m_mana;
};
 
#endif